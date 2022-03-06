//
// Created by oliwi on 26.12.2020.
//

#ifndef KOWALIKOLIWIA_ETAP1_CARD_H
#define KOWALIKOLIWIA_ETAP1_CARD_H

#include "Payment.h"
#include <string>

//wartosc 2
class Card : public Payment{
    bool checkPIN(std::string PIN) const;
public:
    virtual bool pay(Money priceOfProduct);
    virtual std::ostream& print(std::ostream & screen) const;

};

#endif //KOWALIKOLIWIA_ETAP1_CARD_H
