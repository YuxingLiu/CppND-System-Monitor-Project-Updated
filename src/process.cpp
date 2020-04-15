#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {
    user_ = LinuxParser::User(pid);
    cmd_ = LinuxParser::Command(pid);
}

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() {
    long uptime = LinuxParser::UpTime();
    long total_time = LinuxParser::ActiveJiffies(pid_);
    long elaps_time = uptime - UpTime();
    cpu_usage_ = (float) total_time / (float) elaps_time;
    return cpu_usage_;
}

// DONE: Return the command that generated this process
string Process::Command() { return cmd_; }

// DONE: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// DONE: Return the user (name) that generated this process
string Process::User() { return user_; }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { return cpu_usage_ > a.cpu_usage_; }