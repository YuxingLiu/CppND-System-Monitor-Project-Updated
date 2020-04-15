#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor();
  float Utilization();
 private:
  long idle_ = 0;
  long actv_ = 0;
};

#endif