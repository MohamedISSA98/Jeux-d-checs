//
//  TypePiece.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 28/01/2021.
//

#include <iostream>
#include "TypePiece.hpp"
#include <string>
using namespace std;




TypePiece::TypePiece(){
    type="";
    depl=nullptr;
    valeur=0;
    nb_lignes=0;
    nb_colonnes=0;
}





TypePiece::TypePiece(string nom)
{
    //char* type=new char[10];
    type=nom;
    //strcpy(type,nom);
    //char x=cr.get_x();
    //int y=cr.get_y();
    if (type=="roi")
    {
        valeur=0;
        nb_lignes=8;
        nb_colonnes=1;
        depl=new Coordonnees*[8];
        for (int i=0;i<8;i++){
            depl[i]=new Coordonnees[1];
        }

        depl[0][0]=Coordonnees(1,0);
        depl[1][0]=Coordonnees(1,1);
        depl[2][0]=Coordonnees(0,1);
        depl[3][0]=Coordonnees(-1,1);
        depl[4][0]=Coordonnees(-1,0);
        depl[5][0]=Coordonnees(-1,-1);
        depl[6][0]=Coordonnees(0,-1);
        depl[7][0]=Coordonnees(1,-1);
    }

    else if(type=="Pion"){
        valeur=1;
        nb_lignes=1;
        nb_colonnes=2;
        depl= new Coordonnees*[1];
        depl[0]=new Coordonnees[2];
        depl[0][0]=Coordonnees(0,1);
        depl[0][1]=Coordonnees(0,2);
    }
    else if(type=="Tour"){
        valeur=5;
        nb_lignes=4;
        nb_colonnes=7;
        depl=new Coordonnees*[4];
        for (int i=0;i<4;i++){
            depl[i]=new Coordonnees[7];
            }
        for (int i=1;i<8;i++){
            depl[0][i-1]=Coordonnees(i,0);
            depl[1][i-1]=Coordonnees(0,i);
            depl[2][i-1]=Coordonnees(-i,0);
            depl[3][i-1]=Coordonnees(0,-i);
            }
    }

    else if(type=="Fou"){
        valeur=3;
        nb_lignes=4;
        nb_colonnes=7;
        depl=new Coordonnees*[4];
        for (int i=0;i<4;i++){
            depl[i]=new Coordonnees[7];
            }
        for (int i=1;i<8;i++){
            depl[0][i-1]=Coordonnees(i,i);
            depl[1][i-1]=Coordonnees(-i,i);
            depl[2][i-1]=Coordonnees(-i,-i);
            depl[3][i-1]=Coordonnees(i,-i);
            }
    }


    else if(type=="Reine"){
        valeur=9;
        nb_lignes=8;
        nb_colonnes=7;
        depl=new Coordonnees*[8];
        for (int i=0;i<8;i++){
            depl[i]=new Coordonnees[7];
            }
        for (int i=1;i<8;i++){
            depl[0][i-1]=Coordonnees(i,0);
            depl[1][i-1]=Coordonnees(0,i);
            depl[2][i-1]=Coordonnees(-i,0);
            depl[3][i-1]=Coordonnees(0,-i);
            depl[4][i-1]=Coordonnees(i,i);
            depl[5][i-1]=Coordonnees(-i,i);
            depl[6][i-1]=Coordonnees(-i,-i);
            depl[7][i-1]=Coordonnees(i,-i);
            }
    }


    else if(type=="Cavalier"){
        valeur=3;
        nb_lignes=8;
        nb_colonnes=1;
        depl=new Coordonnees*[8];
        for (int i=0;i<8;i++){
            depl[i]=new Coordonnees[1];
            }
        depl[0][0]=Coordonnees(2,1);
        depl[1][0]=Coordonnees(1,2);
        depl[2][0]=Coordonnees(-1,2);
        depl[3][0]=Coordonnees(-2,1);
        depl[4][0]=Coordonnees(-2,-1);
        depl[5][0]=Coordonnees(-1,-2);
        depl[6][0]=Coordonnees(1,-2);
        depl[7][0]=Coordonnees(2,-1);
        }


}   //ctor


TypePiece::~TypePiece()
{

    for (int i=0;i<nb_lignes;i++){
            delete [] depl[i];
    }
    delete [] depl;
    //dtor
}

TypePiece::TypePiece(const TypePiece & Tp):type(Tp.type),valeur(Tp.valeur),nb_lignes(Tp.nb_lignes),nb_colonnes(Tp.nb_colonnes)
{
    depl=new Coordonnees*[nb_lignes];
    for (int i=0; i<nb_lignes; i++){

        depl[i]=new Coordonnees[nb_colonnes];
        for (int j=0; j<nb_colonnes; j++){
            depl[i][j]=Tp.depl[i][j];
        }

    }
}
TypePiece & TypePiece::operator =(const TypePiece & type)
{
    this->type = type.type;
    this->valeur = type.valeur;
    this->nb_lignes = type.nb_lignes;
    this->nb_colonnes = type.nb_colonnes;

    for (int i=0;i<nb_lignes;i++){
            delete [] depl[i];
    }
    delete [] depl;

    this->depl = new Coordonnees*[nb_lignes];

    for (int i=0; i < nb_lignes; i++)
    {
        this->depl[i] = new Coordonnees[nb_colonnes];
        for (int j=0; j < nb_colonnes; j++)
        {
            this->depl[i][j] = type.depl[i][j];
        }
    }
    return *this;
}


string TypePiece::get_type()
{
    return type;
}

Coordonnees** TypePiece::get_depl()
{
    return depl;
}

int TypePiece::get_valeur()
{
    return valeur;
}


int TypePiece::get_nb_lignes()
{
    return nb_lignes;
}


int TypePiece::get_nb_colonnes()
{
    return nb_colonnes;
}

void TypePiece::change_Type(string s){

    for (int i=0;i<nb_lignes;i++){
            delete [] depl[i];
    }
    delete [] depl;
    this->type=s;
    valeur=9;
    nb_lignes=8;
    nb_colonnes=7;
    depl=new Coordonnees*[8];
    for (int i=0;i<8;i++){
        depl[i]=new Coordonnees[7];
    }
    for (int i=1;i<8;i++){
        depl[0][i-1]=Coordonnees(i,0);
        depl[1][i-1]=Coordonnees(0,i);
        depl[2][i-1]=Coordonnees(-i,0);
        depl[3][i-1]=Coordonnees(0,-i);
        depl[4][i-1]=Coordonnees(i,i);
        depl[5][i-1]=Coordonnees(-i,i);
        depl[6][i-1]=Coordonnees(-i,-i);
        depl[7][i-1]=Coordonnees(i,-i);
    }

}

void TypePiece::affiche()
{
    cout<<type<<endl;
    for (int i=0;i<nb_lignes;i++){
            for (int j=0;j<nb_colonnes;j++){
                    depl[i][j].affiche();
            }
    }
}














