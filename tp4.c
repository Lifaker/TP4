#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

//Partie A : une repr¨¦sentation classique
Arbre ABR;

//renvoie un pointeur vers un ABR vide
Arbre *initABR()
{
    ABR.racine = NULL;
    ABR.NbSommet =0;
    Arbre *p = &ABR;
    return p;
}

//renvoie un pointeur vers un nouveau sommet ¨¤ partir d'une cl¨¦ entr¨¦e en param¨¨tre.
Sommet* creerSommet(int cle)
{
    Sommet *p = (Sommet*)malloc(sizeof(Sommet));
    if(NULL == p)
        return NULL;
    p->cle = cle;
    p->left = p->right = NULL;
    return p;
}

//ins¨¨re un sommet dans un ABR. on ne doit pas avoir deux fois la m¨ºme cl¨¦ dans notre ABR.
void insererSommet(int valeur)
{
    Sommet *t,*t1;
    //Si l'ABR est vide
    if (ABR.racine ==NULL)
    {
        t=creerSommet(valeur);
        ABR.racine=t;
        ABR.NbSommet =1;
        return;
    }
    t = ABR.racine;
    //Rechercher le lieu du sommet
    while(t!=NULL)
    {
        t1=t;
        //verifier s'il y a la meme cle
        if (valeur == t->cle)
            return;
        if(valeur < t->cle)
            t = t->left;
        else if (valeur > t->cle)
                t= t->right;
    }
    if (valeur < t1->cle)
    {
        t = creerSommet(valeur);
        t1->left =t;
        ABR.NbSommet++;
        return;
    }
    if (valeur > t1->cle)
    {
        t = creerSommet(valeur);
        t1->right =t;
        ABR.NbSommet++;
        return;
    }
}


//
/*  In-order
    1.Check if the current node is empty / null.
    2.Traverse the left subtree by recursively calling the in-order function.
    3.Display the data part of the root (or current node).
    4.Traverse the right subtree by recursively calling the in-order function.
*/

void inorder_bstree(Sommet *tree)
{
    if(tree != NULL)
    {
        inorder_bstree(tree->left);
        printf("%d ", tree->cle);
        inorder_bstree(tree->right);
    }
}

//affiche tous les ¨¦lements de l'arbre tri¨¦s par ordre croissant
void afficherArbre()
{
    inorder_bstree(ABR.racine);
}

//v¨¦rifie si une cl¨¦ existe dans l'ABR
// return 1, il existe.  return 0, il n'existe pas
int rechercheSommet(int key)
{
    Sommet *tree = ABR.racine;
    while(tree)
    {
        if(key == tree->cle) return 1;

        if(key > tree->cle )
            tree = tree->right;
        else
            tree = tree->left;
    }
    return 0;
}

//renvoie le nombre d'octets utilis¨¦s pour repr¨¦senter l'ABR.
int tailleArbre()
{
    int taille;
    taille = sizeof(Sommet);
    taille = taille * ABR.NbSommet;
    return taille;
}



//Partie B : une représentation plus compacte
ArbreCompact ABRCompact;

//renvoie un pointeur vers un ABR vide
ArbreCompact *initABRCompact()
{
    ABR.racine = NULL;
    ABR.NbSommet =0;
    ArbreCompact *p = &ABRCompact;
    return p;
}


//renvoie un pointeur vers un nouveau sommet à partir d'un nombre entier entré en paramètre.
SommetCompact* creerSommetCompact(int cle)
{
    SommetCompact *p = (SommetCompact*)malloc(sizeof(SommetCompact));
    if(NULL == p)
        return NULL;
    p->inf = p->sup =cle;
    p->droit = p->gauche = NULL;
    return p;
}

// insère un élément (un nombre entier) dans un ABR
void insererElement(int valeur)
{
    SommetCompact *t,*t1,*t2;
    //Si l'ABR est vide
    if (ABRCompact.racine ==NULL)
    {
        t=creerSommetCompact(valeur);
        ABRCompact.racine=t;
        ABRCompact.NbSommet =1;
        return;
    }
    t = ABRCompact.racine;
    //Rechercher le lieu du sommet
    while(t!=NULL)
    {
        t1=t;
        //verifier s'il y a la meme cle
        if (valeur >= t->inf && valeur <= t->sup)
            return;

        //verifier la prioriete
        if(valeur == t->inf-1)
        {
              t->inf = valeur;
              t2=t;
              t = t->gauche;
              if (t->sup ==valeur+1)
              {
                  t2->inf = t->inf;
                  t2->gauche =t->gauche;
                  ABRCompact.NbSommet--;
                  free(t);
              }
              return;
        }
        if (valeur == t->sup+1)
        {
             t->sup = valeur;
             t2=t;
             t = t->droit;
             if (t->inf ==valeur+1)
             {
                  t2->sup = t->sup;
                  t2->droit =t->droit;
                  ABRCompact.NbSommet--;
                  free(t);
             }
             return;
        }
        if (valeur > t->sup+1)
            t= t->droit;
        else if (valeur < t->inf-1)
            t=t->gauche;
    }
    if (valeur < t1->inf-1)
    {
        t = creerSommetCompact(valeur);
        t1->gauche =t;
        ABRCompact.NbSommet++;
        return;
    }
    if (valeur > t1->sup+1)
    {
        t = creerSommetCompact(valeur);
        t1->droit =t;
        ABRCompact.NbSommet++;
        return;
    }
}

//
/*  In-order
    1.Check if the current node is empty / null.
    2.Traverse the left subtree by recursively calling the in-order function.
    3.Display the data part of the root (or current node).
    4.Traverse the right subtree by recursively calling the in-order function.
*/

void inorder_bstree_Compact(SommetCompact *tree)
{
    if(tree != NULL)
    {
        inorder_bstree_Compact(tree->gauche);
        for (int i= tree->inf; i<=tree->sup; i++)
            printf("%d ", i);
        inorder_bstree_Compact(tree->droit);
    }
}

//affiche tous les ¨¦lements de l'arbre tri¨¦s par ordre croissant
void afficherArbreCompact()
{
    inorder_bstree_Compact(ABRCompact.racine);
}

//v¨¦rifie si une cl¨¦ existe dans l'ABR
// return 1, il existe.  return 0, il n'existe pas
int rechercheElement(int key)
{
    SommetCompact *tree = ABRCompact.racine;
    while(tree)
    {
        if(key >= tree->inf && key <= tree->sup) return 1;

        if(key > tree->sup )
            tree = tree->droit;
        else if (key< tree->inf)
            tree = tree->gauche;
    }
    return 0;
}

//renvoie le nombre d'octets utilis¨¦s pour repr¨¦senter l'ABR.
int tailleArbreCompact()
{
    int taille;
    taille = sizeof(SommetCompact);
    taille = taille * ABRCompact.NbSommet;
    return taille;
}


