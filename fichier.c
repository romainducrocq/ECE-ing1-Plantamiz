#include "fichier.h"
char fruits() /// Génération de caractères aléatoires parmi les lettres {P,F,M,O,S}
{
    char caseTab; ///Ressources
    int alea;
    alea=rand()%5; ///variable prend une valeur entre 0 et 4
    switch (alea) ///caractère assigné en fonction de la valeur de la variable
    {
    case 0:
        caseTab='P';
        break;
    case 1:
        caseTab='F';
        break;
    case 2:
        caseTab='M';
        break;
    case 3:
        caseTab='O';
        break;
    case 4:
        caseTab='S';
        break;
    }
    return caseTab; ///Retour du caractère aléatoire
}
void afficherdepart(char tab[10][15])
{
    int k, l;
                       for(k=0; k<15; k++) ///Parcourt de la matrice
                    {
                        for(l=0; l<10; l++)
                    {
                        tab[l][k]=fruits(); ///Chaque case est remplie avec un caractère généré aleatoirement dans la fonction fruit()
                    }
                    }

        CombinaisonGravite(tab, 0); ///Controle des combinaisons et de la gravité avant le début du jeu
        afficher(tab);
            }
void afficher(char tab[10][15]) ///Affichage de la matrice aléatoire
{
    BITMAP *Soleil, *Orange, *Pomme, *Oignon, *Fraise, *BX;
    Soleil=load_bitmap("Soleil.bmp",NULL);
    Orange=load_bitmap("Orange.bmp",NULL);
    Pomme=load_bitmap("Pomme.bmp",NULL);
    Oignon=load_bitmap("Oignon.bmp",NULL);
    Fraise=load_bitmap("Fraise.bmp",NULL);
    BX=load_bitmap("Bonus1.bmp",NULL);
    int k,l; ///Ressources
    for(k=0; k<15; k++) ///Parcourt de la matrice
    {
        for(l=0; l<10; l++)
        {

            switch(tab[l][k]) ///Affichage
            {
            case 'P':
                masked_blit(Pomme,screen,0,0,(k*68),(l*52), Pomme->w, Pomme->h);
                break;
            case 'F':
                masked_blit(Fraise,screen,0,0,(k*68),(l*52), Fraise->w, Fraise->h);
                break;
            case 'M':
                masked_blit(Orange,screen,0,0,(k*68),(l*52), Orange->w, Orange->h);
                break;
            case 'O':
                masked_blit(Oignon,screen,0,0,(k*68),(l*52), Oignon->w, Oignon->h);
                break;
            case 'S':
                masked_blit(Soleil,screen,0,0,(k*68),(l*52), Soleil->w, Soleil->h);
                break;
                case 'X':
                masked_blit(BX,screen,0,0,(k*68),(l*52), BX->w, BX->h);
                break;
            }
        }
    }
}

