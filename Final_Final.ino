#include <Servo_ATTinyCore.h>

#define PIN_SERVO 0
#define PIN_LED LED_BUILTIN
#define PIN_SWITCH_IN 3
#define PIN_SWITCH_OUT 2

Servo servo;

int angry_level = 0;
bool lastSwitchState = LOW;  // Letzter Tasterzustand
long lastDecreaseTime = 0;


void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SWITCH_OUT, OUTPUT);
  pinMode(PIN_SWITCH_IN, INPUT_PULLUP);
  servo.attach(PIN_SERVO);

  digitalWrite(PIN_SWITCH_OUT, LOW);

}

void loop() {
  bool switch_state = digitalRead(PIN_SWITCH_IN);
  
  long now = millis();

  // Wenn der Taster gedrückt wurde (Flanke von HIGH → LOW)
  if (lastSwitchState == HIGH && switch_state == LOW) {
    angry_level = angry_level + 1;
  }

  // Wenn der Taster länger nicht gedrückt war → Level langsam abbauen
  if (switch_state == LOW && now - lastDecreaseTime >= 10000) {
    if (angry_level > 0) angry_level = angry_level - 1;
    lastDecreaseTime = now;
  }

  lastSwitchState = switch_state; // Zustand merken

  if (switch_state == HIGH) {
    if (angry_level == 1) {
      digitalWrite(PIN_LED, HIGH);
      servo.write(90);
      delay(100); 
      servo.write(80); 
      delay(100);
      servo.write(70);  
      delay(100); 
      servo.write(60);
      delay(100); 
      servo.write(50); 
      delay(100);
      servo.write(40);  
      delay(100);
      servo.write(30);
      delay(100); 
      servo.write(20); 
      delay(100);
      servo.write(10);  
      delay(100);
      servo.write(0); 
      delay(200);
      servo.write(120);
      digitalWrite(PIN_LED, LOW); 
      }
    

    

    if (angry_level == 2) {
      digitalWrite(PIN_LED, HIGH);
      servo.write(0);
      delay(200);
      digitalWrite(PIN_LED, LOW);
      servo.write(120);
    }

    if (angry_level == 3) { 
      digitalWrite(PIN_LED, HIGH);
      servo.write(30);
      delay(1000);
      servo.write(0);
      delay(200);
      digitalWrite(PIN_LED, LOW);
      servo.write(120);
    }

    if (angry_level == 4) {
      digitalWrite(PIN_LED, HIGH);
      servo.write(0); 
      servo.write(20);
      delay(500);
      servo.write(0);
      delay(1000);
      servo.write(20);
      delay(200);
      servo.write(0);
      delay(1000);
      servo.write(120);      
      digitalWrite(PIN_LED, LOW);      
    }
    if (angry_level == 5) {
      digitalWrite(PIN_LED, HIGH);
      servo.write(0);
      for (int i = 0; i < 10; i++) {
        servo.write(0);
        delay(100);
        servo.write(30);
        delay(100);
      }
      servo.write(0);
      delay(1000);
      for (int i = 0; i < 10; i++) {
          servo.write(0);
          delay(100);
          servo.write(30);
          delay(100);
        }
      delay(500);
      digitalWrite(PIN_LED, LOW);
      servo.write(120);
    }
  }
}