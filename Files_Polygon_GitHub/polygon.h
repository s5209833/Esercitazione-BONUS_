//---------------------------------------------------------
/**
//    @file		polygon.h
//    @brief	Header file for CLASS polygon
//    @author	Nicolo' Busi	S5209833 & Leonardo Motta S4952213
*/
//---------------------------------------------------------

#ifndef POLYGON_H
#define POLYGON_H

#include<iostream>

using namespace std;
/**
@class polygon
@brief  an abstract base class for polygons

*/
class Polygon 
{
	///////////////////////////// PRIVATE   Segment
private:

	///////////////////////////// PROTECTED Segment
protected:
	float perimeter; 
	float area;
	
	virtual float Area()=0;
	virtual float Perimeter()=0;

	///////////////////////////// PUBLIC    Segment
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	
	/// Default constructor 
	Polygon();
	/// Copy conctructor
	Polygon(const Polygon &p);
	/// Desctructor
	virtual ~Polygon();
	/// @}
	
	/// @name OPERATORS
	/// @{
	
	/// Assignment overloading
	Polygon& operator=(const Polygon &p); 
	/// Comparison overloading
	bool operator==(const Polygon &p);
	/// Print operator
	friend ostream& operator << (ostream& o, Polygon& X);
	/// Input operator
	friend istream& operator >> (istream& i, Polygon& X);
	//@}
	
	/// @name BASIC HANDLING
	/// @{
	
	///Default initialization
	void Init();
	///Copy initialization
	void Init(const Polygon &r);
	/// Object erasure
	void Reset();
	/// Outputs internal errors
	void ErrorMessage(const char* string);
	/// Outputs internal warnings
	void WarningMessage(const char* string);
	// @}

			
	/// @name ACCESS FUNCTIONS
	/// @{
	
	/// GET FUNCTIONS 
	float GetArea();
	float GetPerimeter();
	/// @}

	///DRAWING
	virtual void Draw() = 0; 
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{ 

	void Dump();
	/// @}

};

#endif