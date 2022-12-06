#include "fichier.h"

void Menu()
{
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    BITMAP *BCredits, *BScore, *BMenu, *BTuto, *BFin;
    BMenu=load_bitmap("menu.bmp",NULL);
    BCredits=load_bitmap("Credits.bmp",NULL);
    BScore=load_bitmap("Score.bmp",NULL);
    BTuto=load_bitmap("Tuto.bmp",NULL);
    BFin=load_bitmap("Fin.bmp",NULL);
    char choix; ///Ressource
    int Success;
    int NiveauSauvegarde;
    int Score1=0;
    int Score2=0;
    int Score3=0;
    int Mscore1=ChargerMscore1();
    int Mscore2=ChargerMscore2();
    int Mscore3=ChargerMscore3();
    int quitter=0;
    int tmp;
    masked_blit(BMenu,screen,0,0,0,0, BMenu->w, BMenu->h);

    do ///Boucle tant que le joueur ne quitte pas le jeu
    {
        tmp=0;

         if ((mouse_b&1)&&mouse_x>140&&mouse_y>460&&mouse_x<300&&mouse_y<500)
            {
                clear_bitmap(screen);
                ///Niveau 1
                Score1=Niveau(1); ///Récuparation du score
                Success=Score1;
                if(Success) ///Si le niveau 1 est réussi
                {
                    clear_bitmap(screen);
                    ///Niveau 2
                    Score2=Niveau(2); ///Récupération du score
                    Success=Score2;
                    if(Success) ///Si le niveau 2 est réussi
                    {
                        clear_bitmap(screen);
                        ///Niveau 3
                        Score3=Niveau(3); ///Récupération du score
                        Success=Score3;
                        if(Success) ///Si le niveau 3 est réussi
                        {
                            clear_bitmap(screen);
                            blit(BFin,screen,0,0,0,0, BFin->w, BFin->h);
                                Unite(Score1, 640, 315);
                                Dizaine(Score1, 610, 315);
                                Centaine(Score1, 580, 315);
                                Unite(Score2, 640, 390);
                                Dizaine(Score2, 610, 390);
                                Centaine(Score2, 580, 390);
                                Unite(Score3, 640, 465);
                                Dizaine(Score3, 610, 465);
                                Centaine(Score3, 580, 465);
                            do
            {if((mouse_b&1)&&mouse_x>1000&&mouse_y>748)
            tmp=1;
            }while(tmp==0);
                        }
                    }

                }
                if(Score1>Mscore1) ///Si score niveau 1 supérieur à meilleur score niveau 1
                {
                    Mscore1=Score1; ///Meilleur score niveau 1 prend la valeur score 1
                    FILE*file; ///Sauvegarde meilleur score niveau 1
                    file=fopen("Sauvegarde_Mscore1.txt","w");
                    fprintf(file,"%d",Mscore1);
                    fclose(file);
                }
                if(Score2>Mscore2) ///Si score niveau 2 est supérieur au meilleur score niveau 2
                {
                    Mscore2=Score2; ///Meilleur score niveau 2 prend la valeur score 2
                    FILE*file; ///Sauvegarde meilleur score niveau 2
                    file=fopen("Sauvegarde_Mscore2.txt","w");
                    fprintf(file,"%d",Mscore2);
                    fclose(file);
                }

                if(Score3>Mscore3) ///Si score niveau 3 est supérieur au meilleur score niveau 3
                {
                    Mscore3=Score3; ///Meilleur score niveau 3 prend la valeur score 3
                    FILE*file; ///Sauvegarde meilleur score niveau 3
                    file=fopen("Sauvegarde_Mscore3.txt","w");
                    fprintf(file,"%d",Mscore3);
                    fclose(file);
                }
                clear_bitmap(screen);
                 masked_blit(BMenu,screen,0,0,0,0, BMenu->w, BMenu->h);
        }

         if ((mouse_b&1)&&mouse_x>330&&mouse_y>460&&mouse_x<650&&mouse_y<500)
            {
            NiveauSauvegarde=ChargerNiveau(); ///Reprise de la sauvegarde
            if(NiveauSauvegarde==2) ///Si reprise niveau 2
            {
                clear_bitmap(screen);
                Score1=ChargerScore1(); ///Récupération du score niveau 1
                Score2=Niveau(2); ///Récupération du score niveau 2
                Success=Score2;
                if(Success) ///Si le niveau 2 est réussi
                {
                    ///Niveau 3
                    clear_bitmap(screen);
                    Score3=Niveau(3); ///Récupération du score niveua 3
                    Success=Score3;
                    if(Success) ///Si le niveau 3 est réussi
                    {
                        clear_bitmap(screen);
                        blit(BFin,screen,0,0,0,0, BFin->w, BFin->h);
                                Unite(Score1, 640, 315);
                                Dizaine(Score1, 610, 315);
                                Centaine(Score1, 580, 315);
                                Unite(Score2, 640, 390);
                                Dizaine(Score2, 610, 390);
                                Centaine(Score2, 580, 390);
                                Unite(Score3, 640, 465);
                                Dizaine(Score3, 610, 465);
                                Centaine(Score3, 580, 465);
                            do
            {if((mouse_b&1)&&mouse_x>1000&&mouse_y>748)
            tmp=1;
            }while(tmp==0);
                    }
                }
            }
            if(NiveauSauvegarde==3) ///Si reprise niveau 3
            {
                Score1=ChargerScore1(); ///Récupération du score niveau 1
                Score2=ChargerScore2(); ///Récupération du score niveau 2
                Score3=Niveau(3); ///Récupération du score niveau 3
                Success=Score3;
                if(Success) ///Si le niveau 3 est réussi
                {
                    clear_bitmap(screen);
                    blit(BFin,screen,0,0,0,0, BFin->w, BFin->h);
                                Unite(Score1, 640, 315);
                                Dizaine(Score1, 610, 315);
                                Centaine(Score1, 580, 315);
                                Unite(Score2, 640, 390);
                                Dizaine(Score2, 610, 390);
                                Centaine(Score2, 580, 390);
                                Unite(Score3, 640, 465);
                                Dizaine(Score3, 610, 465);
                                Centaine(Score3, 580, 465);
                            do
            {if((mouse_b&1)&&mouse_x>1000&&mouse_y>748)
            tmp=1;
            }while(tmp==0);
                }
            }
            if(Score1>Mscore1) ///Si score niveau 1 supérieure à meilleur score niveau 1
                {
                    Mscore1=Score1; ///Meilleur score niveau 1 prend la valeur score 1
                    FILE*file; ///Sauvegarde meilleur score niveau 1
                    file=fopen("Sauvegarde_Mscore1.txt","w");
                    fprintf(file,"%d",Mscore1);
                    fclose(file);
                }
                if(Score2>Mscore2) ///Si score niveau 2 supérieure à meilleur score niveau 2
                {
                    Mscore2=Score2; ///Meilleur score niveau 2 prend la valeur score 2
                    FILE*file; ///Sauvegarde meilleur score niveau 2
                    file=fopen("Sauvegarde_Mscore2.txt","w");
                    fprintf(file,"%d",Mscore2);
                    fclose(file);
                }

                if(Score3>Mscore3) ///Si score niveau 3 supérieure à meilleur score niveau 3
                {
                    Mscore3=Score3; ///Meilleur score niveau 3 prend la valeur score 3
                    FILE*file; ///Sauvegarde meilleur score niveau 3
                    file=fopen("Sauvegarde_Mscore3.txt","w");
                    fprintf(file,"%d",Mscore3);
                    fclose(file);
                }
                clear_bitmap(screen);
                 masked_blit(BMenu,screen,0,0,0,0, BMenu->w, BMenu->h);
        }
         if ((mouse_b&1)&&mouse_x>670&&mouse_y>460&&mouse_x<870&&mouse_y<500)
            {
            clear_bitmap(screen);
            blit(BScore,screen,0,0,0,0, BScore->w, BScore->h);
            Unite(Mscore1, 465, 420);
            Dizaine(Mscore1, 435, 420);
            Centaine(Mscore1, 405, 420);
            Unite(Mscore2, 685, 420);
            Dizaine(Mscore2, 655, 420);
            Centaine(Mscore2, 625, 420);
            Unite(Mscore3, 905, 420);
            Dizaine(Mscore3, 875, 420);
            Centaine(Mscore3, 845, 420);
            do
            {if((mouse_b&1)&&mouse_x>1000&&mouse_y>748)
            tmp=1;
            }while(tmp==0);
            clear_bitmap(screen);
                             masked_blit(BMenu,screen,0,0,0,0, BMenu->w, BMenu->h);
        }
        if ((mouse_b&1)&&mouse_x>250&&mouse_y>530&&mouse_x<510&&mouse_y<570)
            {
            clear_bitmap(screen);
            blit(BTuto,screen,0,0,0,0, BTuto->w, BTuto->h);
           do
            {if((mouse_b&1)&&mouse_x>1000&&mouse_y>748)
            tmp=1;
            }while(tmp==0);
            clear_bitmap(screen);
                             masked_blit(BMenu,screen,0,0,0,0, BMenu->w, BMenu->h);
        }


         if ((mouse_b&1)&&mouse_x>590&&mouse_y>550&&mouse_x<820&&mouse_y<590)
            {
            clear_bitmap(screen);
            blit(BCredits,screen,0,0,0,0, BCredits->w, BCredits->h);
            do
            {if((mouse_b&1)&&mouse_x>1000&&mouse_y>748)
            tmp=1;
            }while(tmp==0);
clear_bitmap(screen);
                             masked_blit(BMenu,screen,0,0,0,0, BMenu->w, BMenu->h);
        }
        if ((mouse_b&1)&&mouse_x>720&&mouse_y<50)
            quitter=1;
        }
    while( quitter==0);
}
