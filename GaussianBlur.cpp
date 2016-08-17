#include <opencv\highgui.h>
#include <opencv2\opencv.hpp> // blur fonksiyonu icin

using namespace cv;

int main() {

	Mat kaynak, hedef;

	int i = 15;
	kaynak = imread("C:\\ves.jpg");

	for (; i < 31; i = i + 2){
		GaussianBlur(kaynak, hedef, Size(i, i), 0, 0);

		imshow("Show Blur", hedef);

		waitKey(500);
	}

}