void Unite(int planta, int Wide, int Height)
{
    BITMAP *B0, *B1, *B2, *B3, *B4, *B5, *B6, *B7, *B8, *B9;
    B0=load_bitmap("Zero.bmp",NULL);
    B1=load_bitmap("Un.bmp",NULL);
    B2=load_bitmap("Deux.bmp",NULL);
    B3=load_bitmap("Trois.bmp",NULL);
    B4=load_bitmap("Quatre.bmp",NULL);
    B5=load_bitmap("Cinq.bmp",NULL);
    B6=load_bitmap("Six.bmp",NULL);
    B7=load_bitmap("Sept.bmp",NULL);
    B8=load_bitmap("Huit.bmp",NULL);
    B9=load_bitmap("Neuf.bmp",NULL);

            if(((planta%10)/1)==0)
                masked_blit(B0,screen,0,0,Wide,Height, B0->w, B0->h);
            if(((planta%10)/1)==1)
                masked_blit(B1,screen,0,0,Wide,Height, B1->w, B1->h);
            if(((planta%10)/1)==2)
                masked_blit(B2,screen,0,0,Wide,Height, B2->w, B2->h);
            if(((planta%10)/1)==3)
                masked_blit(B3,screen,0,0,Wide,Height, B3->w, B3->h);
            if(((planta%10)/1)==4)
                masked_blit(B4,screen,0,0,Wide,Height, B4->w, B4->h);
            if(((planta%10)/1)==5)
                masked_blit(B5,screen,0,0,Wide,Height, B5->w, B5->h);
            if(((planta%10)/1)==6)
                masked_blit(B6,screen,0,0,Wide,Height, B6->w, B6->h);
            if(((planta%10)/1)==7)
                masked_blit(B7,screen,0,0,Wide,Height, B7->w, B7->h);
            if(((planta%10)/1)==8)
                masked_blit(B8,screen,0,0,Wide,Height, B8->w, B8->h);
            if(((planta%10)/1)==9)
                masked_blit(B9,screen,0,0,Wide,Height, B9->w, B9->h);

}
void Dizaine(int planta, int Wide, int Height)
{
    BITMAP *B0, *B1, *B2, *B3, *B4, *B5, *B6, *B7, *B8, *B9;
    B0=load_bitmap("Zero.bmp",NULL);
    B1=load_bitmap("Un.bmp",NULL);
    B2=load_bitmap("Deux.bmp",NULL);
    B3=load_bitmap("Trois.bmp",NULL);
    B4=load_bitmap("Quatre.bmp",NULL);
    B5=load_bitmap("Cinq.bmp",NULL);
    B6=load_bitmap("Six.bmp",NULL);
    B7=load_bitmap("Sept.bmp",NULL);
    B8=load_bitmap("Huit.bmp",NULL);
    B9=load_bitmap("Neuf.bmp",NULL);

            if(((planta%100)/10)==0)
                masked_blit(B0,screen,0,0,Wide,Height, B0->w, B0->h);
            if(((planta%100)/10)==1)
                masked_blit(B1,screen,0,0,Wide,Height, B1->w, B1->h);
            if(((planta%100)/10)==2)
                masked_blit(B2,screen,0,0,Wide,Height, B2->w, B2->h);
            if(((planta%100)/10)==3)
                masked_blit(B3,screen,0,0,Wide,Height, B3->w, B3->h);
            if(((planta%100)/10)==4)
                masked_blit(B4,screen,0,0,Wide,Height, B4->w, B4->h);
            if(((planta%100)/10)==5)
                masked_blit(B5,screen,0,0,Wide,Height, B5->w, B5->h);
            if(((planta%100)/10)==6)
                masked_blit(B6,screen,0,0,Wide,Height, B6->w, B6->h);
            if(((planta%100)/10)==7)
                masked_blit(B7,screen,0,0,Wide,Height, B7->w, B7->h);
            if(((planta%100)/10)==8)
                masked_blit(B8,screen,0,0,Wide,Height, B8->w, B8->h);
            if(((planta%100)/10)==9)
                masked_blit(B9,screen,0,0,Wide,Height, B9->w, B9->h);
}
void Centaine(int planta, int Wide, int Height)
{
    BITMAP *B0, *B1, *B2, *B3, *B4, *B5, *B6, *B7, *B8, *B9;
    B0=load_bitmap("Zero.bmp",NULL);
    B1=load_bitmap("Un.bmp",NULL);
    B2=load_bitmap("Deux.bmp",NULL);
    B3=load_bitmap("Trois.bmp",NULL);
    B4=load_bitmap("Quatre.bmp",NULL);
    B5=load_bitmap("Cinq.bmp",NULL);
    B6=load_bitmap("Six.bmp",NULL);
    B7=load_bitmap("Sept.bmp",NULL);
    B8=load_bitmap("Huit.bmp",NULL);
    B9=load_bitmap("Neuf.bmp",NULL);

            if((planta/100)==0)
                masked_blit(B0,screen,0,0,Wide,Height, B0->w, B0->h);
            if((planta/100)==1)
                masked_blit(B1,screen,0,0,Wide,Height, B1->w, B1->h);
            if((planta/100)==2)
                masked_blit(B2,screen,0,0,Wide,Height, B2->w, B2->h);
            if((planta/100)==3)
                masked_blit(B3,screen,0,0,Wide,Height, B3->w, B3->h);
            if((planta/100)==4)
                masked_blit(B4,screen,0,0,Wide,Height, B4->w, B4->h);
            if((planta/100)==5)
                masked_blit(B5,screen,0,0,Wide,Height, B5->w, B5->h);
            if((planta/100)==6)
                masked_blit(B6,screen,0,0,Wide,Height, B6->w, B6->h);
            if((planta/100)==7)
                masked_blit(B7,screen,0,0,Wide,Height, B7->w, B7->h);
            if((planta/100)==8)
                masked_blit(B8,screen,0,0,Wide,Height, B8->w, B8->h);
            if((planta/100)==9)
                masked_blit(B9,screen,0,0,Wide,Height, B9->w, B9->h);
}
void BFS(int j, int i, int xtab, int ytab)
{
    BITMAP *FS;
    FS=load_bitmap("FondJaune.bmp",NULL);
    blit(FS,screen,0,0,((xtab+i)*68),((ytab+j)*52), FS->w, FS->h);
}
void BFF(int j, int i, int xtab, int ytab)
{
    BITMAP *FF;
    FF=load_bitmap("FondRouge.bmp",NULL);
    blit(FF,screen,0,0,((xtab+i)*68),((ytab+j)*52), FF->w, FF->h);
}
void BFP(int j, int i, int xtab, int ytab)
{
    BITMAP *FP;
    FP=load_bitmap("FondVert.bmp",NULL);
    blit(FP,screen,0,0,((xtab+i)*68),((ytab+j)*52), FP->w, FP->h);
}
void BFM(int j, int i, int xtab, int ytab)
{
    BITMAP *FM;
    FM=load_bitmap("FondOrange.bmp",NULL);
    blit(FM,screen,0,0,((xtab+i)*68),((ytab+j)*52), FM->w, FM->h);
}
void BFO(int j, int i, int xtab, int ytab)
{
    BITMAP *FO;
    FO=load_bitmap("FondGris.bmp",NULL);
    blit(FO,screen,0,0,((xtab+i)*68),((ytab+j)*52), FO->w, FO->h);
}
void Coeur(int Vies, int coups, int w, int h)
{
    BITMAP *B5, *B475, *B45, *B425, *B4, *B375, *B35, *B325, *B3, *B275, *B25, *B225, *B2, *B175, *B15, *B125, *B1, *B075, *B05, *B025, *B0;
    B5=load_bitmap("5.bmp",NULL);
    B475=load_bitmap("4_3.4.bmp",NULL);
    B45=load_bitmap("4_1.2.bmp",NULL);
    B425=load_bitmap("4_1.4.bmp",NULL);
    B4=load_bitmap("4.bmp",NULL);
    B375=load_bitmap("3_3.4.bmp",NULL);
    B35=load_bitmap("3_1.2.bmp",NULL);
    B325=load_bitmap("3_1.4.bmp",NULL);
    B3=load_bitmap("3.bmp",NULL);
    B275=load_bitmap("2_3.4.bmp",NULL);
    B25=load_bitmap("2_1.2.bmp",NULL);
    B225=load_bitmap("2_1.4.bmp",NULL);
    B2=load_bitmap("2.bmp",NULL);
    B175=load_bitmap("1_3.4.bmp",NULL);
    B15=load_bitmap("1_1.2.bmp",NULL);
    B125=load_bitmap("1_1.4.bmp",NULL);
    B1=load_bitmap("1.bmp",NULL);
    B075=load_bitmap("0_3.4.bmp",NULL);
    B05=load_bitmap("0_1.2.bmp",NULL);
    B025=load_bitmap("0_1.4.bmp",NULL);
    B0=load_bitmap("0.bmp",NULL);

    if(Vies==5&&coups>15)
        masked_blit(B5,screen,0,0,w,h, B5->w, B5->h);
    else if(Vies==5&&coups>10)
        masked_blit(B475,screen,0,0,w,h, B475->w, B475->h);
    else if(Vies==5&&coups>5)
        masked_blit(B45,screen,0,0,w,h, B45->w, B45->h);
        else if(Vies==5&&coups>0)
        masked_blit(B425,screen,0,0,w,h, B425->w, B425->h);
        else if((Vies==4&&coups>15)||(Vies==5&&coups==0))
        masked_blit(B4,screen,0,0,w,h, B4->w, B4->h);
        else if(Vies==4&&coups>10)
        masked_blit(B375,screen,0,0,w,h, B375->w, B375->h);
        else if(Vies==4&&coups>5)
        masked_blit(B35,screen,0,0,w,h, B35->w, B35->h);
        else if(Vies==4&&coups>0)
        masked_blit(B325,screen,0,0,w,h, B325->w, B325->h);
        else if((Vies==3&&coups>15)||(Vies==4&&coups==0))
        masked_blit(B3,screen,0,0,w,h, B3->w, B3->h);
        else if(Vies==3&&coups>10)
        masked_blit(B275,screen,0,0,w,h, B275->w, B275->h);
        else if(Vies==3&&coups>5)
        masked_blit(B25,screen,0,0,w,h, B25->w, B25->h);
        else if(Vies==3&&coups>0)
        masked_blit(B225,screen,0,0,w,h, B225->w, B225->h);
        else if((Vies==2&&coups>15)||(Vies==3&&coups==0))
        masked_blit(B2,screen,0,0,w,h, B2->w, B2->h);
        else if(Vies==2&&coups>10)
        masked_blit(B175,screen,0,0,w,h, B175->w, B175->h);
        else if(Vies==2&&coups>5)
        masked_blit(B15,screen,0,0,w,h, B15->w, B15->h);
        else if(Vies==2&&coups>0)
        masked_blit(B125,screen,0,0,w,h, B125->w, B125->h);
        else if((Vies==1&&coups>15)||(Vies==2&&coups==0))
        masked_blit(B1,screen,0,0,w,h, B1->w, B1->h);
        else if(Vies==1&&coups>10)
        masked_blit(B075,screen,0,0,w,h, B075->w, B075->h);
        else if(Vies==1&&coups>5)
        masked_blit(B05,screen,0,0,w,h, B05->w, B05->h);
        else if(Vies==1&&coups>0)
        masked_blit(B025,screen,0,0,w,h, B025->w, B025->h);
        else if(Vies==1&&coups==0)
        masked_blit(B0,screen,0,0,w,h, B0->w, B0->h);


}
void CombinaisonGravite(char tab[10][15], int tmp) ///Détection des combinaisons et application de la gravité simulée
{
    int xtab, ytab; ///Ressources
    int Combinaison;
    do ///Boucle tant qu'il y a des combinaisons
    {
        Combinaison=0; ///Pas de combinaison
        for (xtab=0; xtab<15; xtab++) ///Parcourt de la matrice
        {
            for (ytab=0; ytab<10; ytab++)
            {

                ///croix
                if(tab[ytab+1][xtab+1]==tab[ytab+1][xtab]&&tab[ytab+1][xtab+1]==tab[ytab+1][xtab+2]&&tab[ytab+1][xtab+1]==tab[ytab][xtab+1]&&tab[ytab+1][xtab+1]==tab[ytab+2][xtab+1]&&tab[ytab+1][xtab+1]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab+1][xtab+1]=' '; ///Affichage des espaces
                    tab[ytab+1][xtab]=' ';
                    tab[ytab+1][xtab+2]=' ';
                    tab[ytab][xtab+1]=' ';
                    tab[ytab+2][xtab+1]=' ';

                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée

                }

                ///T(pivot O deg)
                if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]==tab[ytab+1][xtab+1]&&tab[ytab][xtab]==tab[ytab+2][xtab+1]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab][xtab+1]=' ';
                    tab[ytab][xtab+2]=' ';
                    tab[ytab+1][xtab+1]=' ';
                    tab[ytab+2][xtab+1]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///T(pivot 9O deg)
                if (tab[ytab+2][xtab+2]==tab[ytab+1][xtab]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+1]&&tab[ytab+2][xtab+2]==tab[ytab][xtab+2]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+2]&&tab[ytab+2][xtab+2]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab+2][xtab+2]=' '; ///Affichage des espaces
                    tab[ytab+1][xtab]=' ';
                    tab[ytab+1][xtab+1]=' ';
                    tab[ytab][xtab+2]=' ';
                    tab[ytab+1][xtab+2]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///T(pivot 18O deg)
                if (tab[ytab+2][xtab+2]==tab[ytab+2][xtab]&&tab[ytab+2][xtab+2]==tab[ytab+2][xtab+1]&&tab[ytab+2][xtab+2]==tab[ytab][xtab+1]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+1]&&tab[ytab+2][xtab+2]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab+2][xtab+2]=' '; ///Affichage des espaces
                    tab[ytab+2][xtab]=' ';
                    tab[ytab+2][xtab+1]=' ';
                    tab[ytab][xtab+1]=' ';
                    tab[ytab+1][xtab+1]=' ';
                    Combinaison=1; ///Combinaison
                   if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///T(pivot 270 deg)
                if (tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]==tab[ytab+1][xtab+1]&&tab[ytab][xtab]==tab[ytab+1][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab+1][xtab]=' ';
                    tab[ytab+2][xtab]=' ';
                    tab[ytab+1][xtab+1]=' ';
                    tab[ytab+1][xtab+2]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///L(pivot 0 deg)
                if (tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab+1]&&tab[ytab][xtab]==tab[ytab+2][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab+1][xtab]=' ';
                    tab[ytab+2][xtab]=' ';
                    tab[ytab+2][xtab+1]=' ';
                    tab[ytab+2][xtab+2]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///L(pivot 90 deg)
                if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]==tab[ytab+1][xtab]&&tab[ytab][xtab]==tab[ytab+2][xtab]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                {
                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab][xtab+1]=' ';
                    tab[ytab][xtab+2]=' ';
                    tab[ytab+1][xtab]=' ';
                    tab[ytab+2][xtab]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///L(pivot 180 deg)
                if (tab[ytab][xtab]==tab[ytab][xtab+1]&&tab[ytab][xtab]==tab[ytab][xtab+2]&&tab[ytab][xtab]==tab[ytab+1][xtab+2]&&tab[ytab][xtab]==tab[ytab+2][xtab+2]&&tab[ytab][xtab]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab][xtab+1]=' ';
                    tab[ytab][xtab+2]=' ';
                    tab[ytab+1][xtab+2]=' ';
                    tab[ytab+2][xtab+2]=' ';
                    Combinaison=1; ///Combinaison
                   if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                ///L(pivot 270 deg)
                if (tab[ytab+2][xtab+2]==tab[ytab][xtab+2]&&tab[ytab+2][xtab+2]==tab[ytab+1][xtab+2]&&tab[ytab+2][xtab+2]==tab[ytab+2][xtab]&&tab[ytab+2][xtab+2]==tab[ytab+2][xtab+1]&&tab[ytab+2][xtab+2]!=' '&&xtab<13&&ytab<8)
                {

                    tab[ytab+2][xtab+2]=' '; ///Affichage des espaces
                    tab[ytab][xtab+2]=' ';
                    tab[ytab+1][xtab+2]=' ';
                    tab[ytab+2][xtab]=' ';
                    tab[ytab+2][xtab+1]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
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

                            tab[ytab+4][xtab]=' '; ///Affichage des espaces
                        }

                        tab[ytab+3][xtab]=' '; ///Affichage des espaces
                    }

                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab+1][xtab]=' ';
                    tab[ytab+2][xtab]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
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

                            tab[ytab][xtab+4]=' '; ///Affichage des espaces
                        }

                        tab[ytab][xtab+3]=' '; ///Affichage des espaces
                    }

                    tab[ytab][xtab]=' '; ///Affichage des espaces
                    tab[ytab][xtab+1]=' ';
                    tab[ytab][xtab+2]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }

                if(tab[0][0]==tab[0][14]&&tab[0][0]==tab[9][0]&&tab[0][0]==tab[9][14]&&tab[0][0]!=' ') ///Combinaison bonus (4 coins du tableau)
                {

                    tab[0][0]=' '; ///Affichage des espaces
                    tab[0][14]=' ';
                    tab[9][0]=' ';
                    tab[9][14]=' ';
                    Combinaison=1; ///Combinaison
                    if(tmp==0)
                    Gravitedepart(tab);
                    if(tmp==1)
                    Gravite(tab); ///Application de la gravité simulée
                }
            }
        }
    }
    while(Combinaison==1);
}

