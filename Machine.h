//
// Created by oliwi on 17.11.2020.
//

#ifndef PROJEKT38_MACHINE_H
#define PROJEKT38_MACHINE_H

#include <vector>
#include "Drink.h"
#include "Payment.h"
#include "Container.h"

class Machine {
    int drinkIndex = -1;
    int paymentIndex = -1;
    Money priceToPay = Money(0,0);
    Container<Payment*> payments;
    Container<Drink*> drinks;
public:
    explicit Machine(int  paymentsCombination = 1);
    Machine(int _paymentsCombination, Drink* d0, Drink* d1, Drink* d2, Drink* d3);
    ~Machine();

    void printDrinks() const;
    void printPayments() const;
    bool chooseDrink(int choice);
    bool choosePayment(int choice);
    bool payment();

    int getDrinksAmount() const;
    int getDrinkIndex() const {return this->drinkIndex;};
    int getPaymentIndex() const {return this->paymentIndex;}
};

#endif //PROJEKT38_MACHINE_H
