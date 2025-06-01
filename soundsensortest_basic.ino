int sound_sensor = A0; 
 
void setup() 
{
  Serial.begin(9600); 
}
 
void loop()
{
  int soundValue = 0; 
  for (int i = 0; i < 32; i++) 
  { soundValue += analogRead(sound_sensor);  } 
 
  soundValue >>= 2; // bitshift
  Serial.println(soundValue); 
 
  }
  delay(50);
}