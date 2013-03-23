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
        CImgDisplay ventana1,ventana2;
        CImg<int> lut_table = lut(2,5);        
        
        
        cimg_forXY(imgTrans, x, y){
            imgTrans(x,y)=lut_table(imgTrans(x,y));
        }
        //creo la imagen de mapeo aplicado
        CImg<unsigned char> mapeoLut(256,256,1);
        mapeoLut.fill(0);
        for(int j=0;j<256;j++){
            mapeoLut(j,255-lut_table(j))=255;           
        }
        
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
        break;
        }
     }
    
    
    return 0;
}

