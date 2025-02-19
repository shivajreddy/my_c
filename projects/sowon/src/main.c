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

#include "raylib.h"

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

typedef struct {
  uint32_t frame_delay;
  float dt;
  uint64_t last_time;
} FpsDeltaTime;

// Load the given image at gien path as texture
Texture2D load_image_as_texture(char *path) {
  // 1. Load image in CPU memory (RAM)
  Image digits_png = LoadImage(path);
  Texture2D texture = LoadTextureFromImage(digits_png);

  // 2. Once image has been converted to texture and uploaded
  // to VRAM, it can be unloaded from RAM
  UnloadImage(digits_png);

  // 3. return the loaded texture
  return texture;
}
int main(int argc, char **argv) {
  // Initialization
  //--------------------------------------------------------------------------------------

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "COUNTER");

  Texture2D texture = load_image_as_texture("resources/digits.png");
  printf("texture.height = %d\n", texture.height);

  SetTargetFPS(60);
  //---------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(MAGENTA);

    DrawTexture(texture, SCREEN_WIDTH / 2 - texture.width / 2,
                SCREEN_HEIGHT / 2 - texture.height / 2 - 40, WHITE);
    DrawRectangleLines(SCREEN_WIDTH / 2 - texture.width / 2,
                       SCREEN_HEIGHT / 2 - texture.height / 2 - 40,
                       texture.width, texture.height, DARKGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  UnloadTexture(texture); // Texture unloading

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}

