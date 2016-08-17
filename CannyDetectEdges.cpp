#include <opencv\highgui.h>
#include <opencv2\imgproc\imgproc.hpp>
 
using namespace cv;

 Mat kaynak, hedef;

int value;
void edge(int,void*);

int main() {

	kaynak = imread("C:\\ves.jpg");
	cvtColor(kaynak,kaynak,CV_RGB2GRAY);
	blur(kaynak,kaynak,Size(10,10));

	namedWindow("canny");
	createTrackbar("value", "canny", &value, 100, edge);
	waitKey(0);

}

void edge(int,void*){
	Canny(kaynak,hedef,value,value*3,3); // detecting edges
	imshow("figure",hedef);

}
