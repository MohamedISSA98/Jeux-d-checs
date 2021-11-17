
#include "Tablier.hpp"
#include "Piece.hpp"

Tablier::Tablier()
{
    this->dim = 0; // choix d'initialiser Ã  0
    this->plateau = NULL;

}

Tablier::~Tablier()
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<8; j++)
        {
            delete plateau[i][j];
        }
        delete [] plateau[i];
    }
    delete [] plateau;
}



int Tablier::get_dim() const
{
    return this->dim;
}

void Tablier::set_dim(int dim)
{
    this->dim = dim;
}

Piece *** Tablier::get_plateau() const
{
    return this->plateau;
}


Tablier::Tablier(const Tablier & T): dim(T.dim)
{
    plateau = new Piece**[T.dim];
    for (int i=0; i<dim; i++)
    {
        plateau[i] = new Piece*[dim];
        for (int j=0; j<dim; j++)
        {
            if (T.plateau[i][j] != nullptr)
                plateau[i][j]=new Piece(*T.plateau[i][j]);
            else
                plateau[i][j]=nullptr;
        }
    }
}


Tablier & Tablier::operator =(const Tablier & T)  // A revoir
{
    this->dim = T.dim;
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<8; j++)
        {
            delete plateau[i][j];
        }
        delete [] plateau[i];
    }
    delete [] plateau;
    this->plateau = new Piece**[this->dim];
    for (int i=0; i<this->dim; i++)
    {
        this->plateau[i] = new Piece*[this->dim];
        for (int j=0; j<this->dim; j++)
        {
            this->plateau[i][j] = new Piece(*T.get_plateau()[i][j]);
        }
    }

    return *this;
}


