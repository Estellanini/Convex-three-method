#pragma once
#ifndef NINI_CONVEX_TIME_H
#define NINI_CONVEX_TIME_H

#include <ctime>
#include <iostream>
#include <string>
#include <time.h>
#include <sys/timeb.h>

typedef unsigned long long ull;

static ull curTime;
static clock_t curClock;

class TimeUtil
{

public:

    static ull getTimeStamp()
    {

        timeb t;
        ftime(&t);
        return t.time * 1000 + t.millitm;
    }

    static void init(std::string tag)
    {

        curClock = clock();

        //        curTime = getTimeStamp();
        //        std::cout << tag << " : "<< curTime <<std::endl;
    }

    static double getDuration()
    {
        //        return getTimeStamp() - curTime;

        clock_t finishClock = clock();

        double dur = finishClock - curTime;

        return dur;

        //        return getTimeStamp() - curTime;
    }

    static void printDuration(std::string tag)
    {
        std::cout << tag << " : " << getDuration() << "ms" << std::endl;
    }
};


#endif //NINI_CONVEX_TIME_H