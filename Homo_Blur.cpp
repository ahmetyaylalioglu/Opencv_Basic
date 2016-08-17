#include <opencv\highgui.h>
#include <opencv2\opencv.hpp> // blur fonksiyonu icin

using namespace cv;

int main() {

	Mat kaynak, hedef;

	int i = 15;
	kaynak = imread("C:\\ves.jpg");
	
		blur(kaynak, hedef, Size(i, i), Point(-1, -1));

		imshow("Show Blur", hedef);

	waitKey(0);


}
