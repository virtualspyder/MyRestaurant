#include "General.h"

// Quick-initialization can be done if we use a char array instead of a std::string
Item_Raw globalRestaurantItems[TOTAL_ITEMS] = {
// Restaurant Appetizer
	{
		"Crispy Crab Wontons", 
		"Crabmeat Blended with Cream Cheese, Green Onion, Water Chestnuts and Sweet Chili Sauce Fried Crisp in Wonton Wrappers.",
		6.50
	},
	{
		"Presunto pot stickers", 
		"Asian Dumplings Pan-Fried in the Classic Tradition. Served with Our Soy-Ginger Sesame Sauce.",
		5.50
	},
	{
		"Crab cakes", 
		"Served with Mustard and Tartar Sauce.",
		6.50
	},

// Restaurant Main Dishes
	{
		"Presunto and Ricotta Flatbread", 
		"Fontina, Parmesan and Romano Cheeses with Kale and Herbs.",
		10.50
	},
	{
		"Fresh Kale Salad", 
		"Apples, Marcona Almonds, Golden Raisins and Green Beans Tossed with Our Buttermilk-Black Pepper Dressing.",
		7.50
	},
	{
		"Shrimp Scampi", 
		"Bistro-Style! Saute'ed with Whole Cloves of Garlic, White Wine, Fresh Basil and Tomato. Served with Angel Hair Pasta.",
		14.50
	},

// Restaurant Beverages
	{
		"Fresh Orange Juice infused with Passion fruit seeds", 
		"Hand-squeezed daily.",
		4.50
	},
	{
		"Cold Green Ice Tea", 
		"Cold green ice tea infused with mint.",
		2.50
	},
	{
		"Flavored Lemonades", 
		"Strawberry, Raspberry, Hibiscus or Cucumber.",
		3.50
	},

// Restaurant Desserts
	{
		"Lemoncello Cream Torte", 
		"Layers of Vanilla Cake and Lemon Mascarpone Cream Topped with Streusel and Served with Strawberries and Whipped Cream.",
		4.50
	},
	{
		"Chocolate Tower Truffle Cake", 
		"Layers and Layers of Fudge Cake with Chocolate Truffle Cream and Chocolate Mousse.",
		4.50
	},
	{
		"Warm Apple Crisp", 
		"Our Delicious Crispy Nutty Topping and Vanilla Ice Cream.",
		4.50
	}
};

