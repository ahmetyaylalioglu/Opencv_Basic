#include <opencv\highgui.h>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

Mat resim1, resim2;
int thresh, maxval = 255, type, value; //trackbar degiskenleri
void track(int,void*); // trackbar tarafından kontrol edilecek olan fonksiyon.

int main(){
	resim1 = imread("C:\\ves.jpg");
	cvtColor(resim1, resim2, CV_RGB2GRAY);

	namedWindow("Adjust",CV_WINDOW_AUTOSIZE); //Trackbar için pencere oluşturuluyor.

	/*trackbar olusturuluyor*/
    
	createTrackbar("Thresh", "Adjust", &thresh, 200, track);
	createTrackbar("Max", "Adjust", &maxval, 255, track);
	createTrackbar("Type", "Adjust", &type, 4, track);

	track(0, 0); // track fonksiyonu ilkkez cagriliyor.

	waitKey(0);
}

void track(int,void*){
	threshold(resim1, resim2, thresh, maxval, type);
	imshow("Sonuc",resim2);
}
