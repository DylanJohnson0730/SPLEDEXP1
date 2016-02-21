#define trigPin 12        
#define echoPin 13
#define led 11
#define led2 10


void setup() {
  Serial.begin (9600);                //Begin serial data log
  pinMode(trigPin, OUTPUT);           //Define trigPin as output pin 12
  pinMode(echoPin, INPUT);            //Define echoPin as input pin 13
  pinMode(led, OUTPUT);               //Define Red LED
  pinMode(led2, OUTPUT);              //Define Green LED
}

void loop() {
  long duration, distance;            //Create duration and distance variable
  digitalWrite(trigPin, LOW);         //Digital write low for trig
  delayMicroseconds(2);               //Delay
  digitalWrite(trigPin, HIGH);        //Digital write high for trig
  delayMicroseconds(10);              //Delay
  digitalWrite(trigPin, LOW);         //Digital write low for trig
  duration = pulseIn(echoPin, HIGH);  //Define duration variable
  distance = (duration/2) / 29.1;     //Define distance variable. 29.1 is ultrasonic constant
  if (distance < 20) {                //If statement for LED On/Off
  digitalWrite(led,HIGH);             //When the Red condition is met
  digitalWrite(led2,LOW);             //The Green LED should turn off
}
  else {
    digitalWrite(led,LOW);            //Else, Red LED turns off
    digitalWrite(led2,HIGH);          //Green LED turns on
  }
  if (distance >= 200 || distance <= 0){  //if 0 >= distance >= 20 cm 
    Serial.println("Out of range");       //Print "Out of Range
  }
  else {
    Serial.print(distance);           //Write distance to serial port
    Serial.println(" cm");            //Print "cm" after value
  }
  delay(500);                         //Delay

}
