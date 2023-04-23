/* Coup.h */
#ifndef __COUP__
#define __COUP__
#include "Position.h"
#include "Joueur.h"
#include "Regles.h"
#include "Clic.h"

    /*Type structuré definissant un coup*/
    typedef struct{
        int x;
        int y;
    }Coup;

    /*Cette fonction permet de renvoyer le coup du joueur selon l'endroit dans lequel il a cliqué dans 'pos'*/
    Coup lire_coup(Position pos);

    /*Cette fonction affecte à 'pos' la tablette une fois que les carré suite au coup 'coup' on été mangés
    de plus elle affecte au champs 'tour' la valeur du joueur adverse*/
    void jouer_coup(Position *pos, Coup coup);


#endif



