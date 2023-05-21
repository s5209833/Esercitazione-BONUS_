//---------------------------------------------------------
/**
//    @file		rectangle.cpp
//    @brief	Implementation file for class rectangle
//    @author	Nicolo' Busi S5209833
*/
//---------------------------------------------------------




#include "rectangle.h"


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

constexpr auto DEFAULT_VALUE = 0;;
constexpr auto DOUBLE = 2;;

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
ostream& operator << (ostream& o, rectangle& X)
{

	return o;
}

///////////////////////////////////////////////////////////////////////////
istream& operator >> (istream& i, rectangle& X)
{

	return i;
}

/************************** MEMBER FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Default Constructor

/// @brief default constructor 
rectangle::rectangle()
{
	cout << "Rectangle - Constructor - Default" << endl<<endl;
	Init();

}

///////////////////////////////////////////////////////////////////////////
// Constructor

/// @brief constructor which also check if the value entered is >= 0
/// @param w width of the rectangle
/// @param l lenght of the rectangle
rectangle::rectangle(float w, float l) {

	width = DEFAULT_VALUE;
	lenght = DEFAULT_VALUE;

	cout << "Rectangle - Constructor" << endl<<endl;

	if (w < DEFAULT_VALUE)
		ErrorMessage("WARNING: rectangle - Constructor : width should be > 0");
	else
		width = w;

	if (l < DEFAULT_VALUE)
		ErrorMessage("WARNING: rectangle - Constructor : lenght should be > 0");
	else
		lenght = l;

}


///////////////////////////////////////////////////////////////////////////
// Copy Constructor

/// @brief copy constructor 
/// @param reference to the object that should be copied 
rectangle::rectangle(rectangle& X)
{
	cout << "Rectangle - Copy Constructor" << endl<<endl;
	Init(X);
}

///////////////////////////////////////////////////////////////////////////
// Destructor

/// @brief destructor 
rectangle::~rectangle()
{
	cout << "Rectangle - Destructor" << endl;
	Reset();
}

///////////////////////////////////////////////////////////////////////////
// Init default initializer

/// @brief init default initializer of the object
void rectangle::Init()
{
	width = DEFAULT_VALUE;
	lenght = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Init copy initializer

/// @brief init copy initializer of the object
/// @param reference to the object that should be copied 
void rectangle::Init(rectangle& X)
{
	Reset();
	width = X.width;
	lenght = X.lenght;
}

///////////////////////////////////////////////////////////////////////////
// Object eraser

/// @brief object's eraser
void rectangle::Reset()
{
	width = DEFAULT_VALUE;
	lenght = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of assignment operator

/// @brief overload of operator = 
/// @param reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
rectangle& rectangle::operator =(rectangle& X)
{
	Reset();
	Init(X);
	return *this;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of comparison operator

/// @brief overload of operator == 
/// @param reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same lenght
bool rectangle::operator ==(rectangle& X)
{
	if (X.width == width && X.lenght == lenght)
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////
// Error messaging routine

/// @brief warning routine
/// @param warning string printed on the screen

void rectangle::ErrorMessage(const char* string)
{	
	printf("%s\n", string);
}

///////////////////////////////////////////////////////////////////////////
// Debug routine

/// @brief It shows the programm status
void rectangle::Dump()
{
	cout << "Width is = " << width << endl;
	cout << "Lenght is = " << lenght << endl;
	
}

/************************** ACCESS FUNCTIONS ******************/


/// @brief set width and lenght of the object
/// @param w width 
/// @param l lenght
void rectangle::SetDim(float w, float l) {

	SetWidth(w);
	SetLenght(l);

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set width of the object
/// @param w width
void rectangle::SetWidth(float w) {

	if (w < DEFAULT_VALUE) {
		ErrorMessage("rectangle - Setwidth: width should be > 0");
		return;
	}

	width = w;

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set lenght of the object
/// @param l lenght
void rectangle::SetLenght(float l) {

	if (l < DEFAULT_VALUE) {
		ErrorMessage("rectangle - Setwidth: width should be > 0");
		return;
	}

	lenght = l;
}
///////////////////////////////////////////////////////////////////////////
// 


/// @brief get width and lenghtof the object
/// @param w width
/// @param l lenght
void rectangle::GetDim(float& w, float& l) {

	w = width;
	l = lenght;

	return;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get width of the object
/// @return width 
float rectangle::GetWidth() {
	return width;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get lenght of the object
/// @return lenght 
float rectangle::GetLenght() {
	return lenght;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the area of the object
/// @return area of the rectangle
float rectangle::GetArea() {
	return Area();
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the perimeter of the object
/// @return perimeter of the rectangle
float rectangle::GetPerimeter() {
	return Perimeter();
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief computing rectangle area
/// @return rectangle area
float rectangle::Area() {
	if (lenght <= DEFAULT_VALUE || width <= DEFAULT_VALUE)
		ErrorMessage("WARNING: the geometric shape should have a positive area");
	return lenght * width;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief computing rectangle perimeter
/// @return rectangle perimeter
float rectangle::Perimeter() {
	if (lenght <= DEFAULT_VALUE || width <= DEFAULT_VALUE)
		ErrorMessage("WARNING: the geometric shape should have both positive dimensions");
	return DOUBLE * (lenght + width);
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief simulation of graphic interface
void rectangle::Draw() {
	cout << "This is a rectangle with this features:" << endl 
		<< "1) lenght = " << lenght << endl 
		<< "2) width = " << width << endl
		<< "3) perimeter = " << Perimeter() << endl 
		<< "4) area = " << Area() << endl
		<< endl 
		<< endl;
}