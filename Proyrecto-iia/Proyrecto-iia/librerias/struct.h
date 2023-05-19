//Estructura 
#ifndef STRUCT_H
    #define STRUCT_H

    //Variables globales 
    #define MAX_PLAYERS 96
    #define MAX_NAME_LENGTH 50
    #define NUM_PLAYERS 12
    #define NUM_TEAMS 8
    #define NUM_MATCHES 7

    //Estructura
    typedef struct {
        char name[MAX_NAME_LENGTH];
        int age;
        float attack;
        float defense;
    } Player;

    typedef struct {
        char name[MAX_NAME_LENGTH];
        Player* players[12];
        float puntos;
        int on_game;
    } Team;
    
    typedef struct {
        Team* winner;
        Team* loser;
        float pointsW;
        float pointsL;
        int golesW;
        int golesL;
    } Match;

#endif