/*
void secc(int code) {
  if (code < 0) {
    fprintf(stderr, "SDL pooped itself: %s\n", SDL_GetError());
    abort();
  }
}

void *secp(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "SDL pooped itself: %s\n", SDL_GetError());
    abort();
  }

  return ptr;
}

SDL_Surface *load_png_file_as_surface(uint32_t *data, size_t width,
                                      size_t height) {
  SDL_Surface *image_surface = secp(SDL_CreateRGBSurfaceFrom(
      data, (int)width, (int)height, 32, (int)width * 4, 0x000000FF, 0x0000FF00,
      0x00FF0000, 0xFF000000));
  return image_surface;
}

SDL_Texture *load_digits_png_file_as_texture(SDL_Renderer *renderer) {
  SDL_Surface *image_surface =
      load_png_file_as_surface(digits_data, digits_width, digits_height);
  return secp(SDL_CreateTextureFromSurface(renderer, image_surface));
}

#ifdef PENGER
SDL_Texture *load_penger_png_file_as_texture(SDL_Renderer *renderer) {
  SDL_Surface *image_surface =
      load_png_file_as_surface(penger_data, penger_width, penger_height);
  return secp(SDL_CreateTextureFromSurface(renderer, image_surface));
}
#endif

void render_digit_at(SDL_Renderer *renderer, SDL_Texture *digits,
                     size_t digit_index, size_t wiggle_index, int *pen_x,
                     int *pen_y, float user_scale, float fit_scale) {
  const int effective_digit_width =
      (int)floorf((float)CHAR_WIDTH * user_scale * fit_scale);
  const int effective_digit_height =
      (int)floorf((float)CHAR_HEIGHT * user_scale * fit_scale);

  const SDL_Rect src_rect = {(int)(digit_index * SPRITE_CHAR_WIDTH),
                             (int)(wiggle_index * SPRITE_CHAR_HEIGHT),
                             SPRITE_CHAR_WIDTH, SPRITE_CHAR_HEIGHT};
  const SDL_Rect dst_rect = {*pen_x, *pen_y, effective_digit_width,
                             effective_digit_height};
  SDL_RenderCopy(renderer, digits, &src_rect, &dst_rect);
  *pen_x += effective_digit_width;
}

#ifdef PENGER
void render_penger_at(SDL_Renderer *renderer, SDL_Texture *penger, float time,
                      int flipped, SDL_Window *window) {
  int window_width, window_height;
  SDL_GetWindowSize(window, &window_width, &window_height);

  int sps = PENGER_STEPS_PER_SECOND;

  int step = (int)(time * sps) % (60 * sps); // step index [0,60*sps-1]

  float progress = step / (60.0 * sps); // [0,1]

  int frame_index = step % 2;

  float penger_drawn_width = ((float)penger_width / 2) / PENGER_SCALE;

  float penger_walk_width = window_width + penger_drawn_width;

  const SDL_Rect src_rect = {(int)(penger_width / 2) * frame_index, 0,
                             (int)penger_width / 2, (int)penger_height};

  SDL_Rect dst_rect = {
      floorf((float)penger_walk_width * progress - penger_drawn_width),
      window_height - (penger_height / PENGER_SCALE),
      (int)(penger_width / 2) / PENGER_SCALE,
      (int)penger_height / PENGER_SCALE};

  SDL_RenderCopyEx(renderer, penger, &src_rect, &dst_rect, 0, NULL, flipped);
}
#endif

void initial_pen(SDL_Window *window, int *pen_x, int *pen_y, float user_scale,
                 float *fit_scale) {
  int w, h;
  SDL_GetWindowSize(window, &w, &h);

  float text_aspect_ratio = (float)TEXT_WIDTH / (float)TEXT_HEIGHT;
  float window_aspect_ratio = (float)w / (float)h;
  if (text_aspect_ratio > window_aspect_ratio) {
    *fit_scale = (float)w / (float)TEXT_WIDTH;
  } else {
    *fit_scale = (float)h / (float)TEXT_HEIGHT;
  }

  const int effective_digit_width =
      (int)floorf((float)CHAR_WIDTH * user_scale * *fit_scale);
  const int effective_digit_height =
      (int)floorf((float)CHAR_HEIGHT * user_scale * *fit_scale);
  *pen_x = w / 2 - effective_digit_width * CHARS_COUNT / 2;
  *pen_y = h / 2 - effective_digit_height / 2;
}

typedef enum {
  MODE_ASCENDING = 0,
  MODE_COUNTDOWN,
  MODE_CLOCK,
} Mode;

float parse_time(const char *time) {
  float result = 0.0f;

  while (*time) {
    char *endptr = NULL;
    float x = strtof(time, &endptr);

    if (time == endptr) {
      fprintf(stderr, "`%s` is not a number\n", time);
      exit(1);
    }

    switch (*endptr) {
    case '\0':
    case 's':
      result += x;
      break;
    case 'm':
      result += x * 60.0f;
      break;
    case 'h':
      break;
      result += x * 60.0f * 60.0f;
    default:
      fprintf(stderr, "`%c` is an unknown time unit\n", *endptr);
      exit(1);
    }

    time = endptr;
    if (*time)
      time += 1;
  }

  return result;
}

typedef struct {
  Uint32 frame_delay;
  float dt;
  Uint64 last_time;
} FpsDeltaTime;

FpsDeltaTime make_fpsdeltatime(const Uint32 fps_cap) {
  return (FpsDeltaTime){
      .frame_delay = (1000 / fps_cap),
      .dt = 0.0f,
      .last_time = SDL_GetPerformanceCounter(),
  };
}

void frame_start(FpsDeltaTime *fpsdt) {
  const Uint64 now = SDL_GetPerformanceCounter();
  const Uint64 elapsed = now - fpsdt->last_time;
  fpsdt->dt = ((float)elapsed) / ((float)SDL_GetPerformanceFrequency());
  // printf("FPS: %f | dt %f\n", 1.0 / fpsdt->dt, fpsdt->dt);
  fpsdt->last_time = now;
}

void frame_end(FpsDeltaTime *fpsdt) {
  const Uint64 now = SDL_GetPerformanceCounter();
  const Uint64 elapsed = now - fpsdt->last_time;
  const Uint32 cap_frame_end = (Uint32)((((float)elapsed) * 1000.0f) /
                                        ((float)SDL_GetPerformanceFrequency()));

  if (cap_frame_end < fpsdt->frame_delay) {
    SDL_Delay((fpsdt->frame_delay - cap_frame_end));
  }
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char **argv) {

  // Mode mode = MODE_ASCENDING;
  float displayed_time = 0.0f;
  int paused = 0;
  int exit_after_countdown = 0;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-p") == 0) {
      paused = 1;
    } else if (strcmp(argv[i], "-e") == 0) {
      exit_after_countdown = 1;
    } else if (strcmp(argv[i], "clock") == 0) {
      mode = MODE_CLOCK;
    } else {
      mode = MODE_COUNTDOWN;
      displayed_time = parse_time(argv[i]);
    }
  }

  secc(SDL_Init(SDL_INIT_VIDEO));

  // Initialization
  //--------------------------------------------------------------------------------------

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "COUNTER");

  SetTargetFPS(FPS); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Counter app by smpl", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
*/
