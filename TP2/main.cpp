/* 
 * File:   main.cpp
 * Author: guido
 *
 * Created on 23 de marzo de 2013, 17:34
 */

#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cimg_library;

/*
 * 
 */
//Funciones

//Negativo de la imagen
// s = 255 - r
CImg<unsigned char> negative(CImg<unsigned char> img){
  CImg<unsigned char> img_i(img.width(), img.height());
  cimg_forXY(img, x, y){
    img_i(x,y) = 255 - img(x,y);
  }
  return img_i;
}
// s = a r + c
CImg<int> lut(float a, float c){    
  CImg<int> r(256,1,1);
  for(int i=0;i<256;i++)
        r(i)=i;  
  CImg<int> s(256,1,1);
  cimg_forXY(r, x, y){
    s(x, y) = a* r(x, y) + c;
    if(s(x,y) < 0)
      s(x,y) = 0;
    else if (s(x,y) > 255)
      s(x,y) = 255;
  }  
  return s;
}

CImg<int> lut_tramos(float x1,float y1, float x2, float y2){    
 CImg<int> lut_tramos(256,1,1);
     float m,b,aux_x,aux_y;//pendiente   
     //y=mx+b
     y1=255-y1;
     y2=255-y2;     
     
 if(x2<x1){//cambio los valores para el calculo de las pendientes
     aux_x = x1;
     x1 = x2;
     x2 = aux_x;
     aux_y = y1;
     y1=y2;
     y2=aux_y;
 }
     
     //calculo la primer pendiente
     m=y1/x1;          
     for(int i=0;i<x1;i++)
         lut_tramos(i)=m*i;
 
     m = (y2-y1) / (x2-x1);     
     b= y2-x2*m;
     for(int j=x1;j<x2;j++)
         lut_tramos(j)=m*j +b;
     
     m = (255-y2) / (255-x2);
     b= 255-255*m;     
     for(int k=x2;k<256;k++)
         lut_tramos(k)=m*k +b;
     
 return lut_tramos;
}

CImg<float> lut_log(CImg<float> imag,float c){
	CImg<float> imag_normal=imag.get_normalize(0,1);
	CImg<float> imag2(imag.width(),imag.height(),imag.depth(),imag.spectrum());
	cimg_forXYC(imag,x,y,v) {
		//std::cout<<imag_normal(x,y,0,v)<<std::endl;
		imag2(x,y,0,v)=c*log(imag_normal(x,y,0,v)+1);
		if(imag2(x,y,0,v)>1)
			imag2(x,y,0,v)=1;
		else 
			if(imag2(x,y,0,v)<0)
				imag2(x,y,0,v)=0;
	}
	return imag2;//imag2.normalize(0,255);
}

CImg<double> lut_potencia(CImg<double> imag,double gamma,double c=1){
	CImg<double> imag_normal=imag.get_normalize(0,1);
	CImg<double> imag2(imag.width(),imag.height(),imag.depth(),imag.spectrum());
	cimg_forXYC(imag_normal,x,y,v) {		
		imag2(x,y,0,v)=c*pow(imag_normal(x,y,0,v),gamma);
		if(imag2(x,y,0,v)>1)
			imag2(x,y,0,v)=1;
		else 
			if(imag2(x,y,0,v)<0)
			imag2(x,y,0,v)=0;
	}
	return imag2;//imag2.normalize(0,255);
}

//Funciones aritmeticas

CImg<unsigned char> suma_img(CImg<unsigned char> img1,CImg<unsigned char> img2){
	CImg<unsigned char> new_img(img1.width(),img1.height(),img1.depth(),img1.spectrum(),0);
	cimg_forXYC(img1,x,y,v){
		new_img(x,y,0,v)=(img1(x,y,0,v)+img2(x,y,0,v))/2;
	}        
	return new_img;
}


//Filtros

