/*
uno: calibrate ADC inputs
*/
const int repeats = 10; // number of times to repeat the measurement
long int sum0 = 0; // a running total of the measurements for that channel
long int sum1 = 0; // a running total of the measurements for that channel
long int sum2 = 0; // a running total of the measurements for that channel
long int sum3 = 0; // a running total of the measurements for that channel
const float scalefactor0 = 1.7093; // my scalefactor: yours will be different!
const float scalefactor1 = 1.6941; // my scalefactor: yours will be different!
const float scalefactor2 = 1.6960; // my scalefactor: yours will be different!
const float scalefactor3 = 1.7018; // my scalefactor: yours will be different!

void setup() {
Serial.begin(9600);
analogReference(DEFAULT); // NB use "EXTERNAL" only if using an external reference
}

// take measurements and print result
void loop() {
readvoltage();
// A0
//Serial.print("sum0 of ten readings is : ");
//Serial.print(sum0);
//Serial.println("; ");
float voltage0 = sum0 * scalefactor0; // convert to voltage in millivolts
Serial.print("voltage cell 0: ");
Serial.print(voltage0,0);
Serial.println("; ");
// A1
//Serial.print("sum1 of ten readings is : ");
//Serial.print(sum1);
//Serial.println("; ");
float voltage1 = sum1 * scalefactor1 - voltage0; // convert to voltage in millivolts
Serial.print("voltage cell 1: ");
Serial.print(voltage1,0);
Serial.println("; ");
// A2
//Serial.print("sum2 of ten readings is : ");
//Serial.print(sum2);
//Serial.println("; ");
float voltage2 = sum2 * scalefactor2 - voltage1 - voltage0; // convert to voltage in millivolts
Serial.print("voltage cell 2: ");
Serial.print(voltage2,0);
Serial.println("; ");
// A3
//Serial.print("sum3 of ten readings is : ");
//Serial.print(sum3);
//Serial.println("; ");
float voltage3 = sum3 * scalefactor3 - voltage2 - voltage1 - voltage0; // convert to voltage in millivolts
Serial.print("voltage cell 3: ");
Serial.print(voltage3,0);
Serial.println("; ");
//TOTAL VOLTAGE
float voltagetotal = sum3 * scalefactor3;
Serial.print("voltage total: ");
Serial.print(voltagetotal,0);
Serial.println("; ");
delay (960);
}

void readvoltage() {
sum0 = 0;
for (int j = 0; j < repeats; j++) {
 sum0 += analogRead(0);
 delay(10); // choose a short delay that does not add to 20msec.
 }
sum1 = 0;
for (int j = 0; j < repeats; j++) {
 sum1 += analogRead(1);
 delay(10); // choose a short delay that does not add to 20msec.
 }
sum2 = 0;
for (int j = 0; j < repeats; j++) {
 sum2 += analogRead(2);
 delay(10); // choose a short delay that does not add to 20msec.
 }
sum3 = 0;
for (int j = 0; j < repeats; j++) {
 sum3 += analogRead(3);
 delay(10); // choose a short delay that does not add to 20msec.
 } 
}
