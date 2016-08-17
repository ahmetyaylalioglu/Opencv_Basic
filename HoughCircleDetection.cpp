#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;

int main(){

	Mat kaynak, kaynak_gri;
	kaynak = imread("C:\\daires.bmp");
	cvtColor(kaynak,kaynak_gri,CV_BGR2GRAY);
	GaussianBlur(kaynak_gri, kaynak_gri, Size(9, 9), 2, 2); //gürültüyü kaldırmak için GaussianBlur filtresi uyguladık.
	

	vector<Vec3f> daireler; //Vec3f float x,y,z den geliyor x ve y noktaları ve z de yarıçapı gibi düşünebiliriz.

	HoughCircles(kaynak_gri,daireler,CV_HOUGH_GRADIENT,1,kaynak_gri.rows / 2,100,30,0,0);//daireli algılamak için

	for (size_t i = 0; i < daireler.size(); i++){
		Point merkez(cvRound(daireler[i][0]),cvRound(daireler[i][1])); //dairenin merkez noktasi
		int yaricap = cvRound(daireler[i][2]);

		circle(kaynak, merkez, 3, Scalar(255, 0, 0), -1, 8, 0);
		circle(kaynak, merkez, yaricap, Scalar(0, 0, 255), 3, 8, 0);
	    
	
	}


	namedWindow("DaireleriBul", CV_WINDOW_AUTOSIZE); //window to display circles
	imshow("DaireleriBul", kaynak); //displaying circles
	waitKey(0);
	return 0;
}
