#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
//---------------------------------------- 

#define T_CS_PIN    21 //--> T_CS

#define NATIVE_SCREEN_WIDTH 240
#define NATIVE_SCREEN_HEIGHT 320
#define FONT_SIZE 2

int centerX, centerY;

byte ts_Calibration_Sequence = 1;
byte cnt = 0;

uint16_t ts_Min_X, ts_Max_X, ts_Min_Y, ts_Max_Y;
bool FT = true;

TFT_eSPI tft = TFT_eSPI();

XPT2046_Touchscreen touchscreen(T_CS_PIN);




void get_Touchscreen_Min_X() {
    print_Title("touchscreen_Min_X (LEFT EDGE)");
    
    while(true) {
        // Draws a filled circle at the far left edge of the screen (0, centerY)
        tft.fillCircle(0, centerY, 5, TFT_RED); 

        if (touchscreen.touched()) {
            cnt++;
            
            // Get Touchscreen raw points
            TS_Point p = touchscreen.getPoint();
    
            print_Val(p.x, p.y, p.z);

            if(FT == true && cnt > 1) {
                ts_Min_X = p.x;
                FT = false;
            }

            if(p.x < ts_Min_X) ts_Min_X = p.x;

            if(cnt > 30) {
                cnt = 0;
                FT = true;
                ts_Calibration_Sequence++;
                break;
            }
    
            delay(50);
        }
    }

    print_Rslt("touchscreen_Min_X", ts_Min_X);

    delay(2000);
}


void get_Touchscreen_Max_X() {
    print_Title("touchscreen_Max_X (RIGHT EDGE)");
    
    while(true) {
        tft.fillCircle(tft.width() - 1, centerY, 5, TFT_RED); 

        if (touchscreen.touched()) {
            cnt++;
            
            TS_Point p = touchscreen.getPoint();
    
            print_Val(p.x, p.y, p.z);

            if(FT == true && cnt > 3) {
                ts_Max_X = p.x;
                FT = false;
            }

            if(p.x > ts_Max_X) ts_Max_X = p.x;

            if(cnt > 30) {
                cnt = 0;
                FT = true;
                ts_Calibration_Sequence++;
                break;
            }
    
            delay(50);
        }
    }

    print_Rslt("touchscreen_Max_X", ts_Max_X);

    delay(2000);
}

void get_Touchscreen_Min_Y() {
    print_Title("touchscreen_Min_Y (TOP EDGE)");
    
    while(true) {
        tft.fillCircle(centerX, 0, 5, TFT_RED);

        if (touchscreen.touched()) {
            cnt++;
            
            TS_Point p = touchscreen.getPoint();
    
            print_Val(p.x, p.y, p.z);

            if(FT == true && cnt > 3) {
                ts_Min_Y = p.y;
                FT = false;
            }

            if(p.y < ts_Min_Y) ts_Min_Y = p.y;

            if(cnt > 30) {
                cnt = 0;
                FT = true;
                ts_Calibration_Sequence++;
                break;
            }
    
            delay(50);
        }
    }

    print_Rslt("touchscreen_Min_Y", ts_Min_Y);

    delay(2000);
}

void get_Touchscreen_Max_Y() {
    print_Title("touchscreen_Max_Y (BOTTOM EDGE)");
    
    while(true) {
        tft.fillCircle(centerX, tft.height() - 1, 5, TFT_RED);

        if (touchscreen.touched()) {
            cnt++;
            
            TS_Point p = touchscreen.getPoint();
    
            print_Val(p.x, p.y, p.z);

            if(FT == true && cnt > 3) {
                ts_Max_Y = p.y;
                FT = false;
            }

            if(p.y > ts_Max_Y) ts_Max_Y = p.y;

            if(cnt > 30) {
                cnt = 0;
                FT = true;
                ts_Calibration_Sequence++;
                break;
            }
    
            delay(50);
        }
    }

    print_Rslt("touchscreen_Max_Y", ts_Max_Y);

    delay(2000);
}

void print_Title(String ttl) {
    Serial.println();
    Serial.print("-----------------Get ");
    Serial.print(ttl);
    Serial.println(" value");
    Serial.println("Please touch inside the red area.");
    Serial.println();
    
    tft.fillScreen(TFT_WHITE);  
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    // Use rotated width/height for centering text
    tft.drawCentreString("Get " + ttl, centerX, 20, FONT_SIZE);
    tft.drawCentreString("value", centerX, 40, FONT_SIZE);
    tft.drawCentreString("Please touch inside", centerX, (centerY - 8) - 10, FONT_SIZE);
    tft.drawCentreString("the red area.", centerX, (centerY - 8) + 10, FONT_SIZE);
}

