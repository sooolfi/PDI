#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cimg_library;

//Funciones

 //Funcion Ej4
 CImg<unsigned char> createWhiteCircle(int size, int radius,unsigned char colorCircle[],unsigned char colorScreen[] ){
        CImg<unsigned char> img(size,size,1,3);
        //Seteo el color de fondo
        cimg_forXY(img,x,y) { 
            img(x,y,0) = colorScreen[0];
            img(x,y,1) = colorScreen[1];
            img(x,y,2) = colorScreen[2];}                                        
        //dibujo el circulo
        img.draw_circle(size/2,size/2,radius,colorCircle,1);
        return img;        
        }
 
 //Funcion Ej7
 CImg<unsigned char> halftoning(CImg<unsigned char> img){
     
        bool class0[3][3]={{0,0,0},{0,0,0},{0,0,0}};     	
	bool class1[3][3]={{0,1,0},{0,0,0},{0,0,0}};
	bool class2[3][3]={{0,1,0},{0,0,0},{0,0,1}};
	bool class3[3][3]={{1,1,0},{0,0,0},{0,0,1}};
	bool class4[3][3]={{1,1,0},{0,0,0},{1,0,1}};
	bool class5[3][3]={{1,1,1},{0,0,0},{1,0,1}};
	bool class6[3][3]={{1,1,1},{0,0,1},{1,0,1}};
	bool class7[3][3]={{1,1,1},{0,0,1},{1,1,1}};
	bool class8[3][3]={{1,1,1},{1,0,1},{1,1,1}};
	bool class9[3][3]={{1,1,1},{1,1,1},{1,1,1}};
               
     //creamos una nueva imagen con 10 tonos, 3 veces mas grande que la original
     int width = img.width();
     int height = img.height();
     
     CImg<bool> halftoningImg(3*width,3*height);
     int clase;
     cimg_forXY(img,x,y){
         //escalamos  0 a 255 , 256/10 clases son 25,6 
         clase = img(x,y)/25;         
         
         switch ((int)clase){
             case 0:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class0[i][j];                              
                 break;
             }
             case 1:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class1[i][j];                              
                 break;
             }
             case 2:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class2[i][j];                              
                 break;
             }
             case 3:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class3[i][j];                              
                 break;
             }
             case 4:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class4[i][j];                              
                 break;
             }
             case 5:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class5[i][j];                              
                 break;
             }
             case 6:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class6[i][j];                              
                 break;
             }
             case 7:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class7[i][j];                              
                 break;
             }
             case 8:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class8[i][j];                              
                 break;
             }
             case 9:{
                 for(int i=0;i<3;i++)
                     for(int j=0;j<3;j++)
                        halftoningImg(3*x+i,3*y+j) = class9[i][j];                              
                 break;
             }
         }
         
     }
     return halftoningImg;
             //.resize(halftoningImg.width()/3,halftoningImg.height()/3,1,1,1);
     
 
 
 }

 

