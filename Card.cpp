//
// Created by oliwi on 26.12.2020.
//

#include "Card.h"

bool Card::pay(Money priceToPay) {
    std::cout << "\nDo zaplaty pozostalo: " << priceToPay << " zl" << "\nZbliz karte wskazanym miejscu i podaj kod PIN (3 proby): ";
    std::string PIN; getline(std::cin, PIN);
    if(checkPIN(PIN)) return true;

    int howManyTriesLeft = 2;
    while(howManyTriesLeft){
        std::cout<<"\nWprowadz PIN ponownie: ";
        getline(std::cin, PIN);
        howManyTriesLeft--;
        if(checkPIN(PIN)) return true;
    }
    std::cout<< "\nKod PIN zostal niepoprawnie wpisany 3 razy. ";
    return false;
}

std::ostream &Card::print(std::ostream &screen) const {
    return screen << "Karta platnicza";

}

bool Card::checkPIN(std::string PIN) const {
    if(PIN.length() != 4) {
        std::cout << "\nKod PIN niepoprawny (zla dlugosc)";
        return false;
    }
    for(int i = 0; i<4 ; i++) {
        if(PIN[i] < '0' || PIN[i] > '9' ) {
            std::cout << "\nKod PIN niepoprawny (niepoprawne znaki)";
            return false;
        }
    }
    return true;
}
