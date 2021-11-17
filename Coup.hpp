//
//  Coup.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#ifndef Coup_hpp
#define Coup_hpp

#include "Piece.hpp"
#include "Coordonnees.hpp"


class Coup
{

    private:
         int coul;
         Piece P;
         Coordonnees av;   //coordonnÈes avant
         Coordonnees ap;   //coordonnÈes aprËs
         int pr;        //0: pas de prise 1:prise
         int sp; //0: coup spÈcial 1: pas de coup spÈcial


    public:
        Coup(int, Piece,Coordonnees,Coordonnees,int,int);
        Coup();
        Coup(const Coup & C);
        Coup & operator =(const Coup & c);
        ~Coup();
        int get_coul();
        Piece get_P();
        Coordonnees get_av();
        Coordonnees get_ap();
        int get_pr();
        int get_sp();

};

#endif /* Coup_hpp */
