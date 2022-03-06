#include "Interface.h"
#include "Errors.h"
//
// Created by oliwi on 28.11.2020.
//

int Interface::readInt() {
    std::string line;
    getline(std::cin, line);
    return atoi(line.c_str());
}

Interface::Interface() {

    this->automat = new Machine(7,
                            new Drink(1, "cola", Money(2,0), 3),
                            new Drink(2, "pepsi", Money(3,70), 3),
                            new Drink(3, "fanta", Money(6,10), 3),
                            new Drink(4, "sprite", Money(10, 0),3));
}

void Interface::choiceOfDrink() {
    std::cout <<"\nWybierz napoj (podaj ID): ";
    int choice = readInt();

       while (automat->getDrinkIndex() == -1) {
           try {
           automat->chooseDrink(choice);
           }
           catch ( IDError& error){
               std::cout << error.message;
               choice = readInt();
           }
       }
}

void Interface::choiceOfPayment() {
    std::cout <<"\n\nWybierz platnosc: ";
    int choice = readInt();

    while(automat->getPaymentIndex() == -1){
        try {
            automat->choosePayment(choice);
        }
        catch (PaymentError& error){
            std::cout << error.message;
            choice = readInt();
        }
    }
}

bool Interface::condition(){
    if(!automat->getDrinksAmount()){
        std::cout<<"\nBrak dostepnych napojow";
        return false;
    }
    else if(!this->wannaContinue){
        std::cout<<"\nZdecydowales sie zakonczyc zakupy, dziekujemy!";
        return false;
    }
    return true;
}

void Interface::run() {
    automat->printDrinks();
    choiceOfDrink();
    automat->printPayments();
    choiceOfPayment();

    if(automat->payment()) std::cout << "\nTransakcja przebiegla pomyslnie, zapraszamy ponownie.\n\n";
    else  std::cout << "Transakcja nie powiodla sie, zapraszamy ponownie.\n";

    std::cout << "Jesli chcesz kontynowac wybierz 1\n";
    std::string ifCointinue; getline(std::cin, ifCointinue);
    if(ifCointinue != "1") this->wannaContinue = false;
}

Interface::~Interface() {
    delete this->automat;
}




