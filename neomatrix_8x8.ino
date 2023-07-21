#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "font_8x8.h"
#include "font_chiffre.h"

#define PIN 13
#define mw 8
#define mh 8

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, 
  PIN,
  NEO_MATRIX_TOP  + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB         + NEO_KHZ800 
);

String inputString = "§ Ne Manger Rien Ou Jeûner Voilà Bien Votre Grande Bêtise §";

void display_scrollText() {
  static uint16_t couleur;
  matrix->setFont(&font_8);
  couleur = random(0, 0xFFFF);

  String replacedString = replaceSpecialCharacters(inputString);
  int16_t leng =  0 - (inputString.length() * 4) ;

  for (int16_t x=7; x>= leng; x--) {
    matrix->clear();
    matrix->setCursor(x,5);
    matrix->setTextColor(couleur);
    //char text[60] = "Encul\xE9 \x22 \xE8 \xE9 \xEA \xEB \x22 ";
    //matrix->print(text);
    matrix->print(replacedString);
    matrix->show();
    delay(100);
  }
}

String replaceSpecialCharacters(String input) {
  String output = "";
  for (int i = 0; i < input.length(); i++) {
    char c = input.charAt(i);
    //Serial.println((int)c);
    if (     (int)c == 169) output += "\xE9";  // é
    else if ((int)c == 168) output += "\xE8";  // è
    else if ((int)c == 170) output += "\xEA";  // ê
    else if ((int)c == 171) output += "\xEB";  // ë
    else if ((int)c == 185) output += "\xF9";  // ù
    else if ((int)c == 187) output += "\xFB";  // û
    else if ((int)c == 160) output += "\xE0";  // à
    else if ((int)c == 162) output += "\xE2";  // â
    else if ((int)c == 175) output += "\xEF";  // ï
    else                    output += c;       // Ajoute le caractère sans modification
  }
  return output;
}

void display_compter() {
  static uint8_t compt;
  static uint32_t time_compt;
  if( millis() - time_compt < 200) return;
  time_compt = millis();

  matrix->setCursor(1,5);
  matrix->setTextColor( random(0, 0xFFFF));
  matrix->clear();
  char CHAR[3];
  sprintf( CHAR, "%02u", compt);
  matrix->print( CHAR);
  matrix->show();
  compt++;
  if( compt > 99) compt = 0;
}

void loop() {
  display_scrollText();
//  display_compter();
}

void setup() {
  Serial.begin(115200);
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(255);
  matrix->setTextColor(0xF800);
  matrix->clear();
  matrix->setTextSize(0);
  matrix->setRotation(0);
  matrix->show();
}
