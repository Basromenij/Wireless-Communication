const int led0 = 5;
const int led1 = 6;

int button0 = 0; // button 0 and 1 on the other arduino
int button1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);

  Serial.begin(9600); // the serial speed needs to be the same in both scketches.
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(led0, 255);
  analogWrite(led1, 255);

  if (Serial.available() > 0) { // if serial communication is recevied, assign new variable values
    if (Serial.read() == '\n') { // looks for a new line 
      button0 = Serial.parseInt(); // reads out the incomming serial communication
      button1 = Serial.parseInt();
    }
  }

  if (button0 == 1 && button1 == 0 ) {
    analogWrite(led0, 0);
  }

  if (button0 == 0 && button1 == 1 ) {
    analogWrite(led1, 0);
  }

}
