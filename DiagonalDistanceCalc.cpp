// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: 
// From control structures through objects. Pearson. 
// https://docs.microsoft.com/en-us/troubleshoot/developer/visualstudio/cpp/libraries/stl-sqrt-pow-functions
// https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-170
// https://stackoverflow.com/questions/32556114/cin-fail-while-loop-input-re-entry
// https://www.mechamath.com/geometry/diagonal-of-a-rectangular-prism-formulas-and-examples/
// d = sqrt(l^2 + w^2 + h^2)

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <cmath>    // To access power function for calculations
using namespace std;

// Global Constant Initialization
const string TITLE = "Diagonal Distance Calculator Program";
const string AUTHOR_LINE = "By Forrest Moulin";

// Function prototypes to notify compiler
void getDimensions();
void calculateDiagonal(double &length, double &width, double &height);

int main()
{
	// Program Logic
	cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl;
	getDimensions();
}
void getDimensions()
{
	bool validDims = false;
	double length = 0, width = 0, height = 0;
	// Create variable aliases using reference parameters
	// These alias values will change as length, width,
	// and height change (value also has same memory location).
	double &lRef = length;
	double &wRef = width;
	double &hRef = height;
	while (validDims == false)
	{
		cout << endl << "Please enter the length, width, and height of the room"
			<< endl << "in meters (space delimited). Example: 12 12.5 15"
			<< endl << endl
			<< "NOTE: Be sure to enter values in l w h order."
			<< endl << endl;

		cin >> length >> width >> height;

		cout << left << setw(10) << "Length:" << lRef << endl
			<< left << setw(10) << "Width:" << wRef << endl
			<< left << setw(10) << "Height:" << hRef << endl
			<< endl;

		if (length > 0 && width > 0 && height > 0)
		{
			cout << "Valid entry" << endl;
			calculateDiagonal(lRef, wRef, hRef);
			break;
		}
		cout << "Invalid entry" << endl;
		// Avoid infinite loop by clearing
		// cin and ignoring '\n' char
		cin.clear();
		cin.ignore(1000, '\n');
	}
}
void calculateDiagonal(double &length, double &width, double &height)
{
	double diagonalDistance;
	double squaredSum;
	// Sum the squares of the dimensions
	squaredSum = pow(length, 2) + pow(width, 2) + pow(height, 2);
	// Take the square root of that some (raised to 0.5 power)
	diagonalDistance = pow((squaredSum), 0.5);

	cout << "The longest diagonal distance would be " << diagonalDistance
		<< " meters" << endl << "from corner to corner." << endl;
}
/*
* CONSOLE OUTPUT # 1
* Diagonal Distance Calculator Program
* By Forrest Moulin
*
* Please enter the length, width, and height of the room
* in meters (space delimited). Example: 12 12.5 15
*
* NOTE: Be sure to enter values in l w h order.
*
* l w h
* Length:   0.00
* Width:    0.00
* Height:   0.00
*
* Invalid entry
*
* Please enter the length, width, and height of the room
* in meters (space delimited). Example: 12 12.5 15
*
* NOTE: Be sure to enter values in l w h order.
*
* 20 16 10
* Length:   20.00
* Width:    16.00
* Height:   10.00
*
* Valid entry
* The longest diagonal distance would be 27.50 meters
* from corner to corner.
*
* CONSOLE OUTPUT # 2
* Diagonal Distance Calculator Program
* By Forrest Moulin
*
* Please enter the length, width, and height of the room
* in meters (space delimited). Example: 12 12.5 15
*
* NOTE: Be sure to enter values in l w h order.
*
* -10 12 15
* Length:   -10.00
* Width:    12.00
* Height:   15.00
*
* Invalid entry
*
* Please enter the length, width, and height of the room
* in meters (space delimited). Example: 12 12.5 15
*
* NOTE: Be sure to enter values in l w h order.
*
* 10 12 15
* Length:   10.00
* Width:    12.00
* Height:   15.00
*
* Valid entry
* The longest diagonal distance would be 21.66 meters
* from corner to corner.
*/
