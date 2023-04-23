/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>

/*On definit les macros*/
#define N 8
#define M 16


/*Type structuré représentant la tablette*/
typedef struct{
    unsigned int n;
    unsigned int m;
    int tab[N][M];
}Tablette;


/*Type enuméré permettant de représenté les joueurs*/
typedef enum{
    JOUEUR_1,
    JOUEUR_2
}Joueur;


/*Type structuré représentant la position*/
typedef struct{
    Tablette chocolat;
    Joueur tour;
}Position;


/*Type structuré definissant un coup*/
typedef struct{
    int x;
    int y;
}Coup;


/*Cette fonction permet de renvoyer la valeur du joueur adverse à celui de 'joueur'*/

Joueur adversaire(Joueur joueur){

    if(joueur == JOUEUR_1)
        return JOUEUR_2;

    if(joueur == JOUEUR_2)
        return JOUEUR_1;
    return 0;
}


/*Cette fonction permet de renvoyer un type Tablette initialisé (aucun carré mangé)*/

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


/*Cette fonction permet d'affecter la valeur 0 à la case 'y' de la case 'x' la tablette 'tab' ainsi qu'à tous les carrès
en bas à droite de celui-ci*/

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


/*Cette fonction renvoie 1 si le coup 'coup' touche une case du tableau de 'pos' égale à 1 et 0 sinon*/

int est_legal(Position pos, Coup coup){

    /*On s'assure que les coordonnées du coup son positives*/
    assert(coup.x >= 0);
    assert(coup.y >= 0);

    /*Si c'est égal à 1 le carré n'a pas été mangé le coup est donc valide*/
    if ((pos.chocolat).tab[coup.y][coup.x] == 1)
        return 1;
    return 0;
}


/*Cette fonction renvoie 1 et affecte à 'joueur' le joueur gagnant si la première case de la tablette de 'pos' vaut 0 cad
que le poison a été mangé renvoie 0 sinon*/

int est_jeu_termine(Position pos, Joueur *joueur_gagnant){

    /*On s'assure que l'on pourra bien accéder à la case [0][0] du tableau*/
    assert((pos.chocolat).tab != NULL);
    assert((pos.chocolat).tab[0] != NULL);

    /*On regarde si la première case vaut 0*/
    if ((pos.chocolat).tab[0][0] == 0){
        /*Le gagnant est l'autre joueur*/
        *joueur_gagnant = adversaire(pos.tour);
        return 1;
    }
    *joueur_gagnant = adversaire(pos.tour);
    return 0;
}


/*Cette fonction affecte à 'pos' la tablette une fois que les carré suite au coup 'coup' on été mangés
de plus elle affecte au champs 'tour' la valeur du joueur adverse*/

void jouer_coup(Position *pos, Coup coup){
    manger(&((*pos).chocolat),coup.x, coup.y);
    (*pos).tour = adversaire((*pos).tour);
}


/*Cette fonction permet de dessiner graphiquement un rectangle de point 'y1'-'x1' au point 'y2'-'x2'*/

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2 - x1);
    mvhline(y2, x1, 0, x2 - x1);
    mvvline(y1, x1, 0, y2 - y1);
    mvvline(y1, x2, 0, y2 - y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}


/*Cette fonction permet d'afficher graphiquement la tablette de 'pos'*/

void afficher_position(Position pos){
    int i, j, centrage;

    /*On met cette valeur afin de pouvoir centrer la tablette*/
    centrage = ((COLS/2) - (((pos.chocolat).m)*2));

    /*On parcourt les cases du tableau à double dimensions*/
    for(i = 0; i < (pos.chocolat).n ; i++){

        for(j = 0; j < (pos.chocolat).m ; j++){

            /*Première itération, on affiche le poison dans la couleur déifnie dans le main*/
            if(j == 0 && i == 0){
                attron(COLOR_PAIR(1));
                mvprintw(1, 2 + centrage, "°");
                mvvline(0, 4, 2, 4);
                attroff(COLOR_PAIR(1));
            }

            /*Si la case du tableau à une valeur égale à 1 on peut afficher la case*/
            if((pos.chocolat).tab[i][j] == 1){
                rectangle(i * 2, (j * 4) + centrage, (i + 1) * 2, ((j + 1) * 4) + centrage);
            }
        }
    }
    /*On actualises les élements graphiques de la fenêtre*/
    refresh();
}


