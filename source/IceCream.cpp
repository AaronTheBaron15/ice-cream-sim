
#include "iceCream.h" //Uses ice cream class
#include <iostream> //Used for cout

IceCream::IceCream(){
    base = "Sugar cone";
    flavor = "Vanilla";
    topping = "nada";
}

IceCream::IceCream(string b, string f, string t){
    base = b;
    flavor = f;
    topping = t;
}

string IceCream::getBase(){
    return base;
}

string IceCream::getFlavor(){
    return flavor;
}

string IceCream::getTopping(){
    return topping;
}

string IceCream::toString(){
    string info;

    info += base;
    info += " of ";
    info += flavor;
    info += " with ";
    info += topping;

    return info;
}

ostream& operator<<(ostream& out, IceCream cream) {
    out << cream.toString();

    return out;
}

