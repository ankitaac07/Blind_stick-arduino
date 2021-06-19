const int trigpin= 9;
const int echopin= 8;
const int led1=10;
const int led2=11;
const int buzzer= 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);

  long distance, duration;
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance= duration*0.034/2;
  Serial.println(distance);
  Serial.println();
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
 
  if (distance<50) {
    
    digitalWrite(led1, HIGH);
    delay(1000);
     
    Serial.println(" alert! ");
    Serial.println();
  }
  
   if (distance<30) {
    
     digitalWrite(led1,HIGH);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    Serial.println(" obstacle ahead");
    Serial.println();
  }
  if(distance<15)
  {
     digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(led2, HIGH);
    delay(1000);
    Serial.println("  obstacle stop ");
    delay(1000);
    Serial.println();
  }
  
}
