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

void creerMatrice(MatriceAdjacence *mat, int size){
    mat->ordre = size;
    mat->lignes = new Maillon*[size];
    for (int i = 0; i < size; i++)
    {
        mat->lignes[i] = nullptr;
    }
}

bool chargerMatrice(char *nomFichier, MatriceAdjacence *mat){
    fstream fichier;
    fichier.open(nomFichier);
    if (!fichier.is_open())
    {
        cout << "Erreur d'ouverture du fichier" << endl;
        return false;
    }
    int ordre;
    fichier >> ordre;
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

void afficherMatrice(MatriceAdjacence mat){
    for (int i = 0; i < mat.ordre; i++)
    {
        for (int j = 0; j < mat.ordre; j++)
        {
            Maillon* tmp = mat.lignes[i];
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

int main(int argc, char* argv[]){
     if (argc < 2)
    {
        cout << "Erreur! \n Usage : programme fichier.txt" << endl;
    }
    MatriceAdjacence matrice;
    creerMatrice(&matrice, 4);

    bool file = chargerMatrice(argv[1], &matrice);
     afficherMatrice(matrice);

     return 1;
}