/*
 * Arduino map function only works for integers
 * A simple change of variable types allows a floating point version
 * 
 */
 
 void setup() {
  // Set up serial port
  Serial.begin(57600);
  while (!Serial && (millis() < 5000)) {} // program continues after a time even if a monitor window is never opened
  Serial.println("\nPort initialized");

  // test new mapping function
  String str = "";
  float x;
  float y;
  for ( int i = 0; i < 10; i++) {
    x = (float)i * .5 - 0.2;
    y = mapFloat(x, -0.41, 1.0, 4, -17.8);
    str =  String(x) + ", " + String(y);
    Serial.println(str);
  }

}


void loop() {
  ;
}


/// map one numerical span to another with floating point values
double mapFloat (double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
