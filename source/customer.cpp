//#include "../headers/customer.h"
//#include "../headers/iceCream.h"

#include "customer.h" 
//#include "iceCream.h" //In customer.h we include iceCream.h

//Used for randomly generating preferences
#include <cstdlib>
#include <ctime>

Customer::Customer(){
    preferences.push_back(IceCream("bowl", "vanilla", "no topping"));
    name = "Bob";
}

Customer::Customer(vector<string> bases, vector<string> flavors, vector<string> toppings, vector<string> names){
    
    generatePreference(((rand()%5)+1), bases, flavors, toppings); //Randomly generates a random number of preferences every time customer is constructed
    
    name = names[rand()%names.size()]; //Name is randomly assigned to each customer
}

string Customer::getName(){
    return name;
}

IceCream Customer::getPreference(int index){
    
    return preferences[index];
}

vector<IceCream> Customer::getPreferences(){
    return preferences;
}

void Customer::generatePreference(int numPreferences, vector<string> bases, vector<string> flavors, vector<string> toppings){
    //srand(time(NULL));
    for(int i=0; i<numPreferences; i++){ //iterates numPreferences number of times
        
        //srand(time(NULL)); //creates a new seed for rand
        string randBase = bases[rand()%bases.size()];

        //srand(time(NULL));
        string randFlavor = flavors[rand()%flavors.size()];

        //srand(time(NULL));
        string randTopping = toppings[rand()%toppings.size()];


        //sets preferences at index i to an IceCream with a random base, a random flavor, and a random topping
        preferences.push_back(IceCream(randBase, randFlavor, randTopping)); 
        //cout << preferences[i] << endl;//prints the preference
    }

}

void Customer::printPreferences(){
    for(int i = 0; i < preferences.size(); i++){ //itereates through the preferences vector
        cout << preferences[i] << endl; //prints the ice cream at index i
    }
}

string Customer::toString(){
    string info;

    info += "The customer's name is: ";
    info += name;
    info += " and their preferences are: ";

    for(int i = 0; i < preferences.size(); i++) {
        info += "\n";
        info += preferences[i].toString() ;
    }
    info += "\n";

    return info;
}

ostream& operator<<(ostream& out, Customer cust) {
    out << cust.toString();

    return out;
}