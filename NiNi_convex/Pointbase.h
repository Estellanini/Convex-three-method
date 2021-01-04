#ifndef NINI_CONVEX_POINTBASE_H 
#define NINI_CONVEX_POINTBASE_H
#include<cmath>

//�����ṹ�����ã���ṹ���Լ���������ж�

struct Point {//�����ṹ��
	int x1; int y1;

	Point(int xx = 0, int yy = 0) {//���캯�� ��ʼ��
		x1 = xx; y1 = yy;
	}

	double Euclideandist(Point point) {
		int dist_x = point.x1 - x1; int dist_y = point.y1 - y1;
		return sqrt(dist_x * dist_x * 1.0 + dist_y * dist_y * 1.0);
	}
};

struct Vector {//���������߽ṹ�岢������
	double x; double y;
	Vector();
	Vector(Point head, Point end) {
		this->x = end.x1 - head.x1;
		this->y = end.y1 - head.y1;
	}
	double crossproduct(Vector vector) {//����жϣ����>0,��Ϊ������ʱ�룻=0���ߣ�<0��Ϊ����˳ʱ��
		return x * vector.y - y * vector.x;
	}
}; 

#endif //NINI_CONVEX_POINTBASE_H 