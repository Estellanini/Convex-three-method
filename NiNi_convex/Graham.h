#ifndef NINI_CONVEX_GRAHAM_H
#define NINI_CONVEX_GRAHAM_H
#include "Pointbase.h"
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Graham {
public:
	static double crossproduct(Vector v1, Vector v2) {
		//����жϣ����>0,��Ϊ������ʱ�룻=0���ߣ�<0��Ϊ����˳ʱ��
		return v1.x * v2.y - v1.y * v2.x;
	}
	static vector<Point> graham(vector<Point> pointList);//Graham������
};

#endif //NINI_CONVEX_GRAHAM_H

