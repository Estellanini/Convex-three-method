#pragma once
#ifndef NINI_CONVEX_DIVIDECONQUER_H
#define NINI_CONVEX_DIVIDECONQUER_H

#include "Pointbase.h"
#include <vector>
#include <algorithm>

using namespace std;

class Divideconquer{
public:
    static int Striangle(Point a1, Point a2, Point a3) {//����������������ж�����͹��
        //��ֵP0->Pmax->Pn-1��˳ʱ��˳�򣬸�ֵΪ��ʱ��˳��
        int S = a1.x1 * a2.y1 + a3.x1 * a1.y1 + a2.x1 * a3.y1 - a3.x1 * a2.y1 - a2.x1 * a1.y1 - a1.x1 * a3.y1;
        return S;
    }
    static void divide(int first, int last, vector<Point> nodeList, vector<Point>& vist);
    static vector<Point> divideconquer(vector<Point> pointList);
};
#endif//NINI_CONVEX_DIVIDECONQUER_H