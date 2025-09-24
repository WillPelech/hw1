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
//https://stackoverflow.com/questions/7416445/what-is-the-use-of-the-c-str-function this is a stack overflow article for the extra credit

//global variable
AppStatus gAppStatus     = RUNNING;
constexpr int   SCREEN_WIDTH  = 1600 / 2,
                SCREEN_HEIGHT = 900 / 2,
                FPS           = 60,
                SIZE          = 200,
                FRAME_LIMIT   = 100;
constexpr float MAX_AMP       = 10.0f;
std::string BG_COLOUR= "#000000";
constexpr Vector2 ORIGIN      = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
constexpr Vector2 BASE_SIZE   = { (float) SIZE, (float) SIZE };
constexpr float ORBIT_SPEED = 1;
// Global Variables
float     gScaleFactor   = SIZE,
          gAngle         = 0.0f,
          gPulseTime     = 0.0f,
          labubuAngle    = 0.0f;
Vector2   gPosition      = ORIGIN;
Vector2   gScale         = BASE_SIZE;
Vector2 louis_pos = ORIGIN;
Vector2 lab1_pos= ORIGIN;
Vector2 lab2_pos = ORIGIN;
float increment_lab2 = 1;
float amplitude_lab2= 50;
float lab2_phase=0;
//declarations
void initialise();
void update();
void render();
void shutdown();
void processInput() 
{
    if (WindowShouldClose()) gAppStatus = TERMINATED;
}

Texture2D louis;
Texture2D labubu1;
Texture2D labubu2;
void initialise(){
  InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Textures");
  louis = LoadTexture("assets/louis.jpg");
  labubu1 = LoadTexture("assets/Labubu1.png");
  labubu2=  LoadTexture("assets/labubu2.png");
  SetTargetFPS(FPS); 
};


void render() {
  BeginDrawing();
  ClearBackground(ColorFromHex(BG_COLOUR.c_str()));
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
  Rectangle lab1Text = {
    0.0f, 0.0f, (float)labubu1.width,(float)labubu1.height
  };
  Rectangle lab2Text = {
    0.0f, 0.0f, (float)labubu1.width,(float)labubu1.height
  };
  DrawTexturePro(louis,louisText,destinationArea,louis_pos,gAngle,WHITE);
  DrawTexturePro(labubu1,lab1Text,destinationArea,lab1_pos,gAngle,WHITE);
  DrawTexturePro(labubu2,lab2Text,destinationArea,lab2_pos,0,WHITE);
  EndDrawing();
}


void shutdown() { CloseWindow(); }

void update() {
  gAngle+=ORBIT_SPEED;
  louis_pos.x = 0.01*ORIGIN.x +0.01*cos(gAngle);
  louis_pos.y =  0.01*ORIGIN.y +0.01*sin(gAngle);
  
  
  float scale = 10;
  labubuAngle+=ORBIT_SPEED*0.05;
  lab1_pos.x = louis_pos.x +scale*(16*powf(sin(labubuAngle),3.0f));
  lab1_pos.y = louis_pos.y +scale*(13*cos(labubuAngle) - 5*cos(2*labubuAngle) - 2*cos(3*labubuAngle) - cos(4*labubuAngle)); 
   

  // the next pattern I want to be a simple harmonic oscillator where the background is determined by 
  //
  lab2_phase +=0.1f;
  lab2_pos.x += (lab2_pos.x > 400 || lab2_pos.x < -250) ? (increment_lab2 *= -1) : increment_lab2;
  lab2_pos.y = ORIGIN.y-100 + amplitude_lab2 * sin(lab2_phase);
  BG_COLOUR = (increment_lab2>0) ? std::string("#008000") : std::string("#000080");
}

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

// imageTexture *labubu1 = nullptr;
// imageTexture *labubu2 = nullptr;
