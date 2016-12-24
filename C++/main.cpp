//
//  main.cpp
//  C++
//
//  Created by Максим Шилов on 24.12.16.
//  Copyright © 2016 Максим Шилов. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "prism.h"
using namespace std;

int main() {
    double height;
    double* lengthOfSides;
    cout << "Введи высоту призмы: ";
    height = getHeight();
    cout << "Отлично! Теперь введи стороны основания\n";
    lengthOfSides = getLengthOfSides();
    Prism myPrism(height, lengthOfSides);
    myPrism.showMenu();
    return 0;
}
