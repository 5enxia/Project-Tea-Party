#pragma once

// DataList
// Sequence No.	0
// W			1
// AS			2
// AATL			3
// Wx			4
// Wy			5
// Wz			6
// STL1			7
// STL2			8
// STL3			9
// time			10


struct vec3 {
	double x, y, z;
};

class Data
{
private:
	float W;
	float as, aatl;
	vec3 w, stl;
	unsigned int time;

public:
	Data() {
		this->W = 0;
		this->aatl = this->as = 0;
		this->w = this->stl = { 0,0,0 };
		this->time = 0;
	};

	~Data() {
	};

	//---------------------------setter-----------------------------------//
	void setW(float W) {
		this->W = W;
	}
	void setVecW(float wx, float wy, float wz) {
		this->w.x = wx;
		this->w.y = wy;
		this->w.z = wz;
	}
	void setAS(float as) {
		this->as = as;
	}
	void setAATL(float aatl) {
		this->aatl = aatl;
	}
	void setSTL(float stlx, float stly, float stlz) {
		this->stl.x = stlx;
		this->stl.y = stly;
		this->stl.z = stlz;
	}
	void setTime(unsigned int time) {
		this->time = time;
	}
	//--------------------------------------------------------------------//
	//---------------------------getter-----------------------------------//
	float getW() {
		return this->W;
	}
	vec3 getVecW() {
		return this->w;
	}
	float getAS() {
		return this->as;
	}
	float getAATL() {
		return this->aatl;
	};
	vec3 getSTL() {
		return this->stl;
	}
	float getTime() {
		return this->time;
	};
	//--------------------------------------------------------------------//
};