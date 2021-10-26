#include "MainControlLoop.hpp"

MainControlLoop::MainControlLoop()
: ControlTask<void>(),
clock_manager(constants::timecontrol::control_cycle_time), 
acs_monitor(constants::timecontrol::acs_monitor_offset),
battery_monitor(constants::timecontrol::battery_monitor_offset),
button_monitor(constants::timecontrol::button_monitor_offset),
camera_report_monitor(constants::timecontrol::camera_report_monitor_offset),
command_monitor(constants::timecontrol::command_monitor_offset),
current_monitor(constants::timecontrol::current_monitor_offset),
fault_monitor(constants::timecontrol::fault_monitor_offset),
imu_monitor(constants::timecontrol::imu_monitor_offset),
normal_report_monitor(constants::timecontrol::normal_report_monitor_offset),
photoresistor_monitor(constants::timecontrol::photoresistor_monitor_offset),
temperature_monitor(constants::timecontrol::temperature_monitor_offset),
acs_control_task(constants::timecontrol::acs_control_task_offset),
burnwire_control_task(constants::timecontrol::burnwire_control_task_offset),
camera_control_task(constants::timecontrol::camera_control_task_offset),
rockblock_control_task(constants::timecontrol::rockblock_control_task_offset),
temperature_control_task(constants::timecontrol::temperature_control_task_offset),
mission_manager(constants::timecontrol::mission_manager_offset)
{
    delay(1000);
    pinMode(27, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, OUTPUT);
    start_time = millis();

}

void MainControlLoop::execute()
{
    

    start_time = millis();

    while(millis()-start_time < 3000){
        Serial.print(millis());
        Serial.print(",");
        Serial.print("ON");
        Serial.print(",");
        Serial.print(sfr::imu::mag_x_average);
        Serial.print(",");
        Serial.print(sfr::imu::mag_y_average);
        Serial.print(",");
        Serial.println(sfr::imu::mag_z_average);

        imu_monitor.execute();
        digitalWrite(27, HIGH);
        digitalWrite(28, LOW);
        digitalWrite(29, HIGH);
        analogWrite(30, 255);
    }

    start_time = millis();

    while(millis()-start_time < 3000){
        Serial.print(millis());
        Serial.print(",");
        Serial.print("OFF");
        Serial.print(",");
        Serial.print(sfr::imu::mag_x_average);
        Serial.print(",");
        Serial.print(sfr::imu::mag_y_average);
        Serial.print(",");
        Serial.println(sfr::imu::mag_z_average);

        imu_monitor.execute();
        digitalWrite(27, HIGH);
        digitalWrite(28, LOW);
        digitalWrite(29, LOW);
        analogWrite(30, 0);
    }


}