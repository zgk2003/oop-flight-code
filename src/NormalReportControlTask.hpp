#ifndef ACS_CONTROL_TASK_HPP_
#define ACS_CONTROL_TASK_HPP_

#include "sfr.hpp"
#include "constants.hpp"
#include <Arduino.h> 

class NormalReportControlTask{
    public:
        NormalReportControlTask();
        void execute();
};

#endif