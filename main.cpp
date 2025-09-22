#include "CS3113/cs3113.h"
#include "string.h"
/**
 * Author:
 * Assignment: Simple 2D Scene
 * Date due: 2025-09-27, 11:59pm
 * I pledge that I have completed this assignment without
 * collaborating with anyone else, in conformance with the
 * NYU School of Engineering Policies and Procedures on
 * Academic Misconduct.
 **/
//global variables
constexpr int   SCREEN_WIDTH  = 1600 / 2,
                SCREEN_HEIGHT = 900 / 2,
                FPS           = 60,
                SIZE          = 200,
                FRAME_LIMIT   = 100;
constexpr float MAX_AMP       = 10.0f;

//declarations
void initialise();
void processInput();
void update();
void render();
void shutdown();

void initialise(){
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT)
}
class imageTexture {
public:
  imageTexture(string url, vector) {}
};

int render() {
  BeginDrawing();
  ClearBackground(ColorFromHex(BG_COLOUR));

  DrawTexturePro(gTexture, textureArea, destinationArea, objectOrigin, gAngle,
                 WHITE);

  EndDrawing();
}
int update() {}
int main(void) {}
