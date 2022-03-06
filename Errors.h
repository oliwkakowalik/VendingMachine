//
// Created by oliwi on 15.01.2021.
//

#ifndef KOWALIKOLIWIA_ETAP2_ERRORS_H
#define KOWALIKOLIWIA_ETAP2_ERRORS_H

struct IDError {
    std::string message = "\nNapoj niedostepny, wybierz inny: ";
};
struct PaymentError {
    std::string message = "\nWybrana platnosc jest niedostepna, wybierz inna: ";
};

#endif //KOWALIKOLIWIA_ETAP2_ERRORS_H
