#ifndef GENERAL_H__
#define GENERAL_H__

// Some standard headers
#include <iostream> // std::cin, std::cout
#include <fstream> // std::ofstream
#include <cstdio> // stricmp()
#include <iomanip> // std::setw(), std::setfill()
#include <string> // std::string
#include <cctype> // isdigit()
#include <vector> // std::vector
#include <cstdlib> // system(), itoa(), rand(), srand()
#include <ctime> // time()
#include <sstream> // std::stringstream
#include <cstring> // stricmp()
#include <map> // std::map()

using namespace std;

enum
{
	Color_White = 7,
	Color_Yellow = 14,
	Color_Purple = 13,
	Color_Green = 10, 
	Color_Bright_White = 15,
	Color_Light_Blue = 11,
	Color_Pink_Blue_Background = 23,
	Color_Red = 12
};

#if (defined(_WIN32) || defined(_WIN64))
	static const char *clearCmd = "cls";
	static const char *htmlCmd = "";	
#elif defined(__APPLE__)
	static const char *clearCmd = "clear";
	static const char *htmlCmd = "safari ";	
#else
	static const char *clearCmd = "tput reset";
	static const char *htmlCmd = "firefox ";	
#endif

#if (defined(_WIN32) || defined (_WIN64))

#include <windows.h>
#include <conio.h>

static std::ostream& setConsoleTextColor(int myColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,myColor);

	return cout;
}

#else

#include "conio.h"

static std::string toInteger_A552(int a)
{
	std::stringstream ss; ss << a; return ss.str();
}

static std::ostream& setConsoleTextColor(int myColor)
{
	static map<int, string> colorCode;
	if(colorCode.size() == 0)
	{
		colorCode[Color_White] = "\033[0m";
		colorCode[Color_Yellow] = "\033[0m\033[38;5;" + toInteger_A552(11) + "m";
		colorCode[Color_Purple] = "\033[0m\033[38;5;" + toInteger_A552(105) + "m";
		colorCode[Color_Green] = "\033[0m\033[38;5;" + toInteger_A552(10) + "m";
		colorCode[Color_Bright_White] = "\033[0m\033[38;5;" + toInteger_A552(15) + "m";
		colorCode[Color_Light_Blue] = "\033[0m\033[38;5;" + toInteger_A552(14) + "m";
		colorCode[Color_Pink_Blue_Background] = "\033[0m\033[38;5;" + toInteger_A552(10) + "m" + "\033[48;5;" + toInteger_A552(57) + "m";
		colorCode[Color_Red] = "\033[0m\033[38;5;" + toInteger_A552(9) + "m";
	}

	cout << colorCode[myColor];

	return cout;	
}

#endif

// Some constants
const int TOTAL_ITEMS = 12;
const int ZERO_FOR_CAL = 0; // Zero for cal(calculation)
const int ONE_FOR_CAL = 1;
const int TWO_FOR_CAL = 2;
const int THREE_FOR_CAL = 3;
const int FOUR_FOR_CAL = 4;

const int MINUS_ONE_FOR_CAL = -1; 

// General item structure for all restaurants
struct Item_Raw
{
	char name[100];
	char description[500];
	double price;	
};

// Global Restaurant Appetizer Items
enum
{
	Item_Crispy_Crab_Wontons = 0,
	Item_Presunto_Pot_Stickers,
	Item_Crab_Cakes
};

// Global Restaurant Main Dishes Items
enum
{
	Item_Presunto_And_Ricotta_Flatbread = Item_Crab_Cakes + 1,
	Item_Fresh_Kale_Salad,
	Item_Shrimp_Scampi,
};

// Global Restaurant Beverages Items
enum
{
	Item_Fresh_Orange_Juice_Infused_With_Passion_Fruit_Seeds = Item_Shrimp_Scampi + 1,
	Item_Cold_Green_Ice_Tea,
	Item_Flavored_Lemonades
};

// Global Restaurant Desserts Items
enum
{
	Item_Lemoncello_Cream_Torte = Item_Flavored_Lemonades + 1,
	Item_Chocolate_Tower_Truffle_Cake,
	Item_Warm_Apple_Crisp
};

extern Item_Raw globalRestaurantItems[TOTAL_ITEMS];

#endif // GENERAL_H__