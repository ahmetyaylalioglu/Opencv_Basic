

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay(Mat frame);

/** Global variables */

/** ADD YOUR OWN PATH FOR THIS TO YOUR OPEN CV DIRECTORY*/


String face_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml";
String gulucuk_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_mcs_mouth.xml";
String smile_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_smile.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
CascadeClassifier gulucuk_cascade;
CascadeClassifier smile_cascade;
string window_name = "Yuz Algilama";
RNG rng(12345);

/** @function main */
int main(int argc, const char** argv)
{
	CvCapture* capture;
	Mat frame;

	//-- 1. Load the cascades
	if (!face_cascade.load(face_cascade_name)){ printf("--(!)Error loading\n"); return -1; };
	if (!eyes_cascade.load(eyes_cascade_name)){ printf("--(!)Error loading\n"); return -1; };
	if (!gulucuk_cascade.load(gulucuk_cascade_name))
	{
		printf("--(!)Error loading\n"); return -1;
	};
	if (!smile_cascade.load(smile_cascade_name))
	{
		printf("--(!)Error loading\n"); return -1;
	};

	//-- 2. Read the video stream
	capture = cvCaptureFromCAM(0);
	if (capture)
	{
		while (true)
		{
			frame = cvQueryFrame(capture);

			//-- 3. Apply the classifier to the frame
			if (!frame.empty())
			{
				detectAndDisplay(frame);
			}
			else
			{
				printf(" --(!) No captured frame -- Break!"); break;
			}

			int c = waitKey(10);
			if ((char)c == 'c') { break; }
		}
	}
	return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		
		std::vector<Rect> eyes;
		

		//-- In each face, detect eyes
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

		for (size_t j = 0; j < eyes.size(); j++)
		{
			Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
			int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
			circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
		}
		
		Mat smileROI = frame_gray(faces[i]);
		std::vector<Rect> gulucuk;
		//--In each face,detect smile"
		gulucuk_cascade.detectMultiScale(smileROI, gulucuk, 1.7, 11, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
		for (size_t k = 0; k < gulucuk.size();k++)
		{
			Point nokta1(faces[i].x + gulucuk[k].x, faces[i].y + gulucuk[k].y + gulucuk[k].height);
			Point nokta2(faces[i].x + gulucuk[k].x + gulucuk[k].width, faces[i].y + gulucuk[k].y);
			rectangle(frame,nokta1,nokta2,Scalar(0,255,0),2,8,0);
			
			Mat gulucukROI = frame_gray(faces[i]);
			std::vector<Rect> smile;
			smile_cascade.detectMultiScale(gulucukROI, smile, 1.7, 22, 0 | CV_HAAR_SCALE_IMAGE, Size(35, 35));
			for (size_t t = 0; t < smile.size(); t++)
			{
				Point nokta11(faces[i].x + smile[t].x, faces[i].y + smile[t].y + smile[t].height);
				Point nokta22(faces[i].x + smile[t].x + smile[t].width, faces[i].y + smile[t].y);
				rectangle(frame, nokta11, nokta22, Scalar(200, 200, 200), 2, 8, 0);


			}

		}

		
	}
	//-- Show what you got
	imshow(window_name, frame);
}
