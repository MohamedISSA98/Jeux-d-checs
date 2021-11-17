//
//  Coordonnees.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 07/02/2021.
//

#include <iostream>
#include "Coordonnees.hpp"
using namespace std;


Coordonnees::Coordonnees(int x, int y)
{
    this->x=x;
    this->y=y;
    //ctor
}

Coordonnees::Coordonnees()
{
    x=0;
    y=0;
}

Coordonnees::Coordonnees (const Coordonnees& C):x(C.x),y(C.y)
{
}

int Coordonnees::get_x()
{
    return x;
}

int Coordonnees::get_y()
{
    return y;
}

/*Coordonnees::~Coordonnees()
{
    //dtor
}*/

void Coordonnees::set_x(int x1)
{
    x=x1;
}

void Coordonnees::set_y(int y1)
{
    y=y1;
}

bool Coordonnees::verif_coord(){
    return ((x>=0)&&(x<=7)&&(y>=0)&&(y<=7));
}

void Coordonnees::affiche(){
    cout <<"("<<x<<","<<y<<")"<<endl;
}
