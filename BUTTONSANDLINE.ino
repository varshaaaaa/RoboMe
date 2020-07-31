//Code based on: https://www.hackster.io/jason_rubadue/ti-rslk-build-workshop-instructions-ff82b7#code
//==================================================================
//Below shows how the line sensor pins are mapped to the MSP-EXP432P401R 
#define LS_PIN_IR  61 // <- Energia Pin #   Launchpad Pin -> P5.3
#define LS_PIN_1  65 // <- Energia Pin #   Launchpad Pin -> P7.0
#define LS_PIN_2  48 // <- Energia Pin #   Launchpad Pin -> P7.1
#define LS_PIN_3  64 // <- Energia Pin #   Launchpad Pin -> P7.2
#define LS_PIN_4  47 // <- Energia Pin #   Launchpad Pin -> P7.3
#define LS_PIN_5  52 // <- Energia Pin #   Launchpad Pin -> P7.4
#define LS_PIN_6  68 // <- Energia Pin #   Launchpad Pin -> P7.5
#define LS_PIN_7  53 // <- Energia Pin #   Launchpad Pin -> P7.6
#define LS_PIN_8  69 // <- Energia Pin #   Launchpad Pin -> P7.7

//Below shows Motor Driver pins
#define MOTOR_L_SLP_PIN 31  // <- Energia Pin #   Launchpad Pin -> P3.7
#define MOTOR_L_DIR_PIN 29  // <- Energia Pin #   Launchpad Pin -> P5.4
#define MOTOR_L_PWM_PIN 40  // <- Energia Pin #   Launchpad Pin -> P2.7
#define MOTOR_R_SLP_PIN 11  // <- Energia Pin #   Launchpad Pin -> P3.6
#define MOTOR_R_DIR_PIN 30  // <- Energia Pin #   Launchpad Pin -> P5.5
#define MOTOR_R_PWM_PIN 39  // <- Energia Pin #   Launchpad Pin -> P2.6

const int bump_sw_pin1 = 24; // P4.0
const int bump_sw_pin2 = 25; // P4.2
const int bump_sw_pin3 = 6; // P4.3
const int bump_sw_pin4 = 27; // P4.5
const int bump_sw_pin5 = 8; // P4.6
const int bump_sw_pin6 = 28; // P4.7

const int BPUSH1 = 34;
const int BPUSH2 = 19;
const int BPUSH3 = 18;
const int BPUSH4 = 17;

int rangeL;
int rangeR;

const int RLED = 77; 
const int buzz = 35;
  
void setup() {
//Initialize Line Sensors:
pinMode(BPUSH1, INPUT_PULLUP);  //Right button on LaunchPad

//setup() From Romi_Motor_Power.cpp
//this setup() should be transferred to Main Example Code
//Initialize Motors:
//setup() 
pinMode(bump_sw_pin1, INPUT_PULLUP);
pinMode(bump_sw_pin2, INPUT_PULLUP);
pinMode(bump_sw_pin3, INPUT_PULLUP);
pinMode(bump_sw_pin4, INPUT_PULLUP);
pinMode(bump_sw_pin5, INPUT_PULLUP);
pinMode(bump_sw_pin6, INPUT_PULLUP);
  
pinMode(MOTOR_L_SLP_PIN, OUTPUT);
pinMode(MOTOR_L_DIR_PIN, OUTPUT);
pinMode(MOTOR_L_PWM_PIN, OUTPUT);
pinMode(MOTOR_R_SLP_PIN, OUTPUT);
pinMode(MOTOR_R_DIR_PIN, OUTPUT);
pinMode(MOTOR_R_PWM_PIN, OUTPUT);

//pinMode(DIR_L, OUTPUT);
//pinMode(DIR_R, OUTPUT);

analogWrite(MOTOR_L_PWM_PIN, 0);      //speed = 0
analogWrite(MOTOR_R_PWM_PIN, 0);      //speed = 0
digitalWrite(MOTOR_L_SLP_PIN, LOW);   //put motor to sleep
digitalWrite(MOTOR_R_SLP_PIN, LOW);   //put motor to sleep
digitalWrite(buzz, LOW);

//Initialize Line Following Sensor:
pinMode(LS_PIN_IR, OUTPUT);
pinMode(LS_PIN_1, OUTPUT);
pinMode(LS_PIN_2, OUTPUT);
pinMode(LS_PIN_3, OUTPUT);
pinMode(LS_PIN_4, OUTPUT);
pinMode(LS_PIN_5, OUTPUT);
pinMode(LS_PIN_6, OUTPUT);
pinMode(LS_PIN_7, OUTPUT);
pinMode(LS_PIN_8, OUTPUT);

pinMode (BPUSH1, INPUT);
pinMode (BPUSH2, INPUT);
pinMode (BPUSH3, INPUT);
pinMode (BPUSH4, INPUT);
pinMode (buzz, OUTPUT);


Serial.begin(9600);
Serial.println("starting...");
}

