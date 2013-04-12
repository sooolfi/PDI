/* 
 * File:   main.cpp
 * Author: guido
 *
 * Created on 4 de abril de 2013, 14:54
 */

#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
//#include <PDI_functions.h>

using namespace std;
using namespace cimg_library;

/*
 * 
 */
//Funciones



int main(int argc, char** argv) {

    
   
    cout<< "Resolución Trabajo Práctico Número 3:"<<endl;
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
            //a
//	CImg<unsigned char> img("/home/guido/NetBeansProjects/TP3/images/lenna.gif"),aux;
//        CImg<unsigned char> hist(256,256);                 
//        hist=img.get_histogram(256,0,255);        
//        hist.display_graph();        
//        aux=img.get_equalize(256);        
//        (img,aux).display();
           
            //b
        CImg<unsigned char> histo_1("/home/guido/NetBeansProjects/TP3/images/histo1.tif");
        CImg<unsigned char> histo_2("/home/guido/NetBeansProjects/TP3/images/histo2.tif");
        CImg<unsigned char> histo_3("/home/guido/NetBeansProjects/TP3/images/histo3.tif");
        CImg<unsigned char> histo_4("/home/guido/NetBeansProjects/TP3/images/histo4.tif");
        CImg<unsigned char> histo_5("/home/guido/NetBeansProjects/TP3/images/histo5.tif");
        
        (histo_1,histo_2,histo_3,histo_4,histo_5).display();
        //cargar imagenes y corroborar orden : D, F, B, A, C
        
        
        break;
        }
                
        case 2: {//Ejercicio 2
      
        CImg<unsigned char> familia_a("/home/guido/NetBeansProjects/TP3/images/FAMILIA_a.jpg");
        CImg<unsigned char> familia_b("/home/guido/NetBeansProjects/TP3/images/FAMILIA_b.jpg");
        CImg<unsigned char> familia_c("/home/guido/NetBeansProjects/TP3/images/FAMILIA_c.jpg");
	
        CImg<unsigned char> hist1(256,256),hist2(256,256),hist3(256,256);
        int x1=1412; int x2=1512;
        int y1=157;  int y2 = 257;
        hist1=familia_a.crop(x1,y1,x2,y2).get_histogram(256,0,255);
        hist2=familia_b.crop(x1,y1,x2,y2).get_histogram(256,0,255);
        hist3=familia_c.crop(x1,y1,x2,y2).get_histogram(256,0,255);
        
        hist1.display_graph();
        hist2.display_graph(); // ruido gausseano.. ?? puede ser?
        hist3.display_graph(); // presenta ruido impulsivo blanco y negro        
        break;            
        }
        
        
        case 3: {//Ejercicio 3

     	CImg<double> img("/home/guido/NetBeansProjects/TP3/images/huang2.jpg");                        
	CImg<double> filtro_1(3,3);
	cimg_forXY(filtro_1,x,y){filtro_1(x,y)=1.0/9.0;}	
	CImg<double> filtro_2(5,5);
	cimg_forXY(filtro_2,x,y){filtro_2(x,y)=1.0/9.0;}
        CImg<double> filtro_3(10,10);
	cimg_forXY(filtro_3,x,y){filtro_3(x,y)=1.0/9.0;}
        
        CImg<double> img_filtrada_1=img.get_convolve(filtro_1);
	CImg<double> img_filtrada_2=img.get_convolve(filtro_2);
        CImg<double> img_filtrada_3=img.get_convolve(filtro_3);
	
        CImgDisplay vent1,vent2,vent3,vent4;
	img.display(vent1);
	
	img_filtrada_1.display(vent2);
        img_filtrada_2.display(vent3);
        img_filtrada_3.display(vent4);
	while(!vent1.is_closed()){}; 
            
            
        break;            
        }
        
        case 4: {//Ejercicio 4

        CImg<double> img("/home/guido/NetBeansProjects/TP3/images/huang2.jpg");                        
	CImg<double> mask(3,3); 
        //filtro pasa bajo para borronear la imagen. 
//        
//        mask.draw_gaussian();        
//        mask/=mask.sum(); //normalizamos        
                
        //gaussian_mask(20,5);
            
               
        break;            
        }
        
         case 5:{
         
          CImg<double> img("/home/guido/NetBeansProjects/TP3/images/huang2.jpg");                        

          //filtros que suman 1
          CImg<double> filtro_1_1(3,3);
          filtro_1_1.fill( 0, -1, 0,-1, 5, -1,0, -1, 0);
          CImg<double> filtro_1_2(3,3);
          filtro_1_2.fill(-1, -1, -1,-1, 9, -1,-1, -1, -1);
          CImg<float> filtro_1_3(3,3);
          filtro_1_3.fill( 1, -2, 1,-2, 5, -2,1, -2, 1);
                
          //filtros que suman 0
          CImg<double> filtro_0_1(3,3);
          filtro_0_1.fill( 0, -1, 0,-1, 4, -1,0, -1, 0);
          CImg<double> filtro_0_2(3,3);
          filtro_0_2.fill(-1, -1, -1,-1, 8, -1,-1, -1, -1);
          CImg<float> filtro_0_3(3,3);
          filtro_0_3.fill( 1, -2, 1,-2, 4, -2,1, -2, 1);    
          
          //convolución
          
          CImg<double> img_filtrada_1_1 = img.get_convolve(filtro_1_1);
          CImg<double> img_filtrada_1_2 = img.get_convolve(filtro_1_2);
          CImg<double> img_filtrada_1_3 = img.get_convolve(filtro_1_3);

          CImg<double> img_filtrada_0_1 = img.get_convolve(filtro_0_1);
          CImg<double> img_filtrada_0_2 = img.get_convolve(filtro_0_2);
          CImg<double> img_filtrada_0_3 = img.get_convolve(filtro_0_3);
          
          CImgDisplay ventana(img, "Huang2");
          CImgDisplay ventana_img_1_1(img_filtrada_1_1, "center: 5, side: 1");
          CImgDisplay ventana_img_1_2(img_filtrada_1_2, "center: 9, other: -1");
          CImgDisplay ventana_img_1_3(img_filtrada_1_3, "center: 5, sides: -2, corners: 1");

          CImgDisplay ventana_img_0_1(img_filtrada_0_1, "center: 4, side: -1");
          CImgDisplay ventana_img_0_2(img_filtrada_0_2, "center: 8, other: -1");
          CImgDisplay ventana_img_0_3(img_filtrada_0_3, "center: 4, sides: -2, corners: 1");
          

          while(!ventana.is_closed()){}; 
         break;
         
         
         }
         case 6:{//ejercicio 6         
         //filtrado mascara difusa         
         //  imagen = A*imamen - imagensuav
         double A;
         cout<< "Ingrese el valor del coeficiente A: "<<endl;
         cin>>A;         
         CImg<double> img("/home/guido/NetBeansProjects/TP3/images/huang3.jpg");         
         CImg<double> filtro_suav(5,5);
	 cimg_forXY(filtro_suav,x,y){filtro_suav(x,y)=1.0/25.0;}  
         
         CImg<double> img_suav = img.get_convolve(filtro_suav);
         CImg<double> img_diffuse_mask(img);
         //coeficiente A
         
         cimg_forXY(img_diffuse_mask,x,y){
             img_diffuse_mask(x,y) = A*img(x,y) - img_suav(x,y); 
         }         
         CImgDisplay vent1,vent2,vent3;
         img.display(vent1);
         img_suav.display(vent2);
         img_diffuse_mask.display(vent3);
	        
	 while(!vent1.is_closed()){};
          
         break;
             
         }
     }
}


