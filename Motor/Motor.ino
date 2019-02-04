int ena = 46;
int enb = 44;
int l_f = 40;
int l_b = 36;
int r_f = 38;
int r_b = 42;

void setup() {
  // put your setup code here, to run once:
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(l_f, OUTPUT);
  pinMode(l_b, OUTPUT);
  pinMode(r_f, OUTPUT);
  pinMode(r_b, OUTPUT);

  analogWrite(ena, 100);
  analogWrite(enb, 100);
}
void forword(){
  digitalWrite(l_f, HIGH);
  digitalWrite(l_b, LOW);
  digitalWrite(r_f, HIGH);
  digitalWrite(r_b, LOW);
}
void backword(){
  digitalWrite(l_f, LOW);
  digitalWrite(l_b, HIGH);
  digitalWrite(r_f, LOW);
  digitalWrite(r_b, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  forword();
  delay(2000);
  backword();
  delay(2000);
}
