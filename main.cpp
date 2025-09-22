#include "CS3113/cs3113.h"
#include <string>
using namespace std;
/**
 * Author:
 * Assignment: Simple 2D Scene
 * Date due: 2025-09-27, 11:59pm
 * I pledge that I have completed this assignment without
 * collaborating with anyone else, in conformance with the
 * NYU School of Engineering Policies and Procedures on
 * Academic Misconduct.
 **/
//global variable
AppStatus gAppStatus     = RUNNING;
constexpr int   SCREEN_WIDTH  = 1600 / 2,
                SCREEN_HEIGHT = 900 / 2,
                FPS           = 60,
                SIZE          = 200,
                FRAME_LIMIT   = 100;
constexpr float MAX_AMP       = 10.0f;
constexpr char    BG_COLOUR[] = "#000000";
constexpr Vector2 ORIGIN      = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
constexpr Vector2 BASE_SIZE   = { (float) SIZE, (float) SIZE };
// Global Variables
float     gScaleFactor   = SIZE,
          gAngle         = 0.0f,
          gPulseTime     = 0.0f;
Vector2   gPosition      = ORIGIN;
Vector2   gScale         = BASE_SIZE;
//declarations
void initialise();
void update();
void render();
void shutdown();
void processInput() 
{
    if (WindowShouldClose()) gAppStatus = TERMINATED;
}

// class imageTexture {
// public:
//   Texture2D gTexture;
//   Rectangle textArea; 
//   //first we want to convert string into gtexture
//   imageTexture(string url):gTexture(LoadTexture(url.c_str()))
//    { 
//     textArea.x= 0.0f;
//     textArea.y=0.0f;
//     textArea.width=(float)gTexture.width;
//     textArea.height= (float)gTexture.height;
//   };
 
// };

Texture2D louis;
Texture2D labubu1;
Texture2D labubu2;
// imageTexture *labubu1 = nullptr;
// imageTexture *labubu2 = nullptr;
void initialise(){
  InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Textures");
  louis = LoadTexture("assets/louis.jpg");
  labubu1 = LoadTexture("assets/Labubu1.png");
  labubu2=  LoadTexture("assets/labubu2.png");
  SetTargetFPS(FPS); 
};


void render() {
  BeginDrawing();
  ClearBackground(ColorFromHex(BG_COLOUR));
  Rectangle destinationArea = {
        gPosition.x,
        gPosition.y,
        static_cast<float>(gScale.x),
        static_cast<float>(gScale.y)
  };

    // Origin inside the source texture (centre of the texture)

  Vector2 objectOrigin = {
        static_cast<float>(gScale.x) / 2.0f,
        static_cast<float>(gScale.y) / 2.0f
  };
  Rectangle louisText = {
    0.0f, 0.0f, (float)louis.width,(float)louis.height
  };
  DrawTexturePro(louis,louisText,destinationArea, objectOrigin,gAngle,WHITE);

  EndDrawing();
}


void shutdown() { CloseWindow(); }

void update() {}

int main(void) {
  initialise();
  while (gAppStatus == RUNNING){
    processInput();
    update();
    render();
  }
  shutdown();
  return 0;

}
