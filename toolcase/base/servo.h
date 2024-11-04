#pragma once

class servo
{
public:
    servo(const PWMpin);

    void set_position(uint64_t);
    uint64_t get_position();

private:
    int position;
    const PWMpin pwm;
    const int period = 20 * 1000 * 1000;
};
