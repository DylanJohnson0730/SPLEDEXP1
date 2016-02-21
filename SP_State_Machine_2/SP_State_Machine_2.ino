//Switch while loops to if statements
//Switch sensor names to in/out arm/car sensor for differentiation
const int S_armdown = 0;
const int S_armup = 1;
const int S_armupperm = 2;
int Count = 80;
float distance1 = 0;
unsigned long duration = millis();
int SensorInArm = 1;
int SensorInCar = 2;
int ts = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() 
{
  static int state = S_armdown;
  switch (state)
  {
    case S_armdown:
      if (digitalRead(SensorInArm) == LOW || digitalRead(SensorInCar) == LOW)
        {
          state = S_armdown;
        //set pulse periodicity lower
        //set arduino to lower power mode
        }
        else
        {
          state = S_armup;
        }
  }
  switch (state){
    case S_armup:
    
      if (digitalRead(SensorInArm) == HIGH && digitalRead(SensorInCar) == HIGH && ts < 15000 ){
        //Maybe use a 2 second delay to debounce 
        Count == Count--;
        //Access rF transciever to send new count value to display
      }
  }
  switch (state){
    case S_armupperm:
      if (digitalRead(SensorInArm) == HIGH && duration >= 1500){
        //put arduino and sensor periodicity in low power mode
        if (digitalRead(SensorInCar) == HIGH && distance1 < 35){
          Count == Count--;
        }
      }
      if (digitalRead(SensorInArm) == LOW && digitalRead(SensorInCar) == LOW)
      {
        
        state = S_armdown;
      }
  }
}
