#include <wiringPi.h>
#include <iostream>

#define SERVO_PIN 1  // GPIO Pin 18 entspricht Pin 1 in WiringPi

int main() {
    // Initialisierung von WiringPi
    if (wiringPiSetup() == -1) {
        std::cerr << "Fehler bei der Initialisierung von WiringPi" << std::endl;
        return 1;
    }

    // PWM-Modus auf den Pin setzen
    pinMode(SERVO_PIN, PWM_OUTPUT);

    // PWM-Range (Frequenz) setzen
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(2000);   // 2000 Schritte (f  r Feineinstellung)
    pwmSetClock(192);    // Basierend auf einem Takt von 19.2 MHz       
    
    //pwmWrite(SERVO_PIN,150);
    //delay(5000);
    std::cout << "jetzt wird bewegt!" << std::endl;
    delay(2000);
    // Servo auf eine Position setzen (Beispiel)
    for(int position = 120; position <=160; position +=5)  // Wertebereich: 50 (0 Grad) bis 250 (180 Grad)
    {
            pwmWrite(SERVO_PIN, position);

            std::cout << "Servo auf Position " << position << " bewegt." << std::endl;

            delay(5000);  // 2 Sekunden warten
    }
    return 0;
}
