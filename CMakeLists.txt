cmake_minimum_required(VERSION 3.17)
project(KowalikOliwia-etap3)

set(CMAKE_CXX_STANDARD 14)

add_executable(KowalikOliwia-etap3
        main.cpp
        Machine.cpp Machine.h
        Drink.cpp Drink.h
        Money.cpp Money.h
        Interface.cpp Interface.h
        Cash.cpp Cash.h
        Card.cpp Card.h
        BLIK.cpp BLIK.h
        Payment.h
        Container.h
        Errors.h
        stdin.txt)