

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hola");
  delay(1000);

  val1 = readSensor(pin1, val);
  Serial.print(val1);
}
