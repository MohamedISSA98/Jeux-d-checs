//
//  Echiquier.cpp
//  Projet jeu d'échecs
//
//  Created by Omar Abdoulaye BADIANE on 31/01/2021.
//


#include "Tablier.hpp"
#include "Echiquier.hpp"
#include "Piece.hpp"
#include <cmath>
#include <iostream>


using namespace std;

Echiquier::Echiquier()  // Ici on va initialiser notre plateau
{
    this->dim =8;
    this->plateau = new Piece**[8];
    for (int i=0; i<8; i++)
    {
        this->plateau[i] = new Piece*[8];

        for (int j=0; j<8; j++)
        {
            this->plateau[i][j] = NULL;
        }

    }




    for (int i=0; i<8; i++)
    {
        plateau[i][1] = new Piece(TypePiece("Pion"), 0, Coordonnees(i,1));
        plateau[i][6] = new Piece(TypePiece("Pion"), 1, Coordonnees(i,6));

        if(i == 0 or i==7 )
        {
            plateau[i][0] = new Piece(TypePiece("Tour"), 0, Coordonnees(i,0));
            plateau[i][7] = new Piece(TypePiece("Tour"), 1, Coordonnees(i,7));
        }
        else if (i == 1 or i == 6)
        {
            plateau[i][0] = new Piece(TypePiece("Cavalier"), 0, Coordonnees( i,0));
            plateau[i][7] = new Piece(TypePiece("Cavalier"), 1, Coordonnees( i,7));
        }
        else if (i == 2 or i == 5)
        {
            plateau[i][0] = new Piece(TypePiece("Fou"), 0, Coordonnees( i,0));
            plateau[i][7] = new Piece(TypePiece("Fou"), 1, Coordonnees( i,7));
        }
        else if (i == 3)
        {
            plateau[i][0] = new Piece(TypePiece("Reine"), 0, Coordonnees(i,0));
            plateau[i][7] = new Piece(TypePiece("Reine"), 1, Coordonnees(i,7));
        }
        else
        {
            plateau[i][0] = new Piece(TypePiece("roi"), 0, Coordonnees(i,0));
            plateau[i][7] = new Piece(TypePiece("roi"), 1, Coordonnees(i,7));
        }
    }
}



Piece* Echiquier::get_Piece(int x,int y)   // Pour atteindre la piÃ¨ce au coords donnÃ©es
{
    return plateau[x][y];
}


Echiquier::Echiquier(const Echiquier & E):Tablier(E)  // Constructeur par copie
{}

void Echiquier::Affiche()   // Un affichage simple de l'echiquier (pour l'instant)
{
    cout << endl<<"-----------------------------"<<endl;
    for (int j=dim-1; j>-1; j--)
    {
        cout << "|| ";
        for (int i=0; i<dim; i++)
        {

            Piece *pt = this->get_plateau()[i][j];
            if (pt != NULL)
            {
                if (pt->get_coul() == 0)
                {
                    cout << pt->get_TypePiece().get_type()[0] << "b" << " ";
                }
                else
                {
                    cout << pt->get_TypePiece().get_type()[0] << "n" << " ";
                }

            }
            else
            {
                cout << "   ";
            }
        }
        cout << "||" << endl;
    }
    cout <<"-----------------------------"<<endl;
}






void Echiquier::deplace(Coordonnees av, Coordonnees ap)
{


    int x=av.get_x();
    int y=av.get_y();
    int a=ap.get_x();
    int b=ap.get_y();
    
    Piece* P=new Piece(*plateau[x][y]);
    P->set_coord(ap);
    delete plateau[x][y];
    plateau[x][y]=nullptr;

    if (plateau[a][b]==nullptr)
    {
        plateau[a][b]=new Piece(*P);
    }
    else
    {
        delete plateau[a][b];
        plateau[a][b]=new Piece(*P);
    }

}



