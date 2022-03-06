//
// Created by oliwi on 17.11.2020.
//

#include "Machine.h"
#include <iostream>
#include "Errors.h"
#include "Cash.h"
#include "Card.h"
#include "BLIK.h"


Machine::Machine(int paymentsCombination) {
    Payment* cash = nullptr;
    Payment* card = nullptr;
    Payment* blik = nullptr;

    switch (paymentsCombination) {
        case 1:
            cash = new Cash;
            payments.PushBack(cash);
            break;

        case 2:
            card = new Card;
            payments.PushBack(card);
            break;

        case 4:
            blik = new BLIK;
            payments.PushBack(blik);
            break;

        case 3:
            cash = new Cash;
            payments.PushBack(cash);
            card = new Card;
            payments.PushBack(card);
            break;

        case 5:
            cash = new Cash;
            payments.PushBack(cash);
            blik = new BLIK;
            payments.PushBack(blik);
            break;

        case 6:
            card = new Card;
            payments.PushBack(card);
            blik = new BLIK;
            payments.PushBack(blik);
            break;

        case 7:
            cash = new Cash;
            payments.PushBack(cash);
            card = new Card;
            payments.PushBack(card);
            blik = new BLIK;
            payments.PushBack(blik);
            break;

        default:
            std::cout << "Nieudane utworzenie wektora platnosci, automat niekompletny";
            break;

    }
}

Machine::Machine(int _paymentsCombination, Drink* d0, Drink* d1, Drink* d2, Drink* d3) : Machine(_paymentsCombination){
    drinks.PushBack(d0);
    drinks.PushBack(d1);
    drinks.PushBack(d2);
    drinks.PushBack(d3);
}

void Machine::printDrinks() const{
    std::cout << "\n------------ DRINKS ------------\n";
    for (int i = 0; i < 4; i++) {
        if (this->drinks[i]->getAmount() > 0) //wypisuje tylko dostepne napoje
            std::cout << *(this->drinks[i]) << std::endl;
    }
    std::cout << "--------------------------------\n";
}

bool Machine::chooseDrink(int choice) {
    if( choice < 1 || choice > 4 || this->drinks[choice - 1]->getAmount() < 1) {
        IDError error;
        throw error;
    }

    this->drinkIndex = choice-1;
    this->priceToPay = this->drinks[drinkIndex]->getPrice();
    return true;
}

int Machine::getDrinksAmount() const {
    int amount = 0;
    for(int i = 0; i < this->drinks.Size(); i++)
        amount+=this->drinks[i]->getAmount();
    return amount;
}

void Machine::printPayments() const {
    std::cout << "\nMetody platnosci obslugiwane przez automat:";
    for(int i = 0; i < payments.Size(); i++)
        std::cout << "\n" << i+1 << ". " << *(payments[i]);
}

bool Machine::choosePayment(int choice) {
    if( choice < 1 || choice > payments.Size()) {
        PaymentError error;
        throw error;
    };

    paymentIndex = choice-1;
    return true;
}

bool Machine::payment() {
    if (payments[paymentIndex]->pay(this->priceToPay)) {
        this->drinks[drinkIndex]->amountDecrementation();
        this->paymentIndex = -1;
        this->drinkIndex = -1;
        return true;
    }
    this->paymentIndex = -1;
    this->drinkIndex = -1;
    return false;
}

Machine::~Machine() {
    while(payments.Size()>0)
        payments.remove( payments.Size() -1);
    while(drinks.Size()>0)
        drinks.remove( drinks.Size() -1);
}





