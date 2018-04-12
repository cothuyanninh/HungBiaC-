
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "Common_Function.h"
#include "BaseObject.h"
#include <vector>

#define WIDTH_MAIN_OBJECT 60
#define HEIGHT_MAIN_OBJECT 30

class MainObject : public BaseObject
{
public:
  MainObject();
  ~MainObject();

  void HandleInputAction(SDL_Event events);
  void HandleMove();

private:
  int x_val_;
  int y_val_;


};



#endif //MAIN_OBJECT_H_