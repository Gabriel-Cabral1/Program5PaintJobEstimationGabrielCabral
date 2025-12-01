﻿/*
 Project Name : Program5PaintJobEstimationGabrielCabral
 File Name : Program5PaintJobEstimationGabrielCabral.cpp
 Programmer : Gabriel Cabral
 Date : 11/30/25
 Requirements:
 A painting company has determined that for every 110 square feet of wall space, 1 gallon of paint
 and 8 hours of labor will be required. The company charges $25.00 per hour for labor. Write a
 modular, procedural program that allows the user to enter the number of rooms that are to be
 painted and the price of the paint per gallon. It should also ask for the square feet of wall space in
 each room. It should then display the following data.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//constants
const double gallonpersqft = 1.0 / 110.0;
const double laborhourspersqft = 8.0 / 110.0;
const double laborchargeperhour = 25.0;

//number of rooms to be painted
int getrooms();
//square feet of wall for a room
double getsqft();
//price per gallon for a room
double getpricepergallon();
//gets number of gallons for a room
double gallonsforroom(double sqft);
//gets the labor hours to paint a room
double laborforroom(double sqft);
//final for paint job
void displayestimate(double paintcharge, double gallonsneeded, double laborcharge, double laborhours);


int main()
{
	//create variables
	double paintcharge = 0.0;
	double laborcharge = 0.0;
	double gallonsneeded = 0.0;
	double laborhours = 0.0;
	int numrooms = getrooms();

	//math for each room
	for (int room = 1; room <= numrooms; room++)
	{
		cout << "\nRoom " << room << endl;

		double sqft = getsqft();
		double gallons = gallonsforroom(sqft);
		double paintprice = getpricepergallon();
		double labor = laborforroom(sqft);

		gallonsneeded += gallons;
		paintcharge += gallons * paintprice;
		laborhours += labor;
		laborcharge += labor * laborchargeperhour;
	}
	//display final
	displayestimate(paintcharge, gallonsneeded, laborcharge, laborhours);
	return 0;
}
//ask user and validate
int getrooms() {
	int rooms;
	do
	{
		cout << "Enter number of rooms to be painted: ";
		cin >> rooms;

		if(rooms<1)
		{
			cout << "Number of rooms must be 1 or greater.\n";
		}
	} while (rooms < 1);
	return rooms;
}
double getsqft() {
	double sqft;
	do {
		cout << "Enter square feet of wall space for this room: ";
		cin >> sqft;
		if(sqft<0.0)
		{
			cout << "Square feet must be 0 or greater.\n";
		}
	} while (sqft < 0.0);
	return sqft;
}
double getpricepergallon()
{
	double price;
	do {
		cout << "Enter price of paint per gallon: $";
		cin >> price;
		if (price < 10.0)
		{
			cout << "Price must be at leat $10.00.\n";
		}
	} while (price < 10.0);
	return price;
}
double gallonsforroom(double sqft) {
	double gallons = sqft * gallonpersqft;
	//round up
	return ceil(gallons);
}
double laborforroom(double sqft) {
	return sqft * laborhourspersqft;
}

//displaying the information
void displayestimate(double paintcharge, double gallonsneeded, double laborcharge, double laborhours)
{
	cout << fixed << setprecision(2);
	cout << "\nPaint Job Estimate\n";
	cout << "------------------\n";
	cout << "Gallons of paint required : " << gallonsneeded << endl;
	cout << "Hours of labor required    : " << laborhours << endl;
	cout << "Cost of paint             : $ " << paintcharge << endl;
	cout << "Labor charges             : $" << laborcharge << endl;
	cout << "Total cost of paint job   : $" << (paintcharge + laborcharge) << endl;
}
