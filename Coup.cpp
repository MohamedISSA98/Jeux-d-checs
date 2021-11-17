//
//  Coup.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#include "Coup.hpp"
//#include "Piece.h"

Coup::Coup(int coul,Piece P, Coordonnees a, Coordonnees b,int pr,int sp):P(P),av(a),ap(b)
{
    this->coul=coul;
    this->pr=pr;           //0 pas de prise sinon prise
    this->sp=sp;    //0 pas de coup spec sinon coup spec

    //ctor
}

Coup::Coup(const Coup & C):coul(C.coul),P(C.P),av(C.av),ap(C.ap),pr(C.pr),sp(C.sp)
{}

Coup::Coup(){
coul=-1;
P=Piece();
av=Coordonnees();
ap=Coordonnees();
pr=0;
sp=0;
}

Coup & Coup::operator =(const Coup & C)
{
    this->coul= C.coul;
    this->P = C.P;
    this->av= C.av;
    this->ap= C.ap;
    this->pr= C.pr;
    this->sp= C.sp;
    return *this;
}

Coup::~Coup()
{
    //dtor
}

int Coup::get_coul(){
    return coul;
}

Piece Coup::get_P(){
    return P;
}

Coordonnees Coup::get_av(){
    return av;
}


Coordonnees Coup::get_ap(){
    return ap;
}

int Coup::get_pr(){
    return pr;
}

int Coup::get_sp(){
    return sp;
}