/*Cette fonction renvoie 1, si le clic ayant pour coordonnées 'x' et 'y' est bien effectué sur une ca de la tablette de 'pos' sinon renvoie 0
de plus si le clic est bien sur une case on affecte aux variables 'case_x' et 'case_y' les valeurs des cases correcpondantes*/

int ClicVersCase(Position pos, int x, int y, int *case_x, int *case_y){
    int i, j, centrage;

    centrage = ((COLS / 2) - (((pos.chocolat).m) * 2));

    /*On reparcourt le tableau dessiné dans la fonction afficher_position*/
    for(i = 0; i < (pos.chocolat).n ; i++){

        for(j = 0; j < (pos.chocolat).m ; j++){

            /*Si les coordonnées du clic sont bien comprises entre celle de la case courante on renvoie 1 et on affecte les valeurs correpodantnes*/
            if((((j * 4) + centrage) <= x) && ((((j + 1) * 4) + centrage) >= x)
                        && ((i * 2) <= y) && (((i + 1) * 2) >= y)){
                *case_x = j;
                *case_y = i;
                return 1;
            }
        }
    }

    return 0;
}


/*Cette fonction permet de renvoyer le coup du joueur selon l'endroit dans lequel il a cliqué dans 'pos'*/

Coup lire_coup(Position pos){
    int touche, clic_valide, centrage, case_x, case_y;
    MEVENT ev;
    Coup clic;

    centrage = ((COLS / 2) - (((pos.chocolat).m) * 2));
    case_x = -1;
    case_y = -1;
    clic_valide = 0;

    do{
        /*On attend un eventuel clic*/
        touche = getch();

        /*S'il s'agit d'un clic*/
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {

            /*On recupère les coordonnées du clic*/
            clic.x = ev.x;
            clic.y = ev.y;

            /*On calcule et affecte à clic.x et clic.y la conversion du clic en case du tableau correcpondante*/
            ClicVersCase(pos, clic.x, clic.y, &case_x, &case_y);
            clic.x = case_x;
            clic.y = case_y;
        }

        /*Si le coup est légal et que l'on a bien trouvé l'équivalent en case du tableau du clic
        de l'utilisateur on arrête la boucle*/
        if(case_x != -1 && est_legal(pos, clic)){
             clic_valide = 1;
        }
    }while(clic_valide == 0);

    return clic;
}


int main(void){
    Position pos;
    Joueur joueur;
    Coup coup;

    /*Initialisation de la tablette*/
    pos.chocolat = creer_tablette();

    /*Ecran graphique et fonctionnalités*/
    initscr();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(0);
    noecho();

    /*Definition de la couleur*/
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    /*Tant que le jeu n'est pas terminé on continue*/
    while(est_jeu_termine(pos, &joueur) != 1){
        clear();
        mvprintw(0, 0, "Joueur :  %d ", joueur + 1); /*Affichage du tour du joueur*/

        /*On affiche la tablette, on lit le coup venant de l'utilisateur, et on joue le coup pour modifier les etats
        de la tablette et du tour du joueur*/
        afficher_position(pos);
        coup = lire_coup(pos);
        jouer_coup(&pos, coup);
    }

    clear();
    /*On affiche le vainqueur*/
    mvprintw(2, (COLS/2) - 15, "Le joueur %d remporte la partie", joueur+1);

    getch();
    endwin();
    return 0;
}
