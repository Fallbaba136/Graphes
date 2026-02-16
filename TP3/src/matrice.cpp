#include "matrice.hpp"



// ---- Fonctions correspondant à chaque question du TP 2

/** 
 * Création et initialisation d'une matrice d'adjacence
 * @param m un pointeur vers la matrice à créer et à initialiser
 * @param size la taille de la matrice à créer et initialiser
 */
void creerMatrice(MatriceAdjacence *m, int taille){
  // initialisation du nombre de lignes/colonnes de la matrice
  m->ordre = taille;
  // allocation mémoire du tableau de lignes
  m->lignes = new Maillon*[taille];
  // initialisation de chaque ligne à "vide"
  for(int i=0; i<taille; i++) m->lignes[i]=nullptr;
}


/**
 * Affichage des coefficients d'une matrice d'adjacence,
 * les lignes aparaissant sur des lignes écran différentes.
 * @param mat la matrice à afficher
 */
void afficherMatrice(MatriceAdjacence mat){
  // affichage de chacune des lignes
  for(int l=0; l<mat.ordre; l++){// affichage de la ligne l
    int c=0;// indice de la colonne
    Maillon *mcur=mat.lignes[l];
    while(c<mat.ordre){
      if(mcur==nullptr){// les coefficients de la ligne >=c sont nuls
	cout << "0 ";
	c++;
      }else if(mcur->col != c){
	// on est sur un coefficient nul, qui se trouve avant c
	cout << "0 ";
	c++;
      }else{// afficher le coefficient
	cout << mcur->coef << " ";
	mcur = mcur->suiv;
	c++;
      }   
    }// while
    cout << endl;// fin de la ligne l
  }// for
}

/**
 * Chargement d'une matrice d'adjacence à partir d'un fichier.
 * @param mat un pointeur vers la matrice qui doit contenir le résultat
 * du chargement
 * @param nom le nom du fichier à relire
 * @return true si la lecture s'est bien déroulée, false sinon.
 */
bool chargerMatrice(char *nom, MatriceAdjacence *mat){
  ifstream in;
  
  in.open(nom, std::ifstream::in);
  if(!in.is_open()){
    printf("Erreur d'ouverture de %s\n", nom);
    return false;
  }

  int taille;
  in >> taille;

  // créer la matrice
  creerMatrice(mat, taille);
  
  int v; // coefficient lu

  for(int l=0; l<mat->ordre; l++){ // lire et créer une ligne complète
    Maillon *fin=nullptr;
    for(int c=0; c<mat->ordre; c++){ // lire et créer chaque colonne de la ligne courante
      in >> v;
      if(v!=0){// créer un maillon et l'insérer en fin de liste
	Maillon *nouveau = new Maillon;
	nouveau->col = c;
	nouveau->coef = v;
	nouveau->suiv = nullptr;
	if(fin!=nullptr){// il y a déjà des éléments dans la liste
	  fin->suiv = nouveau;// insertion en fin
	  fin = nouveau;// maj du pointeur vers le dernier élément de la liste
	}else{// c'est le premier coefficient de la liste
	  mat->lignes[l] = nouveau;// ajout au début de la liste
	  fin = nouveau;// maj du pointeur vers le dernier élément de la liste
	}
      }// if - rien à faire si v vaut 0
    }// for c
  }// for l

  in.close();
  return true;
}

/**
 * Effacement de la mémoire occupée par les structures de données
 * représentant une matrice d'adjacence. En sortie, la taille de la
 * matrice effacée est nulle et son pointeur de lignes vaut nullptr.
 * @param mat la matrice à effacer
 */
void effacerMatrice(MatriceAdjacence *mat){
  // Vérifier que la matrice n'est pas vide
  if(mat->lignes == nullptr) return;
  
  // effacer le contenu de la matrice
  for(int l=0; l<mat->ordre; l++){// effacer chaque ligne
    while(mat->lignes[l]!=nullptr){// tq la ligne n'est pas vide
      // effacer le premier élément qui s'y trouve
      Maillon *cour = mat->lignes[l];// 1er élément de la liste
      mat->lignes[l] = cour->suiv;// élément suivant éventuel
      delete cour; // effacer le 1er élement courant
    }
  }
  // effacer le tableau de lignes
  delete mat->lignes;
  // raz de la taille et des lignes
  mat->ordre = 0;
  mat->lignes = nullptr;
      
}

