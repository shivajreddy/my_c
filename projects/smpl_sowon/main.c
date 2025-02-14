// -----------------------------------------------------------
// Count down timer with animated digits
// rebuild based on tsoding's sowon, but using raylib
// Author: smpl
// Date: 02-14-25
// -----------------------------------------------------------

// -----------------------------------------------------------
// Header Files
// -----------------------------------------------------------
#include <raylib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------
// Definitions
// -----------------------------------------------------------
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Global variables
// -----------------------------------------------------------
char WINDOW_TITLE[200];

// -----------------------------------------------------------

// -----------------------------------------------------------
// Program main entry point
// -----------------------------------------------------------
int main() {
  printf("SMPL-SOWON\n");

  // Initialization
  // ------------------------------------------------------------------┐
  strcpy(WINDOW_TITLE, "SOWON by smpl");
  printf("WINDOW_TITLE: %s\n", WINDOW_TITLE);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  // ------------------------------------------------------------------┘

  // Main game loop
  // ------------------------------------------------------------------┐
  while (!WindowShouldClose()) {
    ClearBackground(RAYWHITE);
    DrawText("Hello there", 190, 200, 20, RAYWHITE);
  }
  // ------------------------------------------------------------------┘

  // De-Initialization
  // ------------------------------------------------------------------
  CloseWindow();
  // ------------------------------------------------------------------

  return EXIT_SUCCESS;
}
