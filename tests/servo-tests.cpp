struct servo_suite : public tmpdir_fixture
{
    // create dirname / "period"
    // create dirname / "duty_cycle"

    // create SysyfsPWMPIN that manages both
    SysFSPWMPin pin;
};

TEST_F(servo_suite, basic)
{
    servo my_servo(pin, 0, pin.period()/2, pin.period());

    my_servo.set_position(-50);
    
    ASSERT_EQ(pin.duty_cycle(), pin.period()/2/2);
}
