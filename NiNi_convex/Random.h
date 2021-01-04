#pragma once
#ifndef NINI_CONVEX_RANDOM_H
#define NINI_CONVEX_RANDOM_H

#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Pointbase.h"

using namespace std;

class Random
{

public:


    static vector<Point> buildRandomPoint(int size = 100);


};

vector<Point> Random::buildRandomPoint(int size)
{

    srand(time(0));

    const int MAT_SIZE = 100;

    vector<Point> resVec;

    for (int i = 0; i < size; ++i)
    {
        Point point;
        point.x1 = rand() % MAT_SIZE;
        point.y1 = rand() % MAT_SIZE;
        resVec.push_back(point);

        //            cout << "point " << i << "  ===>  x: " << pnt.x << "  y:" << pnt.y << endl;
    }

    return resVec;
}


#endif //NINI_CONVEX_RANDOM_H