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

// #include "raylib.h"
#include "../include/raylib.h"

//------------------------------------------------------------------------------------------
// Program Definitions
//------------------------------------------------------------------------------------------
#define SCREEN_WIDTH 1300
#define SCREEN_HEIGHT 400
#define WINDOW_TITLE ""
#define FPS 60
#define TITLE_CAP 256

//------------------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------------------
Texture2D digits;
char hh, mm, ss;
char variations[8] = {0, 1, 2, 3, 0, 0, 0, 1};

// Handle Program Initialization
void initialize_program() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  digits = LoadTexture("resources/digits.png");
  SetTargetFPS(FPS);
}

// Handle Program De-Initialization
void clean_up_program() {
  UnloadTexture(digits);
  CloseWindow();
}

/*
symbol_idx : 0 1 2 3 4 5 6 7 8 9 10
symbol:      0 1 2 3 4 5 6 7 8 9 :
*/
void draw_symbol(char symbol_idx, char variation, float pos_x, float pos_y) {
  float width = (float)digits.width / 11;
  float height = (float)digits.height / 3;

  int start_x = symbol_idx * width;
  int start_y = variation * height;

  // crop the texture (crop from (0,0) with W*H size)
  Rectangle source_rec = {start_x, start_y, width, height};
  // Define where to draw the cropped texture
  Rectangle dest_rec = {pos_x, pos_y, width, height};
  // center origin
  Vector2 origin = {0, 0};

  DrawTexturePro(digits, source_rec, dest_rec, origin, 0, WHITE);
}

// clock is in the format HH MM SS
void draw_clock() {
  char temp_hh = hh, temp_mm = mm, temp_ss = ss;

  // create & set the buffer using hh,mm,ss
  char counter_clock[6];
  // set hours
  counter_clock[1] = temp_hh % 10;
  temp_hh /= 10;
  counter_clock[0] = temp_hh % 10;

  // set minutes
  counter_clock[3] = temp_mm % 10;
  temp_mm /= 10;
  counter_clock[2] = temp_mm % 10;

  // set seconds
  counter_clock[5] = temp_ss % 10;
  temp_ss /= 10;
  counter_clock[4] = temp_ss % 10;

  int symbol_width = (int)(digits.width / 11);

  // Draw Hours
  draw_symbol(counter_clock[0], variations[0], symbol_width * 0, 120);
  draw_symbol(counter_clock[1], variations[1], symbol_width * 1, 120);
  draw_symbol(10, variations[2], symbol_width * 2, 120);
  // Draw Minutes
  draw_symbol(counter_clock[2], variations[3], symbol_width * 3, 120);
  draw_symbol(counter_clock[3], variations[4], symbol_width * 4, 120);
  draw_symbol(10, variations[5], symbol_width * 5, 120);
  // Draw Seconds
  draw_symbol(counter_clock[4], variations[6], symbol_width * 6, 120);
  draw_symbol(counter_clock[5], variations[7], symbol_width * 7, 120);
}

// update counter time
int update_counter_time() {
  ss--;
  if (ss < 0) {
    ss = 59;
    mm--;
  }
  if (mm < 0) {
    mm = 59;
    hh--;
  }
  if (hh < 0) {
    clean_up_program();
    return -1;
  }
  return 1;
}

int main(int argc, char **argv) {
  // Initialization
  initialize_program();

  double last_updated_time_of_variations = GetTime();
  double last_updated_time_of_clock = GetTime();

  // Parse user input
  if (argc == 1) {
    // No args → default to 10 minutes
    hh = 0;
    mm = 10;
    ss = 0;
    printf("No arguments provided. Defaulting to 10 minutes.\n");
  } else if (argc == 2) {
    // 1 arg → seconds
    hh = 0;
    mm = 0;
    ss = atoi(argv[1]);
    printf("Timer set to %d seconds.\n", ss);
  } else if (argc == 3) {
    // 2 args → minutes + seconds
    hh = 0;
    mm = atoi(argv[1]);
    ss = atoi(argv[2]);
    printf("Timer set to %d minutes %d seconds.\n", mm, ss);
  } else if (argc >= 4) {
    // 3 args → hours + minutes + seconds
    hh = atoi(argv[1]);
    mm = atoi(argv[2]);
    ss = atoi(argv[3]);
    printf("Timer set to %d hours %d minutes %d seconds.\n", hh, mm, ss);
  }

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    double current_time = GetTime();

    // update variations of symbols for every 0.25 second
    if (current_time - last_updated_time_of_variations >= 0.25) {
      // update all variations
      for (int i = 0; i < 8; i++) {
        // cycle through 0, 1, 2
        variations[i] = (char)(((int)variations[i] + 1) % 3);
      }
      last_updated_time_of_variations = current_time;
    }

    // update clock-time every 1 second
    if (current_time - last_updated_time_of_clock >= 1.0) {
      if (update_counter_time() == -1) {
        CloseWindow();
        break;
      }
      last_updated_time_of_clock = current_time;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    draw_clock();

    EndDrawing();
  }

  // De-Initialization
  clean_up_program();

  return 0;
}
