
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef CYCLETIMING_H

#define CYCLETIMING_H


class letterArrays {

public:
   // CycleTiming(int cycleTime);
   // boolean check();

	int[] createArray(String inputStr);

    int a[];
    int b[];
    int c[];
    int d[];
    int e[];
    int f[];
    int g[];
    int h[];
    int i[];
    int j[];
    int k[];
    int l[];
    int m[];
    int n[];
    int o[];
    int p[];
    int q[];
    int r[];
    int s[];
    int t[];
    int u[];
    int v[];
    int w[];
    int x[];
    int y[];
    int z[];
    int invalid[];



private:
    int cycleTimeMillis;
    unsigned long lastCheckMillis;
};



#endif