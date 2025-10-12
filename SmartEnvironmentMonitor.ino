#include <DFRobot_BMX160.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;
DFRobot_BMX160 bmx160;

int buzzerPin = 8; 
int soundPinInput = A1;
int IRvalue;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 500; i += tone * 2) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone);
  }
}

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(19200);
  aht.begin();
  bmx160.begin();

  delay(100);
}

void loop() {
  sBmx160SensorData_t Omagn, Ogyro, Oaccel;

  /* Get a new sensor event */
  bmx160.getAllData(&Omagn, &Ogyro, &Oaccel);

  int sensorSound = analogRead(soundPinInput);

  float NET_a = sqrt(Oaccel.x * Oaccel.x + Oaccel.y * Oaccel.y + Oaccel.z * Oaccel.z) - 9;
  NET_a = sqrt(NET_a*NET_a);

  Serial.print("a(m/s^2): ");
  Serial.println(NET_a);
  Serial.print("gx(g): ");
  Serial.println(Ogyro.x);
  Serial.print("gy(g): ");
  Serial.println(Ogyro.y);
  Serial.print("gz(g): ");
  Serial.println(Ogyro.z);

  Serial.print("IR: ");
  IRvalue = analogRead(A0);
  Serial.println(IRvalue);

  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  Serial.print("Temperature: "); 
  Serial.print(temp.temperature); 
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity); 
  Serial.println("% rH");

  if (NET_a > 20 && IRvalue > 30 && sensorSound > 100) {
    playTone(100, 1000);

    if (NET_a > 20)
	digitalWrite(12, HIGH); else digitalWrite(12, LOW);

    if (IRvalue > 30) 
	    digitalWrite(11, HIGH); 
	  else 
      digitalWrite(11, LOW);
    if (sensorSound > 100)
      digitalWrite(10, HIGH); 
    else
      digitalWrite(10, LOW);

    if (NET_a > 30 || IRvalue > 40) {
      digitalWrite(buzzerPin, HIGH);
      playTone(100, 1000);
    } else {
      digitalWrite(buzzerPin, LOW);
    }

    delay(300);
  } 
  delay(100);
}
