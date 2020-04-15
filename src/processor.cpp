#include "processor.h"
#include "linux_parser.h"
#include <unistd.h>

Processor::Processor() {
    idle_ = LinuxParser::IdleJiffies();
    actv_ = LinuxParser::ActiveJiffies();
}

// Return the aggregate CPU utilization for 1 sec time interval
float Processor::Utilization() {
    long idle = LinuxParser::IdleJiffies();
    long actv = LinuxParser::ActiveJiffies();
    long actvd = actv - actv_;
    long totald = actvd + idle - idle_;

    // Update the states
    idle_ = idle;
    actv_ = actv;

    return (float) actvd / (float) totald;
}