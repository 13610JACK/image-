#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat image=imread("C:\\Users\\zhh\\Desktop\\1.jpg",1);
	Mat *image1;
	image1=&image;
	Mat image2(image1->rows,image1->cols,CV_8UC3,Scalar(0,0,0));
	int rows,cols;
	for(rows=1;rows<image2.rows-1;rows++)
	{
		Vec3b *p=image2.ptr<Vec3b>(rows);
		Vec3b *p1=image1->ptr<Vec3b>(rows-1);
		Vec3b *p2=image1->ptr<Vec3b>(rows+1);
		Vec3b *p3=image1->ptr<Vec3b>(rows);
		for(cols=1;cols<image2.cols-1;cols++)
		{
			if((p3[cols-1][0]-p3[cols+1][0])!=0&&(p3[cols-1][1]-p3[cols+1][1])!=0&&(p3[cols-1][2]-p3[cols+1][2])!=0)
			{
		    p[cols][0]=(p1[cols][0]-p2[cols][0])/(p3[cols-1][0]-p3[cols+1][0]);
			p[cols][1]=(p1[cols][1]-p2[cols][1])/(p3[cols-1][1]-p3[cols+1][1]);
			p[cols][2]=(p1[cols][2]-p2[cols][2])/(p3[cols-1][2]-p3[cols+1][2]);
			}
		}
	}
	namedWindow("y方向梯度", CV_WINDOW_NORMAL);
	imshow("y方向梯度",image2);
	waitKey(0);
	destroyWindow("y方向梯度");
	return 0;
}


//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//int main()
//{
//	Mat image=imread("C:\\Users\\zhh\\Desktop\\2.jpg",1);
//	Mat *image1;
//	image1=&image;
//	Mat image2(image1->rows,image1->cols,CV_8UC3,Scalar(0,0,0));
//	int rows,cols;
//	for(rows=0;rows<image2.rows;rows++)
//	{
//		Vec3b *p=image2.ptr<Vec3b>(rows);
//		//Vec3b *p1=image1->ptr<Vec3b>(rows-1);
//		Vec3b *p2=image1->ptr<Vec3b>(rows);
//		for(cols=1;cols<image2.cols-1;cols++)
//		{
//		    p[cols][0]=(p2[cols-1][0]-p2[cols+1][0])/10;
//			p[cols][1]=(p2[cols-1][1]-p2[cols+1][1])/10;
//			p[cols][2]=(p2[cols-1][2]-p2[cols+1][2])/10;
//		}
//	}
//	//Mat image3(image1->rows,image1->cols,CV_8UC3,Scalar(0,0,0));
//	//for(rows=0;rows<image2.rows;rows++)
//	//{
//	//	Vec3b *p=image3.ptr<Vec3b>(rows);
//	//	//Vec3b *p1=image1->ptr<Vec3b>(rows-1);
//	//	Vec3b *p2=image2.ptr<Vec3b>(rows);
//	//	for(cols=1;cols<image2.cols-1;cols++)
//	//	{
//	//	    p[cols][0]=(p2[cols-1][0]-p2[cols+1][0])/5;
//	//		p[cols][1]=(p2[cols-1][1]-p2[cols+1][1])/5;
//	//		p[cols][2]=(p2[cols-1][2]-p2[cols+1][2])/5;
//	//	}
//	//}
//	namedWindow("x方向梯度", CV_WINDOW_NORMAL);
//	imshow("x方向梯度",image2);
//	waitKey(0);
//	destroyWindow("x方向梯度");
//	return 0;
//}



//y方向梯度
/*
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat image=imread("C:\\Users\\zhh\\Desktop\\2.jpg",1);
	Mat *image1;
	image1=&image;
	Mat image2(image1->rows,image1->cols,CV_8UC3,Scalar(0,0,0));
	int rows,cols;
	for(rows=1;rows<image2.rows-1;rows++)
	{
		Vec3b *p=image2.ptr<Vec3b>(rows);
		Vec3b *p1=image1->ptr<Vec3b>(rows-1);
		Vec3b *p2=image1->ptr<Vec3b>(rows+1);
		for(cols=0;cols<image2.cols;cols++)
		{
		    p[cols][0]=(p1[cols][0]-p2[cols][0])/10;
			p[cols][1]=(p1[cols][1]-p2[cols][1])/10;
			p[cols][2]=(p1[cols][2]-p2[cols][2])/10;
		}
	}
	namedWindow("y方向梯度", CV_WINDOW_NORMAL);
	imshow("y方向梯度",image2);
	waitKey(0);
	destroyWindow("y方向梯度");
	return 0;
}
*/
