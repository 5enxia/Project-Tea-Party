#pragma once
#include <cmath>
#include <string>

using namespace std;

enum
{
	NOT_LEARNED = 1,	// 1
	LEARNED			// 2
};

enum
{
	NOT_ELEGANT = 1,	// 1
	COMMON,			// 2
	ELEGANT			// 3
};

struct stls
{
	float min;
	float middle;
	float max;
};

struct results {
	float as;
	stls stl;
	unsigned int elegance;
	unsigned int learning;
};



class Evaluation
{
public:
	static unsigned int subjects;
	static unsigned int getSubjects();

private:
	unsigned int count;

	stls stl;
	float as;
	unsigned int elegance;
	unsigned int learning;

	results first_result;
	results second_result;

public:
	Evaluation() {
		subjects++;
		count = 0;
		stl = { 0,0,0 };
		as = 0;
		elegance = 0;
		learning = 0;
		first_result = { as, stl, elegance, learning};
		second_result = { as, stl, elegance, learning};
	};
	~Evaluation() {};

	// setter(update, save)
	void updateAS(float as);
	void updateSTL(float stl);
	void saveResults();

	// getter
	unsigned int getCount() { 
		return count;
	};
	float getSTL() {
		return (stl.max - stl.middle);
	};
	float getAS() {
		return as;
	};
	string getElegance() {
		return evaluateElegance();
	};
	string getLearning() {
		return evaluateLearning();
	};


private:
	void updateCount();
	string evaluateElegance();
	string evaluateLearning();
	bool linersolver(float x);
	bool ellipsesolver(float x, float y);
	void reset();
};

unsigned int Evaluation::subjects;
inline unsigned int Evaluation::getSubjects()
{
	return subjects;
}

// update variable
void Evaluation::updateCount()
{
	if (count == 0) count = 1;
	else count = 0;
}

void  Evaluation::updateSTL(float stl) {
	if (stl < this->stl.min) this->stl.min = stl;
	if (this->stl.max < stl) this->stl.max = stl;
	this->stl.middle = (this->stl.max + this->stl.min)/2;
}

void Evaluation::updateAS(float as)
{
	this->as += as;
}


// data storing
inline void Evaluation::saveResults()
{
	if (getCount() == 0) {
		first_result.as = as;
		first_result.stl = stl;
		first_result.elegance = elegance;
		first_result.learning = learning;
	}
	else
	{
		second_result.as = as;
		second_result.stl = stl;
		second_result.elegance = elegance;
		second_result.learning = learning;
	}
	updateCount();
	reset();
}

inline void Evaluation::reset()
{
	as = 0;
	stl = { 0,0,0 };
	elegance = 0;
	learning = 0;
}




// evaluate function
string Evaluation::evaluateElegance()
{
	if (true) {
		elegance = ELEGANT;
		return "ELEGANT";
	}
	else if(true){
		elegance = COMMON;
		return "COMMON";
	}
	else {
		elegance = NOT_ELEGANT;
		return "NOT ELEGANT";
	}
}

string Evaluation::evaluateLearning()
{
	if (true) {
		learning = LEARNED;
		return "LEARNED";
	}
	else {
		learning = NOT_LEARNED;
		return "NOT LEARNED";
	}
}

// solver fucntion
bool Evaluation::linersolver(float x) {
	float a, b;
	a = 0;
	b = 0;
	float threshold = 0;
	float y = a * x + b;
	if (y < threshold) return true;
	else return false;
}

bool Evaluation::ellipsesolver(float x, float y) {
	struct circle
	{
		float x = 0;
		float y = 0;
		float r = 0;
	};

	circle center, val;
	center = { 0,0,1 };
	val = { x,y,0 };
	val.r = sqrtf(powf(val.x - center.x, 2) + powf(val.y - center.y, 2));
	if (val.r < center.r) return true;
	else return false;
}