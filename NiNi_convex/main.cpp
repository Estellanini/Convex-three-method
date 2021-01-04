#include "FileUtil.h"
#include "Time.h"
#include <algorithm>
#include "Random.h"
#include "Enumeration.h"
#include "Graham.h"
#include "Divideconquer.h"
#include "Picplot.h"

#include <iostream>

class ConvexHull{
public:
    enum CHType{
        Enumeration,
        Graham,
        Divideconquer
    };
    static void findConvexHull(CHType type, vector<Point> dataPntList);
    static void init();
};


void ConvexHull::init(){
   
    int size = 100;
    cout << "请输入点的数量 " << endl;
    cin >> size;

    // 凸包问题

    vector<Point> dataPntList = Random::buildRandomPoint(size);
    ConvexHull::findConvexHull(ConvexHull::CHType::Enumeration, dataPntList);
    ConvexHull::findConvexHull(ConvexHull::CHType::Graham, dataPntList);
    ConvexHull::findConvexHull(ConvexHull::CHType::Divideconquer, dataPntList);
}

void ConvexHull::findConvexHull(ConvexHull::CHType type, vector<Point> dataPntList)
{
    string typeName = "";
    clock_t begin, end;
    begin = clock();
    vector<Point> res;
    switch (type){
    case Enumeration:
        res = Enumeration::enumeration(dataPntList);
        typeName += "枚举法";
        break;
    case Graham:
        res = Graham::graham(dataPntList);
        typeName += "Graham法";
        break;
    case Divideconquer:
        res = Divideconquer::divideconquer(dataPntList);
        typeName += "分治法";
        break;
    default:
        break;
    }

    // 对极角进行排序
    sort(res.begin(), res.end(), [](Point p1, Point p2)
        {
            double angle1 = std::atan2(p1.y1 - 50, p1.x1 - 50);
            double angle2 = std::atan2(p2.y1 - 50, p2.x1 - 50);
            return angle1 > angle2;
        });

    end = clock();
  
    cout << typeName << endl;
    for (int i = 0; i < res.size(); ++i){
        Point p = res[i];
        cout <<  "(" << p.x1 << " , " << p.y1 << ")  ";
    }
    cout << endl;
    cout << "运行时间: " << end - begin << endl;
    cout << "凸包点数: " << res.size() << endl;
    Picplot::drawConvexHull(dataPntList, res, true, typeName);
    cout << "-----------------------------------------------" << endl;
}

int main() {
    ConvexHull::init();
}