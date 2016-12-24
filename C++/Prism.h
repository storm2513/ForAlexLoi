//
//  Prism.h
//  C++
//
//  Created by Максим Шилов on 24.12.16.
//  Copyright © 2016 Максим Шилов. All rights reserved.
//

#ifndef Prism_h
#define Prism_h


#endif /* Prism_h */
#include <iostream>
#include <cmath>
#include "getters.h"
using namespace std;

class Prism{
private:
    double value, height, squareOfBase;
    double *lengthOfSides;
    
    double calculateSquareOfBase(){
        double a = lengthOfSides[0], b = lengthOfSides[1], c = lengthOfSides[2];
        double halfPerimeter = (a + b + c) / 2.0;
        double square = sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
        return square;
    }
    
    double calculateValue(){
        double value = squareOfBase * height;
        return value;
    }
    
    void getInfo(){
        cout << "--------------------------------" << endl;
        cout << "Объём -- " << value << endl
        << "Площадь основания -- " << squareOfBase << endl
        << "Высота -- " << height << endl;
        cout << "Длины сторон основания: ";
        cout << lengthOfSides[0] << ", " << lengthOfSides[1] << ", " << lengthOfSides[2] << endl;
        cout << "--------------------------------" << endl;
    }
    
    void edit(){
        cout << "Что ты хочешь отредактировать?\n1. Высоту\n2. Длины сторон\n0. Ничего, я случайно сюда попал\n";
        int n;
        cin >> n;
        switch(n){
            case 1:
                cout << "Введи новую высоту: ";
                height = getHeight();
                break;
            case 2:
                lengthOfSides = getLengthOfSides();
                break;
            case 0:
                break;
        }
        squareOfBase = calculateSquareOfBase();
        value = calculateValue();
    }
    
public:
    Prism(double _height, double* _lengthOfSides){
        height = _height;
        lengthOfSides = _lengthOfSides;
        squareOfBase = calculateSquareOfBase();
        value = calculateValue();
    }
    void showMenu(){
        while(true){
            cout << "1. Показать информацию о призме\n2. Отредактировать параметры призмы\n0. Выход\n";
            int n;
            cin >> n;
            switch(n){
                case 1:
                    getInfo();
                    break;
                case 2:
                    edit();
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    cout << "Введи корректный номер:\n";
                    break;
            }
        }
    }
};
