#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#ifdef __unix__
#include <unistd.h>
#define _sleep(x) sleep((x)/500)
#endif

void Menu(); ///Appel du Menu
char fruits(); /// G�n�ration de caract�res al�atoires parmi les lettres {P,F,M,O,S}
void afficherdepart(char tab[10][15]);
void afficher(char tab[10][15]); ///Affichage de la matrice
void CombinaisonGravite(char tab[10][15], int tmp); ///D�tecte les combinaions et appel la gravit� simul�e
void Gravite(char tab[10][15]); ///Applique la gravit� simul�e
void Gravitedepart(char tab[10][15]);
int Niveau(int Niveau); ///Niveau N (1, 2 ou 3)
int ChargerNiveau(); ///Sauvegarde Niveau
int ChargerScore1(); ///Sauvegarde score niveau 1
int ChargerScore2(); ///Sauvegarde score niveau 2
int ChargerMscore1 (); ///Sauvegarde meilleur score niveau 1
int ChargerMscore2 (); ///Sauvegarde meilleur score niveau 2
int ChargerMscore3 (); ///Sauvegarde meilleur score niveau 3
void Unite(int planta, int Wide, int Height);
void Dizaine(int planta, int Wide, int Height);
void Centaine(int planta, int Wide, int Height);
void BFS(int j, int i, int xtab, int ytab);
void BFF(int j, int i, int xtab, int ytab);
void BFP(int j, int i, int xtab, int ytab);
void BFM(int j, int i, int xtab, int ytab);
void BFO(int j, int i, int xtab, int ytab);
void Coeur(int Vies, int coups, int w, int h);
#endif /// FICHIER_H_INCLUDED
