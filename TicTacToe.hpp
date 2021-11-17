//
//  TicTacToe.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 07/02/2021.
//

#ifndef TicTacToe_hpp
#define TicTacToe_hpp

#include <stdio.h>
#include "Tablier.hpp"

class TicTacToe : public Tablier
{
public:
    TicTacToe();
    TicTacToe(const TicTacToe & T); // Constructeur par copie

};

#endif /* TicTacToe_hpp */