CImg<unsigned char> emboss(CImg<unsigned char> img, int desplazamiento){
    CImg<unsigned char> negativo = negative(img);
    CImg<unsigned char> negativo_aux = img;
    
    negativo_aux.fill(0);
    CImg<unsigned char> img_emboss(img.width(),img.height(),img.depth(),img.spectrum(),0);    
    //desplazamos el negativo
    for(int i=img.width()-desplazamiento; i>=0;i--)
        for(int j=0;j<img.height();j++)
            negativo_aux(i+desplazamiento,j)=negativo(i,j);            
    negativo = suma_img(negativo_aux,img_emboss);
    CImg<unsigned char> emboss(img.width()-desplazamiento,img.height(),img.depth(),img.spectrum(),0);        
    cimg_forXY(emboss,x,y){
        emboss(x,y)=negativo(x+desplazamiento,y);
    }
    return emboss; 
   
    
}


//umbrales binarios

CImg<bool> binarize(CImg<unsigned char> img, int umbral,bool inverse){
    CImg<bool> imgbin(img.width(),img.height());    
        cimg_forXY(img,x,y){
            if(!inverse){
            if(img(x,y)<umbral)
                imgbin(x,y)=0;
            else
                imgbin(x,y)=1;
        }else
         if(img(x,y)>umbral)
                imgbin(x,y)=0;
            else
                imgbin(x,y)=1;
        }
        return imgbin;        
}

CImg<bool> binarize_sections(CImg<unsigned char> img, int section1,int section2,bool inverse){
    CImg<bool> imgbin(img.width(),img.height());    
        cimg_forXY(img,x,y){
            if(!inverse){
            if(img(x,y)>section1 && img(x,y)<section2)
                imgbin(x,y)=1;
            else
                imgbin(x,y)=0;
        }
        else        
            if(img(x,y)>section1 && img(x,y)<section2)
                imgbin(x,y)=0;
            else
                imgbin(x,y)=1;
        }
        return imgbin;        
}

 CImg<bool> img_or(CImg<bool> img1,CImg<bool> img2){
	 CImg<bool> salida(img1.width(),img1.height());
	 cimg_forXY(img1,x,y){
		 salida(x,y)=img1(x,y)||img2(x,y);
	 }
	 return salida;
 }
 
 CImg<bool> img_not(CImg<bool> img){
	 CImg<bool> salida(img.width(),img.height());
	 cimg_forXY(img,x,y){
		 salida(x,y)=-1*img(x,y);
	 }
	 return salida;
 }
 
 
 
 CImg<bool> img_op_mayor(CImg<bool> img1,CImg<bool> img2){
	 CImg<bool> salida(img1.width(),img1.height());
	 cimg_forXY(img1,x,y){
		 salida(x,y)=img1(x,y)>img2(x,y);
	 }
	 return salida;
 }




