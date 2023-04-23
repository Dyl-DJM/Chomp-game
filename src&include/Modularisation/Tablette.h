/*Tablette.h */
#ifndef __TABLETTE__
#define __TABLETTE__


    /*On definit les macros*/
    #define N 8
    #define M 16

    /*Type structuré représentant la tablette*/
    typedef struct{
        unsigned int n;
        unsigned int m;
        int tab[N][M];
    }Tablette;

    /*Cette fonction permet de renvoyer un type Tablette initialisé (aucun carré mangé)*/
    Tablette creer_tablette();

    /*Cette fonction permet d'affecter la valeur 0 à la case 'y' de la case 'x' la tablette 'tab' ainsi qu'à tous les carrès
    en bas à droite de celui-ci*/
    void manger(Tablette *tab, int x, int y);

#endif


