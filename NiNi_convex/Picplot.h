#pragma once
#ifndef NINI_CONVEX_PICPLOT_H
#define NINI_CONVEX_PICPLOT_H

#include <opencv2/opencv.hpp>

#include "Pointbase.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;



class Picplot{
public:
    static void
        drawConvexHull(vector<Point> dataPnt, vector<Point> resPnt, bool renderLine, string title = "凸包问题"){      
        const int IMAGE_SIZE = 1000;
        cv::Mat image(IMAGE_SIZE, IMAGE_SIZE, CV_8UC3, cv::Scalar(208, 239, 244));//浅黄色--背景色
        int ds = IMAGE_SIZE / 100;
        for (auto pnt : dataPnt){
            cv::Point cvPnt(pnt.x1 * ds, pnt.y1 * ds);
            cv::circle(image, cvPnt, 3, cv::Scalar(0, 0, 0), -1);
        }

        for (int i = 0; i < resPnt.size(); i++){
            cv::Point curPnt(resPnt[i].x1 * ds, resPnt[i].y1 * ds);
            cv::circle(image, curPnt, 3, cv::Scalar(0, 0, 255), -1);
            if (renderLine){
                int nexIndex = i + 1;
                if (nexIndex == resPnt.size())
                    nexIndex = 0;
                cv::Point nexPnt(resPnt[nexIndex].x1 * ds, resPnt[nexIndex].y1 * ds);
                line(image, curPnt, nexPnt, cv::Scalar(46, 14, 42), 2);
            }
        }

        //        imshow(title, image);
        string baseDir = "F:/NiNi_convex/NiNi_convex/generate/可视化结果";
        baseDir += std::to_string(dataPnt.size());
        baseDir += "个点-";
        baseDir += title;
        baseDir += ".jpg";
        cout << baseDir << endl;

        imwrite(baseDir.c_str(), image);
        //        cv::waitKey(0);
    }
};


#endif //NINI_CONVEX_PICPLOT_H