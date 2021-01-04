#include "Divideconquer.h"

void Divideconquer::divide(int first, int last, vector<Point> nodeList, vector<Point>& vist){
    int Keymax = -1;//�������ĵ���ջ�е�λ��
    int Smax = 0;//��������ʼ��Ϊ0
 
    if (first < last){
        for (int i = first + 1; i < last; i++){//���˱���͹���У����Բ����ж�
            int S = Striangle(nodeList[first], nodeList[i], nodeList[last]);//���������
            if (S > Smax){//������С��0����֤�����ڴ�͹����
                Keymax = i;
                Smax = S;
            }
        }
    }
    else{
        for (int i = first - 1; i > last; i--){
            int S = Striangle(nodeList[first], nodeList[i], nodeList[last]);
            if (S> Smax){
                Keymax = i;
                Smax = S;
            }
        }
    }

    if (Keymax != -1){
        vist.push_back(nodeList[Keymax]);//�˵��Ϊ͹���㣬��������ջ
        divide(first, Keymax, nodeList, vist);
        divide(Keymax, last, nodeList, vist);
    }
}


bool compare_x(Point point1, Point point2) {//����ȽϹ��򣺰�x�������С��������x��ͬ����y���С����
    if (point1.x1 != point2.x1)
        return point1.x1 < point2.x1;
    return point1.y1 < point2.y1;
}

vector<Point> Divideconquer::divideconquer(vector<Point> pointList)
{
    sort(pointList.begin(), pointList.end(),compare_x);//��pointList�еĵ�����������������
    int len = pointList.size();//��ȡ����
    vector<int> vist(len);
     
    vector<Point> res;//����͹�����ջ��
    res.push_back(pointList[0]); // ��ʼ��ֹ���ȻΪ͹����
    res.push_back(pointList.back());//back()�����������һ��Ԫ�صĵ�ַ
    divide(0, len - 1, pointList, res); // ��͹��
    divide(len - 1, 0, pointList, res); // ��͹��
    return res;
}