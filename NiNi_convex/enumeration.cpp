//#include "Pointbase.h"
#include "Enumeration.h"
using namespace std;



bool Enumeration::isInLine(Point X, Point A, Point B) {//用来判断某点是否在另两个点所框出的矩形内，为了之后判断某点是否在三角形边上做准备
	bool judge_x = min(A.x1, B.x1) <= X.x1 && X.x1 <= max(A.x1, B.x1);
	bool judge_y = min(A.y1, B.y1) <= X.y1 && X.y1 <= max(A.y1, B.y1);
	return judge_x && judge_y;

}
bool Enumeration::crossJudge(Point A, Point B, Point C, Point D) {//具体实现：使用判定点D是否在三角形ABC内，使用叉积判断
	//定义三角形的三边
	Vector AB(A, B); Vector BC(B, C); Vector CA(C, A);
	//定义点D与三角形各点的连线
	Vector AD(A, D); Vector BD(B, D); Vector CD(C, D);
	//计算叉积用来判断点D是否在三角形中
	double crossAD = AB.crossproduct(AD);
	double crossBD = BC.crossproduct(BD);
	double crossCD = CA.crossproduct(CD);
	//当所计算的AD、BD、CD叉积均大于0时则点D必在三角形ABC中，则必不为凸包点
	if (crossAD > 0 && crossBD > 0 && crossCD > 0) return true;
	//当点D在三角形边上，则也必不为凸包点
	if (crossAD = 0 && isInLine(D, A, B)) return true;
	else if (crossBD = 0 && isInLine(D, B, C)) return true;
	else if (crossCD = 0 && isInLine(D, C, A)) return true;
	else return false;
}

vector<Point> Enumeration::enumeration(vector<Point> pointList) {
	vector<Point> result;//凸包点集
	int num = pointList.size();//点结构体的个数
	for (int key = 0; key < num; ++key){
		Point point = pointList[key]; bool flag = true;//设置初始状态
		for (int i = 0; i < num; ++i){
			for (int j = i + 1; j < num; ++j){
				for (int k = j + 1; k < num; ++k){
					if (key == i || key == j || key == k)//如果此时的索引点与之后的点相同，则设置此索引点必不为凸包点
						continue;
					if (crossJudge( pointList[i], pointList[j], pointList[k], point)){//判断此索引点是否在三角形内
						flag = false;
						break;
					}
				}
			}
		}
		if (flag)   result.push_back(point);//在vector中加入此点
	}
	return result;//返回点集
}