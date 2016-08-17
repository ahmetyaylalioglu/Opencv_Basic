#include<opencv\highgui.h>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){

	Mat i, p;

	///////////////////////////////////////////////////////////////////////////////
	namedWindow("Control", CV_WINDOW_AUTOSIZE); //Window for track bar

	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;

	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 179);

	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);
	///////////////////////////////////////////////////////////////////////////////
	VideoCapture cap; //object to capture frame
	cap.open(1); //initializing webcam

	while (1){

		cap >> i; //capturing videoframe

		cvtColor(i, i, COLOR_BGR2HSV); //converting itbto SV

		inRange(i, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), p); //inrange function

		imshow("oy", i); //Displaying orignal sreamm
		imshow("yo", p); //displaying with single colour

		waitKey(33);
	}
}
