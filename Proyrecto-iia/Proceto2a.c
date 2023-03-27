
//Prpgrama para la creacion de un tornamento de futbol
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "libreria.h"
#include "players.h"

#define MAX_PLAYERS 96
#define MAX_NAME_LENGTH 50
#define num_players 12
#define num_teams 8
#define num_matches 7



typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int attack;
    int defense;
} Player[MAX_PLAYERS];

typedef struct {
    char name[MAX_NAME_LENGTH];
    Player players[12];
    int puntos;
} Team[num_teams];

typedef struct {
    char winner [MAX_NAME_LENGTH];
    char loser [MAX_NAME_LENGTH];
    int pointsW ;
    int pointsL ;
} Matches[num_matches];


int main ()
{   
    caratula ();
    
    assign_name_players (Player);

   
    
   
    return 0;
}

/*

*/