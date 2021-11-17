//
//  Piece.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#ifndef Piece_hpp
#define Piece_hpp

#include"TypePiece.hpp"
#include "Coordonnees.hpp"



class Piece
{
    private:
        TypePiece type;
        int couleur;          //0:blanc:joueur humain 1:noir:ordi
        Coordonnees coord;    //coordonnÈes (x,y)
        int deplace=0;



    public:
        Piece(TypePiece,int,Coordonnees);
        Piece(const Piece & Pi);
        Piece();
        virtual ~Piece();
        int get_coul();
        Coordonnees get_coord();
        void set_coord(Coordonnees);
        TypePiece get_TypePiece();
        void affiche();
        void set_type();     /// promotion en Reine pour le pion
        int get_deplace();

};

#endif /* Piece_hpp */
