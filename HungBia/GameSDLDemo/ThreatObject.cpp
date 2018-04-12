#include"ThreatObject.h"

ThreatObject::ThreatObject(){
	rect_.x = SCREEN_WIDTH;
	rect_.y = 0;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;

	x_val_ =0;
	y_val_ =0;
}

ThreatObject::~ThreatObject(){

}

void ThreatObject::HandleMove(const int& x_border, const int& y_border){
	rect_.y += y_val_;
	if (rect_.y > SCREEN_HEIGHT-50){
		rect_.y = 0;
		int rand_x = rand()%450;
		if(rand_x < SCREEN_WIDTH -700){
			rand_x = SCREEN_WIDTH*0.3;
		}
		rect_.x = rand_x;
	}
}

void ThreatObject::HandleInputAction(SDL_Event events){

}