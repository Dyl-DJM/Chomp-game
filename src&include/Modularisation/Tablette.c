/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include "Tablette.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>

Tablette creer_tablette(){
    Tablette chocolat_depart;
    int i, j;

    /*On parcourt le tableau à double dimension pour insérer les valeurs 1*/
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            chocolat_depart.tab[i][j] = 1;
        }
    }
    chocolat_depart.n = N;
    chocolat_depart.m = M;

    return chocolat_depart;
}


void manger(Tablette *tab, int x, int y){
    int i, j;

    /*On s'assure que les coordonnées sont positives*/
    assert(x >= 0);
    assert(y >= 0);

    for(i = 0; i < (*tab).n; i++){
        for(j = 0; j < (*tab).m; j++){
            if((i >= y) && (j >= x))
                (*tab).tab[i][j] = 0;
        }
    }
}