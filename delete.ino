char a ;
bool mode = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    a = Serial.read();
    if (a == 'a')digitalWrite(13, HIGH);
    else digitalWrite(13, LOW);
    if (mode) {
      digitalWrite(13, HIGH);
      mode = 0;
    }
    else {
      digitalWrite(13, LOW);
      mode = 1;
    }

  }
}