void print_Val(uint16_t x, uint16_t y, uint16_t z) {
    Serial.print("p.x = ");
    Serial.print(x);
    Serial.print(" | p.y = ");
    Serial.print(y);
    Serial.print(" | Pressure = ");
    Serial.println(z);

    tft.fillScreen(TFT_WHITE);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);

    int textY = 80;
    
    String rslt_Text = "p.x = " + String(x);
    tft.drawCentreString(rslt_Text, centerX, textY, FONT_SIZE);

    textY += 20;
    rslt_Text = "p.y = " + String(y);
    tft.drawCentreString(rslt_Text, centerX, textY, FONT_SIZE);

    textY += 20;
    rslt_Text = "Pressure = " + String(z);
    tft.drawCentreString(rslt_Text, centerX, textY, FONT_SIZE);
}

void print_Rslt(String ttl, uint16_t ts_min_rslt) {
    Serial.println();
    Serial.print("Getting ");
    Serial.print(ttl);
    Serial.print(" value is complete.");
    Serial.println("Please release your touch from the screen.");

    Serial.println();
    Serial.print(ttl);
    Serial.print(" = ");
    Serial.println(ts_min_rslt);

    Serial.println();
    Serial.println("Please wait for the next process...");
    Serial.println("-----------------");

    String rslt_Text = ttl + " = " + String(ts_min_rslt);
    tft.setTextColor(TFT_BLUE, TFT_WHITE);
    tft.drawCentreString(rslt_Text, centerX, 160, FONT_SIZE);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.drawCentreString("Please release your touch", centerX, 200, FONT_SIZE);
    tft.drawCentreString("from the screen.", centerX, 220, FONT_SIZE);
    tft.drawCentreString("Please wait for", centerX, 260, FONT_SIZE);
    tft.drawCentreString("the next process...", centerX, 280, FONT_SIZE);
}

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(3000);

    tft.init();
    tft.setRotation(1); 

    centerX = tft.width() / 2; 
    centerY = tft.height() / 2; 

    touchscreen.begin();

    touchscreen.setRotation(1);

    tft.fillScreen(TFT_WHITE);

    Screen_Display_Test();

    tft.setRotation(1); 

    Serial.println();
    Serial.println("Touchscreen Calibration for LANDSCAPE (Rotation 1)");
    
    tft.fillScreen(TFT_WHITE);
    tft.setTextColor(TFT_BLACK, TFT_LIGHTGREY);
    tft.drawCentreString("LANDSCAPE CALIBRATION", centerX, centerY, FONT_SIZE);
    delay(2000);
}

void loop() {
    if (ts_Calibration_Sequence == 1) {
        get_Touchscreen_Min_X();
    } else if (ts_Calibration_Sequence == 2) {
        get_Touchscreen_Max_X();
    } else if (ts_Calibration_Sequence == 3) {
        get_Touchscreen_Min_Y();
    } else if (ts_Calibration_Sequence == 4) {
        get_Touchscreen_Max_Y();
    } else if (ts_Calibration_Sequence == 5) {
        Serial.println();
        Serial.println("-----------------LANDSCAPE Calibration Results (Rotation 1)");
        Serial.println("Copy and save the calibration results below.");
        Serial.println();
        Serial.print("TS_MAXX_LANDSCAPE (Corresponds to Display X=320) = ");
        Serial.println(ts_Max_X);
        Serial.print("TS_MINX_LANDSCAPE (Corresponds to Display X=0) = ");
        Serial.println(ts_Min_X);
        Serial.print("TS_MAXY_LANDSCAPE (Corresponds to Display Y=240) = ");
        Serial.println(ts_Max_Y); 
        Serial.print("TS_MINY_LANDSCAPE (Corresponds to Display Y=0) = ");
        Serial.println(ts_Min_Y);
        Serial.println("-----------------");

        tft.fillScreen(TFT_WHITE);
        tft.setTextColor(TFT_BLACK, TFT_WHITE);
        tft.drawCentreString("Calibration process complete.", centerX, 10, FONT_SIZE);
        tft.drawCentreString("See the results on", centerX, 30, FONT_SIZE);
        tft.drawCentreString("the serial monitor.", centerX, 50, FONT_SIZE);
        while(true) {
            delay(1000);
        }
    }   

    delay(50);
}
