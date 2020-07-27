  const int nSLPL = 31;
  const int nSLPR = 11;
  const int DIR_L = 29;
  const int DIR_R = 30;
  const int PWML = 40;
  const int PWMR = 39;
  
  const int BPUSH1 = 34;
  const int BPUSH2 = 19;
  const int BPUSH3 = 18;
  const int BPUSH4 = 17;
  
  int rangeL;
  int rangeR;

  const int RLED = 77; 

void setup() {
  // put your setup code here, to run once:
pinMode(nSLPL, OUTPUT);
pinMode(nSLPR, OUTPUT);
pinMode(DIR_L, OUTPUT);
pinMode(DIR_R, OUTPUT);
pinMode(PWML, OUTPUT);
pinMode(PWMR, OUTPUT);

pinMode (BPUSH1, INPUT);
pinMode (BPUSH2, INPUT);
pinMode (BPUSH3, INPUT);
pinMode (BPUSH4, INPUT);

//analogWrite(PWML, 0);
//analogWrite(PWMR, 0);

digitalWrite(nSLPL, LOW);
digitalWrite(nSLPR, LOW);

//digitalWrite(DIR_R, LOW);
//digitalWrite(DIR_R, LOW);  

}

void loop() {
  // put your main code here, to run repeatedly: 

  if (digitalRead(BPUSH1) == HIGH)
  {
    digitalWrite(RLED, HIGH);
  }
  else
  {
    digitalWrite(RLED, LOW);
  }
  if (digitalRead(BPUSH2) == HIGH)
  {
    forward();
    speedLeft(25);
    speedRight(25);
  }
  if (digitalRead(BPUSH3) == HIGH)
  {
    backward();
    speedLeft(25);
    speedRight(25);
  }
  if (digitalRead(BPUSH4) == HIGH)
  {
    right();
    speedLeft(15);
    speedRight(0);
  }
  if ((digitalRead(BPUSH1) == LOW) && (digitalRead(BPUSH2) == LOW) && (digitalRead(BPUSH3) == LOW) && (digitalRead(BPUSH4) == LOW))
  {
    sleepmode();
  }
}

void sleepmode()
{
  digitalWrite(nSLPL, LOW);
  digitalWrite(nSLPR, LOW);
}

void forward()
{
  digitalWrite(nSLPL, HIGH);
  digitalWrite(nSLPR, HIGH);
  digitalWrite(DIR_L, LOW);
  digitalWrite(DIR_R, LOW);
}

void backward()
{
  digitalWrite(nSLPL, HIGH);
  digitalWrite(nSLPR, HIGH);
  digitalWrite(DIR_L, HIGH);
  digitalWrite(DIR_R, HIGH);
}

void right()
{
  digitalWrite(nSLPL, HIGH);
  digitalWrite(nSLPR, HIGH);
  digitalWrite(DIR_L, LOW);
  digitalWrite(DIR_R, HIGH);  
}

void speedLeft(int speedL)
{
  rangeL = map (speedL, 0, 100, 0, 255);
  analogWrite(PWML, rangeL);
}

void speedRight(int speedR)
{
  rangeR = map (speedR, 0, 100, 0, 255);
  analogWrite(PWMR, rangeR);
}
