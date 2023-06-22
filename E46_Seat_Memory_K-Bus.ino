byte keyInserted [7] = {0x44,0x05,0xBF,0x74,0x04,0x00,0x8E};
byte keyRemoved [7] = {0x44,0x05,0xBF,0x74,0x00,0xFF,0x75};
byte ignitionOff [6] = {0x80,0x04,0xBF,0x11,0x00,0x2A};
byte ignitionAcc [6] = {0x80,0x04,0xBF,0x11,0x01,0x2B};
byte ignitionIgn [6] = {0x80,0x04,0xBF,0x11,0x03,0x29};

byte selected = 2;
uint32_t timer1 = millis();

void setup() {
  Serial.begin(9600, SERIAL_8E1);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(2) == LOW){selected = 1; digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);}
  if(digitalRead(3) == LOW){selected = 2; digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);}
  if(digitalRead(4) == LOW){selected = 3; digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);}
  if(digitalRead(5) == LOW){selected = 4; digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);}
  if(digitalRead(6) == LOW){selected = 5; digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW);}

  if(millis() - timer1 > 1000)
  {
    digitalWrite(13, HIGH);
    if(selected == 1){Serial.write(ignitionOff,6);}
    if(selected == 2){Serial.write(ignitionAcc,6);}
    if(selected == 3){Serial.write(ignitionIgn,6);}
    if(selected == 4){Serial.write(keyRemoved,7);}
    if(selected == 5){Serial.write(keyInserted,7);}
    delay(10); digitalWrite(13, LOW);
    timer1 = millis();
  }
}