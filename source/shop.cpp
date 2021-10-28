//#include "../headers/shop.h"
#include "shop.h"

Shop::Shop(){
    flavorServings.push_back(0);
    toppingsServings.push_back(0);
    baseServings.push_back(0);
    money = 1000;
}

Shop::Shop(vector<int> totalFlavor, vector<int> totalTopping, vector<int> totalBase, vector<string> f, vector<string> t, vector<string> b, vector<string> n, float startMoney){
    flavorServings = totalFlavor;
    toppingsServings = totalTopping;
    baseServings = totalBase;
    flavors = f;
    toppings = t;
    bases = b;
    names = n;

    money = startMoney;
}

float Shop::getMoney(){
    return money;
}

void Shop::makeMoney(float amount){
    money += amount; //Adds specified amount of money
}

void Shop::spendMoney(float amount){
    money -= amount; //Subtracts specified amount of money
}


void Shop::addServings(int numServings, vector<int> servings, int index, string type){
    servings[index] += numServings; //Adds specified number of servings
    //Spends different amounts of money depending on what part of ice cream is being bought (flavor, topping, or base)
    if(type == "flavor"){
        spendMoney(2.5 * numServings);
    }
    if(type == "topping"){
        spendMoney(0.5 * numServings);
    }
    if(type == "base"){
        spendMoney(0.05 * numServings);
    }
}

void Shop::removeServings(int numServings, vector<int> servings, int index, string type){
    servings[index] -= numServings; //Subtracts specified number of servings
    //Makes different amounts of money depending on what part of ice cream is being sold (flavor, topping, or base)
    if(type == "flavor"){
        makeMoney(2.99 * numServings);
    }
    if(type == "topping"){
        makeMoney(0.75 * numServings);
    }
    if(type == "base"){
        makeMoney(0.1 * numServings);
    }
}

void Shop::addCustomer(){
    line.push(Customer(bases, flavors, toppings, names)); //Constructs new customer and adds him or her to end of line
}

void Shop::removeCustomer(){
    
    line.pop(); //Customer at the front of line leaves line
}

queue<Customer> Shop::getQ(){
    return line;
}

IceCream Shop::makeOrder(Customer& cust){

    IceCream order; //Represents one of customer's desired orders
    
    for(int i = 0; i < cust.getPreferences().size(); i++){ //Loops through all of customer's preferences
        order = cust.getPreference(i); //Will return this if customer can order it

    //Finds index of flavor servings vector that correlates to desired flavor
        int efIndex = 0;
        int j = 0;
        while(flavors[j] != order.getFlavor()) {
            j++;
            if(flavors[j] == order.getFlavor()) {
                efIndex = j;
            }
        }

    

    //Finds index of topping servings vector that correlates to desired topping
        int tIndex = 0;
        int j2 = 0;
        while(toppings[j2] != order.getTopping()) {
            j2++;
            if(toppings[j2] == order.getTopping()) {
                tIndex = j2;
            }
        }
        

    //Finds index of base servings vector that correlates to desired base
        int bIndex = 0;
        int j3 = 0;
        while(bases[j3] != order.getBase()) {
            j3++;
            if(bases[j3] == order.getBase()) {
                bIndex = j3;
            }
        }

       

        //Shop buys more servings if they are out of the ones requested
        if(flavorServings[efIndex] <= 0 || toppingsServings[tIndex] <= 0 || baseServings[bIndex] <= 0) {
            if(flavorServings[efIndex] <= 0) {
                addServings(5, flavorServings, efIndex, "flavor");
            }
            if(toppingsServings[tIndex] <= 0) {
                addServings(5, toppingsServings, tIndex, "topping");
            }
            if(flavorServings[efIndex] <= 0) {
                addServings(5, baseServings, bIndex, "base");
            }
           
            if(i == (cust.getPreferences().size()-1)){
                
                return IceCream("no", " ice ", "cream"); //If none of customer's preferences are in stock, customer leaves without getting anything
            }
        }
        //If shop has desired ice cream in stock, servings are sold to customer
        else {
            removeServings(1, flavorServings, efIndex, "flavor");
            removeServings(1, toppingsServings, tIndex, "topping");
            removeServings(1, baseServings, bIndex, "base");
            return order;
            
        }
        // if(i == (cust.getPreferences().size())){
        //     return IceCream("no", " ice ", "cream"); //If none of customer's preferences are in stock, customer leaves without getting anything
        // }
    }
    return IceCream();
}