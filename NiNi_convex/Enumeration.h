#ifndef NINI_CONVEX_ENUMERATION_H
#define NINI_CONVEX_ENUMERATION_H
#include "Pointbase.h"
#include <vector>
using namespace std;

class Enumeration {
public:
	static bool crossJudge(Point A, Point B, Point C, Point D);//ʹ���ж���D�Ƿ���������ABC�ڣ�ʹ�ò���ж�
	static vector<Point> enumeration(vector<Point> pointList);//ʹ��ö�ٷ����͹��������ĺ���
	static bool isInLine(Point X, Point A, Point B);

}; 
#endif //NINI_CONVEX_ENUMERATION_H