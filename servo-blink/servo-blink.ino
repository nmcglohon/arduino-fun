#include <Servo.h>

#define SERVO_HIGH 90
#define SERVO_LOW 0

typedef struct{
     int status;
     int led_pin;
     int servo_pin;
     Servo theServo;
}led_servo_pair_state;

led_servo_pair_state lsp1;

void setup()
{
     lsp1.status = LOW;
     lsp1.led_pin = 2;
     lsp1.servo_pin = 9;
     lsp1.theServo.attach(lsp1.servo_pin);

     lsp1.theServo.write(0);
     pinMode(lsp1.led_pin, OUTPUT);
}


void loop()
{
     // servoActuate(90);
     actuate(&lsp1);
     delay(500);

     // servoActuate(0);
     actuate(&lsp1);
     delay(500);

}

void actuate(led_servo_pair_state *lsp)
{
     if(lsp->status == LOW)
     {
          digitalWrite(lsp->led_pin, HIGH);
          lsp->theServo.write(SERVO_HIGH);
          lsp->status = HIGH;
     }
     else if(lsp->status == HIGH)
     {
          digitalWrite(lsp->led_pin, LOW);
          lsp->theServo.write(SERVO_LOW);
          lsp->status = LOW;
     }
}
