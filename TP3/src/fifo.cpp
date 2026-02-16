#include "fifo.hpp"

//==================
// Exercice2:
//==================

// structure d'un maillon d'une fifo de valeur entieres

// Question1
void initialiserFifo(Fifo *file){
    file->in = nullptr;
    file->out = nullptr;
}

// Question2
bool estVide(Fifo file){
    if (file.in == nullptr)
    {
        return true;
    }
    return false;
}

// Question3
void afficherFifo(Fifo file){
    if (estVide(file))
    {
        return;
    }

    MaillonEntier* tmp = file.in;
    while (tmp != nullptr)
    {
        cout << tmp->valeur << " ";
        tmp = tmp->suiv;
    }

}

// Question4

void ajouter(Fifo *file, int val){
    MaillonEntier* newMaillon = new MaillonEntier;
    if (estVide(*file))
    {
        newMaillon->valeur = val;
        file->in = newMaillon;
        file->out = newMaillon;
    }
    else
    {
        file->out->suiv = newMaillon;
        file->out = newMaillon;
    }
  
    newMaillon->valeur = val;
    newMaillon->suiv = nullptr;
    newMaillon->prec = file->out;
}

int retirer(Fifo* file){
    MaillonEntier* tmp = new MaillonEntier;
    tmp = file->out;
    if (file->out != file->in)
    {
        file->out = file->out->prec;
        file->out->suiv = nullptr;
    }else{
        file->out = nullptr;
        file->in = nullptr;
    } 
     int val = tmp->valeur;
     delete tmp;
     return val;
  
}