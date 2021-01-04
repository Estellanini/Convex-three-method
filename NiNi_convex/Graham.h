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
		//叉积判断，如果>0,则为左旋逆时针；=0则共线；<0则为右旋顺时针
		return v1.x * v2.y - v1.y * v2.x;
	}
	static vector<Point> graham(vector<Point> pointList);//Graham主函数
};

#endif //NINI_CONVEX_GRAHAM_H

