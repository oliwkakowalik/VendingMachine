//
// Created by oliwi on 26.12.2020.
//

#ifndef KOWALIKOLIWIA_ETAP1_CASH_H
#define KOWALIKOLIWIA_ETAP1_CASH_H


#include "Payment.h"
#include <string>

//wartosc 1
class Cash : public Payment {
    Money priceToPay;

    int readInt();
    bool checkValue (int coin);
    Money intToMoney(int coin);
    bool insertCoin(int coin);
public:
    virtual bool pay(Money priceOfProduct);
    virtual std::ostream& print(std::ostream & screen) const;
};

#endif //KOWALIKOLIWIA_ETAP1_CASH_H