/**
 * Récupération du coefficient de la matrice aux coordonnées (l,c).
 * La fonction fait l'hypothèse que les coordonnées sont valides.
 * @param mat la matrice dans laquelle récupérer les coefficients
 * @param l l'indice de ligne du coefficient (dans [0, ordre-1])
 * @param c l'indice de colonne du coefficient (dans [0, ordre-1])
 */
int getCoeff(MatriceAdjacence mat, int l, int c){
  Maillon *cur; // pointeur de parcours de la liste chaînée en ligne l

  // initialisation au début de la ligne l
  cur = mat.lignes[l];

  // recherche de la colonne c dans la liste
  while(cur!=nullptr){
    if(cur->col == c) return cur->coef;// on a trouvé la colonne
    if(cur->col>c) return 0; // on ne peut plus trouver la colonne c;
    cur = cur->suiv; // on poursuit la recherche
  }

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
  for(int l=0; l<mat.ordre; l++) 
    for(int c = l; c<mat.ordre; c++)
      if(getCoeff(mat, l, c) != getCoeff(mat, c, l)) return false;
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
  for(int l=0; l<mat.ordre; l++) 
    for(int c = 0; c<mat.ordre; c++)
      if((l!=c) && getCoeff(mat, l, c)!=1) return false;
  
  return true;// aucun 0 trouvé
}


/**
 * Fonction permettant de vérifier que deux liste chaînées
 * sont égales. 
 * @param liste1 la tête de la première liste
 * @param liste2 la tête de la seconde liste
 * @return true si les deux listes sont égales, false sinon
 */
bool listesEgales(Maillon *liste1, Maillon *liste2){
  // initialisation des deux pointeurs de parcours
  Maillon *cur1 = liste1;
  Maillon *cur2 = liste2;
  // boucle de parcours
  while(cur1!=nullptr && cur2!=nullptr){
    if(cur1->col != cur2->col) return false;
    if(cur1->coef != cur2->coef) return false;
    cur1 = cur1->suiv;
    cur2 = cur2->suiv;
  }
  // on vérifie si on est à la fin des deux listes
  if(cur1!=cur2) return false;
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
   
   // vérification de l'ordre des deux matrices
  if(m1.ordre != m2.ordre) return false;

  // vérification de chaque ligne
  for(int i=0; i<m1.ordre; i++)
    if(!listesEgales(m1.lignes[i], m2.lignes[i])) return false;

  return true;
}

/**
 * Fonction permettant de recopier une liste chaînée dans une autre.
 * Si la seconde liste n'est pas vide, elle est effacée.
 * @param liste1 la liste émettrice
 * @param liste2 la nouvelle liste
 */
void copieListe(Maillon *liste1, Maillon **liste2){
  // vérifier si la liste 2 est vide
  if((*liste2) != nullptr){    //effacer la liste
    Maillon *cur = *liste2;
    while(*liste2!=nullptr){
      cur = (*liste2);
      (*liste2) = (*liste2)->suiv;
      delete cur;
    }
  }
  // recopie liste1 => liste 2
  
  Maillon *cur = liste1;// pointeur de parcours de liste 1
  Maillon *endl2 = nullptr;// pointeur vers le dernier élément de liste 1
  
  while(cur!=nullptr){
    // créer la copie du maillon
    Maillon *ncur = new Maillon();
    ncur->coef = cur->coef;
    ncur->col = cur->col;
    ncur->suiv = nullptr;
    // insérer le maillon en fin de liste2
    if(*liste2 == nullptr){
      *liste2 = ncur;
      endl2 = ncur;
    } else {
      endl2->suiv = ncur;
      endl2 = ncur;
    }
    cur = cur->suiv;
  }
      
}

/**
 * Fonction permettant de recopier une matrice d'adjacence dans une autre.
 * La seconde matrice est effacée.
 * @param m1 la matrice à recopier
 * @param m2 la matrice qui doit contenir la copie
 */
void copieMatrice(MatriceAdjacence m1, MatriceAdjacence *m2){
  // effacer et recréer la seconde matrice
  effacerMatrice(m2);
  creerMatrice(m2, m1.ordre);
  // recopier les lignes
  for(int i=0; i<m1.ordre; i++)
    copieListe(m1.lignes[i], &(m2->lignes[i]));
}
