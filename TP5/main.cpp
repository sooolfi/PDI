/* 
 * File:   main.cpp
 * Author: guido
 *
 * Created on 18 de abril de 2013, 14:17
 */
#include <CImg.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <PDI_functions.h>

using namespace std;
using namespace cimg_library;

/*
 * 
 */
int main(int argc, char** argv) {
    cout<< "Resolución Trabajo Práctico Número 5:"<<endl;
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
            
            CImg<double> patrones("/home/guido/NetBeansProjects/TP5/images/FFT2_Patrones.png");
           // patrones.display();
            
            //parte 2
            //imagenes binarias
            unsigned char white[] = { 255,255,255};
            CImg<double> img_hor(256,256),img_ver(256,256),img_cuad(256,256),img_rect(256,256),img_circ(256,256);
            img_hor.fill(0);img_ver.fill(0);
            img_cuad.fill(0);img_rect.fill(0);
            img_circ.fill(0);
            img_hor.draw_line(0,128,255,128,white);            
            img_ver.draw_line(128,0,128,256,white);            
            img_cuad.draw_rectangle(98,98,0,158,158,0,white);            
            img_rect.draw_rectangle(98,108,0,158,148,0,white);           
            img_circ.draw_circle(128,128,25,white);            
            
            //calculo las transformadas.
                              
            CImg<double> TDF_img_hor=magn_tdf(img_hor,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            CImg<double> TDF_img_ver=magn_tdf(img_ver,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            CImg<double> TDF_img_cuad=magn_tdf(img_cuad,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            CImg<double> TDF_img_rect=magn_tdf(img_rect,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            CImg<double> TDF_img_circ=magn_tdf(img_circ,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            
            (TDF_img_hor,TDF_img_ver,TDF_img_cuad,TDF_img_rect,TDF_img_circ).display();
                       
            //parte 3
            CImg<double> img(512,512);
            img.fill(0);
            img.draw_line(256,0,256,512,white);            
            CImg<double> img_cut = img.crop(128,128,383,383);
            CImg<double> img_rotate = img.rotate(20);           
            CImg<double> img_rotate_cut = img_rotate.crop(128,128,383,383);
            //transformadas
            CImg<double> TDF_img=magn_tdf(img_cut,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            CImg<double> TDF_img_rotate=magn_tdf(img_rotate_cut,true,"/home/guido/NetBeansProjects/TP5/paletas/pink.pal");
            //visualizacion
            (img_cut,TDF_img,img_rotate_cut,TDF_img_rotate).display();
            
            
            
            break;
        }
     }//end switch
            
            return 0;
}

