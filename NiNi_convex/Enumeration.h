#ifndef NINI_CONVEX_ENUMERATION_H
#define NINI_CONVEX_ENUMERATION_H
#include "Pointbase.h"
#include <vector>
using namespace std;

class Enumeration {
public:
	static bool crossJudge(Point A, Point B, Point C, Point D);//使用判定点D是否在三角形ABC内，使用叉积判断
	static vector<Point> enumeration(vector<Point> pointList);//使用枚举法解决凸包问题核心函数
	static bool isInLine(Point X, Point A, Point B);

}; 
#endif //NINI_CONVEX_ENUMERATION_H