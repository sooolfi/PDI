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
    
    
//    int valor = 1;
//    
//    cout << "Ingrese el numero de imagen a visualizar" << endl;
//    cout << "1-Cameraman.tif" << endl;
//    cout << "2-a7v600-SE.gif" << endl;
//    cout << "3-billete.jpg" << endl;
//    cout << "4-lenna.gif" << endl;
//    cout << "5-bone.tif" << endl;    
//    cin >> valor ;
//          
//    const char* cadena = "";
//    switch (valor){
//        case 1:{
//            cadena ="cameraman.tif";
//            break;}
//        case 2:{
//            cadena ="a7v600-SE.gif";
//            break;}
//        case 3:{
//            cadena ="billete.jpg";
//            break;}
//        case 4:{
//            cadena ="lenna.gif";
//            break;}
//        case 5:{
//            cadena ="bone.tif";
//            break;}
//  
//    };
//    
//    const char* cadena2 = "/home/guido/NetBeansProjects/TP1/images/";        
//    const char* p = new char [strlen(cadena)+strlen(cadena2)+1];
//    const char* s = new char [strlen(cadena)+strlen(cadena2)+1];
//    strcat(const_cast<char*>(p),cadena2);
//    strcat(const_cast<char*>(p),cadena);
//    strcpy(const_cast<char*>(s),p);        
//
//    const char* filename = cimg_option("-i",s,"Image file\n");
//    CImg<unsigned char> img(filename);
//    CImgDisplay ventana(img,"Info Image");
//    img.print(cadena,1);
//    img.stats();    
//    while(!ventana.is_closed()){}
    
    
    
    //Ejercicio 3
    
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
        
        
        //Ejercicio 4
        

                                                                
        
        return 0;
}

