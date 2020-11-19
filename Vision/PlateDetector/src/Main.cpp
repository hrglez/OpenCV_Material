// Main.cpp

#include "Main.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

    cv::Mat imgOriginalScene;           // input image
    const char* window_name = "Scene";
    int imgNo=1;
    int i = 0;

    if(argc != 2)
    {
        printf("usage must be: ./exeFile <name.extension>\n");
        return -1;
    }

    bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN();           // attempt KNN training

    if (blnKNNTrainingSuccessful == false) {                            // if KNN training was not successful
                                                                        // show error message
        std::cout << std::endl << std::endl << "error: error: KNN traning was not successful" << std::endl << std::endl;
        return(0);                                                      // and exit program
    }

    //cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    //cv::createTrackbar("Image Number", window_name, &imgNo, 8);

    /*std::cout << "Welcome. Please enter the number of image to work with. Enter 0 to exit.\n";
    std::cin >> imgNo;*/

    while(1)
    {
        i=0;

        while(i<2)
        {
            //imgOriginalScene = cv::imread((std::string)"fotos/plate" + std::to_string(imgNo) + (std::string)".jpeg", cv::IMREAD_COLOR);         // open image
            imgOriginalScene = cv::imread(argv[1], cv::IMREAD_COLOR);
            imgOriginalScene = imgOriginalScene(cv::Rect(imgOriginalScene.cols/3,imgOriginalScene.rows/3,imgOriginalScene.cols/3,imgOriginalScene.rows/3));
            /*cv::namedWindow("Test", cv::WINDOW_NORMAL);
            imshow("Test",imgOriginalScene);
            cv::waitKey(0);*/
            //resize(imgOriginalScene, imgOriginalScene, cv::Size(900,1200) );
            //resize(imgOriginalScene, imgOriginalScene, cv::Size(), 0.25, 0.25 );

            if (imgOriginalScene.empty()) {                             // if unable to open image
                std::cout << "Error: image not read from file.\n\n";     // show error message on command line
                break;                                              // and exit program
            }
        
            std::vector<PossiblePlate> vectorOfPossiblePlates = detectPlatesInScene(imgOriginalScene, i);          // detect plates

            vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates, i);                               // detect chars in plates

            //cv::imshow(window_name, imgOriginalScene);           // show scene image

            if (vectorOfPossiblePlates.empty())     // if no plates were found
            {                                              
                if(!i) std::cout << std::endl << "No license plates were detected using first method." << std::endl;       // inform user no plates were found
                else std::cout << std::endl << "No license plates were detected using second method." << std::endl;
            }
            else {                                                                            // else
                                                                                              // if we get in here vector of possible plates has at leat one plate

                                                                                              // sort the vector of possible plates in DESCENDING order (most number of chars to least number of chars)
                std::sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), PossiblePlate::sortDescendingByNumberOfChars);

                // suppose the plate with the most recognized chars (the first plate in sorted by string length descending order) is the actual plate
                PossiblePlate licPlate = vectorOfPossiblePlates.front();

                //cv::imshow("imgPlate", licPlate.imgPlate);            // show crop of plate and threshold of plate
                //cv::imshow("imgThresh", licPlate.imgThresh);

                if (licPlate.strChars.length() == 0) {                                                                          // if no chars were found in the plate
                    if(!i) std::cout << std::endl << "No characters were detected using first method." << std::endl << std::endl;      // show message
                    else std::cout << std::endl << "No characters were detected using second method." << std::endl << std::endl;      // show message
                    std::cout << std::endl << "-----------------------------------------" << std::endl;
                    return(0);                                                                                                  // and exit program
                }

                drawRedRectangleAroundPlate(imgOriginalScene, licPlate);                // draw red rectangle around plate

                if(!i) std::cout << std::endl << "License plate read from image using first method = " << licPlate.strChars << std::endl;     // write license plate text to std out
                else std::cout << std::endl << "License plate read from image using second method = " << licPlate.strChars << std::endl;
                std::cout << std::endl << "-----------------------------------------" << std::endl;

                //writeLicensePlateCharsOnImage(imgOriginalScene, licPlate);              // write license plate text on the image

                //cv::namedWindow(window_name, cv::WINDOW_NORMAL);
                //cv::imwrite("plateDetected"+ std::to_string(imgNo)+".jpeg",imgOriginalScene);
                cv::imshow(window_name, imgOriginalScene);                       // re-show scene image
                //cv::imwrite("imgOriginalScene.png", imgOriginalScene);                  // write image out to file

                cv::waitKey(0);
                //if( cv::waitKey(2000) >= 0 ) break;
            }
            i++;
        }

        std::cout << "\nEnter the next image to continue. Press <CTRL+C> to kill program.\n";
        std::cin >> argv[1];
        std::cout << std::endl << "*******************************************" << std::endl;
        //imgNo++;
    }   //while(1)
    
    return(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawRedRectangleAroundPlate(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) {
    cv::Point2f p2fRectPoints[4];

    licPlate.rrLocationOfPlateInScene.points(p2fRectPoints);            // get 4 vertices of rotated rect

    for (int i = 0; i < 4; i++) {                                       // draw 4 red lines
        cv::line(imgOriginalScene, p2fRectPoints[i], p2fRectPoints[(i + 1) % 4], SCALAR_RED, 2);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) {
    cv::Point ptCenterOfTextArea;                   // this will be the center of the area the text will be written to
    cv::Point ptLowerLeftTextOrigin;                // this will be the bottom left of the area that the text will be written to

    int intFontFace = cv::FONT_HERSHEY_SIMPLEX;                              // choose a plain jane font
    double dblFontScale = (double)licPlate.imgPlate.rows / 30.0;            // base font scale on height of plate area
    int intFontThickness = (int)std::round(dblFontScale * 1.5);             // base font thickness on font scale
    int intBaseline = 0;

    cv::Size textSize = cv::getTextSize(licPlate.strChars, intFontFace, dblFontScale, intFontThickness, &intBaseline);      // call getTextSize

    ptCenterOfTextArea.x = (int)licPlate.rrLocationOfPlateInScene.center.x;         // the horizontal location of the text area is the same as the plate

    if (licPlate.rrLocationOfPlateInScene.center.y < (imgOriginalScene.rows * 0.75)) {      // if the license plate is in the upper 3/4 of the image
                                                                                            // write the chars in below the plate
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) + (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }
    else {                                                                                // else if the license plate is in the lower 1/4 of the image
                                                                                          // write the chars in above the plate
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) - (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }

    ptLowerLeftTextOrigin.x = (int)(ptCenterOfTextArea.x - (textSize.width / 2));           // calculate the lower left origin of the text area
    ptLowerLeftTextOrigin.y = (int)(ptCenterOfTextArea.y + (textSize.height / 2));          // based on the text area center, width, and height

                                                                                            // write the text on the image
    cv::putText(imgOriginalScene, licPlate.strChars, ptLowerLeftTextOrigin, intFontFace, dblFontScale, SCALAR_YELLOW, intFontThickness);
}