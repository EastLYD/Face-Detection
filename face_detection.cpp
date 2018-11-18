#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace cv;
using namespace std;

CascadeClassifier face_cascader;
CascadeClassifier eye_cascader;
//�ǵ���/������\
//λ��ȷ������opencv���ҵ��������ļ���
//haarcascade_frontalface_alt.xml
//haarcascade_eye.xml
//����ʹ�����·��������ʹ�þ���·��
String facefile = "D:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml";
String eyefile = "D:/opencv/build/etc/haarcascades/haarcascade_eye.xml";

int main(int argc, char** argv) {
	if (!face_cascader.load(facefile)) {//����xml
		printf("could not load face feature data...\n");
		return -1;
	}
	if (!eye_cascader.load(eyefile)) {//����xml
		printf("could not load eye feature data...\n");
		return -1;
	}
	//��������
	namedWindow("camera-demo", 0);
	//������ͷ
	VideoCapture capture(0);

	Mat frame;

	Mat gray;

	vector<Rect> faces;

	vector<Rect> eyes;

	while (capture.read(frame)) {//ʵʱ���
								 //ȥɫ
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		equalizeHist(gray, gray);

		face_cascader.detectMultiScale(gray, faces, 1.2, 3, 0, Size(30, 30));

		for (size_t t = 0; t < faces.size(); t++) {
			Rect roi;
			roi.x = faces[static_cast<int>(t)].x;
			roi.y = faces[static_cast<int>(t)].y;
			roi.width = faces[static_cast<int>(t)].width;
			roi.height = faces[static_cast<int>(t)].height / 2;
			Mat faceROI = frame(roi);
			eye_cascader.detectMultiScale(faceROI, eyes, 1.2, 3, 0, Size(20, 20));
			for (size_t k = 0; k < eyes.size(); k++) {
				Rect rect;
				rect.x = faces[static_cast<int>(t)].x + eyes[k].x;
				rect.y = faces[static_cast<int>(t)].y + eyes[k].y;
				rect.width = eyes[k].width;
				rect.height = eyes[k].height;
				//ʶ����ۿ�
				rectangle(frame, rect, Scalar(0, 255, 0), 2, 8, 0);
				Point center;
				center.x = rect.x + rect.width / 2;
				center.y = rect.y + rect.height / 2;
				//ʶ���ͫ��
				circle(frame, center, 5, Scalar(0, 255, 255), -1, 8);
			}
			//ʶ�������
			rectangle(frame, faces[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
		}
		//���ʵʱͼ��
		imshow("camera-demo", frame);
		//�ȴ�������Ӧ
		char c = waitKey(30);
		if (c == 27) {
			break;
		}
	}
	waitKey(0);
	return 0;
}