void Gravite(char tab[10][15]) ///Gravité simulée dans la matrice
{
    int xtab, ytab; ///Ressources
    char tmp;
    int Espace;
    BITMAP *Soleil, *Orange, *Pomme, *Oignon, *Fraise, *Poke;
    Soleil=load_bitmap("Soleil.bmp",NULL);
    Orange=load_bitmap("Orange.bmp",NULL);
    Pomme=load_bitmap("Pomme.bmp",NULL);
    Oignon=load_bitmap("Oignon.bmp",NULL);
    Fraise=load_bitmap("Fraise.bmp",NULL);
    Poke=load_bitmap("Bonus1.bmp",NULL);
    {
        do ///Boucle tant qu'il y a des espaces (ils remontent la matrice pour disparaitre en son sommet)
        {
            Espace=0; ///Pas d'espaces
            {
                for (xtab=0; xtab<15; xtab++) ///Parcourt de la matrice
                {
                    for (ytab=0; ytab<10; ytab++)
                    {
                        if (tab[ytab][xtab]==' ') ///Espace
                        {
                            Espace=1;
                            if (ytab==0) ///Si l'espace est sur la première ligne
                            {
                                tab[0][xtab]=fruits(); ///Case remplie avec un caractère aléatoire de la fonction fruit()

                                if (tab[0][xtab]=='P')
                                    masked_blit(Pomme,screen,0,0,(xtab*68),0, Pomme->w, Pomme->h);
                                if (tab[0][xtab]=='F')
                                    masked_blit(Fraise,screen,0,0,(xtab*68),0, Fraise->w, Fraise->h);
                                if (tab[0][xtab]=='M')
                                    masked_blit(Orange,screen,0,0,(xtab*68),0, Orange->w, Orange->h);
                                if (tab[0][xtab]=='O')
                                    masked_blit(Oignon,screen,0,0,(xtab*68),0, Oignon->w, Oignon->h);
                                if (tab[0][xtab]=='S')
                                    masked_blit(Soleil,screen,0,0,(xtab*68),0, Soleil->w, Soleil->h);

                            }
                            else ///Si l'espace n'est pas sur la première ligne
                            {
                                if (tab[ytab-1][xtab]!=' ') ///Si la case adjacente de la ligne supérieure n'est pas un espace
                                {
                                    tmp=tab[ytab][xtab]; ///SWAP des cases
                                    tab[ytab][xtab]=tab[ytab-1][xtab];
                                    tab[ytab-1][xtab]=tmp;
                                rectfill(screen,(xtab*68),((ytab-1)*52),((xtab+1)*68),(ytab*52),makecol(192,220,192));

                                if (tab[ytab][xtab]=='P')
                                    masked_blit(Pomme,screen,0,0,(xtab*68),(ytab*52), Pomme->w, Pomme->h);
                                if (tab[ytab][xtab]=='F')
                                    masked_blit(Fraise,screen,0,0,(xtab*68),(ytab*52), Fraise->w, Fraise->h);
                                if (tab[ytab][xtab]=='M')
                                    masked_blit(Orange,screen,0,0,(xtab*68),(ytab*52), Orange->w, Orange->h);
                                if (tab[ytab][xtab]=='O')
                                    masked_blit(Oignon,screen,0,0,(xtab*68),(ytab*52), Oignon->w, Oignon->h);
                                if (tab[ytab][xtab]=='S')
                                    masked_blit(Soleil,screen,0,0,(xtab*68),(ytab*52), Soleil->w, Soleil->h);
                                     if (tab[ytab][xtab]=='X')
                                    masked_blit(Poke,screen,0,0,(xtab*68),(ytab*52), Poke->w, Poke->h);
                                }
                            }
                        }
                    }
                }
            }
        }
        while(Espace==1);
    }
}

