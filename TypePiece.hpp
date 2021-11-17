//
//  TypePiece.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#ifndef TypePiece_hpp
#define TypePiece_hpp

#include "Coordonnees.hpp"
#include <string>
using namespace std;


class TypePiece
{
    private:
        string type;          //type de la piËce
        int valeur;           //valeur de la piËce
        Coordonnees** depl;   //dÈplacement relatif en (x,y)
        int nb_lignes;
        int nb_colonnes;

    public:
        TypePiece(string);
        TypePiece();
        TypePiece(const TypePiece & type);
        virtual ~TypePiece();
        void affiche();
        string get_type();
        Coordonnees** get_depl();
        TypePiece & operator =(const TypePiece & type);
        int get_valeur();
        int get_nb_lignes();
        int get_nb_colonnes();
        void change_Type(string);

};

#endif /* TypePiece_hpp */
