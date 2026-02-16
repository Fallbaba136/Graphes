#include <iostream>
#include <fstream>
using namespace std;

// Représentation d'un maillon de liste chaînée
struct Maillon {
  int col; // numéro de la colonne à laquelle correspond le coefficient
  int coef;// coefficient de la matrice
  Maillon *suiv;// élément suivant non nul sur la ligne
} ;

// Représentation d'un matrice d'adjacence
struct MatriceAdjacence {
  int ordre; // nombre de sommets du graphe
  Maillon* *lignes;// tableau à allouer de taille "ordre", représentant les lignes de la matrice
};

// Prédefinition des fonctions utilisées dans le main
void creerMatrice(MatriceAdjacence *m, int taille);
void afficherMatrice(MatriceAdjacence mat);
bool chargerMatrice(char *nom, MatriceAdjacence *mat);
void effacerMatrice(MatriceAdjacence *mat);
bool estSymetrique(MatriceAdjacence mat);
bool estComplet(MatriceAdjacence mat);
int getCoeff(MatriceAdjacence mat, int l, int c);
bool matricesEgales(MatriceAdjacence m1, MatriceAdjacence m2);
void copieMatrice(MatriceAdjacence m1, MatriceAdjacence *m2);
