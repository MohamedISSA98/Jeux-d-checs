//
//  Coordonnees.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 07/02/2021.
//

#ifndef Coordonnees_hpp
#define Coordonnees_hpp

#include <stdio.h>


class Coordonnees
{
    public:
        Coordonnees (int,int);
        Coordonnees();
        Coordonnees (const Coordonnees& C);
        //~Coordonnees();
        int get_x();
        int get_y();
        void set_x(int);
        void set_y(int);
        bool verif_coord();     //vÈrifie si les coordonnees sont ‡ l'intÈrieur de l'Èchiquier
        void affiche();


    private:
        int x;
        int y;
};


#endif /* Coordonnees_hpp */
