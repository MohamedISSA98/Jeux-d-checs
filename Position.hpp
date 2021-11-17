//
//  Position.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#ifndef Position_hpp
#define Position_hpp

#include <cstdio>
#include <string>
#include "Echiquier.hpp"
#include "Coup.hpp"

using namespace std;

//template <typename T>
class Position {

    Position * pos_soeur;        // pointeur sur la position soeur
    Position * pos_fille;        // pointeur sur la position fille
    char joueur;                 // 'h' = humain et 'c' = IA(ordi)
public:
    Position get_pos_soeur() const;
    Position get_pos_fille() const;
    void set_pos_soeur(const Position * & pos_soeur);
    void set_pos_fille(const Position * & pos_fille);
    Position(const Position * &,const Position * &,char);    // Constructeur
    //double eval(Echiquier plateau);         // évaluation, plateau = Echiquier || Tic-Tac-Toe
    //int Alphabeta(Echiquier plateau,int profondeur, int alpha, int beta, Coup &meilleur_coup); // Algo alpha-Beta, en Convention NegaMax
    
    // Pour Tic-Tac-Toe faire profondeur = -1 (signifiant que on
    // parcourt jusqu'au bout)
    
};

#endif /* Position_hpp */
