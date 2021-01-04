#ifndef NINI_CONVEX_POINTBASE_H 
#define NINI_CONVEX_POINTBASE_H
#include<cmath>

//基本结构体设置：点结构体以及向量叉积判断

struct Point {//定义点结构体
	int x1; int y1;

	Point(int xx = 0, int yy = 0) {//构造函数 初始化
		x1 = xx; y1 = yy;
	}

	double Euclideandist(Point point) {
		int dist_x = point.x1 - x1; int dist_y = point.y1 - y1;
		return sqrt(dist_x * dist_x * 1.0 + dist_y * dist_y * 1.0);
	}
};

struct Vector {//定义向量边结构体并计算叉积
	double x; double y;
	Vector();
	Vector(Point head, Point end) {
		this->x = end.x1 - head.x1;
		this->y = end.y1 - head.y1;
	}
	double crossproduct(Vector vector) {//叉积判断，如果>0,则为左旋逆时针；=0则共线；<0则为右旋顺时针
		return x * vector.y - y * vector.x;
	}
}; 

#endif //NINI_CONVEX_POINTBASE_H 