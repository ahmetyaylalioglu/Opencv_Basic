#include<opencv\highgui.h>

using namespace cv;

int main(){
  
	Mat resim;
	VideoCapture cap;

	cap.open(1);

	while (1){
		cap >> resim;

		imshow("Display", resim);

		//imwrite("C:/opencvworks/resim.jpg",resim);

		waitKey(33);
	}




}
