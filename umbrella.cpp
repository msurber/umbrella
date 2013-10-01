#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "umbrella_schirm.cpp"
#include "umbrella_sun.cpp"

#include <wiringPi.h>
#include <oledDirect.h>

// The Arduino Shield from ILSoft uses pins 8, 9 and 7 for CS, DC and Reset.
#define CS      10
#define DC      6
#define RESET   5
#define SPEED 16500000
//#define SPEED   1000000
// Create a variable to hold our OLED class.
SSD1351 *oled;

void drawHeart() {
        Point points[16] = { Point(2, 36), Point(9, 16), Point(19, 6), Point(38, 1),
                            Point(56,6) , Point(66,16), Point(75,6) , Point(93,1),
                            Point(111,6), Point(119,16),Point(125,36),Point(119,65),
                            Point(99,94), Point(66,122),Point(32,94), Point(10,66) };
        oled->drawPolygon(points, 16, Colour::Red);

}

void drawUmbrellaImage() {
        for (int x = 0; x < 128 ; x++) {
                for (int y = 0; y < 128 ; y++) {
                        const unsigned char* rgb = umbrella.pixel_data+(umbrella.width*y+x)*umbrella.bytes_per_pixel;
                        oled->drawPixel(x,y,Colour(rgb[0],rgb[1],rgb[2]));
                }
        }
}

void drawSunImage() {
        for (int x = 0; x < 128 ; x++) {
                for (int y = 0; y < 128 ; y++) {
                        const unsigned char* rgb = sun.pixel_data+(sun.width*y+x)*sun.bytes_per_pixel;
                        oled->drawPixel(x,y,Colour(rgb[0],rgb[1],rgb[2]));
                }
        }
}


void drawUmbrella() {
        oled->drawCircle(Circle(64, 64, 63), Colour::Red);
        oled->fillRect(Rectangle(0, 0, 128, 72), Colour::Black);
        Point points[17] = {    
                                Point(0,72),
                                Point(8,64),
                                Point(16,72),
                                Point(24,64),
                                Point(32,72),
                                Point(40,64),
                                Point(48,72),
                                Point(56,64),
                                Point(64,72),
                                Point(72,64),
                                Point(80,72),
                                Point(88,64),
                                Point(96,72),
                                Point(104,64),
                                Point(112,72),
                                Point(120,64),
                                Point(127,72)
                           };
        oled->drawPolygon(points, 17, Colour::Red);
        oled->drawCircle(Circle(54, 10, 10), Colour::Red);
        oled->fillRect(Rectangle(44, 10, 20, 11), Colour::Black);
        oled->drawLine(Point(64, 10), Point(64, 72), Colour::Red);
}

void drawSun() {
        oled->drawCircle(Circle(64, 64, 20), Colour::Yellow);
        oled->drawLine(Point(35,64),Point(20,64),Colour::Yellow); // r
        oled->drawLine(Point(95,64),Point(110,64),Colour::Yellow); // l
        oled->drawLine(Point(44,44),Point(31,31),Colour::Yellow); // ur
        oled->drawLine(Point(64,20),Point(64,35),Colour::Yellow); // u
        oled->drawLine(Point(84,44),Point(97,31),Colour::Yellow); // ul
        oled->drawLine(Point(84,84),Point(97,97),Colour::Yellow); // ol
        oled->drawLine(Point(43,83),Point(30,96),Colour::Yellow); // or
        oled->drawLine(Point(64,108),Point(64,93),Colour::Yellow); // o
}

int main (int argc, char **argv) {

        int cflag = 0;
        int dflag = 0;
        int c;
        while ((c = getopt (argc, argv, "cd")) != -1)
        switch (c)
                {
                case 'c':
                        cflag = 1;
                case 'd':
                        dflag = 1;
                break;
        }

        wiringPiSetup () ;
        pinMode (18, OUTPUT) ; // reset

        digitalWrite (18,  LOW) ;
        delay (500) ;
        digitalWrite (18,  HIGH);
        delay (500) ;

        oled = new SSD1351(CHANNEL, CS, DC, RESET, SPEED);

        // Clear the screen.
        oled->clearScreen(Colour::Black);
        
        // drawHeart();
        if (cflag == 1) {
                //drawUmbrella();
                drawUmbrellaImage();
        } else {
                //drawSun();
                drawSunImage();
        }

        if (dflag == 1 ) {
                drawUmbrellaImage();
        }
}