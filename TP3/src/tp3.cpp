#include <iostream>
#include "matrice.hpp"
#include "fifo.hpp"

// ---------------------------------------
// Université du Littoral Côte d'Opale
// Licence Informatique 2e année
// Module algorithmique 5 - Graphes - TP 2
// Corrigé - Auteur : C. Renaud
// ---------------------------------------



// ----- Fonction principale du TP 2

int main(int argc, char *argv[]){
  
  // test de présence du paramètre représentant le nom du fichier
  // contenant les coefficients de la matrice d'adjacence
  if(argc!=2){
    printf("Erreur - il manque le nom du fichier à lire\n");
    return -1;
  }

  MatriceAdjacence mat;// matrice d'adjacence utilisée pour tester les différentes fonctions

  // création d'une matrice - Exercice 1
  creerMatrice(&mat, 3);

  // chargement d'une matrice - Exercice 2
  if(!chargerMatrice(argv[1], &mat)) return -1;

  // affichage d'une matrice - Exercice 3
  afficherMatrice(mat); 

  // effacement d'une matrice - Exercice 4
  effacerMatrice(&mat); 
  afficherMatrice(mat);

  // rechargement de la matrice pour pousuivre le TP
  if(!chargerMatrice(argv[1], &mat)) return -1;

  // vérification de la complétude d'une matrice - Exercice 6
  if(estComplet(mat))
    cout << "complet" << endl;
  else
    cout << "incomplet" << endl;

  
  // vérification de la symétrie d'une matrice - Exercice 7
  if(estSymetrique(mat)){
    cout << "symétrique" << endl;
  } else {
    cout << "non symétrique" << endl;
  }

  // copie d'une matrice - Exercice 8
  MatriceAdjacence nouv = {0, nullptr};
  copieMatrice(mat, &nouv);
  cout << "contenu de la matrice de départ:" << endl;
  afficherMatrice(nouv);
  cout << "contenu de la matrice recopiée :" << endl;
  afficherMatrice(mat);

  // test d'égalité de deux matrices - Exercice 9
  if(matricesEgales(mat, nouv))
    cout << "les matrices sont égales" << endl;
  else
    cout << "les matrices sont différentes" << endl;
  
  // effacement de la matrice
  effacerMatrice(&mat);

  Fifo maFile;
  initialiserFifo(&maFile);
 bool empty = estVide(maFile);
 cout << "Est ce vide ? " << empty << endl; 

  ajouter(&maFile, 13);
  ajouter(&maFile, 1);
  ajouter(&maFile, 64);
  ajouter(&maFile, 5);

  afficherFifo(maFile);
  
  return 1;
}
