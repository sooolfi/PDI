#include <CImg.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cimg_library;

int main(int argc, char *argv[]) {
    
    //Ejercicio 1
    	        	                                       	
//	const char* filename = cimg_option("-i","/home/guido/NetBeansProjects/TP1/images/cameraman.tif","Image file\n");
//	CImg<unsigned char> img1(filename); //Carga de disco
//        
//	//corta y pega en imagen 2
//	CImg<unsigned char> img2(img1);
//	img2.crop(85,35,145,95);
//
//	//calculo tamaño de la subimagen (54 bytes de cabecera)
//	float sum=0;
//	sum=60*60*3+54;
//	cout<<"Tamanio de Subimagen: " << sum << endl ;
//
//	//guardo la imagen cortada en archivo .bmp
//	img2.save("images/cameraman2.bmp");
//        
//	//Visualiza ambas imagenes a la vez
//	CImgDisplay vent1(img1,"original"), vent2(img2,"cortada");
//	while(!vent1.is_closed()){}
//	
//
//	CImg<unsigned char> img3(256,256,1,1);
//	for(int i=0;i<256;i++)
//		for(int j=0;j<256;j++)
//			img3(i,j)=i;
//	img3.save("images/grises.bmp");
//
//        //Visualiza imagen 3
//	CImgDisplay vent3(img3,"grises");
//	while(!vent3.is_closed()){}
        
    //Ejercicio 2
    
    
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
    img.print(cadena,0);
    img.stats();    
    while(!ventana.is_closed()){}
    
    
    
    
    
    
        
        
        return 0;
}

