
#ifndef THREATES_OBJECT_H
#define THREATES_OBJECT_H

#include "Common_Function.h"
#include "BaseObject.h"

#define WIDTH_THREAT 30
#define HEIGHT_THREAT 60
#define SPACE_BODY_HEIGHT 700
#define SPACE_BODY_WEIGHT 90
class ThreatObject : public BaseObject{
public:
	int SCORE ;

	ThreatObject();
	~ThreatObject();

	void HandleMove(const int& x_border, const int& y_border);
	void set_x_val(const int& val) {x_val_ = val;}
	void set_y_val(const int& val) {y_val_ = val;}
	int get_x_val() const {return x_val_;}
	int get_y_val() const {return y_val_;}
private:
	int x_val_;
	int y_val_;
};

#endif