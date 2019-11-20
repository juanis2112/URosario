

#include <NewPing.h>
#include <Button.h>

#define TRIGGER_PIN  6   // Arduino pin tied to trigger pin on the ultrasonic sensor. (OUTPUT)
#define ECHO_PIN     5   // Arduino pin tied to echo pin on the ultrasonic sensor. (INPUT)
#define TRIGGER_PIN2  9  // Arduino pin tied to trigger pin on the second ultrasonic sensor.
#define ECHO_PIN2 8     // Arduino pin tied to echo pin on the second ultrasonic sensor.
#define POT A1  // Analog Input 
#define SWITCH  7  // Digital Input
#define BUT1 2 // Digital Input
#define BUT2 4 // Digital Input
#define BUT3 3 // Digital Input
#define MAX_DISTANCE 25 // Maximum sensor distance.

float u;
float r;
float p;
int s;
int s1 = 0;
int s2 = 0;
int s3 = 0;
float b0=0.3;
float b1=0.1;
float b2=0.1;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Object NewPing named Sonar 
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); // 
Button button1(BUT1); // Object Button named button1 
Button button2(BUT2);
Button button3(BUT3);
Button switch1(SWITCH);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results. 115200bits/second
 // No pinmode setup needed
  s = switch1.read();
  p = float(analogRead(POT));
}

void loop() {
  delay(50);     
  // Information gathering               
  float curU = sonar.ping(); // Reads time that it takes for the sound wave to return.
  float curR = sonar2.ping(); 
  float curP = float(analogRead(POT));
  if (switch1.toggled())  // Toggled is true when switch changes state.
    s = switch1.read();
  if (button1.pressed()) // Pressed when it switches from not pressed to pressed.
    s1 = 1 - s1;
  if (button2.pressed())
    s2 = 1 - s2;
  if (button3.pressed())
    s3 = 1 - s3;
  if (curU == 0)
    curU = u;
  if (curR == 0)
    curR = r;

  // Filter
  u += b0 * (curU-u); // For obtaining continuous sound signal change.
  r += b1 * (curR-r);
  p += b2 * (curP-p);    
                                                                                                                                                                                                                            
  float sendU = map(u, 250, 1200, 7, 0);  // Index of notes of scale 
  float sendR = map(r, 250, 1200, -20, 0); // Amplitude of the sound in decibels (0 db = 1 unit of amplitude / -6 db = 0.5 unit of amplitude) -> 20Log(A) 
  float sendP = map(p, 0, 1023, 0, -60); // Master Volume (in decibels) 
 

  sendU = constrain(sendU, 0, 7); // Clip the values to stay in range
  sendR = constrain(sendR, -30, 0);
  sendP = constrain(sendP, -60, 0);

  // Print values in specific format to be read by chuck.
  Serial.print("u");
  Serial.print(sendU);
  Serial.print("r");
  Serial.print(sendR);
  Serial.print("p"); 
  Serial.print(sendP);
  Serial.print("s");
  Serial.print(s);
  Serial.print("b");
  Serial.print(s1);
  Serial.print("c");
  Serial.print(s2);
  Serial.print("d");
  Serial.print(s3);
  Serial.println(";");


  
}
