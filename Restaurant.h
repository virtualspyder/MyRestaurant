#ifndef RESTAURANT_H__
#define RESTAURANT_H__

#include "General.h"

// Some constant
const double TEXAS_RESTAURANT_TAX = 0.0825;

// An item structure for an user-defined restaurant
class Item
{
private : 
	std::string name;
	std::string description;
	double price;

public : 
	void importItem(const Item_Raw &item);

	void setName(std::string _name);

	void setDescription(std::string _description);

	void setPrice(double _price);

	void setItem(std::string _name, std::string _description, double _price);

	std::string getName() const;

	std::string getDescription() const;

	double getPrice() const;
};

// User-defined restaurant items
enum RestaurantAppetizer
{
	Restaurant_Appetizer_1,
	Restaurant_Appetizer_2,
	Restaurant_Appetizer_3
};

enum RestaurantMainDishes
{
	Restaurant_Main_Dishes_1,
	Restaurant_Main_Dishes_2,
	Restaurant_Main_Dishes_3
};

enum RestaurantBeverages
{
	Restaurant_Beverages_1,
	Restaurant_Beverages_2,
	Restaurant_Beverages_3
};

enum RestaurantDesserts
{
	Restaurant_Desserts_1,
	Restaurant_Desserts_2,
	Restaurant_Desserts_3
};

// User-defined restaurant constants
const int RESTAURANT_APPETIZER_ITEMS = 3;
const int RESTAURANT_MAIN_DISHES_ITEMS = 3;
const int RESTAURANT_BEVERAGES_ITEMS = 3;
const int RESTAURANT_DESSERTS_ITEMS = 3;

class Restaurant
{
private : 
	Item restaurantAppetizerItems[RESTAURANT_APPETIZER_ITEMS];
	Item restaurantMainDishesItems[RESTAURANT_MAIN_DISHES_ITEMS];
	Item restaurantBeveragesItems[RESTAURANT_BEVERAGES_ITEMS];
	Item restaurantDessertsItems[RESTAURANT_DESSERTS_ITEMS];
		
	public : 
		
	// The receipt structure for the user-defined Restaurant
	struct Receipt
	{
		Receipt()
		{
			totalPrice = 0;
			taxPrice = 0;
			gratuity = 0;			
		}

		vector<Item> itemsOrdered;

		double totalPrice;
		double taxPrice;
		double gratuity;
	};

	// Default constructor
	Restaurant();

	// Default constructor will also call this function
	void initialize();

	// Show restaurant menu (If bHelp is toggled, the restaurant will show the customer how food items are ordered)
	void showMenu(bool bHelp = false);

	// Show restaurant help
	void showHelp();

	// Validate the customer's choice
	// Returns -1 if fails, 0 if no action should be taken, and 1 if successful
	int getInput(Item &theItem);

	// Formatting function
	static std::string printName(const std::string &s, int len = 0);

	// Generates a Html Receipt
	static std::string generateReceiptHtml(const Receipt &myReceipt);

	// A customer has entered the restaurant. Run the restaurant
	void runRestaurant();

private : 

	// A helper function for Restaurant::getInput()
	// Return 0 if successful, 1 to proceed to order, -1 if fails
	int getDescription(unsigned int category, unsigned int item_id);

	// A helper function for Restaurant::getInput()
	// Return 1 if successful, -1 if fails
	int getPrice(unsigned int category, unsigned int item_id, Item &theItem);

	// A helper function for Restaurant::getInput()
	// Return false (0) if no action should be taken, and return true (1) otherwise
	static int descriptionOrder(const Item &item);

	// A helper function for Restaurant::getInput() and Restaurant::getPrice()
	// This indicates that an order is completed. 
	static void completeOrder(const Item &item, Item &theItem);
};

#endif // RESTAURANT_H__