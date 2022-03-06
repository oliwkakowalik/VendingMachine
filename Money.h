//
// Created by oliwi on 23.11.2020.
//

#ifndef PROJEKT38_MONEY_H
#define PROJEKT38_MONEY_H

#include <iostream>

class Money {
    int ZL;
    int GR;
public:
    explicit Money(int newZL = 0, int newGR = 0);
    Money(const Money &money);

    Money& operator-=(const Money&money);
    bool operator>(const Money & money) const;
    friend std::ostream & operator<<(std::ostream & screen, const Money & money);
};


#endif //PROJEKT38_MONEY_H
