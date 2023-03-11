#define PIN_UP 9
#define PIN_DOWN 10

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_UP, OUTPUT);
  pinMode(PIN_DOWN, OUTPUT);
}

char thresh[20];
const unsigned int SIZE_THRESH = 20;
int8_t dir = 0;
unsigned short speed_ = 0;

void loop()
{
  if (Serial.available())
  {
    dir = Serial.parseInt();
    Serial.print("Direction -> ");
    Serial.println(dir);
    Serial.print("Enter speed: ");
    Serial.readBytes(thresh, SIZE_THRESH);
    while (!Serial.available()) {}
    speed_ = Serial.parseInt();
    Serial.println(speed_);
    engine_power(bool(dir), speed_);
    Serial.readBytes(thresh, SIZE_THRESH);
  }
}

void engine_power(const bool _direction, const int _speed)
{
  stop_engine();
  if (_direction)
  {
    analogWrite(PIN_UP, _speed);
  }
  else
  {
    analogWrite(PIN_DOWN, _speed);
  }
}

void stop_engine()
{
  analogWrite(PIN_UP, 0);
  analogWrite(PIN_DOWN, 0);
}
