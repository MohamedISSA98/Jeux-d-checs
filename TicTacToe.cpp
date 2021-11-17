//
//  TicTacToe.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 07/02/2021.
//

#include "TicTacToe.hpp"

TicTacToe::TicTacToe()
{
    this->dim =3;
    this->plateau = new Piece**[3];
    for (int i=0; i<3; i++)
    {
        this->plateau[i] = new Piece*[3];
    }

}


TicTacToe::TicTacToe(const TicTacToe & T) // Constructeur par copie
: Tablier(T) {}
