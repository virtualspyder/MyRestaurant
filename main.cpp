#include "General.h"
#include "Restaurant.h"

using namespace std;

int main()
{
	string choice;

	// This is my restaurant
	Restaurant myRestaurant;

	while(true)
	{
		// A customer has entered the restaurant! Begin serving him/her now
		myRestaurant.runRestaurant();

		cout << "Do you want to order again? (";
		setConsoleTextColor(Color_Yellow) << "Y";
		setConsoleTextColor(Color_White) << " to continue) : "; 
		
		setConsoleTextColor(Color_Yellow);
		cin >> choice;
		setConsoleTextColor(Color_White);

		if(stricmp(choice.c_str(), "y") == 0 || stricmp(choice.c_str(), "Yes") == 0)
		{
			// Do nothing
		}
		else
		{
			break;
		}
	}

	cout << "Please press any key to continue. . .";
	cin.ignore(); cin.get();

	return 0;
}