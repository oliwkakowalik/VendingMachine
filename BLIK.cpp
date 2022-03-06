//
// Created by oliwi on 26.12.2020.
//

#include "BLIK.h"
#include <time.h>
#include <cstdlib>
#include <string>

bool BLIK::pay(Money priceToPay) {
    std::string blik = generateBLIK();
    std::cout << "\nDo zaplaty pozostalo: " << priceToPay << " zl" << "\nKod BLIK wygenerowany do transakcji: "<< blik;
    std::cout<< "\nPodaj kod BLIK (5 prob): ";
    std::string BLIK; getline(std::cin, BLIK);
    if(blik == BLIK) return true;

    int howManyTriesLeft = 4;
    while(howManyTriesLeft){
        std::cout<<"\nZostal wprowadzony niepoprawny kod BLIK, sprobuj ponownie: ";
        getline(std::cin, BLIK);
        howManyTriesLeft--;
        if(blik == BLIK) return true;
    }
    std::cout<< "\nKod BLIK zostal niepoprawnie wpisany 5 razy.";
    return false;
}

std::ostream &BLIK::print(std::ostream &screen) const {
    return screen << "Kod BLIK";
}

std::string BLIK::generateBLIK() {
    std::string blik;
    srand(time(NULL));

    for(int i=0; i<6; i++)
        blik += rand() % 10 + '0';
    return blik;
}



