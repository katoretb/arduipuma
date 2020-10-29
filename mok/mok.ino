const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;
int timer = 0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  getda();
  Serial.println(distance);
  if (distance > 10) {
    timer++;
    delay(1000);
    if (timer >= 10){
      digitalWrite(13,HIGH);
    }
  }else{
    timer = 0 ;
    digitalWrite(13,LOW);
  }
}
void getda() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
}
