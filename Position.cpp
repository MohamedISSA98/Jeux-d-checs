//
//  Position.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//


#include "Position.hpp"
#include "Coordonnees.hpp"
#include <cmath>

Position Position::get_pos_soeur() const{  return *pos_soeur; }
Position Position::get_pos_fille() const{  return *pos_fille; }

void Position::set_pos_soeur(const Position * & pos_soeur)
{
    *this->pos_soeur = *pos_soeur;
}

void Position::set_pos_fille(const Position * & pos_fille)
{
    *this->pos_fille = *pos_fille;
}



Position::Position(const Position * & pos_soeur,const Position * & pos_fille,char joueur)  // Constructeur
{
    this->set_pos_soeur(pos_soeur);
    this->set_pos_fille(pos_fille);
    
}


