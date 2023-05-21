//---------------------------------------------------------
/**
//    @file		isoTriangle.cpp
//    @brief	Implementation file for class isoTriangle
//    @author	Nicolo' Busi S52DEFAULT_VALUE9833
*/
//---------------------------------------------------------


#include "isoTriangle.h"


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

constexpr auto DEFAULT_VALUE = 0;;
constexpr auto SQUARE = 2;;
constexpr auto DOUBLE = 2;;
constexpr auto HALF = 0.5;;

//////////////////////////////////////////////////////////////////////////////
// fpi
// memory debug, place after includes

#ifdef DBGMEM_CRT
#undef new
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif // DBGMEM_CRT


/************************** GLOBAL FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Print operator
ostream& operator << (ostream& o, isoTriangle& X)
{

	return o;
}

///////////////////////////////////////////////////////////////////////////
// Input operator
istream& operator >> (istream& i, isoTriangle& X)
{

	return i;
}

/************************** MEMBER FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Default Constructor

/// @brief default constructor 
isoTriangle::isoTriangle()
{
	cout << "isoTriangle - Constructor - Default" << endl << endl;
	Init();

}

///////////////////////////////////////////////////////////////////////////
// Constructor

/// @brief constructor which also check if the value entered is >= DEFAULT_VALUE
/// @param b base of the isoTriangle
/// @param h height of the isoTriangle
isoTriangle::isoTriangle(float b, float h) {

	base = DEFAULT_VALUE;
	height = DEFAULT_VALUE;

	cout << "isoTriangle - Constructor" << endl<<endl;

	if (b < DEFAULT_VALUE)
		ErrorMessage("WARNING: isoTriangle - Constructor : base should be > 0");
	else
		base = b;

	if (h < DEFAULT_VALUE)
		ErrorMessage("WARNING: isoTriangle - Constructor : height should be > 0");
	else
		height = h;

}


///////////////////////////////////////////////////////////////////////////
// Copy Constructor

/// @brief copy constructor 
/// @param reference to the object that should be copied 
isoTriangle::isoTriangle(isoTriangle& X)
{
	cout << "isoTriangle - Copy Constructor" << endl<<endl;
	Init(X);
}

///////////////////////////////////////////////////////////////////////////
// Destructor

/// @brief destructor 
isoTriangle::~isoTriangle()
{
	cout << "isoTriangle - Destructor" << endl;
	Reset();
}

///////////////////////////////////////////////////////////////////////////
// Init default initializer

/// @brief init default initializer of the object
void isoTriangle::Init()
{
	base = DEFAULT_VALUE;
	height = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Init copy initializer

/// @brief init copy initializer of the object
/// @param reference to the object that should be copied 
void isoTriangle::Init(isoTriangle& X)
{
	Reset();
	base = X.base;
	height = X.height;
}

///////////////////////////////////////////////////////////////////////////
// Object eraser

/// @brief object's eraser
void isoTriangle::Reset()
{
	base = DEFAULT_VALUE;
	height = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of assignment operator

/// @brief overload of operator = 
/// @param reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
isoTriangle& isoTriangle::operator =(isoTriangle& X)
{
	Reset();
	Init(X);
	return *this;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of comparison operator

/// @brief overload of operator == 
/// @param reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height
bool isoTriangle::operator ==(isoTriangle& X)
{
	if (X.base == base && X.height == height)
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////
// Error messaging routine

/// @brief warning routine
/// @param warning string printed on the screen

void isoTriangle::ErrorMessage(const char* string)
{
	printf("%s\n", string);
}

///////////////////////////////////////////////////////////////////////////
// Debug routine

/// @brief It shows the programm status
void isoTriangle::Dump()
{
	cout << "base = " << base << endl;
	cout << "height = " << height << endl;
	cout << "side = " << Side(base, height) << endl;
}

/************************** ACCESS FUNCTIONS ******************/

/// @brief set the side of the object
/// @param b base
/// @param h height
/// @return side
double isoTriangle::Side(float b, float h) {

	return sqrt(pow(b * HALF, SQUARE) + pow(h, SQUARE));

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set base and height of the object
/// @param b base 
/// @param h height
void isoTriangle::SetDim(float b, float h) {

	SetBase(b);
	SetHeight(h);

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set base of the object
/// @param b base
void isoTriangle::SetBase(float b) {

	if (b < DEFAULT_VALUE) {
		ErrorMessage("isoTriangle - SetBase: base should be > 0");
		return;
	}

	base = b;

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set height of the object
/// @param h height
void isoTriangle::SetHeight(float h) {

	if (h < DEFAULT_VALUE) {
		ErrorMessage("isoTriangle - SetHeight: height should be > 0");
		return;
	}

	height = h;
}
///////////////////////////////////////////////////////////////////////////
// 


/// @brief get base and height of the object
/// @param b base
/// @param h height
void isoTriangle::GetDim(float& b, float& h) {

	b = base;
	h = height;

	return;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get base of the object
/// @return base 
float isoTriangle::GetBase() {
	return base;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get height of the object
/// @return height 
float isoTriangle::GetHeight() {
	return height;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the side of the object
/// @return side 
float isoTriangle::GetSide() {
	return Side(base, height);
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the area of the object
/// @return area of the isoTriangle
float isoTriangle::GetArea() {
	return Area();
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the perimeter of the object
/// @return perimeter of the isoTriangle
float isoTriangle::GetPerimeter() {
	return Perimeter();
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief computing object area
/// @return object area
float isoTriangle::Area() {
	if (base <= DEFAULT_VALUE || height <= DEFAULT_VALUE)
		ErrorMessage("WARNING: the geometric shape should have a positive area");
	return (base * height) * HALF;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief computing object perimeter
/// @return object perimeter
float isoTriangle::Perimeter() {
	if (base <= DEFAULT_VALUE || height <= DEFAULT_VALUE)
		ErrorMessage("WARNING: the geometric shape should have both positive dimensions");
	return (Side(base, height) * DOUBLE) + base;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief simulation of graphic interface
void isoTriangle::Draw() {
	cout << "This is a isoTriangle with this features:" << endl 
		<< "1) base = " << base << endl 
		<< "2) height = " << height << endl
		<< "3) side = " << Side(base, height) << endl 
		<< "4) perimeter = " << Perimeter() << endl 
		<< "5) area = " << Area() << endl 
		<< endl 
		<< endl;
}