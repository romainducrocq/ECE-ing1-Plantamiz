#include "fichier.h"
int ChargerNiveau() ///Sauvegarde Niveau
{
    int Niveau;
    FILE*file;
    file=fopen("Sauvegarde_niveau.txt","r");
    fscanf(file,"%d",&Niveau);
    fclose(file);
    return Niveau;
}
int ChargerScore1() ///Sauvegarde score niveau 1
{
    int Score1;
    FILE*file;
    file=fopen("Sauvegarde_Score1.txt","r");
    fscanf(file,"%d",&Score1);
    fclose(file);
    return Score1;
}
int ChargerScore2() ///Sauvegarde score niveau 2
{
    int Score2;
    FILE*file;
    file=fopen("Sauvegarde_Score2.txt","r");
    fscanf(file,"%d",&Score2);
    fclose(file);
    return Score2;
}
int ChargerMscore1 () ///Sauvegarde meilleur score niveau 1
{
    int Mscore1;
    FILE*file;
    file=fopen("Sauvegarde_Mscore1.txt","r");
    fscanf(file,"%d",&Mscore1);
    fclose(file);
    return Mscore1;
}
int ChargerMscore2 () ///Sauvegarde meilleur score niveau 2
{
    int Mscore2;
    FILE*file;
    file=fopen("Sauvegarde_Mscore2.txt","r");
    fscanf(file,"%d",&Mscore2);
    fclose(file);
    return Mscore2;
}
int ChargerMscore3 () ///Sauvegarde meilleur score niveau 3
{
    int Mscore3;
    FILE*file;
    file=fopen("Sauvegarde_Mscore3.txt","r");
    fscanf(file,"%d",&Mscore3);
    fclose(file);
    return Mscore3;
}
