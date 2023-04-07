//Programa para la creacion de un torneo de futbol
//Librerias de C 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//Mis librerias 
#include "librerias/prints.h"
#include "librerias/moodFiles.h"
#include "librerias/struct.h"
#include "librerias/funciones.h"
//Main
int main (){   
    Player players[MAX_PLAYERS];
    Team teams[NUM_TEAMS];
    Match matches[NUM_MATCHES];
    srand(time(NULL));
    caratula ();   
    read_players_from_file("datos_players.txt", players);
    read_teams_from_file("datos_teams.txt", teams);
    point_rand_player(players);    
    print_players(players);
    assing_team_info(teams, players);
    print_teams(teams);
    tournament(teams, matches);
    return 0;
}