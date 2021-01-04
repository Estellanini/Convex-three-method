#pragma once
#ifndef NINI_CONVEX_FILEUTIL_H
#define NINI_CONVEX_FILEUTIL_H

#include <fstream>
#include <sstream>
#include "Pointbase.h"
#include <vector>

using namespace std;

const char* POINT_TXT_DATA = "F:\\NiNi_convex\\NiNi_convex\\generate\\point.txt";
const char* POINT_TXT_DATA_1000 = "F:\\NiNi_convex\\NiNi_convex\\generate\\point1000.txt";

class FileUtil
{

public:

    static void writePoints(vector<Point> pntList, const char* path = POINT_TXT_DATA)
    {
        ofstream out(path);
        if (out.is_open())
        {
            for (auto p : pntList)
                out << p.x1 << " " << p.y1 << endl;
        }
        out.close();
    }

    static vector<Point> readPoints(const char* path = POINT_TXT_DATA)
    {
        vector<Point> list;

        ifstream in(path);
        int s;
        while (!in.eof())
        {
            Point point;
            in >> point.x1;
            in >> point.y1;
            list.push_back(point);
        }
        in.close();

        return list;
    }


};


#endif //NINI_CONVEX_FILEUTIL_H