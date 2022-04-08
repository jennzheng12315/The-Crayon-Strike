// Pins for buttons
int button1 = 4;   
int button2 = 8; 
int button3 = 12; 

// Pins for LEDs
int r1 = 2;
int r2 = 3;
int y1 = 6;
int y2 = 7;
int b1 = 10;
int b2 = 11;

// Codes to send to Serial
byte audio1 = 1;
byte noaudio1 = 2;
byte audio2 = 3;
byte noaudio2 = 4;
byte audio3 = 5;
byte noaudio3 = 6;

#include<Servo.h> //include the servo library
Servo servo; //create a servo object
int pos = 0;  //initial position of the servo

void setup() {
  // put your setup code here, to run once:
  servo.attach(13);  //pin used by the servo

  // INPUT_PULLUP send to arduino LOW signal, so, when you press the button, you send a LOW signal to arduino
  pinMode(button1, INPUT_PULLUP);  
  pinMode(button2, INPUT_PULLUP); 
  pinMode(button3, INPUT_PULLUP); 

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);

  servo.write(0);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // BUTTON 1
  if (digitalRead(button1) == LOW) { // red button is pressed
    servo.write(0); //servo goes to 0 degrees
    digitalWrite(r1, HIGH); // Turn on light
    digitalWrite(r2, HIGH);
    Serial.write(audio1); // Play audio
  }
  if (digitalRead(button1) == HIGH) { // red button is released
    digitalWrite(r1, LOW); // Turn off light
    digitalWrite(r2, LOW);
    Serial.write(noaudio1); // Stop audio
  }

  // BUTTON 2
  if (digitalRead(button2) == LOW) { // yellow button is pressed
    servo.write(90); // servo goes to 90 degrees
    digitalWrite(y1, HIGH); 
    digitalWrite(y2, HIGH);
    Serial.write(audio2);
  }
  if (digitalRead(button2) == HIGH) { // yellow button is released
    digitalWrite(y1, LOW); 
    digitalWrite(y2, LOW);
    Serial.write(noaudio2);
  }

  // BUTTON 3
  if (digitalRead(button3) == LOW) { // blue button is pressed
    servo.write(180); // servo goes to 180 degrees
    digitalWrite(b1, HIGH); 
    digitalWrite(b2, HIGH);
    Serial.write(audio3);
  }
  if (digitalRead(button3) == HIGH) { // blue button is released
    digitalWrite(b1, LOW); 
    digitalWrite(b2, LOW);
    Serial.write(noaudio3);
  }
}
