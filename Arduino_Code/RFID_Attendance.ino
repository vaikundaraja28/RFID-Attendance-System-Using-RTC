#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

#define GREEN_LED 8
#define RED_LED 7
#define BUZZER 9

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
RTC_DS1307 rtc;

String cardID = "";

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  if (!rtc.begin())
  {
    lcd.print("RTC Error");
    while (1);
  }

  // Run once to set RTC time, then comment it out
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  lcd.print("RFID ATTENDANCE");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);

  lcd.clear();
  lcd.print("Scan Card...");
}

void loop()
{
  if (Serial.available())
  {
    cardID = Serial.readStringUntil('\n');
    cardID.trim();

    DateTime now = rtc.now();

    lcd.clear();

    if (cardID == "1234")
    {
      lcd.print("Student 1");
      lcd.setCursor(0, 1);
      lcd.print("Present");

      digitalWrite(GREEN_LED, HIGH);

      tone(BUZZER, 1000);
      delay(300);
      noTone(BUZZER);

      Serial.println();
      Serial.println("===== ATTENDANCE =====");
      Serial.println("ID: 1234");
      Serial.println("Name: Student 1");

      Serial.print("Date: ");
      Serial.print(now.day());
      Serial.print("/");
      Serial.print(now.month());
      Serial.print("/");
      Serial.println(now.year());

      Serial.print("Time: ");
      Serial.print(now.hour());
      Serial.print(":");
      Serial.print(now.minute());
      Serial.print(":");
      Serial.println(now.second());

      Serial.println("Status: Present");
      Serial.println("======================");

      delay(2000);
      digitalWrite(GREEN_LED, LOW);
    }
    else if (cardID == "5678")
    {
      lcd.print("Student 2");
      lcd.setCursor(0, 1);
      lcd.print("Present");

      digitalWrite(GREEN_LED, HIGH);

      tone(BUZZER, 1000);
      delay(300);
      noTone(BUZZER);

      Serial.println();
      Serial.println("===== ATTENDANCE =====");
      Serial.println("ID: 5678");
      Serial.println("Name: Student 2");

      Serial.print("Date: ");
      Serial.print(now.day());
      Serial.print("/");
      Serial.print(now.month());
      Serial.print("/");
      Serial.println(now.year());

      Serial.print("Time: ");
      Serial.print(now.hour());
      Serial.print(":");
      Serial.print(now.minute());
      Serial.print(":");
      Serial.println(now.second());

      Serial.println("Status: Present");
      Serial.println("======================");

      delay(2000);
      digitalWrite(GREEN_LED, LOW);
    }
    else
    {
      lcd.print("Invalid Card");
      lcd.setCursor(0, 1);
      lcd.print("Access Denied");

      digitalWrite(RED_LED, HIGH);

      tone(BUZZER, 500);
      delay(700);
      noTone(BUZZER);

      Serial.println();
      Serial.println("===== ATTENDANCE =====");
      Serial.print("Unknown ID: ");
      Serial.println(cardID);
      Serial.println("Status: Denied");
      Serial.println("======================");

      delay(2000);
      digitalWrite(RED_LED, LOW);
    }

    lcd.clear();

    lcd.print(now.hour());
    lcd.print(":");

    if (now.minute() < 10)
      lcd.print("0");

    lcd.print(now.minute());

    lcd.setCursor(0, 1);

    lcd.print(now.day());
    lcd.print("/");

    lcd.print(now.month());
    lcd.print("/");

    lcd.print(now.year());

    delay(3000);

    lcd.clear();
    lcd.print("Scan Card...");
  }
}
