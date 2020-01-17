#pragma once
#include <cmath>
#include <string>
#include "MyCSV.h"

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
	float mid;
	float max;
};

struct results {
	stls stl;
	float as;
	unsigned int elegance;
	unsigned int learning;
};



class Evaluation
{
public:
	static int subjects;

private:

	unsigned int id;
	unsigned int count;

	stls stl;
	float as;
	unsigned int elegance;
	unsigned int learning;

	results first;
	results second;
	

public:
	Evaluation() {
		_getsubjects("src/data/subjects.txt");
		count = 0;
		stl = { 0,0,0 };
		as = elegance = learning = 0;
		first = second = { {0,0,0},0,0,0 };
	};
	~Evaluation() {};

	// setter(update, save)
	void increaseCount() {
		this->count++;
	};
	void updateAS(float as);
	void updateSTL(float stl);
	void setResults();
	void saveResults();

	// getter
	int getID() {
		return id;
	}
	static int getSubjects() {
		return Evaluation::subjects;
	}
	unsigned int getCount() { 
		return count;
	};
	float getSTL() {
		return (stl.max - stl.mid);
	};
	float getAS() {
		return as;
	};
	int getEleganceInt() {
		return elegance;
	}
	int getLearningInt() {
		return learning;
	}
	string getEleganceStr() {
		return evaluateElegance();
	};
	string getLearningStr() {
		return evaluateLearning();
	};


	// util
	vector <string> conv2csv() {
		vector <string> row;
		row.push_back(to_string(id));
		_setresult(row, first);
		_setresult(row, second);
		return row;
	}
	void retry() {
		count = 0;
		reset();
	}

private:
	string evaluateElegance();
	string evaluateLearning();
	bool linersolver(float x);
	bool ellipsesolver(float x, float y);
	void reset();

	void _getsubjects(string fn) {
		fstream fs(fn);
		string line;
		getline(fs, line);
		subjects = stoi(line);
		id = subjects;
		subjects++;
		fs.seekp(ios::beg);
		fs << to_string(subjects) << endl;
		fs.close();
	}

	void _setresult(vector<string>& row, results res) {
		row.push_back(to_string(res.stl.min));
		row.push_back(to_string(res.stl.mid));
		row.push_back(to_string(res.stl.max));
		row.push_back(to_string(res.as));
		row.push_back(to_string(res.elegance));
		row.push_back(to_string(res.learning));
	}
};
int Evaluation::subjects;


// update variable
void  Evaluation::updateSTL(float stl) {
	if (stl < this->stl.min) this->stl.min = stl;
	if (this->stl.max < stl) this->stl.max = stl;
	this->stl.mid = (this->stl.max + this->stl.min)/2;
}

void Evaluation::updateAS(float as)
{
	this->as += as;
}


// data storing
inline void Evaluation::setResults()
{
	if (getCount() == 0) {
		first.as = as;
		first.stl = stl;
		first.elegance = elegance;
		first.learning = learning;
	}
	else
	{
		second.as = as;
		second.stl = stl;
		second.elegance = elegance;
		second.learning = learning;
	}
	reset();
}

void Evaluation::saveResults() {

	CSV csv;
	vector <vector<string>> cells;
	vector <string> row = { to_string(id) };
	_setresult(row, first);
	_setresult(row, second);
	cells.push_back(row);
	csv.setCells(cells);
	csv.write("src/data/results.txt");
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

	// y Ç™ËáílÇÊÇËè¨Ç≥Ç¢Ç∆Ç´Ç…trueÇï‘Ç∑
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

	// â~ÇÃì‡ë§Ç…ë∂ç›Ç∑ÇÈÇ∆Ç´Ç…trueÇï‘Ç∑
	if (val.r < center.r) return true;
	else return false;
}