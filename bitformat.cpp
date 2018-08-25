#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
void main (int argc,char *argv[])
{
   string create;
   cout << "input a created filename>>";
   cin >>create;
   ofstream infile(create,ios::binary);
   char signature[2]={'B','M'};
   cout << "input a filesize>>";
   cin >> dilesize;
   cout << "input a reserved>>";
   cin >> reserved;
   cout << "input a dataoffset>>";
   cin >> dataoffset;
   cout << "input a size>>";
   cin >> size;
   cout << "input a width>>";
   cin >> width;
   cout << "input a height>>";
   cin >> height;
   cout << "input a planes>>";
   cin >> planes;
   cout << "input a BitPerPixel>>";
   cin >> BitPerPixel;
   cout << "input a compressedsize_of_image>>";
   cin >> compressedsize_of_image;
   cout << "input a XpiexelsPerM>>";
   cin >> XpiexelsPerM;
   cout << "input a YpiexelsPerM>>";
   cin >> YpiexelsPerM;
   cout << "input a ColorUsed>>";
   cin >> ColorUsed;
   cout << "input a ColorImportan>>";
   cin >> ColorImportan;
   int filesize,reserved,dataoffset,size,width,height,planes,BitPerPixel,compression,
        compressedsize_of_image,XpiexelsPerM,YpiexelsPerM,ColorUsed,ColorImportant;
   char ColorTable[8]={0,0,0,0,255,255,255,255};
   infile.write(signature,2);
   infile.write(reinterpret_cast<char *>(&filesize),4);
   infile.write(reinterpret_cast<char *>(&reserved),4);
   infile.write(reinterpret_cast<char *>(&dataoffset),4);
   infile.write(reinterpret_cast<char *>(&size),4);
   infile.write(reinterpret_cast<char *>(&width),4);
   infile.write(reinterpret_cast<char *>(&height),4);
   infile.write(reinterpret_cast<char *>(&planes),2);
   infile.write(reinterpret_cast<char *>(&BitPerPixel),2);
   infile.write(reinterpret_cast<char *>(&compression),4);
   infile.write(reinterpret_cast<char *>(&compressedsize_of_image),4);
   infile.write(reinterpret_cast<char *>(&XpiexelsPerM),4);
   infile.write(reinterpret_cast<char *>(&YpiexelsPerM),4);
   infile.write(reinterpret_cast<char *>(&ColorUsed),4);
   infile.write(reinterpret_cast<char *>(&ColorImportant),4);
   infile.write(ColorTable,8);	
	
   char black=0;
   char white=255;
   int d= height/ atoi(argv[1]);
   for(int i=0; i<height; i++){
          for(int j=0; j<width; j+=8){  
	      int a=(j/d)% 2;   
	      int b=(i/d)% 2;
	      int t=(a+b)% 2;
	      if(t)
		   infile.write(&black,1);			
	
	      else
	           infile.write(&white,1);			
        } 
  }	
   infile.close();
}
