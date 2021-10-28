//Ice Cream Final Project
//CS 172-1
//Trenten Nogle and Aaron Borjas
//5/15/19
//Simulates an ice cream shop with shop class that contains a queue of a customer class that contains a vector of an ice cream class
//Uses file io to get flavor/topping/base/customer names

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
//#include "../headers/iceCream.h"
//#include "../headers/customer.h"
//#include "../headers/shop.h"

#include "../headers/iceCream.h"
#include "../headers/customer.h"
#include "../headers/shop.h"

using namespace std;

//Puts information from file into vector
//Input: input file stream and empty vector
//Output: Vector filled with data from files
void applyToVector(ifstream& file, vector<string>& stuff){
    string currLine;
    while(getline(file, currLine)){ //while we can get text from the file
        int i = 0; //counter int
        string word; //temporary word
        while(currLine[i] != '\0'){ //while the current line's current character is not new line character
            word += currLine[i]; //append the current character to our word
            i++; //increment i
        }
        stuff.push_back(word); //push the full word to the end of the vector listing items in the file.
    }
}


int main() {
    srand(time(NULL)); //seeds time

    //Declares input file streams
    ifstream flavorFile;
    ifstream toppingsFile;
    ifstream basesFile;
    ifstream namesFile;

    //Calls applyToVector function to put data from four files into four vectors, one for bases, 
    //one for flavors, one for toppings, and one for customer names
    vector<string> allFlavors;
    flavorFile.open(".//data/flavors.dat");
    applyToVector(flavorFile, allFlavors);

    vector<string> allToppings;
    toppingsFile.open(".//data/toppings.dat");
    applyToVector(toppingsFile, allToppings);

    vector<string> allBases;
    basesFile.open(".//data/bases.dat");
    applyToVector(basesFile, allBases);

    vector<string> allNames;
    namesFile.open(".//data/names.dat");
    applyToVector(namesFile, allNames);

    //Makes vectors to represent number of servings of each base, flavor, and topping
    vector<int> flavorServings;
    for(int i = 0; i < allFlavors.size(); i++){
        flavorServings.push_back(3); //Starts off with three servings of each flavor
    }

    vector<int> toppingServings;
    for(int i = 0; i < allToppings.size(); i++){
        toppingServings.push_back(4); //Starts off with four servings of each topping
    }

    vector<int> baseServings;
    for(int i = 0; i < allBases.size(); i++){ //Starts off with five servings of each base
        baseServings.push_back(5);
    }


    
    
    //Makes ice cream shop with vectors of bases, flavors, and toppings, and 1000 dollars
    Shop store = Shop(flavorServings, toppingServings, baseServings, allFlavors, allToppings, allBases, allNames, 1000); 
    
    cout << "Shop has $" << store.getMoney() << endl;

   
    int numDays = (rand()%5)+10; //Shop will run for a random number of days between 10 and 15
    int numCusts = 0; //Counter for served customers

    for(int i = 1; i <= numDays; i++){ //i represents day of shop operation
        for(int h = 1; h <= 8; h++){ //h represents work hour of day
            cout << "Hour " << h << ": " << endl;
            cout << endl;
            for(int c = 1; c <= (rand()%7)+5; c++){ //c represents customer that enters during hour
                store.addCustomer(); //Random number of customer enter each hour
                numCusts++; //Number of customers served increments after each customer
                cout << "Customer enters!" << endl;
                cout << store.getQ().back() << endl; //Prints information about each customer after he or she enters
            }

            while(!store.getQ().empty()){

                cout << store.getQ().front().getName() << " ordered " << store.makeOrder(store.getQ().front()) << endl; //Prints ice cream ordered by customer
                cout << store.getQ().front().getName() << " leaves" << endl;
                store.removeCustomer(); //Customer leaves line (queue)
                cout << endl;
            }
        }

        cout << "Money after day " << i << ": $" << store.getMoney() << endl; //Prints total amount of money shop has after each day
        cout << endl;
    }
    cout << "Total customers served: " << numCusts << " in " << numDays << " days " << endl; //Prints total amount of customers served after all the days
    

    return 0;
}