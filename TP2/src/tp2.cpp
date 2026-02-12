#include <iostream>
#include <fstream>
using namespace std;

struct Maillon
{
    int col;
    int coef;
    Maillon* suiv;
};

struct MatriceAdjacence
{
    int ordre;
    Maillon* *lignes; //tab a allouer de taille ordre, representant less lignes de la matrice
};

//=====================
// Exercice1:
//=====================

void creerMatrice(MatriceAdjacence *mat, int size){
    mat->ordre = size;
    mat->lignes = new Maillon*[size];
    for (int i = 0; i < size; i++)
    {
        mat->lignes[i] = nullptr;
    }
}

//=====================
// Exercice2:
//=====================

bool chargerMatrice(char *nomFichier, MatriceAdjacence *mat){
    fstream fichier;
    fichier.open(nomFichier); // ouverture 
    if (!fichier.is_open())
    {
        cout << "Erreur d'ouverture du fichier" << endl;
        return false;
    }
    int ordre;
    fichier >> ordre; // ordre stocke le premier chiffre du fichier qui est la taille spécifier dans le fichier en 1e ligne 
    creerMatrice(mat, ordre);
    for (int i = 0; i < ordre; i++)
    {
        for (int j = 0; j < ordre; j++)
        {   
            int valeur;
            fichier >> valeur;
            if (valeur != 0)
            {
                Maillon* newNode = new Maillon;
                newNode->col = j;
                newNode->coef = valeur;
                if (mat->lignes[i] == nullptr)
                {
                    newNode->suiv = nullptr;
                    mat->lignes[i] = newNode;
                    
                }else
                {
                    newNode->suiv = mat->lignes[i];
                    mat->lignes[i] = newNode;
                }
                
            }
            
        }
        
    }
    fichier.close();
    return true;
}

//=========================
// Exercice3:
//=========================

void afficherMatrice(MatriceAdjacence mat){
    for (int i = 0; i < mat.ordre; i++)
    {
        for (int j = 0; j < mat.ordre; j++)
        {
            Maillon* tmp = mat.lignes[i]; // ligne[] => tête du maillon
           int valeur = 0;
           while (tmp != nullptr)
           {
                if (tmp->col== j)
           {
                valeur = tmp->coef;
                break;
                cout << valeur << " ";
           }
           tmp = tmp->suiv;
           }
           cout << valeur << " ";
        }
        cout << endl;
}
}

//========================
// Exercice4:
//========================

void effacerMatrice(MatriceAdjacence *M){
    if (M->lignes == nullptr)
    {
        return;
    }
    
    for (int i = 0; i < M->ordre; i++)
    {
        Maillon* tmp = M->lignes[i];
        while (tmp != nullptr)
        {
             Maillon* aSupprimer = tmp;
             tmp = tmp->suiv;
            delete aSupprimer; // new = delete, malloc = free 
        }       
        M->lignes[i] = nullptr;
    }
    delete[] M->lignes;
    M->lignes = nullptr;
    M->ordre = 0;
    
}

//==========================
// Exercice5:
//=========================

int getCoef(MatriceAdjacence mat, int l, int c){ // l => indice ligne, c => indice colonne
    int taille = mat.ordre;
    if (mat.lignes == nullptr)
    {
        cout << "Matrice vide" << endl;
        return 0;
    }
   Maillon* tmp = mat.lignes[l];
   while (tmp != nullptr)
   {
        if (tmp->col == c)
        {
            return tmp->coef;
        }
        tmp = tmp->suiv;
}
   
    return 0;
    
}


//====================
// Exercice6 
//====================

bool estComplet(MatriceAdjacence mat){
    int taille = mat.ordre;
    if (mat.lignes == nullptr)
    {
        return false;
    }

    for (int i = 0; i < taille; i++)
    {
        
    }
    
    
}





















//=========================
// MAIN
//========================= 

int main(int argc, char* argv[]){
     if (argc < 2)
    {
        cout << "Erreur! \n Usage : programme fichier.txt" << endl;
    }
    MatriceAdjacence matrice;
    creerMatrice(&matrice, 4);

    bool file = chargerMatrice(argv[1], &matrice);
     afficherMatrice(matrice);
     effacerMatrice(&matrice);
     afficherMatrice(matrice);
     return 1;
}