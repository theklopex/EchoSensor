int trigger = 2;
int echo = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("Echo Sensor!");

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);  

  digitalWrite(trigger, LOW);
  digitalWrite(echo, LOW);  
}

void loop() {
  unsigned long startTime;
  unsigned long triggerEndTime;
  unsigned long triggerElapsedTime;
  int echoStart;
  int counter1;
  unsigned long burstStartTime;
  int echoStop;
  int counter2;
  unsigned long echoReceivedTime;
  unsigned long echoElapsedTime;
  float distance;


  startTime = micros();
  // Send the trigger
  digitalWrite(trigger, HIGH);

  do
  {
    triggerEndTime = micros();
    triggerElapsedTime = triggerEndTime - startTime;
    
  } while(triggerElapsedTime < 10);

  digitalWrite(trigger, LOW);

  // Wait for the burst to begin
  counter1 = 0;
  do
  {
    counter1++;
    echoStart = digitalRead(echo);
    burstStartTime = micros();
  } while ((echoStart == 0) && (counter1 < 10000)); 


  // Wait for the echo to return
  counter2 = 0;
  do
  {
    counter2++;
    echoStop = digitalRead(echo);
    echoReceivedTime = micros();
  } while ((echoStop != 0) && (counter2 < 10000)); 

  echoElapsedTime = echoReceivedTime - burstStartTime;

  // Convert microseconds into centimeters using 343m/s for speed of sound
  distance = echoElapsedTime/58.3090379;





  Serial.print("startTime = ");
  Serial.print(startTime);
//  Serial.print(" echoStart = ");
//  Serial.print(echoStart);
  Serial.print(" c1 = ");
  Serial.print(counter1);
  Serial.print(" t1 = ");
  Serial.print(burstStartTime);
//  Serial.print(" echoStop = ");
//  Serial.print(echoStop);
  Serial.print(" c2 = ");
  Serial.print(counter2);
  Serial.print(" t2 = ");
  Serial.print(echoReceivedTime);
  Serial.print(" t3 = ");
  Serial.print(echoElapsedTime);
  Serial.print(" distance = ");
  Serial.print(distance);

  Serial.println();
}










