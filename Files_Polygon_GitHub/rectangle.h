//---------------------------------------------------------
/**
//    @file		rectangle.h
//    @brief	Header file for CLASS rectangle
//    @author	Nicolo' Busi	S5209833 & Leonardo Motta S4952213
*/
//---------------------------------------------------------

#ifndef rectangle__DEF
#define rectangle__DEF

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "polygon.h"

using namespace std;
/**
@class rectangle
@brief the class rectangle is a poligonal figure with 4 sides and all the internal angles of 90 degrees 

*/
class rectangle :public Polygon
{
	///////////////////////////// PRIVATE   Segment
private:
	float lenght;
	float width;


	///////////////////////////// PROTECTED Segment
protected:

	///////////////////////////// PUBLIC    Segment
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{

	/// Default constructor
	rectangle();
	/// Constructor
	rectangle(float w, float l);
	/// Copy constructor
	rectangle(rectangle& X);
	/// Destructor
	virtual ~rectangle();
	//@}

	/// @name OPERATORS
	/// @{

	/// Assignment overloading
	rectangle& operator = (rectangle& X);
	/// Comparison overloading
	bool	 operator ==(rectangle& X);
	/// Print operator
	friend ostream& operator << (ostream& o, rectangle& X);
	/// Input operator
	friend istream& operator >> (istream& i, rectangle& X);
	//@}

	/// @name BASIC HANDLING
	/// @{

	/// Default initialization
	void Init();
	/// Copy initialization
	void Init(rectangle& X);
	/// Object erasure
	void Reset();
	/// Outputs internal errors
	void ErrorMessage(const char* string);
	//@}

	/// @name ACCESS FUNCTIONS
	/// @{
	
	virtual float Area();
	virtual float Perimeter();

	///DRAWING
	virtual void Draw();

	/// SET FUNCTIONS
	void SetDim(float w, float l);
	void SetLenght(float l);
	void SetWidth(float w);

	/// GET FUNCTIONS
	void GetDim(float& w, float& l);
	float GetLenght();
	float GetWidth();
	float GetArea();
	float GetPerimeter();
	//@}

	/// @name DEBUG and SERIALIZATION
	/// @{

	/// Object printout for diagnostic
	void Dump();
	//@}
};

#endif

