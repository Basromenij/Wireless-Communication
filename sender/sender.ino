const int button0 = 2;   // Two buttons are used to trigger a serial communcation 
const int button1 = 4;

const int led0 = 5; // Two leds are used as feedback of the buttons
const int led1 = 6;

int i = 0;
int sendData[] = {0, 0};  // An array with two elements, when you want to send more or less change the content
void setup() {
  
  pinMode (button0, INPUT);
  pinMode (button1, INPUT);

  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);

  Serial.begin(9600); // the serial speed needs to be the same in both scketches.
}

void loop() {

  analogWrite(led0, 255);  // I've used inversed leds, therefore setting them with 255 makes them turn off
  analogWrite(led1, 255); 

  sendData[0] = digitalRead(button0); // Defines what the array is sending, when you want to send more create an sendData[2] with what it needs to send
  sendData[1] = digitalRead(button1);  

  if (sendData[0] == HIGH) { // When the button0 is high serial communcation is send
    Serial.print('\n'); // sends an empty line to have the sendData on a new line
    for ( i = 0; i < 2; i++) { // Amount of information that is send. Want to send more increase the maximum of i
      if ( i  == 0) {
        Serial.print(sendData[i]);
      }
      else {
        Serial.print(','); // seperates elememtns with a , making it able to read out for the parseint
        Serial.print(sendData[i]);
      }
    }  
    analogWrite(led0, 0); // Pressing button0 will turn led0 on
    delay (200); // Push buttons often work with a spring that results in a not stable signal, therefore use a delay
  }

  if (  sendData[1] == HIGH) {
    for ( i = 0; i < 2; i++) {
      if ( i  == 0) {
        Serial.print(sendData[i]);
      }
      else {
        Serial.print(',');
        Serial.print(sendData[i]);
      }
    }
    Serial.print('\n');

    analogWrite(led1, 0);
    delay (500);
  }
}

