#include <opencv\highgui.h>

using namespace cv;

Mat kynk_1, kynk_2, hedef;
double alpha;
int deger = 0;

void blend(int, void*);


int main(){
	kynk_1 = imread("C:\\612_1.jpg");
	kynk_2 = imread("C:\\612_2.jpg");

	namedWindow("Track",CV_WINDOW_AUTOSIZE); //trackbar için pencere onunla aynı boyutta
	createTrackbar("Alfa Degeri","Track",&deger,100,blend);
	waitKey(0);

}

void blend(int,void*){

	alpha = (double)deger / 100;
	addWeighted(kynk_1, alpha, kynk_2,1-alpha, 0, hedef);

	imshow("Blended Images", hedef);

}
