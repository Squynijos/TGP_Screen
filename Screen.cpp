#include "Screen.h"

Screen::Screen(int8_t reset_pin) : Ecran(reset_pin) {}

void Screen :: drawSideDimmer(float valeur,float min, float max, byte ligne)
{
  valeur = (valeur-min) * 128/(max-min);
  effacer(ligne);
  drawRect(0, ligne*8, 128, 8, WHITE);
  fillRect(0, ligne*8, valeur, 8, WHITE);
}

//void Screen :: drawTriDimmer (float valeur,float min, float max, bool)

void Screen :: drawUpDimmer(float valeur,float min, float max, byte column)
{
  valeur = (valeur-min) * 64/(max-min);
  effacerUp(column);
  drawRect(column*8, 0, 8, 64, WHITE);
  fillRect(column*8, 0, 8, valeur, WHITE);
}

void Screen :: effacerUp(byte column)
{
  fillRect(column*8, 0, 8, 64, BLACK);
}
