//
// Created by oliwi on 17.11.2020.
//

#include <cstring>
#include "Drink.h"

Drink::Drink(int newID, const std::string &newName, Money newPrice, int newAmount) :
ID(newID), Name(newName), Price(newPrice), Amount(newAmount)  {
}

Drink::Drink(const Drink &drink) : Drink(drink.ID, drink.Name, drink.Price, drink.Amount){
}

std::ostream &operator<<(std::ostream &screen, const Drink &drink) {
    screen << "ID:" << drink.ID << " " << drink.Name << "  price: " << drink.Price << " zl  (" << drink.Amount << ")";
    return screen;
}







