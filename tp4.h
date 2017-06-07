#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

//Partie A : une repr¨¦sentation classique
typedef struct Sommet
{
    int cle;
    struct Sommet *left;
    struct Sommet *right;
}Sommet;

typedef struct Arbre
{
    struct Sommet *racine;
    int NbSommet;
}Arbre;

Arbre *initABR();
Sommet* creerSommet(int);
void insererSommet(int);
void inorder_bstree(Sommet *);
void afficherArbre();
int rechercheSommet(int);
int tailleArbre();




//Partie B : une représentation plus compacte.
typedef struct SommetCompact
{
    int inf;    //la valeur inférieure de l’intervalle
    int sup;    //la valeur supérieure de l’intervalle supérieure
    struct SommetCompact *gauche;    //la racine du sous-arbre gauche de x (ou NULL si un tel sous-arbre n’existe pas)
    struct SommetCompact *droit;  //la racine du sous-arbre droit de x (ou NULL si un tel sous-arbre n’existe pas)
}SommetCompact;


typedef struct ArbreCompact
{
    struct SommetCompact *racine;
    int NbSommet;
}ArbreCompact;

ArbreCompact *initABRCompact();
SommetCompact* creerSommetCompact(int);
void insererElement(int);
void inorder_bstree_Compact(SommetCompact *);
void afficherArbreCompact();
int rechercheElement(int);
int tailleArbreCompact();

#endif // TP4_H_INCLUDED
