int ledpin = 9;
int brilho = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  while (brilho < 255)
  {
    brilho++;
    analogWrite(ledPin, brilho);
    delay(10)
  }

  brilho = 256;

  while (brilho > 1)
  {
    brilho--;
    analogWrite(ledPin, brilho);
    delay(10);
  }
}