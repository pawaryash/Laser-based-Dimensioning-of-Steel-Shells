int laserPin = 34;
const float adcMax = 4095.0;
const float adcMin = 0.0;
const float distanceMax = 1000.0;
const float distanceMin = 200.0;
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max);
  
void setup() {
  
  pinMode(laserPin,INPUT);
  Serial.begin(115200);

}

void loop() {
  
  //read the raw ADC values from the sensor;
  float rawADCValue = analogRead(laserPin);
  //float distance = map(output, 0, 4095, 162, 1000);
  float distance = mapFloat(rawADCValue, adcMin, adcMax, distanceMin, distanceMax);
  //float distance = ((rawADCValue*1000)/4095)+200;

  float avgReadings=0;
  float fiveReadings;
  for(int i=0;i<5;i++){
    fiveReadings += analogRead(laserPin);
    delay(100);
  }

  avgReadings = fiveReadings/5;


  Serial.print("Raw ADC Value: ");
  Serial.print(rawADCValue);
  Serial.print(", Mapped Distance: ");
  Serial.print(distance);
  Serial.println(" mm");


 
  
  delay(500);

}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max){
    float output =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    return output;
}
