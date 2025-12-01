?/*
 Project Name : Program5PaintJobEstimatorGabrielCabral
 File Name : Program5PaintJobEstimatorGabrielCabral.cpp
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
#include <iomanip>
#include <cmath>
using namespace std;

//constants
const double gallonpersqft = 1.0 / 110.0;
const double laborhourspersqft = 8.0 / 110.0;
const double laborchargeperhour = 25.0;

//number of rooms to be painted
int getrooms();
//square feet of wall for a room
double getsqft();

double getpricepergallon();

double gallonsforroom(double sqft);

double laborforroom(double sqft);

void displayestimate(double paintcharge, double gallonsneeded, double laborcharge, double laborhours);



int main()
{
    std::cout << "Hello World!\n";
}
