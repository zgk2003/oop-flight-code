#ifndef _ISENSOR_MONITOR_HPP_
#define _ISENSOR_MONITOR_HPP_

#include "sfr.hpp"

class ISensorMonitor{
    public:
        virtual void execute()=0;
        virtual void transition_to_normal()=0;
        virtual void transition_to_abnormal_init()=0;
        virtual void transition_to_abnormal_readings()=0;
        virtual void transition_to_retry()=0;
        virtual void transition_to_abandon()=0;
};

#endif