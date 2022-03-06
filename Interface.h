//
// Created by oliwi on 28.11.2020.
//

#ifndef PROJEKT38_INTERFACE_H
#define PROJEKT38_INTERFACE_H

#include "Machine.h"

class Interface {
    Machine* automat;
    bool wannaContinue = true;

    int readInt();
public:
     Interface();
    ~Interface();

    void choiceOfDrink();
    void choiceOfPayment();
    bool condition();
    void run();
};
#endif //PROJEKT38_INTERFACE_H
