#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "evive.h"
#include "Servo.h"

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void stop();
Servo servo_4;
Servo servo_44;
Servo servo_2;
Servo servo_45;
Servo servo_3;
void back();
double dela;
void reverse();
double DelayTime;
void Forward();
void Left();
void Right();
TFT_ST7735 lcd = TFT_ST7735();
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}


void stop()
{
    servo_4.write(90); // write to servo
    
    servo_44.write(90); // write to servo
    
    servo_2.write(90); // write to servo
    
    servo_45.write(90); // write to servo
    
    servo_3.write(90); // write to servo
    
}

void back()
{
    servo_4.write(90); // write to servo
    
    servo_2.write(145); // write to servo
    
    _delay(dela);
    
    servo_3.write(125); // write to servo
    
    _delay(dela);
    
    servo_44.write(110); // write to servo
    
    servo_45.write(110); // write to servo
    
    _delay(dela);
    
    servo_2.write(90); // write to servo
    
    _delay(dela);
    
    servo_3.write(90); // write to servo
    
    _delay(dela);
    
    servo_3.write(35); // write to servo
    
    _delay(dela);
    
    servo_2.write(55); // write to servo
    
    _delay(dela);
    
    servo_44.write(70); // write to servo
    
    servo_45.write(70); // write to servo
    
    _delay(dela);
    
    servo_3.write(90); // write to servo
    
    _delay(dela);
    
    servo_2.write(90); // write to servo
    
    _delay(dela);
    
}

void reverse()
{
    back();
    
    _delay(DelayTime);
    
    Left();
    
    _delay((DelayTime) * (3));
    
}

void Forward()
{
    servo_4.write(90); // write to servo
    
    servo_2.write(145); // write to servo
    
    _delay(0.1);
    
    servo_3.write(125); // write to servo
    
    _delay(dela);
    
    servo_44.write(70); // write to servo
    
    servo_45.write(80); // write to servo
    
    _delay(0.1);
    
    servo_45.write(70); // write to servo
    
    _delay(0.1);
    
    servo_2.write(90); // write to servo
    
    _delay(0.1);
    
    servo_3.write(90); // write to servo
    
    _delay(dela);
    
    servo_3.write(35); // write to servo
    
    _delay(dela);
    
    servo_2.write(55); // write to servo
    
    _delay(dela);
    
    servo_45.write(110); // write to servo
    
    servo_44.write(80); // write to servo
    
    _delay(0.1);
    
    servo_44.write(90); // write to servo
    
    _delay(0.1);
    
    servo_44.write(100); // write to servo
    
    _delay(0.1);
    
    servo_44.write(110); // write to servo
    
    _delay(0.1);
    
    servo_3.write(90); // write to servo
    
    _delay(0.1);
    
    servo_2.write(90); // write to servo
    
    _delay(dela);
    
}

void Left()
{
    servo_4.write(90); // write to servo
    
    servo_2.write(145); // write to servo
    
    _delay(0.1);
    
    servo_3.write(125); // write to servo
    
    _delay(dela);
    
    servo_44.write(70); // write to servo
    
    servo_45.write(80); // write to servo
    
    _delay(0.1);
    
    servo_45.write(70); // write to servo
    
    _delay(0.1);
    
    servo_2.write(90); // write to servo
    
    _delay(0.1);
    
    servo_3.write(90); // write to servo
    
    _delay(dela);
    
    servo_3.write(35); // write to servo
    
    _delay(dela);
    
    servo_2.write(55); // write to servo
    
    _delay(dela);
    
    servo_44.write(130); // write to servo
    
    servo_45.write(90); // write to servo
    
    _delay(0.1);
    
    servo_3.write(90); // write to servo
    
    _delay(0.1);
    
    servo_2.write(90); // write to servo
    
    _delay(dela);
    
}

void Right()
{
    servo_4.write(90); // write to servo
    
    servo_2.write(145); // write to servo
    
    _delay(0.1);
    
    servo_3.write(125); // write to servo
    
    _delay(dela);
    
    servo_44.write(70); // write to servo
    
    servo_45.write(80); // write to servo
    
    _delay(0.1);
    
    servo_45.write(70); // write to servo
    
    _delay(0.1);
    
    servo_2.write(90); // write to servo
    
    _delay(0.1);
    
    servo_3.write(90); // write to servo
    
    _delay(dela);
    
    servo_3.write(35); // write to servo
    
    _delay(dela);
    
    servo_2.write(55); // write to servo
    
    _delay(dela);
    
    servo_45.write(130); // write to servo
    
    servo_44.write(90); // write to servo
    
    _delay(0.1);
    
    servo_3.write(90); // write to servo
    
    _delay(0.1);
    
    servo_2.write(90); // write to servo
    
    _delay(dela);
    
}


void setup(){
    lcd.init(INITR_BLACKTAB);
     lcd.setRotation(1);
    DelayTime = 0.5;
    dela = 0.5;
    lcd.fillScreen(0);
    
    servo_4.attach(4); // init pin
    servo_44.attach(44); // init pin
    servo_2.attach(2); // init pin
    servo_45.attach(45); // init pin
    servo_3.attach(3); // init pin
    pinMode(A0+7,INPUT);
    pinMode(40,INPUT);
}

void loop(){
    
    lcd.setCursor(10, 10);
    lcd.print((analogRead(A0+7)) / (0.0381));
    if(((digitalRead(40))==(1))){
        if((getDistance(8,9)) < (15)){
            stop();
            lcd.setCursor(10, 20);
            lcd.print("Obstacle");
            servo_4.write(45); // write to servo
            _delay(0.5);
            if((getDistance(8,9)) > (25)){
                Right();
                lcd.setCursor(10, 20);
                lcd.print("Right   ");
                _delay(DelayTime);
            }else{
                servo_4.write(135); // write to servo
                lcd.setCursor(10, 20);
                lcd.print("Obstacle");
                _delay(0.5);
                if((getDistance(8,9)) > (25)){
                    Left();
                    lcd.setCursor(10, 20);
                    lcd.print("Left    ");
                    _delay(DelayTime);
                }else{
                    servo_4.write(0); // write to servo
                    lcd.setCursor(10, 20);
                    lcd.print("obstacle");
                    _delay(0.5);
                    if((getDistance(8,9)) > (25)){
                        Right();
                        lcd.setCursor(10, 20);
                        lcd.print("Right   ");
                        _delay((DelayTime) * (2));
                    }else{
                        servo_4.write(180); // write to servo
                        lcd.setCursor(10, 20);
                        lcd.print("obstacle");
                        _delay(0.5);
                        if((getDistance(8,9)) > (25)){
                            Left();
                            lcd.setCursor(10, 20);
                            lcd.print("Left    ");
                            _delay((DelayTime) * (2));
                        }else{
                            reverse();
                            lcd.setCursor(10, 20);
                            lcd.print("Reverse ");
                        }
                    }
                }
            }
        }
        Forward();
        lcd.setCursor(10, 20);
        lcd.print("forward ");
        _delay(0.2);
    }else{
        stop();
        lcd.setCursor(10, 20);
        lcd.print("Stop    ");
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

