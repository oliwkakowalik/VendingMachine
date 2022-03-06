//
// Created by oliwi on 14.01.2021.
//

#ifndef KOWALIKOLIWIA_ETAP2_CONTAINER_H
#define KOWALIKOLIWIA_ETAP2_CONTAINER_H

#include <iostream>

template <typename T>
class Container {
    T *Table = nullptr;
    int currentCapacity = 0;
    int currentSize = 0;

    void ReAlloc(int newCapacity);
public:
    Container() {ReAlloc(2);};
    ~Container();

    void PushBack(T& t);
    int Size() const {return this->currentSize;};
    T operator[](int index) const {return this->Table[index];};
    void remove(int index);
};

template<typename T>
void Container<T>::ReAlloc(int newCapacity) {
    T* newBlock = new T[newCapacity];

    if(newCapacity < this->currentSize)
        this->currentSize = newCapacity;

    for(int i = 0; i < this->currentSize; i++)
        newBlock[i]=this->Table[i];

    delete[] this->Table;
    this->Table=newBlock;
    this->currentCapacity=newCapacity;
}

template<typename T>
void Container<T>::PushBack(T& t) {
    if(this->currentSize >= this->currentCapacity)
        ReAlloc(this->currentCapacity * 2);

    this->Table[currentSize++]=t;
    //currentSize++;
}

template<typename T>
Container<T>::~Container() {
    currentSize = 0;
    currentCapacity = 0;
    delete[] this->Table;
}

template<typename T>

void Container<T>::remove(int index) {
    delete Table[index];

while(index < currentSize-1) {
    Table[index] = Table[index+1];
    index++;
}
    currentSize--;
}

#endif //KOWALIKOLIWIA_ETAP2_CONTAINER_H