void loop() {
//=====================================================================
//motor pin variables
uint8_t slp_pin_L = MOTOR_L_SLP_PIN;
uint8_t dir_pin_L = MOTOR_L_DIR_PIN;
uint8_t pwm_pin_L = MOTOR_L_PWM_PIN;
uint8_t motor_dir_L = 0;
uint8_t slp_pin_R = MOTOR_R_SLP_PIN;
uint8_t dir_pin_R = MOTOR_R_DIR_PIN;
uint8_t pwm_pin_R = MOTOR_R_PWM_PIN;
uint8_t motor_dir_R = 0;
//line following sensor variables
digitalWrite(LS_PIN_IR, HIGH);
digitalWrite(LS_PIN_1, HIGH);
digitalWrite(LS_PIN_2, HIGH);
digitalWrite(LS_PIN_3, HIGH);
digitalWrite(LS_PIN_4, HIGH);
digitalWrite(LS_PIN_5, HIGH);
digitalWrite(LS_PIN_6, HIGH);
digitalWrite(LS_PIN_7, HIGH);
digitalWrite(LS_PIN_8, HIGH);

//wait until button is pressed to start robot motors
//while(digitalRead(BPUSH1));

//NEWWWW
//enable motors
//digitalWrite(slp_pin_L, HIGH);
//digitalWrite(slp_pin_R, HIGH);

//NEWWW
//set motors to go forward
//digitalWrite(dir_pin_L, LOW);
//digitalWrite(dir_pin_R, LOW);

//test code for motors
/*for(int i=20; i<255; i++){
analogWrite(pwm_pin_L, i);  //ramp motors from 0 to full speed
analogWrite(pwm_pin_R, i);  //ramp motors from 0 to full speed
delay(50);   
}*/



//======================================================================
//THIS AREA IS JUST FOR TESTING THE LINE SENSOR SENSITIVITY AND LIGHTING
//======================================================================
/*
while(true)
{
Serial.println("Testing time for line following sensor sensitivity:");

for(int i=0; i<100; i+=1){  //set how much time to test for
digitalWrite(LS_PIN_IR, LOW);
pinMode(LS_PIN_1, INPUT);
pinMode(LS_PIN_2, INPUT);
pinMode(LS_PIN_3, INPUT);
pinMode(LS_PIN_4, INPUT);
pinMode(LS_PIN_5, INPUT);
pinMode(LS_PIN_6, INPUT);
pinMode(LS_PIN_7, INPUT);
pinMode(LS_PIN_8, INPUT);
delay(i);
pin1 = digitalRead(LS_PIN_1);
pin2 = digitalRead(LS_PIN_2);
pin3 = digitalRead(LS_PIN_3);
pin4 = digitalRead(LS_PIN_4);
pin5 = digitalRead(LS_PIN_5);
pin6 = digitalRead(LS_PIN_6);
pin7 = digitalRead(LS_PIN_7);
pin8 = digitalRead(LS_PIN_8);
delay(10);
Serial.print("Time = ");
Serial.print(i);
Serial.println("ms");
Serial.print(pin8);
Serial.print(pin7); 
Serial.print(pin6);
Serial.print(pin5);
Serial.print(pin4);
Serial.print(pin3);
Serial.print(pin2);
Serial.println(pin1);

//CHARGE BACK UP AND GET READY TO SENSE AGAIN
pinMode(LS_PIN_1, OUTPUT);
pinMode(LS_PIN_2, OUTPUT);
pinMode(LS_PIN_3, OUTPUT);
pinMode(LS_PIN_4, OUTPUT);
pinMode(LS_PIN_5, OUTPUT);
pinMode(LS_PIN_6, OUTPUT);
pinMode(LS_PIN_7, OUTPUT);
pinMode(LS_PIN_8, OUTPUT);
digitalWrite(LS_PIN_IR, HIGH);
digitalWrite(LS_PIN_1, HIGH);
digitalWrite(LS_PIN_2, HIGH);
digitalWrite(LS_PIN_3, HIGH);
digitalWrite(LS_PIN_4, HIGH);
digitalWrite(LS_PIN_5, HIGH);
digitalWrite(LS_PIN_6, HIGH);
digitalWrite(LS_PIN_7, HIGH);
digitalWrite(LS_PIN_8, HIGH);
delay(100);
}
}
*/
//======================================================================
//THIS AREA IS FOR LINE FOLLOWING APPLICATION
//======================================================================
int time = 10; //ENTER VALUE HERE FROM YOUR SENSITIVITY TESTS
Serial.println("Entering line following mode:");

if(digitalRead(BPUSH1)==HIGH){  
  
digitalWrite(slp_pin_L, HIGH);
digitalWrite(slp_pin_R, HIGH);

digitalWrite(dir_pin_L, LOW);
digitalWrite(dir_pin_R, LOW);

bool pin1 = 1;
bool pin2 = 1;
bool pin3 = 1;
bool pin4 = 1;
bool pin5 = 1;
bool pin6 = 1;
bool pin7 = 1;
bool pin8 = 1;

int steering = 128;
digitalWrite(LS_PIN_IR, LOW); //turn off LED
pinMode(LS_PIN_1, INPUT);     //turn on sensors
pinMode(LS_PIN_2, INPUT);
pinMode(LS_PIN_3, INPUT);
pinMode(LS_PIN_4, INPUT);
pinMode(LS_PIN_5, INPUT);
pinMode(LS_PIN_6, INPUT);
pinMode(LS_PIN_7, INPUT);
pinMode(LS_PIN_8, INPUT);
delay(time);                     //USE YOUR SENSITIVITY TEST TO FIGURE OUT THIS VALUE
pin1 = digitalRead(LS_PIN_1);
pin2 = digitalRead(LS_PIN_2);
pin3 = digitalRead(LS_PIN_3);
pin4 = digitalRead(LS_PIN_4);
pin5 = digitalRead(LS_PIN_5);
pin6 = digitalRead(LS_PIN_6);
pin7 = digitalRead(LS_PIN_7);
pin8 = digitalRead(LS_PIN_8);
if (pin1) steering += 64;
if (pin2) steering += 32;
if (pin3) steering += 16;
if (pin4) steering += 8;
if (pin5) steering -= 8;
if (pin6) steering -= 16;
if (pin7) steering -= 32;
if (pin8) steering -= 64;

//CHARGE BACK UP AND GET READY TO SENSE AGAIN
pinMode(LS_PIN_1, OUTPUT);
pinMode(LS_PIN_2, OUTPUT);
pinMode(LS_PIN_3, OUTPUT);
pinMode(LS_PIN_4, OUTPUT);
pinMode(LS_PIN_5, OUTPUT);
pinMode(LS_PIN_6, OUTPUT);
pinMode(LS_PIN_7, OUTPUT);
pinMode(LS_PIN_8, OUTPUT);
digitalWrite(LS_PIN_IR, HIGH);
digitalWrite(LS_PIN_1, HIGH);
digitalWrite(LS_PIN_2, HIGH);
digitalWrite(LS_PIN_3, HIGH);
digitalWrite(LS_PIN_4, HIGH);
digitalWrite(LS_PIN_5, HIGH);
digitalWrite(LS_PIN_6, HIGH);
digitalWrite(LS_PIN_7, HIGH);
digitalWrite(LS_PIN_8, HIGH);

//Serial.println(steering);
if (steering > 205) analogWrite(pwm_pin_L, 60);  
else if (steering > 175) analogWrite(pwm_pin_L, 40);
else if (steering > 150) analogWrite(pwm_pin_L, 20);
else analogWrite(pwm_pin_L, 0);

if (steering < 50) analogWrite(pwm_pin_R, 60);  //ramp motors from 0 to full speed
else if (steering < 80) analogWrite(pwm_pin_R, 40);
else if (steering < 105) analogWrite(pwm_pin_R, 20);
else analogWrite(pwm_pin_R, 0);

if (steering >= 106 && steering <= 149){
  analogWrite(pwm_pin_L, 40);
  analogWrite(pwm_pin_R, 40);
    }
  } //END OF WHILE() LOOP
if (digitalRead(BPUSH2) == HIGH)
  {
    right();
    speedLeft(15);
    speedRight(0);
  }
if (digitalRead(BPUSH3) == HIGH)
  {
    forward();
    speedLeft(30);
    speedRight(30);
  }
if (digitalRead(BPUSH4) == HIGH)
  {
    backward();
    speedLeft(30);
    speedRight(30);
  }
if ((digitalRead(BPUSH1) == LOW) && (digitalRead(BPUSH2) == LOW) && (digitalRead(BPUSH3) == LOW) && (digitalRead(BPUSH4) == LOW))
  {
    sleepmode();
  }
if ((digitalRead(bump_sw_pin1) == 0) || (digitalRead(bump_sw_pin2) == 0) || (digitalRead(bump_sw_pin3) == 0) || (digitalRead(bump_sw_pin4) == 0) || (digitalRead(bump_sw_pin5) == 0) || (digitalRead(bump_sw_pin6) == 0))
{
  digitalWrite (buzz, HIGH);
} 
if ((digitalRead(bump_sw_pin1) == 1) && (digitalRead(bump_sw_pin2) == 1) && (digitalRead(bump_sw_pin3) == 1) && (digitalRead(bump_sw_pin4) == 1) && (digitalRead(bump_sw_pin5) == 1) && (digitalRead(bump_sw_pin6) == 1))
{
  digitalWrite (buzz, LOW);
}
}
//END OF LOOP()
void sleepmode()
{
  digitalWrite(MOTOR_L_SLP_PIN, LOW);
  digitalWrite(MOTOR_R_SLP_PIN, LOW);
}

