
#include "Screen.h"

/*#######################
  Variables and Constants
#######################*/
bool _showPercent;

/*##################################
  Constructor for the Screen Object
##################################*/
Screen::Screen(int8_t reset_pin) : Ecran(reset_pin) {}

/*##########
  Utilities
###########*/
void Screen :: effacerUp(byte column)
{
  fillRect(column*8, 0, 8, 64, BLACK);
}

/*#############################
  Functions to create a dimmer
#############################*/
void Screen :: drawSideDimmer(float valeur,float min, float max, byte ligne)
{
  valeur = (valeur-min) * 128/(max-min);
  effacer(ligne);
  drawRect(0, ligne*8, 128, 8, WHITE);
  fillRect(0, ligne*8, valeur, 8, WHITE);
}

void Screen :: drawUpDimmer(float valeur,float min, float max, byte column)
{
  valeur =((valeur-min) * 64/(max-min));
  effacerUp(column);
  drawRect(column*8, 0, 8, 64, WHITE);
  fillRect(column*8, 64-valeur, 8, valeur, WHITE);
}

// void Screen :: drawCircleDimmer(float valeur,float min, float max)
// {

// }

void Screen :: showPercentage(bool show)
{
  _showPercent = show;
}

/*#####################################
  Functions to print text on the screen
#####################################*/
void Screen :: centerPrint(String message, int line, int textSize)
{
  
}

void Screen :: displayTxt(String message, int line, int textSize)
{
  effacer(line, textSize);
  ecrire(message, line, textSize);
}

void Screen :: displayNbr(int message, int line, int textSize)
{
  effacer(line, textSize);
  ecrire(message, line, textSize);
}

/*#####################################
  Functions to create a loading screen
#####################################*/

void Screen :: loadingDotScreen()
{
  displayTxt("Loading", 0, 1); 
}

