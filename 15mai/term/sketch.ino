int ThermistorPin = A0;
int LedPin = 13;
float R1 = 10000; // valor de R1 na placa
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; // coeficientes de Steinhart-Hart para o termistor

void setup()
{
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT); // define o pino do LED como saída
}

void loop()
{
    int Vo = analogRead(ThermistorPin);
    R2 = R1 * (1023.0 / (float)Vo - 1.0); // calcula a resistência no termistor
    logR2 = log(R2);
    T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // temperatura em Kelvin
    T = T - 273.15;                                             // converte Kelvin para Celsius

    Serial.print("Temperatura: ");
    Serial.print(T);
    Serial.println(" C");
}