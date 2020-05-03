#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
    int h = seconds/3600;
    int m = seconds%3600/60;
    int s = seconds%3600%60;
    char time[10];
    sprintf(time, "%.2i:%.2i:%.2i", h, m, s);
    return std::string(time);
}