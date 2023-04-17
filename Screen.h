#ifndef Screen_h
#define Screen_h

#include "Arduino.h"
#include "Ecran.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    //Si pas nécessaire, il faut alors mettre <= 0

#define DEFAULT_ADDRESS 0x3C

/******************************************************************************
* Definitions
******************************************************************************/
class Screen : public Ecran
{
    public:
        Screen(int8_t reset_pin = OLED_RESET);

        void effacerUp(byte column);
        void drawSideDimmer(float valeur, float min, float max, byte ligne=0);
        void drawUpDimmer(float valeur, float min, float max, byte column=15);
        void showPercentage(bool show);
        void centerPrint(String message, int line=0, int textSize=1);
        void displayTxt(String message, int line=0, int textSize=1);
        void displayNbr(int message, int line=0, int textSize=1);
        // void loadingScreen();

    private:
        bool _showPercent=false;
};
#endif
