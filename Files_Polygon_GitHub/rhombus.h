//---------------------------------------------------------
/**
//    @file		rhombus.h
//    @brief	Header file for CLASS rhombus
//    @author	Nicolo' Busi	S5209833 & Leonardo Motta S4952213
*/
//---------------------------------------------------------

#ifndef rhombus__DEF
#define rhombus__DEF

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "polygon.h"

using namespace std;
/**
@class rhombus
@brief the class rhombus is a poligonal figure with 4 equal sides and perpendicolar diagonals

*/
class rhombus :public Polygon
{
	///////////////////////////// PRIVATE   Segment
private:
	float diagH;
	float diagV;

	double Side(float dH, float dV);

	///////////////////////////// PROTECTED Segment
protected:

	///////////////////////////// PUBLIC    Segment
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{

	/// Default constructor
	rhombus();
	/// Constructor
	rhombus(float dH, float dV);
	/// Copy constructor
	rhombus(rhombus& X);
	/// Destructor
	virtual ~rhombus();
	//@}

	/// @name OPERATORS
	/// @{

	/// Assignment overloading
	rhombus& operator = (rhombus& X);
	/// Comparison overloading
	bool	 operator ==(rhombus& X);
	/// Print operator
	friend ostream& operator << (ostream& o, rhombus& X);
	/// Input operator
	friend istream& operator >> (istream& i, rhombus& X);
	//@}

	/// @name BASIC HANDLING
	/// @{

	/// Default initialization
	void Init();
	/// Copy initialization
	void Init(rhombus& X);
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
	void SetDim(float dH, float dV);
	void SetDiagH(float dH);
	void SetDiagV(float dV);

	/// GET FUNCTIONS
	void GetDim(float& dH, float& dV);
	float GetDiagH();
	float GetDiagV();
	float GetSide();
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
