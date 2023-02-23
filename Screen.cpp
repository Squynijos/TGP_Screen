#include "Screen.h"

Screen::Screen(int8_t reset_pin) : Ecran(reset_pin) {}

void Screen :: drawRectDimmer(float valeur,float min, float max, int ligne)
{
  ligne = ligne - 1; // permet d'ecrire ligne 1 au lieu de ligne 0 pour 1
  valeur = valeur * 128/(max-min);
  effacer(ligne);
  drawRect(0, ligne*8, 128, 8, WHITE);
  fillRect(0, ligne*8, valeur, 8, WHITE);
}

