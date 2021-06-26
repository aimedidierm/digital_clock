#include <LiquidCrystal.h>
#include "RTClib.h"

RTC_DS3231 rtc;

LiquidCrystal lcd(A0, A1, A2, A3, 8, 9);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  if (! rtc.begin()) {
    lcd.print("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    lcd.clear();
    lcd.print("RTC lost power");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  lcd.print("System Ready");
  lcd.setCursor(7,1);
  lcd.print("^_^");

}

void loop() {
  DateTime now = rtc.now();
  lcd.clear();
    lcd.print(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    lcd.print(" (");
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(") ");
    lcd.setCursor(0,1);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    lcd.print("");
    delay(1000);
}
