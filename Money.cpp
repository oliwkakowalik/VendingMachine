//
// Created by oliwi on 23.11.2020.
//

#include "Money.h"

Money::Money(int newZL, int newGR) : ZL(newZL), GR(newGR) {
}

Money::Money(const Money &money) : Money(money.ZL, money.GR){
}

std::ostream &operator<<(std::ostream &screen, const Money &money) {
    screen << money.ZL << "." << money.GR;
    return screen;
}

Money &Money::operator-=(const Money &money) {
    int m1, m2;
    m1 = money.GR + 100*money.ZL;
    m2 = this->GR + 100*this->ZL;
    this->ZL = (m2 - m1) / 100;
    this->GR = (m2 - m1) % 100;
    return *this;
}

bool Money::operator>(const Money &money) const {
    return this->ZL > money.ZL || (this->ZL == money.ZL && this->GR > money.GR);
}










