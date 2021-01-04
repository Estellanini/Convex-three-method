#include "Graham.h"

Point original_point;//设置初始点一般是左下角的点

bool compare_polar_angle(Point p1, Point p2) {//极角比较大小规则设定
	Vector vec1(original_point, p1);
	Vector vec2(original_point, p2);
	double cross = vec1.crossproduct(vec2);//计算叉积
	if (cross > 0){// 叉积大于0 则p2在p1逆时针方向，为左旋
		return true;
	}
	else if (cross == 0){// 叉积=0， 则两点在同一条线上，取距离较短的，小于是true,大于是false
		if (original_point.Euclideandist(p1) < original_point.Euclideandist(p2))
			return true;
	}
	return false;
}

vector<Point> Graham::graham(vector<Point>pointList) {
	int key = 0;
	original_point = pointList[key];
	for (int i = 1; i < pointList.size(); i++) {//目的是用来找到左下角的点即横纵坐标都最小的点
		Point compare_point = pointList[i];//设置比较点
		if (compare_point.x1 > original_point.x1 || (compare_point.x1 == original_point.x1 && compare_point.y1 < original_point.y1)) {
			original_point = compare_point;
			key = i;
		}
	}
	swap(pointList[key], pointList[0]);//此时pointList[0]是最小值
	sort(pointList.begin() + 1, pointList.end(),compare_polar_angle);//根据极角排序

	vector<Point> res;
	res.push_back(pointList[0]); // 原始结点
	res.push_back(pointList[1]);//向栈中推入两个元素

	for (int i = 2; i < pointList.size(); i++){
		int len = res.size();//数据的长度
		while (crossproduct(Vector(res[len - 2], res[len - 1]),
			Vector(res[len - 2], pointList[i])) <= 0){
			res.pop_back();
			len = res.size();
			if (len < 2)
				break;
		}

		res.push_back(pointList[i]);
	}


	return res;



}
