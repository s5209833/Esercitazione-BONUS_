//---------------------------------------------------------
/**
//    @file		main.cpp
//    @brief	cration interface of geometric shapes
//    @author	Nicolo' Busi S5209833 & Leonardo Motta S4952213
*/
//---------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "polygon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "isoTriangle.h"

/** @param Dimension of the maximum realizable geometric shapes
*/
#define SIZE 100

/// @name  Main

using namespace std;

int main() {


	int choice = 0;				//choice of first interface
	int typeConstr = 0; 		//choice of construction type
	int object_counter = 0; 	//array position
	float base = 0;
	float height = 0;
	float diagH = 0;
	float diagV = 0;
	Polygon* Geo_shapes[SIZE];

	/// Interface menu

	cout << "Hello World! Welcome to the 'Geometric shapes generator'!" << endl;
	cout << "You can create, draw or delete 3 specific geometric shapes." << endl;
	cout << "To implement a function, enter the corrispondent number." << endl << endl;


	while (choice != 5)
	{
		if (object_counter > SIZE)
		{
			cout << "WARNING: the list is full, you can't create geometric shapes anymore!" << endl;

			if (object_counter == SIZE) 					//drawing and deletion of the macro-pointer, freeing of the memory
			{
				for (int i = 0; i < object_counter; i++)
				{

					cout << "You have reached the maximum number of creations!" << endl;
					cout << "Here you are the geometric shapes you have created: " << endl;

					Geo_shapes[i]->Draw();

					cout << endl;

					delete Geo_shapes[i];
				}
			}

			/// Exit of the program

			cout << "The program successfully ended" << endl << endl;

			exit(0);
		}

		cout << "You still have " << (SIZE - object_counter) << " creations." << endl
			<< "Pay attention! If you reach this limit, you can only draw what you have created." << endl
			<< "If you want to create other geometric shapes, you have to relaunch the program."
			<< endl << endl

			<< "So, choose a function:" << endl

			<< "1) Create a RECTANGLE" << endl
			<< "2) Create a RHOMBUS" << endl
			<< "3) Create an ISOSCELES TRAINGLE" << endl
			<< "4) DRAW all the created geometric shapes" << endl
			<< "5) Exit: end the session" << endl << endl;

		/// Schedule of the menu, with relative implementation of the commands

		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:

			rectangle * rect;

			cout << endl
				<< "Good, now how would you create it?" << endl		//choice of construction type
				<< "1) Default Construction" << endl
				<< "2) Normal Construction" << endl << endl;

			scanf_s("%d", &typeConstr);
			cin.get();

			while (typeConstr > 0 && typeConstr <= 2)
			{
				if (typeConstr == 1)
				{
					rect = new rectangle();
					Geo_shapes[object_counter] = rect; 									//assignment of the object in the macro-pointer
					cout << "Default Construction successfully ended." << endl << endl;
					typeConstr = 0;
					object_counter++;
				}

				else if (typeConstr == 2)
				{
					cout << "Please enter the dimensions of your rectangle:" << endl
						<< "Lenght: ";
					scanf_s("%f", &base);
					cin.get();

					cout << "Width: ";
					scanf_s("%f", &height);
					cin.get();

					rect = new rectangle(base, height);
					Geo_shapes[object_counter] = rect;									//assignment of the object in the macro-pointer
					cout << "Normal Construction successfully ended." << endl << endl;
					typeConstr = 0;
					object_counter++;
				}
				else
				{
					cout << "Please enter a valid option! Try again" << endl << endl;
				}
			}

			break;

		case 2:

			rhombus * rhom;

			cout << endl
				<< "Good,how would you create it?" << endl		//choice of type of construction
				<< "1) Default Construction" << endl
				<< "2) Normal Construction" << endl << endl;

			scanf_s("%d", &typeConstr);
			cin.get();

			while (typeConstr > 0 && typeConstr <= 2)
			{
				if (typeConstr == 1)
				{
					rhom = new rhombus();
					Geo_shapes[object_counter] = rhom;									//assignment of the object in the macro-pointer
					cout << "Default Construction successfully ended." << endl << endl;
					typeConstr = 0;
					object_counter++;
				}

				else if (typeConstr == 2)
				{
					cout << "Please enter the dimensions of your Rhombus:" << endl
						<< "Horizontal Diagonal: ";
					scanf_s("%f", &diagH);
					cin.get();

					cout << "Vertical Diagonal: ";
					scanf_s("%f", &diagV);
					cin.get();

					rhom = new rhombus(diagH, diagV);
					Geo_shapes[object_counter] = rhom;									//assignment of the object in the macro-pointer
					cout << "Normal Construction successfully ended." << endl << endl;
					typeConstr = 0;
					object_counter++;
				}
				else
				{
					cout << "Please enter a valid option! Try again" << endl << endl;
				}
			}

			break;

		case 3:

			isoTriangle * isoT;

			cout << endl
				<< "Good, how would you create it?" << endl		//choice of type of construction
				<< "1) Default Construction" << endl
				<< "2) Normal Construction" << endl << endl;

			scanf_s("%d", &typeConstr);
			cin.get();

			while (typeConstr > 0 && typeConstr <= 2)
			{
				if (typeConstr == 1)
				{
					isoT = new isoTriangle();
					Geo_shapes[object_counter] = isoT;									//assignment of the object in the macro-pointer
					cout << "Default Construction successfully ended." << endl << endl;
					typeConstr = 0;
					object_counter++;
				}

				else if (typeConstr == 2)
				{
					cout << "Please enter the dimensions of your triangle:" << endl
						<< "Base: ";
					scanf_s("%f", &base);
					cin.get();

					cout << "Height: ";
					scanf_s("%f", &height);
					cin.get();

					isoT = new isoTriangle(base, height);
					Geo_shapes[object_counter] = isoT;									//assignment of the object in the macro-pointer
					cout << "Normal Construction successfully ended." << endl << endl;
					typeConstr = 0;
					object_counter++;
				}
				else
				{
					cout << "Please enter a valid option! Try again" << endl << endl;
				}
			}

			break;

		case 4:

			if (object_counter == 0)
			{
				cout << "You haven't already drawn anything! Before you should create something." << endl;
				break;
			}

			cout << "Here you are the geometric shapes you have created! " << endl << endl;

			for (int i = 0; i < object_counter; i++)
			{
				cout << "" << (i+1) << " geometric shape" << endl;

				Geo_shapes[i]->Draw();

				cout << endl;
			}
			break;

		case 5:
			if (object_counter == SIZE) 					//deletion of the macro-pointer, freeing of the memory
			{
				for (int i = 0; i < object_counter; i++)
				{
					delete Geo_shapes[i];
				}
			}

			/// Exit of the program

			cout << endl
				<< "The program successfully ended. We hope you enjoyed!" << endl << endl;

			break;

			/// Default execution if the option isn't valid

		default:

			cout << "Please enter a valid option! Try again" << endl << endl;

			break;
		}
	}

	//@}

	return 0;
}