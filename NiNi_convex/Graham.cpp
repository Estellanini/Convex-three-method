#include "Graham.h"

Point original_point;//���ó�ʼ��һ�������½ǵĵ�

bool compare_polar_angle(Point p1, Point p2) {//���ǱȽϴ�С�����趨
	Vector vec1(original_point, p1);
	Vector vec2(original_point, p2);
	double cross = vec1.crossproduct(vec2);//������
	if (cross > 0){// �������0 ��p2��p1��ʱ�뷽��Ϊ����
		return true;
	}
	else if (cross == 0){// ���=0�� ��������ͬһ�����ϣ�ȡ����϶̵ģ�С����true,������false
		if (original_point.Euclideandist(p1) < original_point.Euclideandist(p2))
			return true;
	}
	return false;
}

vector<Point> Graham::graham(vector<Point>pointList) {
	int key = 0;
	original_point = pointList[key];
	for (int i = 1; i < pointList.size(); i++) {//Ŀ���������ҵ����½ǵĵ㼴�������궼��С�ĵ�
		Point compare_point = pointList[i];//���ñȽϵ�
		if (compare_point.x1 > original_point.x1 || (compare_point.x1 == original_point.x1 && compare_point.y1 < original_point.y1)) {
			original_point = compare_point;
			key = i;
		}
	}
	swap(pointList[key], pointList[0]);//��ʱpointList[0]����Сֵ
	sort(pointList.begin() + 1, pointList.end(),compare_polar_angle);//���ݼ�������

	vector<Point> res;
	res.push_back(pointList[0]); // ԭʼ���
	res.push_back(pointList[1]);//��ջ����������Ԫ��

	for (int i = 2; i < pointList.size(); i++){
		int len = res.size();//���ݵĳ���
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
