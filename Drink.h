//
// Created by oliwi on 17.11.2020.
//

#ifndef PROJEKT38_DRINK_H
#define PROJEKT38_DRINK_H
#include <iostream>
#include "Money.h"
#include <string>

class Drink {
    int ID;
    std::string Name;
    Money Price;
    int Amount;
public:
    explicit Drink(int newID = 0, const std::string &newName = "default", Money newPrice = Money(0,0), int newAmount = 0);
    Drink(const Drink &drink);

    friend std::ostream & operator<<(std::ostream & screen, const Drink & drink);

    Money getPrice() const {return this->Price;};
    int getAmount() const {return this->Amount;};

    void amountDecrementation() {this->Amount--;};

};

#endif //PROJEKT38_DRINK_H
