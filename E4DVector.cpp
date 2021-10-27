/*
 *
 * Evo 4D Math Engine
 * E4DVector.cpp
 * Author	Daniel Rill
 * Date		10.05.2021
 * Version	1.0
 *
 */

#include "E4DVector.h"
 
namespace E4DEngine {


//Konstruktor
//#pragma mark-constructors		
	
	E4DVector::E4DVector(): x(0.0), y(0.0), z(0.0){}
	
	E4DVector::E4DVector(float uX, float uY, float uZ): x(uX), y(uY), z(uZ){}
	
//Destruktor
//#pragma mark-destructors

	E4DVector::~E4DVector() {}
	
//Copy-Konstruktor
//#pragma mark-copy constructor

	E4DVector::E4DVector(const E4DVector& v): x(v.x), y(v.y), z(v.z) {}
	
	E4DVector& E4DVector::operator=(const E4DVector& v) {
	
		x=v.x;
		y=v.y;
		z=v.z;
		
		return *this;
		
	} 

//#pragma mark-add

	void E4DVector::operator+=(const E4DVector& v) {
	
		x+=v.x;
		y+=v.y;
		z+=v.z;
		
	}
	
	E4DVector E4DVector::operator+(const E4DVector& v)const {
	
		return E4DVector(x+v.x, y+v.y, z+v.z);
		
	}
	
//#pragma mark-subtract

	void E4DVector::operator-=(const E4DVector& v) {
	
		x-=v.x;
		y-=v.y;
		z-=v.z;
		
	}
	
	E4DVector E4DVector::operator-(const E4DVector& v)const {
	
		return E4DVector(x-v.x, y-v.y, z-v.z);
	}

//#pragma mark-multiply

	void E4DVector::operator*=(const float s) {
	
		x*=s;
		y*=s;
		z*=s;
		
	}
	
	E4DVector E4DVector::operator*(const float s) const {
		
		return E4DVector(x*s, y*s, z*s);
	}

//#pragma mark-division

	void E4DVector::operator/=(const float s) {

		x/=s;
		y/=s;
		z/=s;

	}

	E4DVector E4DVector::operator/(const float s) const {

		return E4DVector(x/s, y/s, z/s);
	}
}
