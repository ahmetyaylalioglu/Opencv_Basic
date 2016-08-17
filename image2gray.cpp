#include<opencv\highgui.h>
#include<opencv2\opencv.hpp>

using namespace cv;

int main(){
	Mat img, img_gri;

	VideoCapture cap;

	cap.open(1);

	while (1){
		cap >> img;
		cvtColor(img, img_gri, COLOR_RGB2HSV);

		imshow("Original", img);
		imshow("Grayed", img_gri);
		waitKey(33);

	}
}
