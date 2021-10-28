#ifndef ICECREAM_H
#define ICECREAM_H

#include <vector>
#include <string>

using namespace std;

class IceCream{
    private:
        string base; //Represents base of ice cream, such as cone or bowl
        string flavor; //Represents flavor of ice cream
        string topping; //Represents topping on ice cream
    public:
        //Empty constructor
        //Sets base as sugar cone, flavor as vanilla, no toppings, not a milkshake
        IceCream();

        //Ice cream constructor
        //Sets selected base, flavor, and toppings
        IceCream(string b, string f, string t);

        //Method to get the base of the ice cream cone
        //input: none
        //output: a string that is the base of the cone
        string getBase();

        //Method to get the current flavor of the ice cream cone
        //input: none
        //output: returns the flavor of the ice cream as a string
        string getFlavor(); 

        //Method to get the current topping of the ice cream cone
        //input: none
        //output: returns the topping of the ice cream as a string
        string getTopping();

        //prints information about the iceCream
        //inputs - none
        //outputs - a string containing information about the ice cream
        string toString();

        //operator overload for the stream insertion operator, prints all the information about the ice cream that is input to the overload
        //inputs - reference to an output stream, reference to an initialized IceCream
        //outputs - returns information about the input IceCream
        friend ostream& operator<<(ostream& out, IceCream cream);
};

#endif