void Gravitedepart(char tab[10][15])
{
    int xtab, ytab; ///Ressources
    char tmp;
    int Espace;
    BITMAP *Soleil, *Orange, *Pomme, *Oignon, *Fraise, *Poke;
    Soleil=load_bitmap("Soleil.bmp",NULL);
    Orange=load_bitmap("Orange.bmp",NULL);
    Pomme=load_bitmap("Pomme.bmp",NULL);
    Oignon=load_bitmap("Oignon.bmp",NULL);
    Fraise=load_bitmap("Fraise.bmp",NULL);
    Poke=load_bitmap("Bonus1.bmp",NULL);
    {
        do ///Boucle tant qu'il y a des espaces (ils remontent la matrice pour disparaitre en son sommet)
        {
            Espace=0; ///Pas d'espaces
            {
                for (xtab=0; xtab<15; xtab++) ///Parcourt de la matrice
                {
                    for (ytab=0; ytab<10; ytab++)
                    {
                        if (tab[ytab][xtab]==' ') ///Espace
                        {
                            Espace=1;
                            if (ytab==0) ///Si l'espace est sur la première ligne
                            {
                                tab[0][xtab]=fruits(); ///Case remplie avec un caractère aléatoire de la fonction fruit()

                            }
                            else ///Si l'espace n'est pas sur la première ligne
                            {
                                if (tab[ytab-1][xtab]!=' ') ///Si la case adjacente de la ligne supérieure n'est pas un espace
                                {
                                    tmp=tab[ytab][xtab]; ///SWAP des cases
                                    tab[ytab][xtab]=tab[ytab-1][xtab];
                                    tab[ytab-1][xtab]=tmp;
                                }
                            }
                        }
                    }
                }
            }
        }
        while(Espace==1);
    }
}
