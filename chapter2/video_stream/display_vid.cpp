#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main() {
    string path = "videos/butterfly.mp4";
    VideoCapture cap(path);
    if(!cap.isOpened()){
        cout<<"Error"<<endl;
        return -1;
    }
    while(1){
        Mat frame;
        // capture frame by frame
        cap >> frame;

        if(frame.empty()) //if the frame is empty, break
            break;
        
        imshow("Frame",frame); //display the resulting frames
        char c=(char)waitKey(25); //press esc on keyboard to exit
        if(c==27)
            break;

    }
    cap.release(); //release the video capture object
    destroyAllWindows(); //close all frames
    return 0;
}