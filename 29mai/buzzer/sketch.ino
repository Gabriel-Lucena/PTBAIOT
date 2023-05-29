const int pin_led1 = 11;
const int pin_led2 = 12;
const int pin_buzzer = 13;
const int pin_aLDR = A0;

const float GAMMA = 0.7;
const float RL10 = 50;

int troca = 1;

void setup()
{

  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);
  pinMode(pin_aLDR, INPUT);
}

void loop()
{

  int leitura_analog = analogRead(pin_aLDR);
  float tensao = leitura_analog / 1024. * 5;
  float resistencia = 2000 * tensao / (1 - tensao / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistencia, (1 / GAMMA));

  delay(100);

  if (lux >= 100)
  {
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    if (troca)
    {
      tone(pin_buzzer, 4000, 5000);
      troca = 0;
    }
  }

  else
  {
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led1, LOW);
    noTone(pin_buzzer);
    troca = 1;
  }
}
