// -----------------------------------------------------------------------------------------
// Countdown Animation
// - Inspired from sowon(https://github.com/tsoding/sowon) by
//   tsoding(https://www.twitch.tv/tsoding)
// - Dependencies: raylib(v5.5) (but is included as static library)
// - Author: smpl
// - Date: Feb-18-2025
// -----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
// Program Header Files
//------------------------------------------------------------------------------------------
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #include "raylib.h"
#include "../include/raylib.h"

//------------------------------------------------------------------------------------------
// Program Definitions
//------------------------------------------------------------------------------------------
#define FPS 60
#define SPRITE_CHAR_WIDTH (300 / 2)
#define SPRITE_CHAR_HEIGHT (380 / 2)
#define CHAR_WIDTH (300 / 2)
#define CHAR_HEIGHT (380 / 2)
#define CHARS_COUNT 8
#define TEXT_WIDTH (CHAR_WIDTH * CHARS_COUNT)
#define TEXT_HEIGHT (CHAR_HEIGHT)
#define WIGGLE_COUNT 3
#define WIGGLE_DURATION (0.40f / WIGGLE_COUNT)
#define COLON_INDEX 10
#define MAIN_COLOR_R 220
#define MAIN_COLOR_G 220
#define MAIN_COLOR_B 220
#define PAUSE_COLOR_R 220
#define PAUSE_COLOR_G 120
#define PAUSE_COLOR_B 120
#define BACKGROUND_COLOR_R 24
#define BACKGROUND_COLOR_G 24
#define BACKGROUND_COLOR_B 24
#define SCALE_FACTOR 0.15f
#define PENGER_SCALE 4
#define PENGER_STEPS_PER_SECOND 3
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE_CAP 256

//------------------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------------------
Texture2D digits;

// Handle Program Initialization
void initialize_program() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "COUNTER");
  digits = LoadTexture("resources/digits.png");
  SetTargetFPS(60);
}

// Handle Program De-Initialization
void clean_up_program() {
  UnloadTexture(digits);
  CloseWindow();
}

void draw_digit(int num, int variation, float x, float y) {
  float width = (float)digits.width / 11;
  float height = (float)digits.height / 3;

  int start_x = num * width;
  int start_y = variation * height;

  // crop the texture (crop from (0,0) with W*H size)
  Rectangle source_rec = {start_x, start_y, width, height};
  // Define where to draw the cropped texture
  Rectangle dest_rec = {x, y, width, height};
  // center origin
  Vector2 origin = {0, 0};

  DrawTexturePro(digits, source_rec, dest_rec, origin, 0, WHITE);
}

int main(int argc, char **argv) {
  // Initialization
  initialize_program();

  int variation = 0;        // current variation (0, 1, 2)
  float change_time = 0.25; // in seconds
  double last_updated_time = GetTime();

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // update animation variation
    double current_time = GetTime();
    if (current_time - last_updated_time >= change_time) {
      variation = (variation + 1) % 3; // cycle through 0, 1, 2
      last_updated_time = current_time;
    }

    BeginDrawing();
    ClearBackground(MAROON);
    draw_digit(2, variation + 2, 350, 200);

    EndDrawing();
  }

  // De-Initialization
  clean_up_program();

  return 0;
}
