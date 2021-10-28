#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <queue> //Used for line
#include <string>
//#include "../headers/customer.h"
#include "customer.h"
using namespace std;

class Shop{
    private:
        vector<int> flavorServings; //Represents servings of all flavors
        vector<int> toppingsServings; //Represents servings of all toppings
        vector<int> baseServings; //Represents servings of all bases

        vector<string> flavors; //Represents all flavors offered
        vector<string> toppings; //Represents all toppings offered
        vector<string> bases; //Represents all bases offered

        vector<string> names; //Represents all possible nammes of customers

        queue<Customer> line; //Represents line of customers
        float money; //Represents amount of money store has
    public:
        //empty constructor for shop
        //initializes the money to start with and sets servings vectors to one 0
        Shop();

        //filled constructor for shop
        //sets each vector to be a vector of servings left of a certain thing (flavors, toppings, bases), and sets the money the shop starts with
        //also sets vectors of flavors, bases, toppings, and customer names
        Shop(vector<int> totalFlavor, vector<int> totalTopping, vector<int> totalBase, vector<string> f, vector<string> t, vector<string> b, vector<string> n, float startMoney);

        //gets the current amount of money
        //no inputs
        //returns the money the store currently holds
        float getMoney();

        //makes a certain amount of money for the shop
        //inputs - takes in a float for the amount of money the shop generates
        //outputs - none, but changes the amount of money the shop currently holds
        void makeMoney(float amount);

        //uses a certain amount of money, decreasing the money the shop currently holds
        //inputs - a float for the amount of money the shop spends
        //outputs - none, but changes the amount of money the shop currently holds
        void spendMoney(float amount);

        //this function is essentially creating a new supply of an item
        //inputs - numServings is the number of servings to create, vector<int> servings is the servings vector to apply the changes to, int index is the specific
        //      item to change, and string type helps change the money spent to create the new servings
        //outputs - none, but does change the numbers inside one of the shop's member variable vectors
        void addServings(int numServings, vector<int> servings, int index, string type);

        //this function is essentially using the current supply of an item to give to a customer
        //inputs - numservings is the number of servings to remove, vector<int> servings is the servings vector to apply the changes to, int index is the specific
        //      item to change, and string type helps chose how much money is added to the store's current money
        void removeServings(int numServings, vector<int> servings, int index, string type);

        //Interface method to return line
        //Input: NA
        //Output: queue line
        queue<Customer> getQ();

        //creates a new customer and adds them to the queue
        //inputs - a reference to a customer  that is fully initialized (has preferences)
        //outputs - none, but adds customer to a queue
        void addCustomer();

        //removes a customer from a queue
        //inputs - none
        //outputs - none, but removes a customer from the shop's queue
        void removeCustomer();

        //this function decides from the customer's preferences what they  order
        //inputs - a customer reference to a customer with preferences, and three vectors of integers which contain information about the number of servings left of each item
        //outputs - returns an IceCream that the customer ordered
        IceCream makeOrder(Customer& cust);
};

#endif