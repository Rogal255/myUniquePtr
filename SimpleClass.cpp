#include "SimpleClass.hpp"
#include <iostream>

SimpleClass::SimpleClass() {
    std::cout << "SimpleClass c'tor\n";
}
SimpleClass::~SimpleClass() {
    std::cout << "SimpleClass d'tor\n";
}

void SimpleClass::simpleMethod() {
    std::cout << "SimpleMethod\n";
}
