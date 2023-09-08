#include "SR04.h" // biblioteca do módulo ultrasom HC-SR04
#include <Wire.h> // biblioteca de transmissão de dados
#include "LiquidCrystal_I2C.h" // biblioteca da tela lcd IIC LCD1602

LiquidCrystal_I2C lcd(0x27,16,2); // seta o endereço do LCD para 0x27 para 16 caracteres e 2 linhas

#define TRIG_PIN 11 // número da entrada que recebe o trigger do sensor
#define ECHO_PIN 10 // número da entrada que o echo do sensor
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN); // cria uma instância de objeto do sensor, com o trigger e o echo
long distance; // variável que armazena a distância

void setup() {
  lcd.init(); // inicializa o LCD
}

void loop() {
  distance = sr04.Distance(); // calcula a distância utilizando o objeto instanciado anteriormente
  lcd.backlight(); // inicializa a luz de fundo do LCD
  lcd.setCursor(0, 0); // seta o cursor de escrita para o ponto (0, 0)
  lcd.print("Distancia:    cm"); // printa esse texto na tela
  lcd.setCursor(11,0); // seta o cursor de escrita para o ponto (11, 0)
  lcd.print(distance); // printa a distância na tela
  delay(1000); // aguarda 1 segundo
}
