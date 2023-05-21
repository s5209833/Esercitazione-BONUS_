//---------------------------------------------------------
/**
//    @file		rectangle.cpp
//    @brief	Implementation file for class rectangle
//    @author	Nicolo' Busi S5209833 & Leonardo Motta S4952213
*/
//---------------------------------------------------------


#include "polygon.h"

constexpr auto DEFAULT_VALUE = 0;;

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
ostream& operator << (ostream& o, Polygon& X)
{

	return o;
}

///////////////////////////////////////////////////////////////////////////
//Input operator
istream& operator >> (istream& i, Polygon& X)
{

	return i;
}

/************************** MEMBER FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Default Constructor

/// @brief default constructor 
Polygon::Polygon() {

	cout << "Polygon - Constructor - Default" << endl;

	area = DEFAULT_VALUE;
	perimeter = DEFAULT_VALUE;

} 

///////////////////////////////////////////////////////////////////////////
// Copy Constructor

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
Polygon::Polygon(const Polygon &p) {
	
	cout << "Polygon - Copy Constructor" << endl;

	Init(p);
}

///////////////////////////////////////////////////////////////////////////
// Destructor

/// @brief destructor
Polygon::~Polygon() {

	cout << "Polygon - Destructor" << endl<<endl;
	Reset();

}

///////////////////////////////////////////////////////////////////////////
// Init default initializer

/// @brief default initialization of the object
void Polygon::Init() {
	Reset();
	perimeter = DEFAULT_VALUE;
	area = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Init copy initializer

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Polygon::Init(const Polygon& p) {
	Reset();

}

///////////////////////////////////////////////////////////////////////////
// Object eraser

/// @brief total reset of the object  
void Polygon::Reset() {
	perimeter = DEFAULT_VALUE;
	area = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of assignment operator

/// @brief overload of operator = 
/// @param p reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Polygon& Polygon::operator=(const Polygon &p) { 

	return *this;
	
}

///////////////////////////////////////////////////////////////////////////
// Overloading of comparison operator

/// @brief overload of operator == 
/// @param p reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool Polygon::operator==(const Polygon &r) { 
	return false;
}

///////////////////////////////////////////////////////////////////////////
// Error messaging routine

/// @brief write an error message 
/// @param string message to be printed
void Polygon::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Polygon --";
	cout << string << endl;

}

///////////////////////////////////////////////////////////////////////////
// Debug routine

/// @brief for debugging: all about the object
void Polygon::Dump() {

	cout << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << endl << flush;

}


/// @brief write a warning message 
/// @param string message to be printed
void Polygon::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Polygon --";
	cout << string << endl;

}

/************************** ACCESS FUNCTIONS ******************/


/// @brief get the area of the object
/// @return area 
float Polygon::GetArea() {
	
	area = Area();
	return area;

}

/// @brief get the perimeter of the object
/// @return perimeter 
float Polygon::GetPerimeter() {

	perimeter = Perimeter();
	return perimeter;

}




