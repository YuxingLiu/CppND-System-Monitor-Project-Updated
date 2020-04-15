#include "processor.h"
#include "linux_parser.h"
#include <unistd.h>

// Return the aggregate CPU utilization for 1 sec time interval
float Processor::Utilization() {
    long previdle = LinuxParser::IdleJiffies();
    long prevactv = LinuxParser::ActiveJiffies();

    sleep(1);

    long idle = LinuxParser::IdleJiffies();
    long actv = LinuxParser::ActiveJiffies();

    long actvd = actv - prevactv;
    long totald = actvd + idle - previdle;

    return (float) actvd / (float) totald;
}