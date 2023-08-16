  #include <Servo.h>
  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>
  const int SensorPin = 8;
  const int buzzer=12;
  const int trigPin=11;
  const int echoPin=10;
  Servo myservo;
  int lcdAddress = 0x27;
  int lcdColumns = 16;
  int lcdRows = 2;
  LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);
 
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13 , OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(SensorPin, INPUT);
  myservo.attach(9);
  Wire.begin(); 
  lcd.init();
  lcd.backlight();
  
  
  

 


}

void loop() {
  long duration , distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin , HIGH);
  distance=(duration/2)/29.1;

  String D1="Ultrasonic-1 value:";
  int val1=distance;
  String cm1="CM";
  String combine1= D1+val1+cm1;
  Serial.println(combine1);
  delay(100);
  int sensorValue = digitalRead(SensorPin); // Read the sensor value
  

  
  
  if (sensorValue==LOW){
    digitalWrite(13 ,HIGH);
    digitalWrite(buzzer,HIGH);
    myservo.write(90); 
    myservo.write(0);
    
  }
  else if (distance>9){
    digitalWrite(13 ,LOW);
    digitalWrite(buzzer,LOW);
    myservo.write(0); 
    myservo.write(90); 

  }
  else if(distance<=9){
    digitalWrite(13 , HIGH);
    digitalWrite(buzzer,HIGH);
    myservo.write(90); 
    myservo.write(0); 
  }
  else if (distance<=9 && sensorValue==LOW){
    myservo.write(90); 
    myservo.write(0);
  }
  
  else 
  {
    digitalWrite(13 , HIGH);
    digitalWrite(buzzer,HIGH);
    myservo.write(90); 
    myservo.write(0);  
      
  }
  if(sensorValue==LOW && distance<=9){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Overheight");
    lcd.setCursor(0, 1);
    lcd.print("Vehicle Detected");
    delay(1500);
    lcd.clear();
    lcd.print("Take Right Turn");
    delay(1500);
    
  }
  else if(distance<=9){
    lcd.clear();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Overheight");
    lcd.setCursor(0, 1);
    lcd.print("Vehicle Detected");
    delay(1500);
    lcd.clear();
    lcd.print("Take Right Turn");
    delay(1500);
  
  }
  else if (sensorValue==LOW){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Overheight");
    lcd.setCursor(0, 1);
    lcd.print("Vehicle Detected");
    delay(1500);
    lcd.clear();
    lcd.print("Take Right Turn");
    delay(1500);
  }
  else{
    lcd.clear();
    lcd.print("  Happy Journey");
    
  }
 
  

}
