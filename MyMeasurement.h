#include <cmath>

struct results
{
	float as;
	float tilt;
};

struct tilts
{
	float min;
	float middle;
	float max;
};

class Measurement
{
public:
	Measurement() {};
	~Measurement() {};

	float getAS();
	float getTilt();

	void calcAS(float as);
	void calcTilt(float tilt);

private:
	results old_result;
	results new_result;
	tilts old_tilt;
	tilts new_tilt;
};

void Measurement::calcAS(float as) {
	new_result.as = old_result.as + as;
}

void  Measurement::calcTilt(float tilt) {
	if (tilt < old_tilt.min) new_tilt.min = tilt;
	if (old_tilt.max < tilt) new_tilt.max = tilt;
	new_tilt.middle = new_tilt.max - new_tilt.min;

	new_result.tilt = fabsf(new_tilt.max - new_tilt.middle);
}

 float Measurement::getAS() {
	 return this->new_result.as;
}

 float Measurement::getTilt() {
	 return this->new_result.tilt;
 }