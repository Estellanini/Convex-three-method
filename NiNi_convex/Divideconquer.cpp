#include "Divideconquer.h"

void Divideconquer::divide(int first, int last, vector<Point> nodeList, vector<Point>& vist){
    int Keymax = -1;//最大面积的点在栈中的位置
    int Smax = 0;//最大面积初始设为0
 
    if (first < last){
        for (int i = first + 1; i < last; i++){//两端必在凸包中，所以不用判断
            int S = Striangle(nodeList[first], nodeList[i], nodeList[last]);//三点求面积
            if (S > Smax){//如果面积小于0，则证明不在此凸包区
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
        vist.push_back(nodeList[Keymax]);//此点必为凸包点，所以推入栈
        divide(first, Keymax, nodeList, vist);
        divide(Keymax, last, nodeList, vist);
    }
}


bool compare_x(Point point1, Point point2) {//定义比较规则：按x轴坐标从小到大排序，x相同，则按y轴大小排序
    if (point1.x1 != point2.x1)
        return point1.x1 < point2.x1;
    return point1.y1 < point2.y1;
}

vector<Point> Divideconquer::divideconquer(vector<Point> pointList)
{
    sort(pointList.begin(), pointList.end(),compare_x);//将pointList中的点根据排序规则来排序
    int len = pointList.size();//获取点数
    vector<int> vist(len);
     
    vector<Point> res;//最终凸包点的栈集
    res.push_back(pointList[0]); // 起始终止点必然为凸包点
    res.push_back(pointList.back());//back()函数返回最后一个元素的地址
    divide(0, len - 1, pointList, res); // 上凸包
    divide(len - 1, 0, pointList, res); // 下凸包
    return res;
}