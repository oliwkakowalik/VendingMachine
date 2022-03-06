//
// Created by oliwi on 26.12.2020.
//

#include "Cash.h"

bool Cash::pay(Money priceOfProduct) {
   this->priceToPay  = priceOfProduct;
   while(this->priceToPay > Money(0,0)) {

       std::cout << "\nDo zaplaty pozostalo: " << this->priceToPay << " zl";
       std::cout << "\nWrzuc monete: ";
       int coin = readInt();

       if(!checkValue(coin) )
           std::cout << "\nWrzuc poprawny nominal.\n";
       else if(!this->insertCoin(coin))
           std::cout << "\nWrzuc mniejszy nominal.\n";
   }
    return true;
}

bool Cash::checkValue(int coin) {
        return coin==1 || coin==2 || coin==5 || coin==10 || coin==20 || coin==50;
}

int Cash::readInt() {
    std::string line;
    getline(std::cin, line);
    return atoi(line.c_str());
}
Money Cash::intToMoney(int coin) {
    return coin <= 5 ? Money(coin, 0) : Money(0, coin%100);
}

bool Cash::insertCoin(int coin) {
    Money newCoin = intToMoney(coin);
    if(newCoin > this->priceToPay) return false;

    this->priceToPay -= newCoin;
    return true;
}

std::ostream &Cash::print(std::ostream &screen) const {
    return screen << "Gotowka";
}


