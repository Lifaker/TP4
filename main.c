#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"
#include "tp4.c"

//static int arr[]= {1,5,4,3,2,6};
int arr[100];
int taille;
//1.une repr¨¦sentation classique    2.une repr¨¦sentation plus compacte
int flag = 0;


//Pre-charger un ABR (max 100)
void PrechargerABR()
{
    int ch,i;

    while(1)
    {
        printf("La taille(<100) ");
        scanf("%d", &taille);
        if (taille <100)
            break;
        else
            printf("La taille doit < 100\n");
    }
    while (1)
    {
        printf("1. Al¨¦atoire   2.Manuel\n");
        scanf("%d", &ch);
        if (ch == 1 || ch == 2)
            break;
        else
            printf("Taper 1 ou 2\n");
    }
    // 1 Al¨¦atoire
    if (ch == 1)
    {
        //srand((unsigned)time(NULL));
        srand(1);
        for (i=0; i<taille; i++)
        {
            arr[i] = rand()%15;
             //verifier s'il exite la meme cle
            for (int j=0;j<i;j++){
                if (arr[i]==arr[j]){
                    i--;
                    break;
                }
            }
        }
    }
    // 2.Manuel
    else if (ch==2)
    {
        printf("Les ¨¦l¨¦ments :");
        for (i=0;i<taille;i++)
        {
            scanf("%d", &arr[i]);
            //verifier s'il exite la meme cle
            for (int j=0;j<i;j++){
                if (arr[i]==arr[j]){
                    i--;
                    break;
                }
            }
        }
    }
    printf("Les ¨¦l¨¦ments :");
    for(i=0; i<taille; i++)
        printf("%d ", arr[i]);
}


int main()
{
    int choice,key;
    int t;
    int tArbre;
    while(1)
    {
        printf("\n\n");
        printf("\n  1. Pre-charger un ABR (max 100)");
        printf("\n  2. Initialiser un ABR suivant une r¨¦sentation classique");
        printf("\n  3. Initialiser un ABR suivant une r¨¦sentation plus compacte");
        printf("\n  4. L'insertion dans l'ABR");
        printf("\n  5. L'affichage de l'ABR");
        printf("\n  6. La recherche dans l'ABR");
        printf("\n  7. Comparer la taille occup¨¦e par l¡¯ABR avec chacune des repr¨¦sentations");
        printf("\n  8. Quitter");
        printf("\n======================================");
        printf("\n  Please enter your choice (1,2,3,4,5,6,7,8)");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            PrechargerABR();
            break;
        case 2:
            initABR();
            for (int i=0; i<taille;i++)
                insererSommet(arr[i]);
            flag =1;
            break;
        case 3:
            initABRCompact();
            for (int i=0; i<taille;i++)
                insererElement(arr[i]);
            flag =2;
            break;
        case 4:
            switch (flag)
            {
            case 1:
                printf("La cle: ");
                scanf("%d",&key);
                insererSommet(key);
                break;
            case 2:
                printf("La cle: ");
                scanf("%d",&key);
                insererElement(key);
                break;
            default:
                printf("l'ABS n'exist pas\n");
            }

            break;
        case 5:
            switch (flag)
            {
            case 1:
                afficherArbre();
                break;
            case 2:
                afficherArbreCompact();
                break;
            default:
                printf("l'ABS n'exist pas\n");
            }

            break;
        case 6:
            switch (flag)
            {
            case 1:
                printf("La cle: ");
                scanf("%d",&key);
                t=rechercheSommet(key);
                if (t==1)
                    printf("Cette cle existe dans l'ABR\n");
                else if (t==0)
                        printf("Cette cle n'existe pas dans l'ABR\n");
                break;
            case 2:
                printf("La cle: ");
                scanf("%d",&key);
                t=rechercheElement(key);
                if (t==1)
                    printf("Cette cle existe dans l'ABR\n");
                else if (t==0)
                        printf("Cette cle n'existe pas dans l'ABR\n");
                break;
            default:
                printf("l'ABS n'exist pas\n");
                break;
            }
            break;
        case 7:
            // comparer la taille occupée par l’ABR avec chacune des représentations
            // utiliser le tableau pre charge
            initABR();
            for (int i=0; i<taille;i++)
                insererSommet(arr[i]);
            tArbre=tailleArbre();
            printf("la taille occupee par l'ABR avec representation classique : %d \n", tArbre);

            initABRCompact();
            for (int i=0; i<taille;i++)
                insererElement(arr[i]);
            tArbre = tailleArbreCompact();
            printf("la taille occupee par l'ABR avec representation plus compacte : %d \n", tArbre);
            break;
        case 8:
            exit(0);
        }
    }
    return 0;
}
