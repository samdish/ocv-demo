#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera

    if(!cap.isOpened())  // check if we succeeded
        return -1;

    // Constants
    int fWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //True frame width
    int fHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //True frame height
    int cHeight = floor(fHeight * 0.7); // Cropped height
    int cWidth = fWidth; // Width remains same
    int X = 0; // X of Top left corner of Rectangle
    int Y = fHeight - cHeight; // Y of Top left corner of Rectangle
    
    Mat frame;
    Mat croppedFrame;
    Rect cropper(X, Y, cWidth, cHeight);
    
    for(;;)
    {
        cap >> frame;
        croppedFrame = frame(cropper);
        imshow("cropped", croppedFrame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}