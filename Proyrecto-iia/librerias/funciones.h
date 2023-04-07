//Librerias de C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//Mis librerias 
#include "struct.h"

void point_rand_player(Player* players){
    int max_points = 100;
    int min_points = 50;
    for (int i = 0; i < MAX_PLAYERS; i++){
        players[i].attack = rand() % (max_points - min_points + 1 ) + min_points;
        players[i].defense = rand() % (max_points - min_points + 1 ) + min_points;
    }
}

void assing_team_info(Team* teams, Player* p){
    int no_player = 0;
    int assing_team = 0; 
    do{
        teams[assing_team].puntos = 0;
        for (int i = 0; i < NUM_PLAYERS; i++){
            teams[assing_team].players[i] = &p[no_player];
            teams[assing_team].puntos += p[no_player].attack;
            teams[assing_team].puntos += p[no_player].defense;
            teams[assing_team].on_game = 1;
            no_player++;
        }
        teams[assing_team].puntos = teams[assing_team].puntos / 24;
        assing_team++;
    } while (assing_team < NUM_TEAMS);
}

void match_results(Team* player_one, Team* player_two, int no_matches,  Match* matches){
    if (player_one->puntos > player_two->puntos){
        //Asigna quien fue el ganador y quien el perdedor 
        matches[no_matches].winner = player_one;
        matches[no_matches].loser = player_two;
        //Registra los puntos de cada equipo 
        matches[no_matches].pointsW = player_one->puntos;
        matches[no_matches].pointsL = player_two->puntos;
        //Asigna los goles que resultaron del partido 
        matches[no_matches].golesW = (rand() % 6) + 1;
        matches[no_matches].golesL = (rand() % matches[no_matches].golesW);
        //Saca del torneo al perdedor 
        player_two->on_game = 0;
    } else {
        //Asigna quien fue el ganador y quien el perdedor 
        matches[no_matches].winner = player_two;
        matches[no_matches].loser = player_one;
        //Registra los puntos de cada equipo 
        matches[no_matches].pointsW = player_two->puntos;
        matches[no_matches].pointsL = player_one->puntos;
        //Asigna los goles que resultaron del partido 
        matches[no_matches].golesW = (rand() % 6) + 1;
        matches[no_matches].golesL = (rand() % matches[no_matches].golesW);
        player_one->on_game = 0;
    }
    print_match_results(matches, no_matches);    
}

void tournament( Team* teams ,Match* matches){  
    int no_matches = 0, x = 0, y = 0;
    Team* player1;
    Team* player2;
    do{
        while (!teams[x].on_game) //si es 0
            x++;
        player1 = &teams[x];
        y = x+1;
        while (!teams[y].on_game) //si es 0
            y++;
        player2 = &teams[y];
        match_results (player1,player2, no_matches, matches);
        if (y == 7)
            x = 0;
        else
            x = y + 1;
        no_matches++;
    } while (no_matches<NUM_MATCHES);  
}