void Echiquier::jouer_coup(Coup c)
{
    int sp=c.get_sp();
    int coul=c.get_coul();
    Coordonnees av=c.get_av();
    Coordonnees ap=c.get_ap();
    if (sp==0)
    {
        deplace(av,ap);
    }
    else
    {
        Piece P=c.get_P();
        if (P.get_TypePiece().get_type()=="Pion")
        {

            deplace(av,ap);
            plateau[ap.get_x()][ap.get_y()]->set_type();

        }
        else                                  //"roi"
        {
            int diff=ap.get_x()-av.get_x();
            deplace(av,ap);
            if (coul==0)
            {
                if (diff>0)    //petit roque
                {
                    deplace(Coordonnees(7,0),Coordonnees(5,0));
                }
                else    //grand roque
                {
                    deplace(Coordonnees(0,0),Coordonnees(3,0));
                }

            }
            else
            {
                if (diff>0)    //petit roque
                {
                    deplace(Coordonnees(7,7),Coordonnees(5,7));
                }
                else    //grand roque
                {
                    deplace(Coordonnees(0,7),Coordonnees(3,7));
                }

            }
        }
    }
}




bool** Echiquier::controle (int coul)
{
    bool** res=new bool*[8];
    for (int i=0; i<8; i++)
    {
        res[i]=new bool[8];
    }

    //initialisation des cases de res
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            res[i][j]=false;
        }
    }

    for (int i=0; i<8; i++)                           //on parcourt l'échiquier
    {
        for (int j=0; j<8; j++)
        {
            if (plateau[i][j]==nullptr)
                continue;
            int c=plateau[i][j]->get_coul();
            if (c==coul)                              //on parcourt les pièces de couleurs coul
            {


                TypePiece TP=plateau[i][j]->get_TypePiece();
                Coordonnees** depl=TP.get_depl();
                int nl=TP.get_nb_lignes();
                int nc=TP.get_nb_colonnes();
                string type=TP.get_type();
                if (type=="Pion")
                {
                    Coordonnees cr1(i+1,j+1);
                    Coordonnees cr2(i-1,j+1);
                    Coordonnees cr3(i+1,j-1);
                    Coordonnees cr4(i-1,j-1);
                    if (coul==0)
                    {
                        if (cr1.verif_coord())
                        {
                            if(plateau[i+1][j+1]==nullptr)
                                res[i+1][j+1]=true;
                            else
                            {
                                if (plateau[i+1][j+1]->get_coul() != coul)
                                    res[i+1][j+1]=true;

                            }
                        }
                        if (cr2.verif_coord())
                        {
                            if(plateau[i-1][j+1]==nullptr)
                                res[i-1][j+1]=true;
                            else
                            {
                                if (plateau[i-1][j+1]->get_coul()!=coul)
                                    res[i-1][j+1]=true;
                            }
                        }
                    }
                    else    //couleur noir
                    {
                        if (cr3.verif_coord())
                        {
                            if(plateau[i+1][j-1]==nullptr)
                                res[i+1][j-1]=true;
                            else
                            {
                                if (plateau[i+1][j-1]->get_coul()!=coul)
                                    res[i+1][j-1]=true;
                            }
                        }
                        if (cr4.verif_coord())
                        {
                            if(plateau[i-1][j-1]==nullptr)
                                res[i-1][j-1]=true;
                            else
                            {
                                if (plateau[i-1][j-1]->get_coul()!=coul)
                                    res[i-1][j-1]=true;
                            }

                        }
                    }


                }

                else                //autres que que Pion
                {
                    for (int ab=0; ab<nl; ab++)
                    {
                        for (int ord=0; ord<nc; ord++)
                        {
                            int a=depl[ab][ord].get_x();
                            int b=depl[ab][ord].get_y();
                            Coordonnees cr(i+a,j+b);
                            if (!cr.verif_coord())
                                break;
                            else
                            {
                                if (plateau[i+a][j+b]==nullptr)
                                    res[i+a][j+b]=true;
                                else
                                {
                                    int k=plateau[i+a][j+b]->get_coul();
                                    if (k!=coul)
                                    {
                                        res[i+a][j+b]=true;
                                    }
                                    break;   //passer à la deuxième ligne des coordonnées relatifs
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}





void Echiquier::affiche_controle(bool** c)
{
    for (int j=7; j>-1; j--)
    {
        for (int i=0; i<8; i++)
        {
            cout <<c[i][j]<< " ";
        }
        cout<<endl;
    }
}







bool Echiquier::verif_deplac(Piece* P,Coordonnees cor)
{

    if (P==nullptr)
        return false;
    int coul=P->get_coul();
    //coordonnees de la piece
    Coordonnees cord_P=P->get_coord();
    int x=cord_P.get_x();
    int y=cord_P.get_y();

    //coordonnees de cor
    int x_d=cor.get_x();
    int y_d=cor.get_y();

    TypePiece TP=P->get_TypePiece();

    int nl=TP.get_nb_lignes();
    int nc=TP.get_nb_colonnes();
    Coordonnees**depl=TP.get_depl();
    string type=TP.get_type();

    if (cor.verif_coord())
    {


        if ((plateau[x_d][y_d] != nullptr)&&(plateau[x_d][y_d]->get_coul()==coul))
            return false;
        if (type=="Pion")
        {
            if ((y==1)&&(x==x_d)&&(coul==0))
            {

                if (y_d==2)
                {
                    if(plateau[x_d][y_d]==nullptr)
                        return true;
                }
                else if ((y_d==3)&&(plateau[x_d][y_d]==nullptr)&&(plateau[x_d][2]==nullptr))
                    return true;
            }
            else if ((y==6)&&(x==x_d)&&(coul==1))
            {
                if (y_d==5)
                {
                    if(plateau[x_d][y_d]==nullptr)
                        return true;
                }
                else if ((y_d==4)&&(plateau[x_d][y_d]==nullptr)&&(plateau[x_d][5]==nullptr))
                {
                    return true;
                }
            }
            else
            {
                if (coul==0)                                    //joueur blanc
                {
                    if ((x_d==x)&&(y_d==y+1)&&(plateau[x_d][y_d]==nullptr))
                        return true;
                    else if ((abs(x-x_d)==1)&&(y_d==y+1)&&((plateau[x_d][y_d]!=nullptr)&&(plateau[x_d][y_d]->get_coul()==1)))
                        return true;
                }
                else                                            //joueur noir
                {
                    if ((x_d==x)&&(y_d==y-1)&&(plateau[x_d][y_d]==nullptr))
                        return true;
                    else if (((abs(x-x_d)==1))&&(y_d==y-1)&&(plateau[x_d][y_d]!=nullptr)&&(plateau[x_d][y_d]->get_coul()==0))
                        return true;
                }
            }
            return false;
        }
        else
        {
            //parcourir et voir si on atteint cord
            for (int i=0; i<nl; i++)
            {
                for(int j=0; j<nc; j++)
                {
                    int a=depl[i][j].get_x();
                    int b=depl[i][j].get_y();
                    Coordonnees cr=Coordonnees(x+a,y+b);
                    if (!cr.verif_coord())
                        break;

                    if (plateau[x+a][y+b] != nullptr)
                    {
                        if (((x+a)==x_d)&&((y+b)==y_d)&&(plateau[x+a][y+b]->get_coul()!=coul))
                            return true;
                        else
                            break;
                    }
                    else if ((x+a==x_d)&&(y+b==y_d))
                    {
                        return true;
                    }

                }
            }

        }
    }
    return false;
}




















bool Echiquier::Echec(int coul)
{

    // en échec si le roi se trouve dans une position atteignable par l'adversaire (fonction contrôle)
    // On cherche la position du roi, de couleur coul (puis on applique ce qui écrit au dessus)


    // On parcourt notre plateau
    for (int i=0; i<dim; i++)
    {

        for (int j=0; j<dim; j++)
        {
            // Puis on cherche le roi de couleur coul
            if (plateau[i][j]!=nullptr  && (plateau[i][j]->get_coul() == coul) && (plateau[i][j]->get_TypePiece().get_type() == "roi"))
            {
                // Puis on vérifie si ce dernier est atteignable ou pas
                return Piece_controle(Coordonnees(i,j));

            }
        }
    }
    return false;
}




bool Echiquier::Piece_controle(Coordonnees cor)
{
    int x=cor.get_x();
    int y=cor.get_y();
    if ((cor.verif_coord())&&(plateau[x][y]!=nullptr))
    {
        int c=plateau[x][y]->get_coul();
        return controle(1-c)[x][y]==1;
    }
    return 0;

}








double eval(Echiquier plateau)
{
    double gamma_p = .5;    // choix arbitraire (à faire varier lors des tests)
    double gamma_c = .5;    // choix arbitraire (à faire varier lors des tests)
    int val_h = 0;          // valeur des pièces du joueur humain
    int val_c = 0;          // valeur des pièces de l'ordinateur
    int cont_h = 0;         // nombre de cases controlées par l'humain
    int cont_c = 0;         // nombre de cases controlées par l'ordinateur
    bool ** control_humain = plateau.controle(0); // les cases controlées par l'humain (coul blanche)
    bool ** control_ordi = plateau.controle(1);   // les cases controlées par l'ordinateur (coul noir)
    
    for (int i=0; i < 8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (control_humain[i][j] == true) cont_h++;
            if (control_ordi[i][j] == true) cont_c++;
        }
    }
    
    bool echec = plateau.Echec(1);
    
    // retourner zéro pour une partie nulle

    if (echec == true) {return +INFINITY;}            // Pos gagnante du joueur humain = pos p de c
    else if (echec == false) {return -INFINITY;}      // Pos perdante du joueur humain = pos p de c
    else
        
        for (int i=0; i<plateau.get_dim(); i++)
        {
            for (int j=0; j<plateau.get_dim(); j++)
            {
                if (plateau.get_plateau()[i][j]->get_coul() == 0) // joueur humain (pièce blanche)
                {
                    val_h += plateau.get_plateau()[i][j]->get_TypePiece().get_valeur();
                }
                else // l'ordinateur (pièce noire)
                {
                    val_c += plateau.get_plateau()[i][j]->get_TypePiece().get_valeur();
                }
            }
            
        }
    return gamma_p*(val_h-val_c) + gamma_c*(cont_h-cont_c);
}


int Alphabeta(Echiquier plateau, int profondeur, int alpha, int beta, Coup &meilleur_coup) // Algo alpha-Beta
{
    if(profondeur <= 0) return eval(plateau);
    //Coup meilleur_coup = Coup();
    Coup m = Coup();
    int score = 0;
    // Parcourir tous les coups dans la boucle for suivante
    for(int i=0; i<plateau.get_dim(); i++)
    {
        for (int j=0; j<plateau.get_dim(); j++)
        {
            Piece* P = plateau.get_plateau()[i][j];
            // Parcourir tous les déplacements relatifs
            for(int k1=0; k1<P->get_TypePiece().get_nb_lignes(); k1++)   //  boucle for nbLignes
            {
                for (int k2=0; k2<P->get_TypePiece().get_nb_colonnes(); k2++)  // boucle for nbColonnes
                {
                    // J'ai mis (pr,cs) = (0,1) pour l'instant (attention à changer)
                    // Vérifier si le déplacement est possible
                    if (plateau.verif_deplac(P, P->get_TypePiece().get_depl()[k1][k2]) == true)
                    {
                        m = Coup(0, *P, P->get_coord(), P->get_TypePiece().get_depl()[k1][k2], 0, 1);
                        Coordonnees coord = P->get_coord(); // pour garder une trace des anciennes coords
                        P->set_coord(P->get_TypePiece().get_depl()[k1][k2]);  // Jouer le coup m
                        score = - Alphabeta(plateau, profondeur-1, -alpha, -beta, meilleur_coup); // Calcul du score
                        P->set_coord(coord);  // annuler le coup m (remmetre les anciennes coords)
                        if (score >= alpha)
                        {
                            alpha = score;
                            meilleur_coup = m;
                            if (alpha >= beta) break;
                        }
                    }
                }
            }
        }
    }
    // Le meilleur coup est renvoyé par référence
    return alpha;
}
















Coup Echiquier::retourne_coup_humain(int tour)
{
    int j;
    
    if (tour==0){
        cout<<"Le tour est au joueur blanc"<<endl;
        cout <<"jouer (1) ou abandonner (0)"<<endl;
        cin>>j;
        if (j==0)
            return Coup(0,Piece(),Coordonnees(-1,-1),Coordonnees(-1,-1),0,0);
        }
    else{
        cout<<"Le tour est au joueur noir"<<endl;
        cout <<"jouer (1) ou abandonner (0)"<<endl;
        cin>>j;
        if (j==0)
            return Coup(1,Piece(),Coordonnees(-1,-1),Coordonnees(-1,-1),0,0);
        }
//choix de la pièce à jouer

        cout<<"coordonnees x,y de la piece a jouer"<<endl;
        int x,y;
        while (1)
        {
            ///Coordonnées (x,y) de la pièce à jouer
            cin>>x;
            cin>>y;
            if ((plateau[x][y]!=nullptr)&&(plateau[x][y]->get_coul()==tour))
            {
                int ch;
                cout<<"Confirmer le choix de la piece par 1 ou 0 sinon"<<endl;
                cin>>ch;
                if (ch==1)
                    break;
            }
            cout<<"Veuillez choisir une de vos pieces"<<endl;

        }
        Coordonnees av(x,y);

    //choix de la nouvelle position
    while (1){
            cout<<"coordonnees x,y de la nouvelle position"<<endl;
            ///Coordonnées (x,y) de la nouvelle position
            int a,b;
            cin>>a;
            cin>>b;
            Coordonnees ap(a,b);
            int prise=0;
            if ((plateau[x][y]->get_TypePiece().get_type()=="roi")&&(abs(a-x)==2))     /// cas d'un roque
            {

                if ((abs(a-x)<=1))
                    return Coup(tour,*plateau[x][y],av,ap,prise,0);
                else if (a>x)    /// petit roque
                {
                    Coordonnees c1(x+1,y);
                    Coordonnees c2(x+2,y);
                    if ((!plateau[x][y]->get_deplace())&&((!plateau[7][y]->get_deplace())&&(!Piece_controle(c1)&&(!Piece_controle(c2)))))
                        return Coup(tour,*plateau[x][y],av,ap,prise,1);   ///roque
                }
                else            ///grand roque
                {
                    Coordonnees c1(x-1,y);
                    Coordonnees c2(x-2,y);
                    Coordonnees c3(x-3,y);
                    if ((!plateau[x][y]->get_deplace())&&((!plateau[7][y]->get_deplace())&&(!Piece_controle(c1)&&(!Piece_controle(c2)&&(!Piece_controle(c3))))))
                        return Coup(tour,*plateau[x][y],av,ap,prise,1);   ///roque
                }

            }
            if (this->verif_deplac(plateau[x][y],ap))
            {

                if (plateau[a][b]!=nullptr)
                    prise=1;

                Echiquier EC_tmp=Echiquier(*this);

                EC_tmp.deplace(av,ap);
                if (!EC_tmp.Echec(tour))                                        /// si le roi ne sera pas mis en échec
                {
                    if ((plateau[x][y]->get_TypePiece().get_type()=="Pion")&&(((tour==0)&&(b==7))||((tour==1)&&(b=0))))   ///promotion du pion
                        return(Coup(tour,*plateau[x][y],av,ap,prise,1));

                    else
                        return(Coup(tour,*plateau[x][y],av,ap,prise,0));
                }
                else
                    cout<<"Attention au roi !"<<endl;


            }


        }

        cout<<"Veuillez choisir un autre deplacement"<<endl;
}
































