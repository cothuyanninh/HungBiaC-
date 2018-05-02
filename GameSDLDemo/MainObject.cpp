
#include "MainObject.h"

MainObject::MainObject()
{
  rect_.x = 0;
  rect_.y = 0;
  rect_.w = WIDTH_MAIN_OBJECT;
  rect_.h = HEIGHT_MAIN_OBJECT;
  x_val_ = 0;
  y_val_ = 0;
}

MainObject::~MainObject()
{

}

void MainObject::HandleInputAction(SDL_Event events)
{
  if (events.type == SDL_KEYDOWN)
  {
    switch (events.key.keysym.sym)
    {
    case SDLK_RIGHT:
      x_val_ += WIDTH_MAIN_OBJECT/8;
      //Todo
      break;
    case SDLK_LEFT:
      x_val_ -= WIDTH_MAIN_OBJECT/8;
      break;;
    default:
      break;
    }
  }
  else if (events.type == SDL_KEYUP)
  {
    switch(events.key.keysym.sym )
    {
      case SDLK_LEFT: x_val_ += WIDTH_MAIN_OBJECT/8; break;
      case SDLK_RIGHT: x_val_ -= WIDTH_MAIN_OBJECT/8; break;
    }
  }

  else
  {
    ;//
  }
}

void MainObject::HandleMove()
{
  rect_.x += x_val_;

  if (rect_.x < BODER_LIMIT || rect_.x  > SCREEN_WIDTH*0.5)
  {
    rect_.x -= x_val_;
  }

}