int main(int argc, char** argv) {

    
    
    cout<< "Resolución Trabajo Práctico Número 2:"<<endl;
    cout<< "1-Ejercicio-1"<<endl;
    cout<< "2-Ejercicio-2"<<endl;
    cout<< "3-Ejercicio-3"<<endl;
    cout<< "4-Ejercicio-4"<<endl;
    cout<< "5-Ejercicio-5"<<endl;
    cout<< "6-Ejercicio-6"<<endl;
    cout<< "7-Ejercicio-7"<<endl;
    int ejercicio;
    cin>>ejercicio; 
    
     switch(ejercicio){
        
        case 1:{   //Ejercicio 1                           
	const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP2/images/bone.tif","Image file\n");
	CImg<unsigned char> img1(filename); //Carga de disco
        CImg<unsigned char> imgTrans(filename); //Carga de disco
        CImgDisplay ventana1,ventana2,ventana3,ventana4;
        CImg<int> lut_table = lut(0.5,10);        
        
        
        cimg_forXY(imgTrans, x, y){
            imgTrans(x,y)=lut_table(imgTrans(x,y));
        }
        //creo la imagen de mapeo aplicado
        CImg<unsigned char> mapeoLut(256,256,1);
        mapeoLut.fill(0);
        for(int j=0;j<256;j++){
            mapeoLut(j,255-lut_table(j))=255;           
        }
        
        //para que entren en la misma ventana las 3 imagenes
        img1.resize(256,256,1,1,1);        
        imgTrans.resize(256,256,1,1);
        
        (img1,mapeoLut,imgTrans).display(ventana1);
        while(!ventana1.is_closed()){};
        
        //ejercicio 1)-3
        const char* filename2 = cimg_option("-i","/home/guido/NetBeansProjects/TP2/images/cameraman.tif","Image file\n");
        CImg<unsigned char> img2(filename2); //Carga de disco        
        CImg<unsigned char> negative_img = negative(img2);
        
        (img2,negative_img).display(ventana2);
        while(!ventana2.is_closed()){};
        
        
         
        CImg<bool> ejes(256,256,1);
        ejes.fill(0);
        cimg_forXY(ejes, x, y){
            if (x == 255 - y)
            ejes(x,y) = 1;
        }
          float x1, y1, x2, y2;
          ejes.display(ventana3);
          int clicks = 0;
          while (!ventana3.is_closed()){
            ventana3.wait(); // TODO
            if (ventana3.button() && (clicks == 0)){
              x1 = ventana3.mouse_x(); 
              y1 = ventana3.mouse_y(); 
              clicks++;
            }
            else if (ventana3.button() && (clicks == 1)){ 
              x2 = ventana3.mouse_x(); 
              y2 = ventana3.mouse_y();
              ventana3.close();
            }
          }
          
        //lut x tramos; 
          
        CImg<int> lutTramos=lut_tramos(x1,y1,x2,y2);
        //primer pendiente, 
        
        CImg<unsigned char> mapeoLut2(256,256,1);
        mapeoLut2.fill(0);
        
        for(int j=0;j<256;j++){//armo grafica con el mapeo
            mapeoLut2(j,255-lutTramos(j))=255;                       
        }                        
        mapeoLut2.display(ventana4);
        while(!ventana4.is_closed()){};
        break;
        }
        
        
        case 2: {//Ejercicio 2
      
        CImg<float> img("/home/guido/NetBeansProjects/TP2/images/rmn.jpg");
	CImg<float> img_log(img.width(),img.height(),img.depth(),img.spectrum());
	CImg<float> img_pot(img.width(),img.height(),img.depth(),img.spectrum());
        img_log=lut_log(img,2);
	img_pot=lut_potencia(img,2,1);
	CImgDisplay ventana1,ventana2,ventana3;
        ventana1.display(img);
	ventana2.display(img_log);
        ventana3.display(img_pot);
	while (!ventana1.is_closed() &&!ventana2.is_closed() && !ventana3.is_closed()  ){};
	return 0;
        break;            
        }
        
        case 3: {//Ejercicio 3
        
        CImg<unsigned char> futbol("/home/guido/NetBeansProjects/TP2/images/futbol.jpg");
	CImg<unsigned char> chairs("/home/guido/NetBeansProjects/TP2/images/flowers_oscura.tif");
	CImg<unsigned char> sumaimg=suma_img(futbol,chairs);
	sumaimg.display();
        break;   
        }
        
        case 4: {//Ejercicio 4        
            CImg<unsigned char> img1("/home/guido/NetBeansProjects/TP2/images/chairs.jpg");        
            CImgDisplay ventana;        
            CImg<unsigned char> img=emboss(img1,20);
            ventana.display(img);
            while (!ventana.is_closed()){};
            break;        
        }        
        
        case 5: {//Ejercicio 5        
            CImg<unsigned char> img1("/home/guido/NetBeansProjects/TP2/images/chairs.jpg");
            CImg<unsigned char> img2("/home/guido/NetBeansProjects/TP2/images/lenna.gif");
            CImg<bool> imgbin=binarize(img1,100,false);
            CImg<bool> imgbinSec=binarize_sections(img1,50,100,false);            
            CImgDisplay ventana;        
            //(imgbin,imgbinSec).display(ventana);
            
            (img_not(imgbin),imgbin).display(ventana);
            while (!ventana.is_closed()){};
            break;        
        }
        
        
        case 7: {//Ejercicio 7        
            //7a 
            CImg<unsigned char> img("/home/guido/NetBeansProjects/TP2/images/earth.bmp");                       
            CImgDisplay ventana;                                
            CImg<bool> imgN=binarize(img,200,false);
            
            
            
            imgN.display(ventana);
            
            while (!ventana.is_closed()){};
            break;        
        }
     }
    
    
    return 0;
}

