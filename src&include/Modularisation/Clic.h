/* Clic.h */
#ifndef __CLIC__
#define __CLIC__
#include "Position.h"

    /*Cette fonction renvoie 1, si le clic ayant pour coordonnées 'x' et 'y' est bien effectué sur une ca de la tablette de 'pos' sinon renvoie 0
    de plus si le clic est bien sur une case on affecte aux variables 'case_x' et 'case_y' les valeurs des cases correcpondantes*/
    int ClicVersCase(Position pos, int x, int y, int *case_x, int *case_y);

#endif