int main(int argc, char *argv[]) {
    
    
    
    cout<< "Resolución Trabajo Práctico Número 1:"<<endl;
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
	const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/cameraman.tif","Image file\n");
	CImg<unsigned char> img1(filename); //Carga de disco        
	//corta y pega en imagen 2
	CImg<unsigned char> img2(img1);
	img2.crop(85,35,145,95);

	//calculo tamaño de la subimagen (54 bytes de cabecera)
	float sum=0;
	sum=60*60*3+54;
	cout<<"Tamanio de Subimagen: " << sum << endl ;

	//guardo la imagen cortada en archivo .bmp
	img2.save("images/cameraman2.bmp");
        
	//Visualiza ambas imagenes a la vez
	CImgDisplay vent1(img1,"original"), vent2(img2,"cortada");
	while(!vent1.is_closed()){}
	

	CImg<unsigned char> img3(256,256,1,1);
	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)
			img3(i,j)=i;
	img3.save("images/grises.bmp");

        //Visualiza imagen 3
	CImgDisplay vent3(img3,"grises");
	while(!vent3.is_closed()){}
        break;
        }
        
        case 2:{//Ejercicio 2
    
    
    int valor = 1;
    
    cout << "Ingrese el numero de imagen a visualizar" << endl;
    cout << "1-Cameraman.tif" << endl;
    cout << "2-a7v600-SE.gif" << endl;
    cout << "3-billete.jpg" << endl;
    cout << "4-lenna.gif" << endl;
    cout << "5-bone.tif" << endl;    
    cin >> valor ;
          
    const char* cadena = "";
    switch (valor){
        case 1:{
            cadena ="cameraman.tif";
            break;}
        case 2:{
            cadena ="a7v600-SE.gif";
            break;}
        case 3:{
            cadena ="billete.jpg";
            break;}
        case 4:{
            cadena ="lenna.gif";
            break;}
        case 5:{
            cadena ="bone.tif";
            break;}
  
    };
    
    const char* cadena2 = "/home/guido/NetBeansProjects/TP1/images/";        
    const char* p = new char [strlen(cadena)+strlen(cadena2)+1];
    const char* s = new char [strlen(cadena)+strlen(cadena2)+1];
    strcat(const_cast<char*>(p),cadena2);
    strcat(const_cast<char*>(p),cadena);
    strcpy(const_cast<char*>(s),p);        

    const char* filename = cimg_option("-i",s,"Image file\n");
    CImg<unsigned char> img(filename);
    CImgDisplay ventana(img,"Info Image");
    img.print(cadena,1);
    img.stats();    
    while(!ventana.is_closed()){}
    break;
        }
    
    
        case 3: {//Ejercicio 3
    
//    Las imágenes de intensidad, son el producto de los datos del sistema láser, 
//    cuya ventaja es que son capturadas sin necesidad de luz, pudiendo ser estas 
//    producidas las 24 horas del día, aplicable en zonas de condiciones meteorológicas 
//    adversas, donde el área se despeja en horas de la noche y también como un elemento 
//    que acompaña a todos los productos y planos generados con el LIDAR.    
        
        
        int valor = 1;
        cout<< "Ingrese la opción: "<<endl;
        cout<< "1- Blanco y Negro: "<<endl;
        cout<< "2- Color: "<<endl;
        cin >> valor;
                
        int pos_y;
        
        switch(valor){
            case 1:{
                const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/coins.tif","Image file\n");
                CImg<unsigned char> img(filename),perfil(256,256,1,1,0);       
                CImgDisplay ventana(img,"Imagen Intensa",0);        
                CImgDisplay ventana2(perfil, "Perfil",0);
                while(!ventana.is_closed()){
                ventana.wait();
                pos_y=ventana.mouse_y();
                perfil.fill(0).draw_graph(img.get_crop(0,pos_y,0,0,img.width()-1,pos_y,0,0),"white",1,1,0,255,0).display(ventana2);                
                    }
                break;}
            case 2:{
                const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/lenna.gif","Image file\n");
                CImg<unsigned char> img(filename),perfil(500,400,1,3,0);                                                
                img.blur(2.5);
                CImgDisplay ventana(img,"Imagen Intensa",0);        
                CImgDisplay ventana2(perfil, "Perfil",0);
                const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
                while(!ventana.is_closed()){
                    ventana.wait();
                    pos_y=ventana.mouse_y();                
                    perfil.fill(0).draw_graph(img.get_crop(0,pos_y,0,0,img.width()-1,pos_y,0,0),red,1,1,0,255,0);
                    perfil.draw_graph(img.get_crop(0,pos_y,0,1,img.width()-1,pos_y,0,1),green,1,1,0,255,0);
                    perfil.draw_graph(img.get_crop(0,pos_y,0,2,img.width()-1,pos_y,0,2),blue,1,1,0,255,0).display(ventana2);
                }
                break;
            }                        
        }
        break;
        }
        case 4: {//Ejercicio 4
            int valor1,valor2;
            
            cout<< "Ingrese cantidad de valores en la escala 1:" << endl;
            cin>>valor1;
            cout<< "Ingrese cantidad de valores en la escala 2:" << endl;
            cin>>valor2;
            
        int val;
        CImg<unsigned char> img(256,256);
        for (int i=0;i<img.width()-1;i++){
            val = rand() % valor1;                
            for (int j=0;j<img.height()-1;j++)                
                img(i,j)=val;
        }
        
        CImg<unsigned char> img2(256,256);
        for (int i=0;i<img2.width()-1;i++){
            val = rand() % valor2;                
            for (int j=0;j<img2.height()-1;j++)                
                img2(i,j)=val;
        }
        CImgDisplay ventana(img,"Grises-Valor1"),ventana2(img2,"Grises-Valor2")        ;
        while(!ventana.is_closed() && !ventana2.is_closed()){} 
        
        //Pasamos los parametros a la funcion
        unsigned char colorCircle[] = { 255,255,255};
        unsigned char colorScreen[] = { 0,0,0};
        CImg<unsigned char> imgC =createWhiteCircle(600,100,colorCircle,colorScreen); 
        CImgDisplay ventanaCirculo(imgC,"Circulo");
        while(!ventanaCirculo.is_closed()){};                               
        break;
        }
        
        
        case 5: {//Ejercicio 5
            
        const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/rmn.jpg","Image file\n");
	CImg<unsigned char> img(filename); //Carga de disco
        CImgDisplay vent1,vent2;        
        int width = img.width()/2;
        int height = img.height()/2;                
        CImg<unsigned char> imgSub = img.get_resize(width,height,1,1,1);        
        img.display(vent1);
	imgSub.display(vent2);
	while(!vent1.is_closed()){}            
        break;
        }
        
        case 6: {//Ejercicio 6
            
        const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/huang2.jpg","Image file\n");
	CImg<unsigned char> img(filename); //Carga de disco
        CImgDisplay vent;
        
        CImg<unsigned char> imgsub1=img.get_quantize(8);
	CImg<unsigned char> imgsub2=img.get_quantize(7);        
        CImg<unsigned char> imgsub3=img.get_quantize(6);
	CImg<unsigned char> imgsub4=img.get_quantize(5);        
        CImg<unsigned char> imgsub5=img.get_quantize(4);
	CImg<unsigned char> imgsub6=img.get_quantize(3);
        CImg<unsigned char> imgsub7=img.get_quantize(2);
        CImg<unsigned char> imgsub8=img.get_quantize(1);                
        
        (imgsub1,imgsub2,imgsub3,imgsub4,imgsub5,imgsub6,imgsub7,imgsub8).display(vent);
	
	while(!vent.is_closed()){}      
        break;
            
        }
        case 7: {//Ejercicio 7
            
        const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/huang2.jpg","Image file\n");    
        CImg<unsigned char> img(filename);
        
        CImg<bool> imgH = halftoning(img);
        CImgDisplay vent;
        imgH.display(vent);
        while(!vent.is_closed()){}      
        break;
            
        }        
        
                                                                
     }   
    
    
    
    
    
    

    
    
        return 0;
}











