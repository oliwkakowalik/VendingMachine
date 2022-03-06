//
// Created by oliwi on 26.12.2020.
//

#ifndef KOWALIKOLIWIA_ETAP1_BLIK_H
#define KOWALIKOLIWIA_ETAP1_BLIK_H

#include "Payment.h"

//wartosc 4
class BLIK : public Payment{
    std::string generateBLIK();
public:
    virtual bool pay(Money priceToPay);
    virtual std::ostream& print(std::ostream & screen) const;
};
#endif //KOWALIKOLIWIA_ETAP1_BLIK_H
