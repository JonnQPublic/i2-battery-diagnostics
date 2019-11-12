
#pragma once
#ifndef SPI_OLED_H
#define SPI_OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

// You can use any (4 or) 5 pins 
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

struct displaymsg {
  char *line1;
  char *line2;
  char *line3;
  char *line4;
};

extern void initDisplay();
extern void updateDisplay();
extern void lcdTestPattern();
extern void clearDisplay();

#endif
