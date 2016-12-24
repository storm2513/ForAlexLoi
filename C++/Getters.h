//
//  Getters.h
//  C++
//
//  Created by Максим Шилов on 24.12.16.
//  Copyright © 2016 Максим Шилов. All rights reserved.
//

#ifndef Getters_h
#define Getters_h


#endif /* Getters_h */
#include <iostream>
using namespace std;

double* getLengthOfSides(){
    bool bad = true;
    double* lengthOfSides = new double[3];
    while (bad){
        for (int i = 0; i < 3; i++){
            cout << "Введи " << i + 1 << "-ую сторону: ";
            cin >> lengthOfSides[i];
        }
        double a = lengthOfSides[0], b = lengthOfSides[1], c = lengthOfSides[2];
        if((a > 0) && (b > 0) && (c > 0) && (a + b > c) && (b + c > a) && (c + a > b))
            bad = false;
        else
            std::cout << "Треугольник с указанными сторонами не существует. Введи стороны заново: " << endl;
    }
    return lengthOfSides;
}

double getHeight(){
    double height;
    while(true){
        cin >> height;
        if(height <= 0){
            cout << "Введи корректную высоту: \n";
        }
        else
            break;
    }
    return height;
}
