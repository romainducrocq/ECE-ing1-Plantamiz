#include "fichier.h"

int Niveau(int Niveau) ///Niveau N
{
    show_mouse(screen);
    install_mouse();
    install_keyboard();
    BITMAP *BSoleil, *BOrange, *BPomme, *BOignon, *BFraise, *BPerdu, *BGagne, *BAbandon, *BVies;
    BITMAP *BContratniveau1, *BContratniveau2, *BContratniveau3;
    BITMAP *BDeselection, *BSelection;
    BITMAP *BFondHaut, *BFondMilieu, *BFondBas;
    BITMAP *BX, *BBonus, *BMalus;
    BSoleil=load_bitmap("Soleil.bmp",NULL);
    BOrange=load_bitmap("Orange.bmp",NULL);
    BPomme=load_bitmap("Pomme.bmp",NULL);
    BOignon=load_bitmap("Oignon.bmp",NULL);
    BFraise=load_bitmap("Fraise.bmp",NULL);
    BPerdu=load_bitmap("Perdu.bmp",NULL);
    BGagne=load_bitmap("gagne.bmp",NULL);
    BAbandon=load_bitmap("Abandon.bmp",NULL);
    BVies=load_bitmap("Vies.bmp",NULL);
    BContratniveau1=load_bitmap("Contratniveau1.bmp",NULL);
    BContratniveau2=load_bitmap("Contratniveau2.bmp",NULL);
    BContratniveau3=load_bitmap("Contratniveau3.bmp",NULL);
    BDeselection=load_bitmap("Deselection.bmp",NULL);
    BSelection=load_bitmap("Selection.bmp",NULL);
    BFondHaut=load_bitmap("FondHaut.bmp",NULL);
    BFondMilieu=load_bitmap("FondMilieu.bmp",NULL);
    BFondBas=load_bitmap("FondBas.bmp",NULL);
    BX=load_bitmap("Bonus1.bmp",NULL);
    BBonus=load_bitmap("Bonus+1.bmp",NULL);
    BMalus=load_bitmap("Malus-1.bmp",NULL);
    char tab[10][15]; ///Ressources ///Matrice
    int Vies; ///Elements de jeu (vie, plantamitz, coups disponibles)
    Vies=5;
    int Score;
    int Soleil;
    int Fraise;
    int Pomme;
    int Oignon;
    int Mandarine;
    int coups;
    char t; ///Variables temporaires
    char x,y;
    char tmp;
    char tmplig5;
    char tmpcol5;
    int xtab, ytab; ///Compteurs
    int xtab5, ytab5; ///Compteurs (ligne ou colonne de 5)
    int Combinaison; ///Booléen qui indique si il y a une combinaison
    int continuer; ///Booléen qui indique si le joueur reste dans le niveau ou le quitte (victoire, défaite, abandon)
    int gagne=0; ///Booléen qui indique si il y a victoire ou défaite
    int deplacement=1; ///Booléen qui indique si le joueur a éffectué un coups
    int NiveauSuivant; ///Booléen qui confirme ou non le passage au niveau suivant
    int Abandon;
    int Souris;
    int NcaseX1, NcaseX2, NcaseY1, NcaseY2;
    int boolcoups;
    int aleax1, aleax2, aleay1, aleay2, aleax3, aleay3, aleax4, aleay4; ///Postion des caractères bonus
    int BonusX; ///variable du bonus n°1 qui prend une valeur aléatoire entre 0 et 1
     int BonusCoin; ///variable du bonus n°2 qui prend une valeur aléatoire entre 0 et 3 (niveau 2) ou 0 et 4 (niveau 3)
    int BonusCoinBool=1; ///Booléen qui indique si le bonnus n°2 est disponible ou a déjà été utilisé (il est unique par niveau)
    do ///Boucle tant qu'il y a des vies disponibles
    {
        rectfill(screen,0,0,1020,768, makecol(192,220,192));

        Score=0; ///Valeurs de départ
        Soleil=0;
        Fraise=0;
        Pomme=0;
        Oignon=0;
        Mandarine=0;
        Abandon=0;
        Souris=0;

        if(Niveau==1) ///Affichages contrat niveau 1
        {
            coups=20;
            masked_blit(BContratniveau1,screen,0,0,0,0, BContratniveau1->w, BContratniveau1->h);
        }

        if(Niveau==2) ///Affichages contrat niveau 2
        {
            coups=25;
            masked_blit(BContratniveau2,screen,0,0,0,0, BContratniveau2->w, BContratniveau2->h);
        }

        if (Niveau==3) ///Affichages contrat niveau 3
        {
            coups=30;
            masked_blit(BContratniveau3,screen,0,0,0,0, BContratniveau3->w, BContratniveau3->h);
        }
        ///Niveau
        Unite(Niveau, 330, 540);
///Vies
Unite(Vies, 240, 622);
Coeur(Vies, coups, 264, 622);

///Nombres coups

Unite(coups, 330, 706);
Dizaine(coups, 300, 706);

        ///Score total
Unite(Score, 938, 706);
Dizaine(Score, 908, 706);
Centaine(Score, 878, 706);

        Score=0; ///Valeurs de départ
        Soleil=0;
        Fraise=0;
        Pomme=0;
        Oignon=0;
        Mandarine=0;

        afficherdepart(tab);
         aleax1=rand()%15; ///Postion des caractères bonus X
        aleay1=rand()%5;
        do
        {
            aleax2=rand()%15;
            aleay2=rand()%5;
        }
        while(aleax2==aleax1&&aleay2==aleay1);
        aleax3=rand()%15;
        aleay3=(rand()%5)+5;
        do
        {
            aleax4=rand()%15;
            aleay4=(rand()%5)+5;
        }
        while(aleax4==aleax3&&aleay4==aleay3);
        if(Niveau==2||Niveau==3)
        {
            tab[aleay1][aleax1]='X'; ///Bonus 1e caractere X
            masked_blit(BX,screen,0,0,(aleax1*68),(aleay1*52), BX->w, BX->h);
            tab[aleay2][aleax2]='X'; ///Bonus 2e caractere X
            masked_blit(BX,screen,0,0,(aleax2*68),(aleay2*52), BX->w, BX->h);
            tab[aleay3][aleax3]='X'; ///Bonus 3e caractere X
            masked_blit(BX,screen,0,0,(aleax3*68),(aleay3*52), BX->w, BX->h);
            tab[aleay4][aleax4]='X'; ///Bonus 4e caractere X
            masked_blit(BX,screen,0,0,(aleax4*68),(aleay4*52), BX->w, BX->h);
        }

        do ///Boucle tant qu'il y a des coups disponibles et que le contrat n'est pas rempli
        {


            boolcoups=0;

            do
            {

                if (key[KEY_V]) ///Pour la soutenance, perdre une vie
                {
                    coups=0;
                        Abandon=0;
                        boolcoups=1;
                }
                  if (key[KEY_P]) ///Pour la soutenance, perdre la partie
                        {
                          coups=0;
                        Vies=1;
                        Abandon=0;
                        boolcoups=1;
                        }
                   if (key[KEY_G]) ///Pour la soutenance, gagner un niveau
                        {
                         gagne=1;
                        Abandon=1;
                        boolcoups=1;
                        if(Score==0)
                            Score=1;
                        }
                if((mouse_b&1)&&mouse_y>748&&mouse_x>1000)
                {
                    boolcoups=1;
                    Score=0;
                    continuer=0;
                    gagne=0;
                    Abandon=1;
                }


                else if ((mouse_b&1)&&deplacement==1&&mouse_y<520)
                {
                    NcaseX1=(mouse_x/68);
                    NcaseY1=(mouse_y/52);
                    deplacement=0;
                    masked_blit(BSelection,screen,0,0,(NcaseX1*68),(NcaseY1*52), BSelection->w, BSelection->h);
                    _sleep(200);
                }
                else if ((mouse_b&1)&&deplacement==0&&mouse_y<520)
                {
                    NcaseX2=(mouse_x/68);
                    NcaseY2=(mouse_y/52);
                    deplacement=1;
                    if (NcaseX1==NcaseX2&&NcaseY1==(NcaseY2-1))  ///Bas
                    {
                        tmp=tab[NcaseY1][NcaseX1]; ///SWAP case adjacente Basse
                        tab[NcaseY1][NcaseX1]=tab[NcaseY2][NcaseX2];
                        tab[NcaseY2][NcaseX2]=tmp;

                        if (tab[NcaseY1][NcaseX1]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX1*68),(NcaseY1*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY1][NcaseX1]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX1*68),(NcaseY1*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY1][NcaseX1]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX1*68),(NcaseY1*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY1][NcaseX1]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX1*68),(NcaseY1*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY1][NcaseX1]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX1*68),(NcaseY1*52), BSoleil->w, BSoleil->h);
                            if (tab[NcaseY1][NcaseX1]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX1*68),(NcaseY1*52), BX->w, BX->h);

                        if (tab[NcaseY2][NcaseX2]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX2*68),(NcaseY2*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY2][NcaseX2]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX2*68),(NcaseY2*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY2][NcaseX2]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX2*68),(NcaseY2*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY2][NcaseX2]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX2*68),(NcaseY2*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY2][NcaseX2]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX2*68),(NcaseY2*52), BSoleil->w, BSoleil->h);
                            if (tab[NcaseY2][NcaseX2]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX2*68),(NcaseY2*52), BX->w, BX->h);

                        ///Décrémentation coups restants
                        boolcoups=1;
                        coups=coups-1;
                    }

                    else if (NcaseX1==NcaseX2&&NcaseY1==(NcaseY2+1))  ///Haut
                    {
                        tmp=tab[NcaseY1][NcaseX1]; ///SWAP case adjacente Haute
                        tab[NcaseY1][NcaseX1]=tab[NcaseY2][NcaseX2];
                        tab[NcaseY2][NcaseX2]=tmp;

                        if (tab[NcaseY1][NcaseX1]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX1*68),(NcaseY1*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY1][NcaseX1]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX1*68),(NcaseY1*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY1][NcaseX1]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX1*68),(NcaseY1*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY1][NcaseX1]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX1*68),(NcaseY1*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY1][NcaseX1]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX1*68),(NcaseY1*52), BSoleil->w, BSoleil->h);
                            if (tab[NcaseY1][NcaseX1]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX1*68),(NcaseY1*52), BX->w, BX->h);

                        if (tab[NcaseY2][NcaseX2]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX2*68),(NcaseY2*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY2][NcaseX2]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX2*68),(NcaseY2*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY2][NcaseX2]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX2*68),(NcaseY2*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY2][NcaseX2]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX2*68),(NcaseY2*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY2][NcaseX2]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX2*68),(NcaseY2*52), BSoleil->w, BSoleil->h);
                            if (tab[NcaseY2][NcaseX2]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX2*68),(NcaseY2*52), BX->w, BX->h);

                        ///Décrémentation coups restants
                        boolcoups=1;
                        coups=coups-1;
                    }

                    else if (NcaseX1==(NcaseX2-1)&&NcaseY1==NcaseY2)  ///Gauche
                    {
                        tmp=tab[NcaseY1][NcaseX1]; ///SWAP case adjacente Gauche
                        tab[NcaseY1][NcaseX1]=tab[NcaseY2][NcaseX2];
                        tab[NcaseY2][NcaseX2]=tmp;

                        if (tab[NcaseY1][NcaseX1]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX1*68),(NcaseY1*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY1][NcaseX1]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX1*68),(NcaseY1*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY1][NcaseX1]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX1*68),(NcaseY1*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY1][NcaseX1]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX1*68),(NcaseY1*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY1][NcaseX1]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX1*68),(NcaseY1*52), BSoleil->w, BSoleil->h);
                             if (tab[NcaseY1][NcaseX1]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX1*68),(NcaseY1*52), BX->w, BX->h);

                        if (tab[NcaseY2][NcaseX2]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX2*68),(NcaseY2*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY2][NcaseX2]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX2*68),(NcaseY2*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY2][NcaseX2]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX2*68),(NcaseY2*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY2][NcaseX2]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX2*68),(NcaseY2*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY2][NcaseX2]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX2*68),(NcaseY2*52), BSoleil->w, BSoleil->h);
                             if (tab[NcaseY2][NcaseX2]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX2*68),(NcaseY2*52), BX->w, BX->h);

                        ///Décrémentation coups restants
                        boolcoups=1;
                        coups=coups-1;
                    }

                    else if (NcaseX1==(NcaseX2+1)&&NcaseY1==NcaseY2)  ///Droite
                    {
                        tmp=tab[NcaseY1][NcaseX1]; ///SWAP case adjacente Droite
                        tab[NcaseY1][NcaseX1]=tab[NcaseY2][NcaseX2];
                        tab[NcaseY2][NcaseX2]=tmp;

                        if (tab[NcaseY1][NcaseX1]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX1*68),(NcaseY1*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY1][NcaseX1]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX1*68),(NcaseY1*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY1][NcaseX1]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX1*68),(NcaseY1*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY1][NcaseX1]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX1*68),(NcaseY1*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY1][NcaseX1]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX1*68),(NcaseY1*52), BSoleil->w, BSoleil->h);
                            if (tab[NcaseY1][NcaseX1]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX1*68),(NcaseY1*52), BX->w, BX->h);


                        if (tab[NcaseY2][NcaseX2]=='P')
                            masked_blit(BPomme,screen,0,0,(NcaseX2*68),(NcaseY2*52), BPomme->w, BPomme->h);
                        if (tab[NcaseY2][NcaseX2]=='F')
                            masked_blit(BFraise,screen,0,0,(NcaseX2*68),(NcaseY2*52), BFraise->w, BFraise->h);
                        if (tab[NcaseY2][NcaseX2]=='M')
                            masked_blit(BOrange,screen,0,0,(NcaseX2*68),(NcaseY2*52), BOrange->w, BOrange->h);
                        if (tab[NcaseY2][NcaseX2]=='O')
                            masked_blit(BOignon,screen,0,0, (NcaseX2*68),(NcaseY2*52), BOignon->w, BOignon->h);
                        if (tab[NcaseY2][NcaseX2]=='S')
                            masked_blit(BSoleil,screen,0,0,(NcaseX2*68),(NcaseY2*52), BSoleil->w, BSoleil->h);
                         if (tab[NcaseY2][NcaseX2]=='X')
                            masked_blit(BX,screen,0,0,(NcaseX2*68),(NcaseY2*52), BX->w, BX->h);

                        ///Décrémentation coups restants
                        boolcoups=1;
                        coups=coups-1;
                    }
                    else
                    {
                        deplacement=1;
                        masked_blit(BDeselection,screen,0,0,(NcaseX1*68),(NcaseY1*52), BDeselection->w, BDeselection->h);
                        _sleep(200);
                    }

                }
            }
            while(boolcoups==0);
            do ///Boucle tant qu'il y a des combinaisons
            {
                Combinaison=0; ///Pas de combinaisons
                for (xtab=0; xtab<15; xtab++) ///Parcourt de la matrice
                {
                    for (ytab=0; ytab<10; ytab++)
                    {
                        ///Bonus n°1 (si 2 X adjacents, 1/2 chance bonus score, 1/2 chance malus coups disponibles)
                                if(tab[ytab][xtab]=='X')
                                {
                                    BonusX=rand()%2;
                                    if(BonusX==0) ///Bonus Score +100 (niveau 2) ou +200 (niveau 3)
                                    {
                                        ///ligne
                                        if(tab[ytab][xtab+1]=='X'&&xtab<14)
                                        {
                                            if(Niveau==2)
                                                Score=Score+100; ///Incrémentation score bonus
                                            if(Niveau==3)
                                                Score=Score+200;
                                            tab[ytab][xtab]=' '; ///Affichage des espaces
                                            tab[ytab][xtab+1]=' ';
                                            masked_blit(BBonus,screen,0,0,(xtab*68),(ytab*52), BBonus->w, BBonus->h);
                                            masked_blit(BBonus,screen,0,0,((xtab+1)*68),(ytab*52), BBonus->w, BBonus->h);
                                            _sleep(1000);
                                            Combinaison=1; ///Combinaison
                                            Gravite(tab); ///Application de la gravité simulée
                                        }
                                        ///Colonne
                                        if(tab[ytab+1][xtab]=='X'&&ytab<9)
                                        {
                                            if(Niveau==2)
                                                Score=Score+100; ///Incrémentation score bonus
                                            if(Niveau==3)
                                                Score=Score+200;
                                            tab[ytab][xtab]=' '; ///Affichage des espaces
                                            tab[ytab+1][xtab]=' ';
                                            masked_blit(BBonus,screen,0,0,(xtab*68),(ytab*52), BBonus->w, BBonus->h);
                                            masked_blit(BBonus,screen,0,0,(xtab*68),((ytab+1)*52), BBonus->w, BBonus->h);
                                            _sleep(1000);
                                            Combinaison=1; ///Combinaison
                                            Gravite(tab); ///Application de la gravité simulée
                                        }
                                    }
                                    if(BonusX==1) ///Malus coups disponibles -10 (niveau 2) ou -20 (niveau 3)
                                    {
                                        ///ligne
                                        if(tab[ytab][xtab+1]=='X'&&xtab<14)
                                        {
                                            if(Niveau==2)
                                            {
                                                if((coups-9)>0) ///Malus coups-10
                                                    coups=coups-9; ///Incrémentation score bonus
                                                else
                                                    coups=0;
                                            }
                                            if(Niveau==3)
                                            {
                                                if((coups-19)>0) ///Malus coups-10
                                                    coups=coups-19; ///Incrémentation score bonus
                                                else
                                                    coups=0;
                                            }
                                            tab[ytab][xtab]=' '; ///Affichage des espaces
                                            tab[ytab][xtab+1]=' ';
                                            masked_blit(BMalus,screen,0,0,(xtab*68),(ytab*52), BMalus->w, BMalus->h);
                                            masked_blit(BMalus,screen,0,0,((xtab+1)*68),(ytab*52), BMalus->w, BMalus->h);
                                            _sleep(1000);
                                            Combinaison=1; ///Combinaison
                                            Gravite(tab); ///Application de la gravité simulée
                                        }
                                        ///Colonne
                                        if(tab[ytab+1][xtab]=='X'&&ytab<9)
                                        {
                                            if(Niveau==2)
                                            {
                                                if((coups-9)>0) ///Malus coups-10
                                                    coups=coups-9; ///Incrémentation score bonus
                                                else
                                                    coups=0;
                                            }
                                            if(Niveau==3)
                                            {
                                                if((coups-19)>0) ///Malus coups-10
                                                    coups=coups-19; ///Incrémentation score bonus
                                                else
                                                    coups=0;
                                            }
                                            tab[ytab][xtab]=' '; ///Affichage des espaces
                                            tab[ytab+1][xtab]=' ';
                                            masked_blit(BMalus,screen,0,0,(xtab*68),(ytab*52), BMalus->w, BMalus->h);
                                            masked_blit(BMalus,screen,0,0,(xtab*68),((ytab+1)*52), BMalus->w, BMalus->h);
                                            _sleep(1000);
                                            Combinaison=1; ///Combinaison
                                            Gravite(tab); ///Application de la gravité simulée
                                        }
                                    }
                                }
                                ///Combinaison bonus (4 coins du tableau), une seule fois par niveau
                                if(tab[0][0]==tab[0][14]&&tab[0][0]==tab[9][0]&&tab[0][0]==tab[9][14]&&tab[0][0]!=' '&&BonusCoinBool==1)
                                {
                                    if(Niveau==2||Niveau==3) ///Applicable uniquement aux niveaux 2 et 3
                                    {
                                    if(Niveau==2) ///Si niveau 2
                                    {
                                        do{
                                        BonusCoin=rand()%4; ///Variable aléatoire entre 0 et 3
                                        if(BonusCoin==0&&Soleil<25) ///Remplissage du contrat pour un type de plantamitz unique, aléatoire et non encore achevé
                                        {
                                            Soleil=25;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==1&&Pomme<15)
                                        {
                                            Pomme=15;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==2&&Fraise<10)
                                        {
                                            Fraise=10;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==3&&Oignon<15)
                                        {
                                            Oignon=15;
                                            BonusCoinBool=0;
                                        }
                                        }while(BonusCoinBool==1);
                                    }
                                    if(Niveau==3) ///Si niveau 3
                                    {
                                        do{
                                        BonusCoin=rand()%5; ///Variable aléatoire entre 0 et 4
                                        if(BonusCoin==0&&Soleil<25) ///Remplissage du contrat pour un type de plantamitz unique, aléatoire et non encore achevé
                                        {
                                            Soleil=25;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==1&&Pomme<25)
                                        {
                                            Pomme=25;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==2&&Fraise<25)
                                        {
                                            Fraise=25;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==3&&Oignon<25)
                                        {
                                            Oignon=25;
                                            BonusCoinBool=0;
                                        }
                                        if(BonusCoin==4&&Mandarine<25)
                                        {
                                            Mandarine=25;
                                            BonusCoinBool=0;
                                        }
                                        }while(BonusCoinBool==1);
                                    }
                                    if(tab[0][0]=='S')
                                    {
                                        BFS(0, 0, 0, 0);
                                        BFS(0, 0, 14, 0);
                                        BFS(0, 0, 0, 9);
                                        BFS(0, 0, 14, 9);
                                    }
                                    if(tab[0][0]=='F')
                                    {
                                        BFF(0, 0, 0, 0);
                                        BFF(0, 0, 14, 0);
                                        BFF(0, 0, 0, 9);
                                        BFF(0, 0, 14, 9);
                                    }
                                    if(tab[0][0]=='P')
                                    {
                                        BFP(0, 0, 0, 0);
                                        BFP(0, 0, 14, 0);
                                        BFP(0, 0, 0, 9);
                                        BFP(0, 0, 14, 9);
                                    }
                                    if(tab[0][0]=='O')
                                    {
                                        BFO(0, 0, 0, 0);
                                        BFO(0, 0, 14, 0);
                                        BFO(0, 0, 0, 9);
                                        BFO(0, 0, 14, 9);
                                    }
                                    if(tab[0][0]=='M')
                                    {
                                        BFM(0, 0, 0, 0);
                                        BFM(0, 0, 14, 0);
                                        BFM(0, 0, 0, 9);
                                        BFM(0, 0, 14, 9);
                                    }
                                   tab[0][0]=' '; ///Affichage des espaces
                                   tab[0][14]=' ';
                                   tab[9][0]=' ';
                                   tab[9][14]=' ';

                                    _sleep(500);
                                    Combinaison=1; ///Combinaison
                                    Gravite(tab); ///Application de la gravité simulée
                                }
                            }
                        ///croix
                        if(tab[ytab+1][xtab+1]==tab[ytab+1][xtab]&&tab[ytab+1][xtab+1]==tab[ytab+1][xtab+2]&&tab[ytab+1][xtab+1]==tab[ytab][xtab+1]&&tab[ytab+1][xtab+1]==tab[ytab+2][xtab+1]&&tab[ytab+1][xtab+1]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab+1][xtab+1]=='S') ///Incrémentation plantamitz
                            {
                                Soleil=Soleil+5;
                                BFS(1, 1, xtab, ytab);
                                BFS(1, 0, xtab, ytab);
                                BFS(1, 2, xtab, ytab);
                                BFS(0, 1, xtab, ytab);
                                BFS(2, 1, xtab, ytab);
                            }
                            if(tab[ytab+1][xtab+1]=='F')
                            {
                                Fraise=Fraise+5;
                                BFF(1, 1, xtab, ytab);
                                BFF(1, 0, xtab, ytab);
                                BFF(1, 2, xtab, ytab);
                                BFF(0, 1, xtab, ytab);
                                BFF(2, 1, xtab, ytab);
                            }
                            if(tab[ytab+1][xtab+1]=='P')
                            {
                                Pomme=Pomme+5;
                                BFP(1, 1, xtab, ytab);
                                BFP(1, 0, xtab, ytab);
                                BFP(1, 2, xtab, ytab);
                                BFP(0, 1, xtab, ytab);
                                BFP(2, 1, xtab, ytab);
                            }
                            if(tab[ytab+1][xtab+1]=='O')
                            {
                                Oignon=Oignon+5;
                                BFO(1, 1, xtab, ytab);
                                BFO(1, 0, xtab, ytab);
                                BFO(1, 2, xtab, ytab);
                                BFO(0, 1, xtab, ytab);
                                BFO(2, 1, xtab, ytab);
                            }
                            if(tab[ytab+1][xtab+1]=='M')
                            {
                                Mandarine=Mandarine+5;
                                BFM(1, 1, xtab, ytab);
                                BFM(1, 0, xtab, ytab);
                                BFM(1, 2, xtab, ytab);
                                BFM(0, 1, xtab, ytab);
                                BFM(2, 1, xtab, ytab);
                            }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab+1][xtab+1]=' '; ///Affichage des espaces
                            tab[ytab+1][xtab]=' ';
                            tab[ytab+1][xtab+2]=' ';
                            tab[ytab][xtab+1]=' ';
                            tab[ytab+2][xtab+1]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///T(pivot O deg)
                        if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]==tab[ytab+1][xtab+1]&&tab[ytab][xtab]==tab[ytab+2][xtab+1]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                                {
                                Soleil=Soleil+5;
                                BFS(0, 0, xtab, ytab);
                                BFS(0, 1, xtab, ytab);
                                BFS(0, 2, xtab, ytab);
                                BFS(1, 1, xtab, ytab);
                                BFS(2, 1, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='F')
                            {
                                Fraise=Fraise+5;
                                BFF(0, 0, xtab, ytab);
                                BFF(0, 1, xtab, ytab);
                                BFF(0, 2, xtab, ytab);
                                BFF(1, 1, xtab, ytab);
                                BFF(2, 1, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='P')
                            {
                                Pomme=Pomme+5;
                                BFP(0, 0, xtab, ytab);
                                BFP(0, 1, xtab, ytab);
                                BFP(0, 2, xtab, ytab);
                                BFP(1, 1, xtab, ytab);
                                BFP(2, 1, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='O')
                            {
                                Oignon=Oignon+5;
                                BFO(0, 0, xtab, ytab);
                                BFO(0, 1, xtab, ytab);
                                BFO(0, 2, xtab, ytab);
                                BFO(1, 1, xtab, ytab);
                                BFO(2, 1, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='M')
                            {
                                Mandarine=Mandarine+5;
                                BFM(0, 0, xtab, ytab);
                                BFM(0, 1, xtab, ytab);
                                BFM(0, 2, xtab, ytab);
                                BFM(1, 1, xtab, ytab);
                                BFM(2, 1, xtab, ytab);
                            }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab][xtab+1]=' ';
                            tab[ytab][xtab+2]=' ';
                            tab[ytab+1][xtab+1]=' ';
                            tab[ytab+2][xtab+1]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///T(pivot 9O deg)
                        if (tab[ytab+2][xtab+2]==tab[ytab+1][xtab]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+1]&&tab[ytab+2][xtab+2]==tab[ytab][xtab+2]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+2]&&tab[ytab+2][xtab+2]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab+2][xtab+2]=='S') ///Incrémentation plantamitz
                                {
                                Soleil=Soleil+5;
                                BFS(2, 2, xtab, ytab);
                                BFS(1, 0, xtab, ytab);
                                BFS(1, 1, xtab, ytab);
                                BFS(0, 2, xtab, ytab);
                                BFS(1, 2, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='F')
                            {
                                Fraise=Fraise+5;
                                BFF(2, 2, xtab, ytab);
                                BFF(1, 0, xtab, ytab);
                                BFF(1, 1, xtab, ytab);
                                BFF(0, 2, xtab, ytab);
                                BFF(1, 2, xtab, ytab);
                            }
                            if(tab[ytab+2][xtab+2]=='P')
                            {
                                Pomme=Pomme+5;
                                BFP(2, 2, xtab, ytab);
                                BFP(1, 0, xtab, ytab);
                                BFP(1, 1, xtab, ytab);
                                BFP(0, 2, xtab, ytab);
                                BFP(1, 2, xtab, ytab);
                            }
                            if(tab[ytab+2][xtab+2]=='O')
                            {
                                Oignon=Oignon+5;
                                BFO(2, 2, xtab, ytab);
                                BFO(1, 0, xtab, ytab);
                                BFO(1, 1, xtab, ytab);
                                BFO(0, 2, xtab, ytab);
                                BFO(1, 2, xtab, ytab);

                            }
                            if(tab[ytab+2][xtab+2]=='M')
                            {
                                Mandarine=Mandarine+5;
                                BFM(2, 2, xtab, ytab);
                                BFM(1, 0, xtab, ytab);
                                BFM(1, 1, xtab, ytab);
                                BFM(0, 2, xtab, ytab);
                                BFM(1, 2, xtab, ytab);
                            }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab+2][xtab+2]=' '; ///Affichage des espaces
                            tab[ytab+1][xtab]=' ';
                            tab[ytab+1][xtab+1]=' ';
                            tab[ytab][xtab+2]=' ';
                            tab[ytab+1][xtab+2]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///T(pivot 18O deg)
                        if (tab[ytab+2][xtab+2]==tab[ytab+2][xtab]&&tab[ytab+2][xtab+2]==tab[ytab+2][xtab+1]&&tab[ytab+2][xtab+2]==tab[ytab][xtab+1]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+1]&&tab[ytab+2][xtab+2]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab+2][xtab+2]=='S') ///Incrémentation plantamitz
                                {
                                Soleil=Soleil+5;
                                BFS(2, 2, xtab, ytab);
                                BFS(2, 0, xtab, ytab);
                                BFS(2, 1, xtab, ytab);
                                BFS(0, 1, xtab, ytab);
                                BFS(1, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='F')
                                {
                                    Fraise=Fraise+5;
                                    BFF(2, 2, xtab, ytab);
                                BFF(2, 0, xtab, ytab);
                                BFF(2, 1, xtab, ytab);
                                BFF(0, 1, xtab, ytab);
                                BFF(1, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='P')
                                {
                                 Pomme=Pomme+5;
                                BFP(2, 2, xtab, ytab);
                                BFP(2, 0, xtab, ytab);
                                BFP(2, 1, xtab, ytab);
                                BFP(0, 1, xtab, ytab);
                                BFP(1, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='O')
                            {
                                Oignon=Oignon+5;
                                BFO(2, 2, xtab, ytab);
                                BFO(2, 0, xtab, ytab);
                                BFO(2, 1, xtab, ytab);
                                BFO(0, 1, xtab, ytab);
                                BFO(1, 1, xtab, ytab);
                            }
                            if(tab[ytab+2][xtab+2]=='M')
                            {
                                Mandarine=Mandarine+5;
                                BFM(2, 2, xtab, ytab);
                                BFM(2, 0, xtab, ytab);
                                BFM(2, 1, xtab, ytab);
                                BFM(0, 1, xtab, ytab);
                                BFM(1, 1, xtab, ytab);
                            }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab+2][xtab+2]=' '; ///Affichage des espaces
                            tab[ytab+2][xtab]=' ';
                            tab[ytab+2][xtab+1]=' ';
                            tab[ytab][xtab+1]=' ';
                            tab[ytab+1][xtab+1]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///T(pivot 270 deg)
                        if (tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]==tab[ytab+1][xtab+1]&&tab[ytab][xtab]==tab[ytab+1][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                                {
                                  Soleil=Soleil+5;
                                  BFS(0, 0, xtab, ytab);
                                BFS(1, 0, xtab, ytab);
                                BFS(2, 0, xtab, ytab);
                                BFS(1, 1, xtab, ytab);
                                BFS(1, 2, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='F')
                            {
                                Fraise=Fraise+5;
                                BFF(0, 0, xtab, ytab);
                                BFF(1, 0, xtab, ytab);
                                BFF(2, 0, xtab, ytab);
                                BFF(1, 1, xtab, ytab);
                                BFF(1, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='P')
                            {
                                Pomme=Pomme+5;
                                BFP(0, 0, xtab, ytab);
                                BFP(1, 0, xtab, ytab);
                                BFP(2, 0, xtab, ytab);
                                BFP(1, 1, xtab, ytab);
                                BFP(1, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='O')
                            {
                                Oignon=Oignon+5;
                                BFO(0, 0, xtab, ytab);
                                BFO(1, 0, xtab, ytab);
                                BFO(2, 0, xtab, ytab);
                                BFO(1, 1, xtab, ytab);
                                BFO(1, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='M')
                            {
                                Mandarine=Mandarine+5;
                                BFM(0, 0, xtab, ytab);
                                BFM(1, 0, xtab, ytab);
                                BFM(2, 0, xtab, ytab);
                                BFM(1, 1, xtab, ytab);
                                BFM(1, 2, xtab, ytab);
                            }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab+1][xtab]=' ';
                            tab[ytab+2][xtab]=' ';
                            tab[ytab+1][xtab+1]=' ';
                            tab[ytab+1][xtab+2]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///L(pivot 0 deg)
                        if (tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab+1]&&tab[ytab][xtab]==tab[ytab+2][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                            {
                                Soleil=Soleil+5;
                                BFS(0, 0, xtab, ytab);
                                BFS(1, 0, xtab, ytab);
                                BFS(2, 0, xtab, ytab);
                                BFS(2, 1, xtab, ytab);
                                BFS(2, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='F')
                                {
                                   Fraise=Fraise+5;
                                   BFF(0, 0, xtab, ytab);
                                BFF(1, 0, xtab, ytab);
                                BFF(2, 0, xtab, ytab);
                                BFF(2, 1, xtab, ytab);
                                BFF(2, 2, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='P')
                                {
                                  Pomme=Pomme+5;
                                  BFP(0, 0, xtab, ytab);
                                BFP(1, 0, xtab, ytab);
                                BFP(2, 0, xtab, ytab);
                                BFP(2, 1, xtab, ytab);
                                BFP(2, 2, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='O')
                            {
                                Oignon=Oignon+5;
                                BFO(0, 0, xtab, ytab);
                                BFO(1, 0, xtab, ytab);
                                BFO(2, 0, xtab, ytab);
                                BFO(2, 1, xtab, ytab);
                                BFO(2, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='M')
                            {
                                Mandarine=Mandarine+5;
                                BFM(0, 0, xtab, ytab);
                                BFM(1, 0, xtab, ytab);
                                BFM(2, 0, xtab, ytab);
                                BFM(2, 1, xtab, ytab);
                                BFM(2, 2, xtab, ytab);
                            }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab+1][xtab]=' ';
                            tab[ytab+2][xtab]=' ';
                            tab[ytab+2][xtab+1]=' ';
                            tab[ytab+2][xtab+2]=' ';
                            _sleep(500);
                            Combinaison=1; ///Incrémentation
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///L(pivot 90 deg)
                        if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                            {
                                Soleil=Soleil+5;
                                BFS(0, 0, xtab, ytab);
                                BFS(0, 1, xtab, ytab);
                                BFS(0, 2, xtab, ytab);
                                BFS(1, 0, xtab, ytab);
                                BFS(2, 0, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='F')
                                {
                                  Fraise=Fraise+5;
                                  BFF(0, 0, xtab, ytab);
                                BFF(0, 1, xtab, ytab);
                                BFF(0, 2, xtab, ytab);
                                BFF(1, 0, xtab, ytab);
                                BFF(2, 0, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='P')
                            {
                                Pomme=Pomme+5;
                                BFP(0, 0, xtab, ytab);
                                BFP(0, 1, xtab, ytab);
                                BFP(0, 2, xtab, ytab);
                                BFP(1, 0, xtab, ytab);
                                BFP(2, 0, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='O')
                                {
                                 Oignon=Oignon+5;
                                 BFO(0, 0, xtab, ytab);
                                BFO(0, 1, xtab, ytab);
                                BFO(0, 2, xtab, ytab);
                                BFO(1, 0, xtab, ytab);
                                BFO(2, 0, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='M')
                                {
                                  Mandarine=Mandarine+5;
                                  BFM(0, 0, xtab, ytab);
                                BFM(0, 1, xtab, ytab);
                                BFM(0, 2, xtab, ytab);
                                BFM(1, 0, xtab, ytab);
                                BFM(2, 0, xtab, ytab);
                                }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab][xtab+1]=' ';
                            tab[ytab][xtab+2]=' ';
                            tab[ytab+1][xtab]=' ';
                            tab[ytab+2][xtab]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///L(pivot 180 deg)
                        if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]==tab[ytab+1][xtab+2]&&tab[ytab][xtab]==tab[ytab+2][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                            {
                                Soleil=Soleil+5;
                                BFS(0, 0, xtab, ytab);
                                BFS(0, 1, xtab, ytab);
                                BFS(0, 2, xtab, ytab);
                                BFS(1, 2, xtab, ytab);
                                BFS(2, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='F')
                            {
                               Fraise=Fraise+5;
                               BFF(0, 0, xtab, ytab);
                                BFF(0, 1, xtab, ytab);
                                BFF(0, 2, xtab, ytab);
                                BFF(1, 2, xtab, ytab);
                                BFF(2, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='P')
                            {
                                Pomme=Pomme+5;
                                BFP(0, 0, xtab, ytab);
                                BFP(0, 1, xtab, ytab);
                                BFP(0, 2, xtab, ytab);
                                BFP(1, 2, xtab, ytab);
                                BFP(2, 2, xtab, ytab);
                            }

                            if(tab[ytab][xtab]=='O')
                                {
                                    Oignon=Oignon+5;
                                    BFO(0, 0, xtab, ytab);
                                BFO(0, 1, xtab, ytab);
                                BFO(0, 2, xtab, ytab);
                                BFO(1, 2, xtab, ytab);
                                BFO(2, 2, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='M')
                                {
                                   Mandarine=Mandarine+5;
                                   BFM(0, 0, xtab, ytab);
                                BFM(0, 1, xtab, ytab);
                                BFM(0, 2, xtab, ytab);
                                BFM(1, 2, xtab, ytab);
                                BFM(2, 2, xtab, ytab);
                                }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab][xtab+1]=' ';
                            tab[ytab][xtab+2]=' ';
                            tab[ytab+1][xtab+2]=' ';
                            tab[ytab+2][xtab+2]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///L(pivot 270 deg)
                        if (tab[ytab+2][xtab+2]==tab[ytab][xtab+2]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+2]&&tab[ytab+2][xtab+2]==tab[ytab+2][xtab]&&tab[ytab+2][xtab+2]==tab[ytab+2][xtab+1]&&tab[ytab+2][xtab+2]!=' '&&xtab<13&&ytab<8)
                        {
                            if(tab[ytab+2][xtab+2]=='S') ///Incrémentation plantamitz
                                {
                                     Soleil=Soleil+5;
                                BFS(2, 2, xtab, ytab);
                                BFS(0, 2, xtab, ytab);
                                BFS(1, 2, xtab, ytab);
                                BFS(2, 0, xtab, ytab);
                                BFS(2, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='F')
                                {
                                 Fraise=Fraise+5;
                                 BFF(2, 2, xtab, ytab);
                                BFF(0, 2, xtab, ytab);
                                BFF(1, 2, xtab, ytab);
                                BFF(2, 0, xtab, ytab);
                                BFF(2, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='P')
                                {
                                    Pomme=Pomme+5;
                                    BFP(2, 2, xtab, ytab);
                                BFP(0, 2, xtab, ytab);
                                BFP(1, 2, xtab, ytab);
                                BFP(2, 0, xtab, ytab);
                                BFP(2, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='O')
                                {
                                  Oignon=Oignon+5;
                                  BFO(2, 2, xtab, ytab);
                                BFO(0, 2, xtab, ytab);
                                BFO(1, 2, xtab, ytab);
                                BFO(2, 0, xtab, ytab);
                                BFO(2, 1, xtab, ytab);
                                }
                            if(tab[ytab+2][xtab+2]=='M')
                                {
                                  Mandarine=Mandarine+5;
                                  BFM(2, 2, xtab, ytab);
                                BFM(0, 2, xtab, ytab);
                                BFM(1, 2, xtab, ytab);
                                BFM(2, 0, xtab, ytab);
                                BFM(2, 1, xtab, ytab);
                                }
                            Score=Score+12; ///Incrémentation score

                            tab[ytab+2][xtab+2]=' '; ///Affichage des espaces
                            tab[ytab][xtab+2]=' ';
                            tab[ytab+1][xtab+2]=' ';
                            tab[ytab+2][xtab]=' ';
                            tab[ytab+2][xtab+1]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///colonne de 3
                        if (tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]!=' '&&ytab<8)
                        {
                            ///colonne de 4
                            if (tab[ytab][xtab]==tab[ytab+3][xtab]&&tab[ytab][xtab]!=' '&&ytab<7)
                            {
                                ///colonne de 5
                                if (tab[ytab][xtab]==tab[ytab+4][xtab]&&tab[ytab][xtab]!=' '&&ytab<6)
                                {
                                    Score=Score+1; ///Incrémentation score
                                    tmpcol5=tab[ytab][xtab];
                                    for (xtab5=0; xtab5<15; xtab5++) ///Parcourt de la matrice
                                    {
                                        for (ytab5=0; ytab5<10; ytab5++)
                                        {

                                            if(tab[ytab5][xtab5]==tmpcol5)
                                            {
                                                if(tab[ytab5][xtab5]=='S') ///Incrémentation plantamitz
                                                {
                                                    Soleil=Soleil+1;
                                                    BFS(0, 0, xtab5, ytab5);
                                                }
                                                if(tab[ytab5][xtab5]=='F')
                                                    {
                                                        Fraise=Fraise+1;
                                                        BFF(0, 0, xtab5, ytab5);
                                                    }
                                                if(tab[ytab5][xtab5]=='P')
                                                    {
                                                     Pomme=Pomme+1;
                                                     BFP(0, 0, xtab5, ytab5);
                                                    }
                                                if(tab[ytab5][xtab5]=='O')
                                                    {
                                                       Oignon=Oignon+1;
                                                       BFO(0, 0, xtab5, ytab5);
                                                    }
                                                if(tab[ytab5][xtab5]=='M')
                                                    {
                                                        Mandarine=Mandarine+1;
                                                        BFM(0, 0, xtab5, ytab5);
                                                    }
                                                tab[ytab5][xtab5]=' '; ///Affichage des espaces
                                                Score=Score+1;

                                            }
                                        }
                                    }
                                    Gravite(tab); ///Combinaison
                                    CombinaisonGravite(tab, 1);
                                }
                                if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                                {
                                    Soleil=Soleil+1;
                                    BFS(3, 0, xtab, ytab);
                                }
                                if(tab[ytab][xtab]=='F')
                                    {
                                      Fraise=Fraise+1;
                                      BFF(3, 0, xtab, ytab);
                                    }
                                if(tab[ytab][xtab]=='P')
                                    {
                                       Pomme=Pomme+1;
                                       BFP(3, 0, xtab, ytab);
                                    }
                                if(tab[ytab][xtab]=='O')
                                    {
                                        Oignon=Oignon+1;
                                        BFO(3, 0, xtab, ytab);
                                    }
                                if(tab[ytab][xtab]=='M')
                                    {
                                       Mandarine=Mandarine+1;
                                       BFM(3, 0, xtab, ytab);
                                    }
                                Score=Score+1; ///Incrémentation score

                                tab[ytab+3][xtab]=' '; ///Affichage des espaces
                            }
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                                {
                                     Soleil=Soleil+3;
                                     BFS(0, 0, xtab, ytab);
                                     BFS(1, 0, xtab, ytab);
                                     BFS(2, 0, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='F')
                                {
                                    Fraise=Fraise+3;
                                    BFF(0, 0, xtab, ytab);
                                    BFF(1, 0, xtab, ytab);
                                    BFF(2, 0, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='P')
                                {
                                    Pomme=Pomme+3;
                                    BFP(0, 0, xtab, ytab);
                                     BFP(1, 0, xtab, ytab);
                                     BFP(2, 0, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='O')
                                {
                                 Oignon=Oignon+3;
                                 BFO(0, 0, xtab, ytab);
                                     BFO(1, 0, xtab, ytab);
                                     BFO(2, 0, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='M')
                                {
                                  Mandarine=Mandarine+3;
                                  BFM(0, 0, xtab, ytab);
                                     BFM(1, 0, xtab, ytab);
                                     BFM(2, 0, xtab, ytab);
                                }
                            Score=Score+3; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab+1][xtab]=' ';
                            tab[ytab+2][xtab]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }

                        ///ligne de 3
                        if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13)
                        {
                            ///lige de 4
                            if (tab[ytab][xtab]==tab[ytab][xtab+3]&&tab[ytab][xtab]!=' '&&xtab<12)
                            {
                                ///ligne de 5
                                if (tab[ytab][xtab]==tab[ytab][xtab+4]&&tab[ytab][xtab]!=' '&&xtab<11)
                                {
                                    Score=Score+1; ///Incrémentation score
                                    tmplig5=tab[ytab][xtab];
                                    for (xtab5=0; xtab5<15; xtab5++) ///Parcourt de la matrice
                                    {
                                        for (ytab5=0; ytab5<10; ytab5++)
                                        {

                                            if(tab[ytab5][xtab5]==tmplig5)
                                            {
                                                if(tab[ytab5][xtab5]=='S') ///Incrémentation plantamitz
                                                {
                                                    Soleil=Soleil+1;
                                                    BFS(0, 0, xtab5, ytab5);
                                                }
                                                if(tab[ytab5][xtab5]=='F')
                                                    {
                                                      Fraise=Fraise+1;
                                                      BFF(0, 0, xtab5, ytab5);
                                                    }
                                                if(tab[ytab5][xtab5]=='P')
                                                    {
                                                       Pomme=Pomme+1;
                                                       BFP(0, 0, xtab5, ytab5);
                                                    }
                                                if(tab[ytab5][xtab5]=='O')
                                                    {
                                                        Oignon=Oignon+1;
                                                        BFO(0, 0, xtab5, ytab5);
                                                    }
                                                if(tab[ytab5][xtab5]=='M')
                                                {
                                                    Mandarine=Mandarine+1;
                                                    BFM(0, 0, xtab5, ytab5);
                                                }
                                                tab[ytab5][xtab5]=' '; ///Affichage des espaces
                                                Score=Score+1;
                                            }
                                        }
                                    }
                                    Gravite(tab); ///Combinaison
                                    CombinaisonGravite(tab, 1);

                                }
                                if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                                {
                                    Soleil=Soleil+1;
                                    BFS(0, 3, xtab, ytab);
                                }
                                if(tab[ytab][xtab]=='F')
                                    {
                                       Fraise=Fraise+1;
                                       BFF(0, 3, xtab, ytab);
                                    }
                                if(tab[ytab][xtab]=='P')
                                    {
                                       Pomme=Pomme+1;
                                       BFP(0, 3, xtab, ytab);
                                    }
                                if(tab[ytab][xtab]=='O')
                                {
                                    Oignon=Oignon+1;
                                    BFO(0, 3, xtab, ytab);
                                }
                                if(tab[ytab][xtab]=='M')
                                {
                                    Mandarine=Mandarine+1;
                                    BFM(0, 3, xtab, ytab);
                                }

                                Score=Score+1; ///Incrémentation score

                                tab[ytab][xtab+3]=' '; ///Affichage des espaces
                            }
                            if(tab[ytab][xtab]=='S') ///Incrémentation plantamitz
                            {
                                Soleil=Soleil+3;
                                BFS(0, 0, xtab, ytab);
                                BFS(0, 1, xtab, ytab);
                                BFS(0, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='F')
                                {
                                   Fraise=Fraise+3;
                                   BFF(0, 0, xtab, ytab);
                                BFF(0, 1, xtab, ytab);
                                BFF(0, 2, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='P')
                                {
                                  Pomme=Pomme+3;
                                   BFP(0, 0, xtab, ytab);
                                BFP(0, 1, xtab, ytab);
                                BFP(0, 2, xtab, ytab);
                                }
                            if(tab[ytab][xtab]=='O')
                            {
                                Oignon=Oignon+3;
                                BFO(0, 0, xtab, ytab);
                                BFO(0, 1, xtab, ytab);
                                BFO(0, 2, xtab, ytab);
                            }
                            if(tab[ytab][xtab]=='M')
                                {
                                  Mandarine=Mandarine+3;
                                  BFM(0, 0, xtab, ytab);
                                BFM(0, 1, xtab, ytab);
                                BFM(0, 2, xtab, ytab);
                                }
                            Score=Score+3; ///Incrémentation score

                            tab[ytab][xtab]=' '; ///Affichage des espaces
                            tab[ytab][xtab+1]=' ';
                            tab[ytab][xtab+2]=' ';
                            _sleep(500);
                            Combinaison=1; ///Combinaison
                            Gravite(tab); ///Application de la gravité simulée
                        }
                    }
                }
            }
            while(Combinaison==1); ///Boucle tant qu'il y a des combinaisons


            blit(BFondHaut,screen,0,0,490,540, BFondHaut->w, BFondHaut->h);
            blit(BFondHaut,screen,0,0,788,540, BFondHaut->w, BFondHaut->h);
            blit(BFondMilieu,screen,0,0,490,622, BFondMilieu->w, BFondMilieu->h);
            blit(BFondMilieu,screen,0,0,788,622, BFondMilieu->w, BFondMilieu->h);
            blit(BFondBas,screen,0,0,490,706, BFondBas->w, BFondBas->h);
            blit(BFondBas,screen,0,0,878,706, BFondBas->w, BFondBas->h);
            blit(BFondBas,screen,0,0,300,706, BFondBas->w, BFondBas->h);



///Vies
Coeur(Vies, coups, 264, 622);

///Nombres coups

Unite(coups, 330, 706);
Dizaine(coups, 300, 706);

///Score Pomme

Unite(Pomme, 550, 540);
Dizaine(Pomme, 520, 540);
Centaine(Pomme, 490, 540);

///Score Fraise

Unite(Fraise, 550, 622);
Dizaine(Fraise, 520, 622);
Centaine(Fraise, 490, 622);

///Score Oignon

Unite(Oignon, 550, 706);
Dizaine(Oignon, 520, 706);
Centaine(Oignon, 490, 706);

///Score Mandarine

Unite(Mandarine, 848, 540);
Dizaine(Mandarine, 818, 540);
Centaine(Mandarine, 788, 540);

 ///Soleil score

 Unite(Soleil, 848, 622);
 Dizaine(Soleil, 818, 622);
 Centaine(Soleil, 788, 622);

         ///Score total
Unite(Score, 938, 706);
Dizaine(Score, 908, 706);
Centaine(Score, 878, 706);


            if(Niveau==1) ///Si niveau 1
            {
                if(Fraise>9&&Oignon>19&&Mandarine>9) ///Si contrat niveau 1 effectué
                    gagne=1; ///Niveau 1 gagné
            }
            if(Niveau==2) ///Si niveau 2
            {
                if(Soleil>24&&Pomme>14&&Fraise>9&&Oignon>14) ///Si contrat niveau 2 effetué
                    gagne=1; ///Niveau 2 gagné
            }
            if(Niveau==3) ///Si niveau 3
            {
                if(Soleil>24&&Pomme>24&&Fraise>24&&Oignon>24&&Mandarine>24) ///Si contrat niveau 3 effectué
                    gagne=1; ///Niveau 3 gagné

            }


        }
        while(coups>0&&gagne==0&&Abandon==0); ///Boucle tant qu'il y a des coups disponibles et que le contrat n'est pas rempli
        if ((Score!=0)||(Abandon==0)) ///Si le joueur n'a pas quitté la partie
        {
            if(gagne==1) ///Si le contrat est rempli
                continuer=0; ///Quitter le niveau
            else if(coups==0) ///Si le contrat n'est pas rempli et qu'il n'y a plus de coups disponibles
            {

                Vies=Vies-1; ///Décrémentation vies restantes
                rectfill(screen,238,622,268,674, makecol(32,96,128));
                Unite(Vies, 240, 622);
                if (Vies==0); ///S'il n'y a plus de vies disponibles
                {
                    continuer=0; ///Quitter le niveau
                }
                if(Vies>0) ///S'il y a des vies disponibles
                {
                    _sleep(2500);
                    blit(BVies,screen,0,0,0,0, BVies->w, BVies->h);
                    Unite(Vies, 700, 25);
                    do
                    {

                        if ((mouse_b&1)&&mouse_y>500) ///Si touche zero
                        {
                            continuer=0; ///Quitter le niveau
                            gagne=0;
                            Souris=1;
                        }
                        if ((mouse_b&1)&&mouse_y<500) ///Sinon
                        {
                            continuer=1; ///Recommencer le niveau
                            Souris=1;
                        }
                    }
                    while(Souris==0);
                }

            }
        }

    }
    while(continuer==1); ///Boucle tant qu'il y a des vies disponibles

    if (gagne==1) ///Si le contrat est rempli
    {
        {
            if(Niveau==3) ///Si niveau 3
            {
                NiveauSuivant=1; ///Fin du niveau
            }
            else ///Si niveau 1 ou 2
            {
                blit(BGagne,screen,0,0,0,0, BGagne->w, BGagne->h);
                do     ///Touche appuyée
                {
                    if ((mouse_b&1)&&mouse_x>800) ///Sauvegarde
                    {
                            if(Niveau==1) ///Sauvegarde score niveau 1
                            {
                                FILE*file;
                                file=fopen("Sauvegarde_Score1.txt","w");
                                fprintf(file,"%d",Score);
                                fclose(file);
                            }
                            if(Niveau==2) ///Sauvegarde score niveau 2
                            {
                                FILE*file;
                                file=fopen("Sauvegarde_Score2.txt","w");
                                fprintf(file,"%d",Score);
                                fclose(file);
                            }
                            FILE*file; ///Sauvegarde niveau
                            file=fopen("Sauvegarde_niveau.txt","w");
                            fprintf(file,"%d",Niveau+1);
                            fclose(file);
                            Souris=0;
                        }
                    if ((mouse_b&1)&&mouse_x<800&&mouse_y>500) ///Si touche zero
                    {
                        Souris=1;
                        NiveauSuivant=0; ///Abandon et fin du jeu
                    }
                    if ((mouse_b&1)&&mouse_x<800&&mouse_y>200&&mouse_y<500)///Sinon
                        {
                            Souris=1;
                            NiveauSuivant=1; ///Fin du niveau et niveau suivant
                        }

                }
                while(Souris==0);
            }
        }
    }
    if (gagne==0&&Vies==0) ///Si le contrat n'est pas rempli et qu'il n'y a plus de vies disponibles
    {
        _sleep(2500);
        blit(BPerdu,screen,0,0,0,0, BPerdu->w, BPerdu->h);
        NiveauSuivant=0; ///Perdu et fin du jeu
        _sleep(5000);
    }
    if((gagne==0&&Vies>0)&&(Abandon==1)) ///Si le contrat n'est pas rempli et qu'il y a des vies disponibles
    {
        NiveauSuivant=0; ///Abandon et fin du jeu

    }
    Score=Score*NiveauSuivant;
    return Score; ///Retour score si niveau gagné ou 0 si niveau perdu, abandonné
}
