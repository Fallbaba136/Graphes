#include <iostream>
#include <fstream>
using namespace std;

//-------------------------
//  Exercice 1
//-------------------------
struct MatriceAdjacent
{
    int *coeff; // tableau
    int ordre; // nombre de sommet du graphe (taille)
};


void creerMatrice(MatriceAdjacent *m, int size){
    m->coeff = new int[size*size];
    m->ordre = size;
    for (int i = 0; i < size; i++)
    {
        m->coeff[i] = 0;
    }
}

void afficheMatrice(MatriceAdjacent mat){
    for (int i = 0; i < mat.ordre-1; i++)
    {
        for (int j = 0; j < mat.ordre - 1; j++)
        {
            cout << mat.coeff[i*mat.ordre + j] << " ";
        }
        cout << endl;
    }
    
}

//-------------------------
//  Exercice 3
//-------------------------

bool chargerMatrice(MatriceAdjacent *mat, string nomFichier){
    fstream fichier;
    fichier.open(nomFichier);
    if (!fichier.is_open())
    {
        cout << "Erreur d'ouverture du fichier" << endl;
        return false;
    }
    int reserve;
    fichier >> reserve;
    creerMatrice(mat, reserve);
    
    for (int i = 0; i < reserve; i++)
    {
        for (int j = 0; j < reserve; j++)
        {
           fichier >> mat->coeff[i*reserve+j];
        }
    }
    
    fichier.close();
  
    return true;
}


//-------------------------
//  Exercice 4
//-------------------------

bool estComplet(MatriceAdjacent mat){
    for (int i = 0; i < mat.ordre; i++)
    {
        for (int j = 0; j < mat.ordre; i++)
        {
            if (j!=i)
            {
                if (mat.coeff[i*mat.ordre+j] != 1)
                {
                    cout << "Matrice incomplet" << endl;
                    return false;
                }
            }
        }
    }
    cout << "Matrice complet" << endl;
    return true;
}


//-------------------------
//  Exercice 5
//-------------------------

bool estSymetrique(MatriceAdjacent mat){
    for (int i = 0; i < mat.ordre; i++)
    {
        for (int j = i+1; j < mat.ordre; j++)
        {
            if (mat.coeff[i*mat.ordre+j] != mat.coeff[j*mat.ordre+i])
            {
                  cout << "Matrice non symetrique" << endl;
                    return false;
            }
        }
    }
    cout << "Matrice symetrique" << endl;
                return true;
    cout << "Matrice non symetrique" << endl;
    return false;
}


//-------------------------
//  Exercice 6
//-------------------------


bool estIsole(MatriceAdjacent mat, int i){
        for (int j = 0; j < mat.ordre; j++)
        {   
            if (j!=i)
            {
                 if (mat.coeff[i*mat.ordre+j] != 0 || mat.coeff[j*mat.ordre+i] != 0)
                {
                    cout << "sommet non isolé" << endl;
                            return false;
                    }
            }
        }
    return true;
}

//-------------------------
//  Exercice 7
//-------------------------

void afficheDegeresNonOrienter(MatriceAdjacent mat){
    for (int i = 0; i < mat.ordre; i++)
    {
        int degres = 0;
        for (int j = 0; j < mat.ordre; j++)
        {
           if (i!=j)
        {
             if (mat.coeff[i*mat.ordre+j] != 0)
        {
            degres+=1;
        }
        }else
        {
            if (mat.coeff[i*mat.ordre+i])
            {
                degres += 2;
            }
            
        }
        
        }
        cout << degres << endl;
        
    }
    
}


//-------------------------
//  Exercice 8
//-------------------------

//void afficherDegres










int main(int argc, char* argv[]){
    if (argc < 2)
    {
        cout << "Erreur! \n Usage : programme fichier.txt" << endl;
    }
    

    MatriceAdjacent matrice;
    creerMatrice(&matrice, 8);
   // afficheMatrice(matrice);

    bool file = chargerMatrice(&matrice, argv[1]);
     afficheMatrice(matrice);

     bool complet = estComplet(matrice);
     cout << complet << endl;

     bool symetrique = estSymetrique(matrice);
     cout << symetrique << endl;
}
