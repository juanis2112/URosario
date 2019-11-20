void setup() {
   Serial.begin(9600);
   pinMode(6, OUTPUT);
   pinMode(5, INPUT);
}
 
void loop() {
   long duration, distanceCm;
   digitalWrite(6, LOW); 
   delayMicroseconds(4);
   digitalWrite(6, HIGH); 
   delayMicroseconds(10);
   digitalWrite(6, LOW);
   
   duration = pulseIn(5, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   Serial.print("Tiempo: ");
   Serial.println(duration);
   Serial.print("duration: ");
   Serial.println(distanceCm);
   delay(1000);
}
