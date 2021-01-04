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
    cout << "������������ " << endl;
    cin >> size;

    // ͹������

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
        typeName += "ö�ٷ�";
        break;
    case Graham:
        res = Graham::graham(dataPntList);
        typeName += "Graham��";
        break;
    case Divideconquer:
        res = Divideconquer::divideconquer(dataPntList);
        typeName += "���η�";
        break;
    default:
        break;
    }

    // �Լ��ǽ�������
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
    cout << "����ʱ��: " << end - begin << endl;
    cout << "͹������: " << res.size() << endl;
    Picplot::drawConvexHull(dataPntList, res, true, typeName);
    cout << "-----------------------------------------------" << endl;
}

int main() {
    ConvexHull::init();
}