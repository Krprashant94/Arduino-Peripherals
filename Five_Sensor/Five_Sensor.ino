int sensor_pin[7] = {2, 3, 4, 5, 6, 8, 9};
int sensor_data[7] = {0, 0, 0, 0, 0, 0, 0};
int i;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<=6; i++){
    sensor_data[i] = digitalRead(sensor_pin[i]);
    Serial.println("SENS "+String(i)+":"+String(sensor_data[i]));
  }
  Serial.println("------------------");
  delay(1000);
}
