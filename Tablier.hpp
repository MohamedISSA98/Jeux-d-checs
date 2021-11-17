//
//  Tablier.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 07/02/2021.
//

#ifndef Tablier_hpp
#define Tablier_hpp

#include <cstdio>
#include "Piece.hpp"
#include <string>

class Tablier
{
protected:

    int dim;
    Piece *** plateau;

public:
    Tablier();
    Tablier(const Tablier & T);
    int get_dim() const;
    void set_dim(int dim);
    Piece *** get_plateau() const;
    void affiche();
    ~Tablier();
    Tablier & operator =(const Tablier & E);



};

#endif /* Tablier_hpp */
