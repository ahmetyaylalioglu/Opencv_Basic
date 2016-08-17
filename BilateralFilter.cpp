#include <opencv\highgui.h>
#include <opencv2\opencv.hpp> // blur fonksiyonu icin

using namespace cv;

int main() {

	Mat kaynak, hedef;

	int i = 1;
	kaynak = imread("C:\\ves.jpg"); 

	for (; i < 31; i = i + 2){
		bilateralFilter(kaynak,hedef,i,i*2,i/2);

		imshow("Show Blur", hedef);

		waitKey(500);
	}

}
