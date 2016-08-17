#include <opencv\highgui.h>
#include <opencv2\opencv.hpp> // blur fonksiyonu icin

using namespace cv;

int main() {

	Mat kaynak, hedef;

	int i = 1;
	kaynak = imread("C:\\ves.jpg");

	for (; i < 31; i = i + 2){
		medianBlur(kaynak,hedef,i);

		imshow("Show Blur", hedef);

		waitKey(500);
	}

}