void forward()
{
  digitalWrite(MOTOR_L_SLP_PIN, HIGH);
  digitalWrite(MOTOR_R_SLP_PIN, HIGH);
  digitalWrite(MOTOR_L_DIR_PIN, LOW);
  digitalWrite(MOTOR_R_DIR_PIN, LOW);
}

void backward()
{
  digitalWrite(MOTOR_L_SLP_PIN, HIGH);
  digitalWrite(MOTOR_R_SLP_PIN, HIGH);
  digitalWrite(MOTOR_L_DIR_PIN, HIGH);
  digitalWrite(MOTOR_R_DIR_PIN, HIGH);
}

void right()
{
  digitalWrite(MOTOR_L_SLP_PIN, HIGH);
  digitalWrite(MOTOR_R_SLP_PIN, HIGH);
  digitalWrite(MOTOR_L_DIR_PIN, LOW);
  digitalWrite(MOTOR_R_DIR_PIN, HIGH);  
}

void left()
{
  digitalWrite(MOTOR_L_SLP_PIN, HIGH);
  digitalWrite(MOTOR_R_SLP_PIN, HIGH);
  digitalWrite(MOTOR_L_DIR_PIN, HIGH);
  digitalWrite(MOTOR_R_DIR_PIN, LOW);  
}

void speedLeft(int speedL)
{
  rangeL = map (speedL, 0, 100, 0, 255);
  analogWrite(MOTOR_L_PWM_PIN, rangeL);
}

void speedRight(int speedR)
{
  rangeR = map (speedR, 0, 100, 0, 255);
  analogWrite(MOTOR_R_PWM_PIN, rangeR);
}
