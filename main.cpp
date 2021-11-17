//
//  main.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#include <iostream>
#include "Coordonnees.hpp"
#include "TypePiece.hpp"
#include "Piece.hpp"
#include "Coup.hpp"
#include "Tablier.hpp"
#include "Echiquier.hpp"
//#include "Position.hpp"
#include <string>

using namespace std;

int main()
{

    int tour=0;
    Echiquier EC;
    while (1){
        EC.Affiche();
        Coup c=EC.retourne_coup_humain(tour);
        Coordonnees resign=c.get_ap();
        if (resign.get_x()==-1){
            if (tour==0){
                cout<< "le gagnant est le joueur noir" <<endl;
                break;
            }
            else{
                cout<< "le gagnant est le joueur blanc" <<endl;
                break;
            }
        }
        else{
            EC.jouer_coup(c);
        }
        tour=1-tour;
    }




    return 0;
}














 
