  const int nSLPL = 31;
  const int nSLPR = 11;
  const int DIR_L = 29;
  const int DIR_R = 30;
  const int PWML = 40;
  const int PWMR = 39;
  
  const int TLED1 = 38;
  const int TLED2 = 37;
  const int TLED3 = 36;
  const int TLED4 = 35;
  const int BPUSH1 = 34;
  const int BPUSH2 = 19;
  const int BPUSH3 = 18;
  const int BPUSH4 = 17;
  
  int rangeL;
  int rangeR;

  const int LineIR = 61;
  const int Line1 = 65;
  const int Line2 = 48;
  const int Line3 = 64;
  const int Line4 = 47;
  const int Line5 = 52;
  const int Line6 = 68;
  const int Line7 = 53;
  const int Line8 = 69;

void setup() {
  // put your setup code here, to run once:
pinMode(nSLPL, OUTPUT);
pinMode(nSLPR, OUTPUT);
pinMode(DIR_L, OUTPUT);
pinMode(DIR_R, OUTPUT);
pinMode(PWML, OUTPUT);
pinMode(PWMR, OUTPUT);

pinMode (TLED1, OUTPUT);
pinMode (TLED2, OUTPUT);
pinMode (TLED3, OUTPUT);
pinMode (TLED4, OUTPUT);
pinMode (BPUSH1, INPUT);
pinMode (BPUSH2, INPUT);
pinMode (BPUSH3, INPUT);
pinMode (BPUSH4, INPUT);

pinMode (LineIR, OUTPUT);
pinMode (Line1, OUTPUT);
pinMode (Line2, OUTPUT);
pinMode (Line3, OUTPUT);
pinMode (Line4, OUTPUT);
pinMode (Line5, OUTPUT);
pinMode (Line6, OUTPUT);
pinMode (Line7, OUTPUT);
pinMode (Line8, OUTPUT);

//analogWrite(PWML, 0);
//analogWrite(PWMR, 0);

digitalWrite(nSLPL, LOW);
digitalWrite(nSLPR, LOW);

digitalWrite(TLED1, LOW);
digitalWrite(TLED2, LOW);
digitalWrite(TLED3, LOW);
digitalWrite(TLED4, LOW);

}

void loop() {
  // put your main code here, to run repeatedly: 

  if (digitalRead(BPUSH1) == HIGH)
  {
    digitalWrite(TLED1, HIGH);
  }
  else
  {
    digitalWrite(TLED1, LOW);
  }
  if (digitalRead(BPUSH2) == HIGH)
  {
    digitalWrite(TLED2, HIGH);
    forward();
    speedLeft(25);
    speedRight(25);
  }
  else
  {
    digitalWrite(TLED2, LOW);
  }
  if (digitalRead(BPUSH3) == HIGH)
  {
    digitalWrite(TLED3, HIGH);
    backward();
    speedLeft(25);
    speedRight(25);
  }
  else
  {
    digitalWrite(TLED3, LOW);
  }
  if (digitalRead(BPUSH4) == HIGH)
  {
    digitalWrite(TLED4, HIGH);
    right();
    speedLeft(15);
    speedRight(0);
  }
  else
  {
    digitalWrite(TLED4, LOW);
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
