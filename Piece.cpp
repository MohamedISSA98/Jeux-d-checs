//
//  Piece.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#include <iostream>
#include "Piece.hpp"
using namespace std;

Piece::Piece(TypePiece ty, int coul, Coordonnees cr):type(ty),coord(cr)
{
    couleur= coul;
    deplace=0;
    //ctor
}

Piece::Piece(const Piece & Pi):type(Pi.type),couleur(Pi.couleur),coord(Pi.coord),deplace(Pi.deplace)
{}


Piece::Piece()
{
    type=TypePiece();
    couleur=-1;
    coord=Coordonnees();
}

Piece::~Piece()
{
    //dtor
}

int Piece::get_coul()
{
    return couleur;
}

Coordonnees Piece::get_coord()
{
    return coord;
}

void Piece::set_coord(Coordonnees cor)
{
    coord=cor;
    deplace=1;
}


TypePiece Piece::get_TypePiece(){
    return type;
}



int Piece::get_deplace(){
return deplace;
}


void Piece::set_type(){
    type.change_Type("Reine");
}


void Piece::affiche()
{
    if (couleur==0){
        cout<<type.get_type()<<"Blanc ‡ ("<<coord.get_x()<<","<<coord.get_y()<<")"<<endl;
    }
    else
        cout<<type.get_type()<<"Noir ‡ ("<<coord.get_x()<<","<<coord.get_y()<<")"<<endl;
}
