
const int kPin_Tilt = A0;
const int LED = 13;

void setup() {
  // put your setup code here, to run once:
    pinMode (kPin_Tilt, INPUT);
    digitalWrite (kPin_Tilt, HIGH);
    pinMode (LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(kPin_Tilt) == HIGH) {
      digitalWrite (LED, LOW);
    }
    else {
      digitalWrite(LED,HIGH);
    }
    delay(20);

}
