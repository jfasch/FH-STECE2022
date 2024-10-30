#pragma once

class PWMPin
{
public:
    PWMPin(const std::string& dirpath); // e.g. /sys/class/pwm/pwmchip0/pwm7

    void set_duty_cycle(uint64_t);
    uint64_t get_period(); // read in constructor

private:
    
};
