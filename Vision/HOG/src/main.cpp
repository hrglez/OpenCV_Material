#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <string>
//#include < opencv2\gpu\gpu.hpp>

int main(void)
{
   char SaveHogDesFileName[] = "HOGDescriptor.xml";
   char destinationName[20];
   char baseName[] = "samples/pic";
   unsigned int count = 1;

   int imgSizeX = 64, imgSizeY = 48;
   int wndwSizeX = 32, wndwSizeY = 16;
   int blockSize = 8, cellSize = 4;

   cv::Mat img = cv::imread("invicta.png", cv::IMREAD_GRAYSCALE);
   resize(img, img, cv::Size(imgSizeX,imgSizeY) ); //Resize the image to achieve computing time
   int cols = img.cols;
   int rows = img.rows;
   int puntxLocal=0, puntyLocal=0;
   int puntxGlobal=0, puntyGlobal=0;

   imwrite("ReducedImg.jpg", img);
   //printf("cols= %d, rows= %d\n", cols, rows);

   cv::Mat aux = cv::Mat::zeros(wndwSizeY, wndwSizeY, CV_8U); //Variable used to simplify code by saving the ROI here
   cv::Rect roi; //variable used to simplify code by saving the rect here

   cv::HOGDescriptor hog( cv::Size(wndwSizeX,wndwSizeY), cv::Size(blockSize,blockSize), cv::Size(cellSize,cellSize), cv::Size(cellSize,cellSize), 9); //window size, block size, block padding, cell size, bins for histogram

   std::vector< float> descriptorsValues;
   std::vector< cv::Point> locations;

   hog.compute( img, descriptorsValues, cv::Size(wndwSizeX,wndwSizeY), cv::Size(0,0), locations);

   for(unsigned int idxWindow = 0; idxWindow < ( (imgSizeX/wndwSizeX) * (imgSizeY/wndwSizeY) ) ; idxWindow++) //Necessary loop to get the fragments of each block
   {
      for(unsigned int idxBlock = 0; idxBlock < ( ((wndwSizeX/cellSize)-1)*((wndwSizeY/cellSize)-1) ) ;idxBlock++)
      {
         if( puntxLocal == (wndwSizeX-cellSize) )
            {
               puntxLocal = 0;
               puntyLocal += cellSize;
            }

         //printf("%d\n", idxWindow*idxBlock);
         //printf("puntx: %d, punty: %d, count: %d\n\n", puntxLocal+puntxGlobal, puntyLocal+puntyGlobal, count);

         roi = cv::Rect(puntxLocal+puntxGlobal, puntyLocal+puntyGlobal, blockSize, blockSize);
         img(roi).copyTo(aux);
         
         puntxLocal += cellSize;

         sprintf(destinationName, "%s%d.jpg", baseName, count);
         imwrite(destinationName, aux);
         count++;
      }

      puntxLocal = 0;
      puntyLocal = 0;

      puntxGlobal += wndwSizeX;

      if(puntxGlobal==imgSizeX)
      {
         puntxGlobal=0;
         puntyGlobal += wndwSizeY;
      } 
      
   }
  
   //refer to this address -> http://feelmare.blogspot.kr/2014/04/the-example-source-code-of-2d-vector.html
   //save to xml
   cv::FileStorage hogXml(SaveHogDesFileName, cv::FileStorage::WRITE); //FileStorage::READ
   //2d vector to Mat
   int row=1, col=descriptorsValues.size();
   printf("col=%d\n", col);
   cv::Mat xmlResults(row,col,CV_32F);
   //save Mat to XML
   memcpy( &(xmlResults.data[0]), descriptorsValues.data(), col * sizeof(float));
   //write xml
   write(hogXml, "Descriptor_of_image",  xmlResults);
   hogXml.release();
   
}