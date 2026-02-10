#include <iostream>
#include <fstream>
using namespace std;

// ---------------------------------------
// Université du Littoral Côte d'Opale
// Licence Informatique 2e année
// Module algorithmique 5 - Graphes - TP 2
// ---------------------------------------


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



// ----- Fonction principale du TP 2
//
// NE RIEN MODIFIER DANS CETTE FONCTION
// Elle est écrite pour que vous puissiez tester les
// différentes autres fonctions à développer.

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
  
  return 1;
}

// ---- Fonctions correspondant à chaque question du TP 2

/** 
 * Création et initialisation d'une matrice d'adjacence
 * @param m un pointeur vers la matrice à créer et à initialiser
 * @param size la taille de la matrice à créer et initialiser
 */
void creerMatrice(MatriceAdjacence *m, int taille){

    // à compléter

}


/**
 * Affichage des coefficients d'une matrice d'adjacence,
 * les lignes aparaissant sur des lignes écran différentes.
 * @param mat la matrice à afficher
 */
void afficherMatrice(MatriceAdjacence mat){

  // à compléter

}

/**
 * Chargement d'une matrice d'adjacence à partir d'un fichier.
 * @param mat un pointeur vers la matrice qui doit contenir le résultat
 * du chargement
 * @param nom le nom du fichier à relire
 * @return true si la lecture s'est bien déroulée, false sinon.
 */
bool chargerMatrice(char *nom, MatriceAdjacence *mat){

  // à compléter

  return true;
}

/**
 * Effacement de la mémoire occupée par les structures de données
 * représentant une matrice d'adjacence. En sortie, la taille de la
 * matrice effacée est nulle et son pointeur de lignes vaut nullptr.
 * @param mat la matrice à effacer
 */
void effacerMatrice(MatriceAdjacence *mat){

  // à compléter
      
}

/**
 * Récupération du coefficient de la matrice aux coordonnées (l,c).
 * La fonction fait l'hypothèse que les coordonnées sont valides.
 * @param mat la matrice dans laquelle récupérer les coefficients
 * @param l l'indice de ligne du coefficient (dans [0, ordre-1])
 * @param c l'indice de colonne du coefficient (dans [0, ordre-1])
 */
int getCoeff(MatriceAdjacence mat, int l, int c){

  // à compléter

  return 0; // on a pas trouvé la colonne c
}


/**
 * Vérification de la propriété de symétrie d'une matrice.
 * Une matrice est symétrique si les coefficients
 * aux coordonnées (l,c) sont tous égaux aux coefficients
 * des coordonnées (c,l).
 *
 * @param mat la matrice dont il faut vérifier la symétrie
 * @return true si la matrice est symétrique, false sinon
 */
bool estSymetrique(MatriceAdjacence mat){

  // à compléter
  
  return true;
}

/**
 * Vérification de la propriété de complétude du graphe associé
 * à une matrice d'adjacence.
 * Un graphe est complet si chacun de ses sommets est connecté
 * à tous les autres sommets. Les boucles ne comptent pas.
 * Il suffit dont de vérifier qu'il n'y a que des 1 dans la
 * matrice, sans tenir compte des éléments de la diagonale.
 *
 * @param mat la matrice dont il faut vérifier la complétude
 * @return true si le graphe associé à la matrice est complet, false sinon
 */
bool estComplet(MatriceAdjacence mat){
  
  // à compléter

  return true;
}




/**
 * Fonction permettant de vérifier que deux matrices d'adjacence
 * sont égales. 
 * @param m1 la première matrice
 * @param m2 la tête la seconde matrice
 * @return true si les deux matrices sont égales, false sinon
 */
bool matricesEgales(MatriceAdjacence m1, MatriceAdjacence m2){

  cout << "egalité de deux matrices non implémentée ..." << endl;

  return false;
}


/**
 * Fonction permettant de recopier une matrice d'adjacence dans une autre.
 * La seconde matrice est effacée.
 * @param m1 la matrice à recopier
 * @param m2 la matrice qui doit contenir la copie
 */
void copieMatrice(MatriceAdjacence m1, MatriceAdjacence *m2){
  
  cout << "egalité de deux matrices non implémentée ..." << endl;

}
