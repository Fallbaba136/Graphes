#include <iostream>
using namespace std;

struct MaillonEntier{
    int valeur; // valeur stocker dans le maillon
    MaillonEntier *suiv; // element suivant dans la file
    MaillonEntier *prec; // element precedent dans la file
};

//structure d'une file de type FIFO pouvant contenir des entier
struct Fifo
{
    MaillonEntier *in; // pointeur vers le debut de la liste
    MaillonEntier *out; // pointeur vers la fin de la liste  
};

//Predefinition des fonctions utilisees 
void initialiserFifo(Fifo *file);
bool estVide(Fifo file);
void afficherFifo(Fifo file);
void ajouter(Fifo *file, int val);
int retirer(Fifo* file);