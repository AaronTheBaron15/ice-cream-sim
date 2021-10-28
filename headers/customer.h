#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream> //Used for cout
#include "iceCream.h" //Customer uses ice cream class
#include <string>
#include <vector>
using namespace std;

class Customer{
    private:
        vector<IceCream> preferences; //Represents the multiple amount of preferences each customer has
        string name; //Represents name of each customer
    public:

        //Empty constructor for customer
        //creates a customer with a preference of a plain bowl of vanilla ice cream 
        Customer();

        //Constructor for customer that randomly generates preferences and customer's name
        //Input: vectors for each part of ice cream and customer names
        //Customer's preferences and name are set randomly
        Customer(vector<string> bases, vector<string> flavors, vector<string> toppings, vector<string> names);

        //Interface method to access customer's name
        //Input: NA
        //Output: customer's name
        string getName();

        //this function returns the IceCream at a certain index of a vector
        //inputs - a vector of ice cream preferences and an integer for the index of the preference to get
        //outputs - an IceCream at index index
        IceCream getPreference(int index);

        //returns a vector of preferences
        //no inputs
        //returns a vector of ice cream preferences
        vector<IceCream> getPreferences();

        //This function generates random ice cream preferences for a customer
        //inputs - three string vectors, one for bases, one for flavors, and one for toppings, as well as the number of preferences to add to the vector
        //outputs - adds new random-ish IceCream(s) to the preferences vector
        void generatePreference(int numPreferences, vector<string> bases, vector<string> flavors, vector<string> toppings);

        //prints each individual preference of the customer's preferences
        //no inputs
        //prints out some basic information about the customer's preferences to the screen
        void printPreferences();

        //prints information about the Customer
        //inputs - none
        //outputs - a string containing information about the customer
        string toString();

        //operator overload for the stream insertion operator, prints all the information about the customer that is input to the overload
        //inputs - reference to an output stream, reference to an initialized Customer
        //outputs - returns information about the input Customer
        friend ostream& operator<<(ostream& out, Customer cust);
};

#endif