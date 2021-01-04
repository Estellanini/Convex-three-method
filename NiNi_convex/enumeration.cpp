//#include "Pointbase.h"
#include "Enumeration.h"
using namespace std;



bool Enumeration::isInLine(Point X, Point A, Point B) {//�����ж�ĳ���Ƿ�����������������ľ����ڣ�Ϊ��֮���ж�ĳ���Ƿ��������α�����׼��
	bool judge_x = min(A.x1, B.x1) <= X.x1 && X.x1 <= max(A.x1, B.x1);
	bool judge_y = min(A.y1, B.y1) <= X.y1 && X.y1 <= max(A.y1, B.y1);
	return judge_x && judge_y;

}
bool Enumeration::crossJudge(Point A, Point B, Point C, Point D) {//����ʵ�֣�ʹ���ж���D�Ƿ���������ABC�ڣ�ʹ�ò���ж�
	//���������ε�����
	Vector AB(A, B); Vector BC(B, C); Vector CA(C, A);
	//�����D�������θ��������
	Vector AD(A, D); Vector BD(B, D); Vector CD(C, D);
	//�����������жϵ�D�Ƿ�����������
	double crossAD = AB.crossproduct(AD);
	double crossBD = BC.crossproduct(BD);
	double crossCD = CA.crossproduct(CD);
	//���������AD��BD��CD���������0ʱ���D����������ABC�У���ز�Ϊ͹����
	if (crossAD > 0 && crossBD > 0 && crossCD > 0) return true;
	//����D�������α��ϣ���Ҳ�ز�Ϊ͹����
	if (crossAD = 0 && isInLine(D, A, B)) return true;
	else if (crossBD = 0 && isInLine(D, B, C)) return true;
	else if (crossCD = 0 && isInLine(D, C, A)) return true;
	else return false;
}

vector<Point> Enumeration::enumeration(vector<Point> pointList) {
	vector<Point> result;//͹���㼯
	int num = pointList.size();//��ṹ��ĸ���
	for (int key = 0; key < num; ++key){
		Point point = pointList[key]; bool flag = true;//���ó�ʼ״̬
		for (int i = 0; i < num; ++i){
			for (int j = i + 1; j < num; ++j){
				for (int k = j + 1; k < num; ++k){
					if (key == i || key == j || key == k)//�����ʱ����������֮��ĵ���ͬ�������ô�������ز�Ϊ͹����
						continue;
					if (crossJudge( pointList[i], pointList[j], pointList[k], point)){//�жϴ��������Ƿ�����������
						flag = false;
						break;
					}
				}
			}
		}
		if (flag)   result.push_back(point);//��vector�м���˵�
	}
	return result;//���ص㼯
}