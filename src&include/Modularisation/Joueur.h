/*Joueur.h */
#ifndef __JOUEUR__
#define __JOUEUR__


    /*Type enuméré permettant de représenté les joueurs*/
    typedef enum{
        JOUEUR_1,
        JOUEUR_2
    }Joueur;

    /*Cette fonction permet de renvoyer la valeur du joueur adverse à celui de 'joueur'*/
    Joueur adversaire(Joueur joueur);

#endif


