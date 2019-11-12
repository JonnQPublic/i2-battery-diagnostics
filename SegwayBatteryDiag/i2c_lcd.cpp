
#include "config.h"

#ifdef I2C_LCD_DISPLAY
#include "i2c_lcd.h"
#include "char.h"

struct displaymsg i2cdisplay;

int spinstate;
int refreshDisplay;

LiquidCrystal_I2C lcd(DISPADDR, DISPCOLS, DISPROWS);

void initDisplay() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.home();
}

void doBlink() {
  switch (spinstate) {
    case 0:
      lcd.createChar(0, batt0);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 1:
      lcd.createChar(0, batt1);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 2:
      lcd.createChar(0, batt2);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 3:
      lcd.createChar(0, batt3);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 4:
      lcd.createChar(0, batt4);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 5:
      lcd.createChar(0, batt5);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 6:
      lcd.createChar(0, batt6);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate++;
      break;
    case 7:
      lcd.createChar(0, batt7);
      lcd.setCursor(19, 3);
      lcd.write(uint8_t(0));
      spinstate = 0;
      break;
    default:
      spinstate = 0;
      break;
  }
}

void storeLine(int line, char *message) {
  switch(line) {
    case 1:
      strcpy(i2cdisplay.line1, message);
      break;
    case 2:
      strcpy(i2cdisplay.line2, message);
      break;
    case 3:
      strcpy(i2cdisplay.line3, message);
      break;
    case 4:
      strcpy(i2cdisplay.line3, message);
      break;
    default:
      break;
  }
}

void updateDisplay() {
  if (refreshDisplay) {
    lcd.home();
    lcd.clear();
    refreshDisplay = 0;
  }
  lcd.setCursor(0, 0);
  lcd.print(i2cdisplay.line1);
  lcd.setCursor(0, 1);
  lcd.print(i2cdisplay.line2);
  lcd.setCursor(0, 2);
  lcd.print(i2cdisplay.line3);
  lcd.setCursor(0, 3);
  lcd.print(i2cdisplay.line4);
}

void clearDisplay(void) {
  lcd.clear();
}

#endif
