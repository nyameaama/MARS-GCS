#include <Adafruit_GrayOLED.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>

#include <Adafruit_TFTLCD.h>
#include <registers.h>
#include <pin_magic.h>

// Pin configuration for the LCD
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

// LCD dimensions
#define LCD_WIDTH 320
#define LCD_HEIGHT 480

// Create an instance of the TFTLCD object
Adafruit_TFTLCD lcd(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup() {
  lcd.begin();
  lcd.setRotation(1); // Set the rotation if needed (0, 1, 2, 3)
  lcd.fillScreen(TFT_BLACK); // Clear the screen with black color

  // Set text color and size
  lcd.setTextColor(TFT_WHITE);
  lcd.setTextSize(3);

  // Set the cursor position to the center of the screen
  int16_t textWidth = 8 * 9; // Width of the text in pixels (9 characters)
  int16_t textHeight = 8 * 3; // Height of the text in pixels (3 characters)
  int16_t posX = (LCD_WIDTH - textWidth) / 2;
  int16_t posY = (LCD_HEIGHT - textHeight) / 2;

  // Print the text on the LCD
  lcd.setCursor(posX, posY);
  lcd.println("Nyameaama");
}

void loop() {
  // Leave the loop empty as we don't need continuous updates for this example
}