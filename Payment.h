//
// Created by oliwi on 26.12.2020.
//

#ifndef KOWALIKOLIWIA_ETAP1_PAYMENT_H
#define KOWALIKOLIWIA_ETAP1_PAYMENT_H

#include "Money.h"

class Payment {
public:
    virtual bool pay(Money priceToPay) = 0;
    virtual std::ostream& print(std::ostream & screen) const = 0;
    friend std::ostream& operator<<(std::ostream & screen, Payment & payment){return payment.print(screen);};
};

#endif //KOWALIKOLIWIA_ETAP1_PAYMENT_H
