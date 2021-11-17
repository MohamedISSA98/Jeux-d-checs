//
//  Echiquier.hpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 31/01/2021.
//

#ifndef Echiquier_hpp
#define Echiquier_hpp




#include "Tablier.hpp"
#include <cstdio>
#include "Piece.hpp"
#include "TypePiece.hpp"
//#include "Position.hpp"
#include "Coup.hpp"

class Echiquier : public Tablier {

public:
    Echiquier();
    Echiquier(const Echiquier & E);     // Constructeur par copie
    Piece* get_Piece(int x,int y);       // Pour atteindre la piÃ¨ce au coords donnÃ©es
    void Affiche();                     // fonction d'affichage de l'Ã©chiquier
    void deplace(Coordonnees av,Coordonnees ap); //deplace la piece qui se trouve dans Coordonnees av aux coordonnees ap
    void jouer_coup(Coup);                     //jouer le coup c
    bool ** controle(int coul);                // les cases controlées par le joueur de couleur coul
    void affiche_controle(bool **);
    bool verif_deplac(Piece* P,Coordonnees cor); //verifie le deplacement de la piece pointée par P vers cor
    bool Piece_controle (Coordonnees);            //verifie si une Piece est atteignable par l'adversaire
    bool Echec(int coul);
    Coup retourne_coup_humain(int tour);            //demande au joueur humain de jouer un coup
};

double eval(Echiquier plateau);         // évaluation, plateau = Echiquier || Tic-Tac-Toe
int Alphabeta(Echiquier plateau,int profondeur, int alpha, int beta, Coup &meilleur_coup); // Algo alpha-Beta,



#endif /* Echiquier_hpp */
