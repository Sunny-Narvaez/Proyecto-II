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




void validarContrasena() {
    unsigned int longitud_minima = 8;
    unsigned int tiene_mayuscula = 0;
    unsigned int tiene_minuscula = 0;
    unsigned int tiene_numero = 0;
    unsigned int tiene_caracter_especial = 0;
    unsigned int es_sunny_125 = 0;

    char contrasena[50];

    printf("Ingrese su contraseña: ");
    scanf("%s", contrasena);

    // Verificar si la contraseña es "Sunny-125"
    if (strcmp(contrasena, "Sunny-125") == 0) {
        es_sunny_125 = 1;
    }

    // Verificar longitud mínima
    if (strlen(contrasena) < longitud_minima) {
        printf("La contraseña debe tener al menos %d caracteres.\n", longitud_minima);
        exit(0); // Cerrar el programa
    }

    // Verificar si contiene al menos una mayúscula
    for (int i = 0; contrasena[i] != '\0'; i++) {
        if (contrasena[i] >= 'A' && contrasena[i] <= 'Z') {
            tiene_mayuscula = 1;
            break;
        }
    }

    // Verificar si contiene al menos una minúscula
    for (int i = 0; contrasena[i] != '\0'; i++) {
        if (contrasena[i] >= 'a' && contrasena[i] <= 'z') {
            tiene_minuscula = 1;
            break;
        }
    }

    // Verificar si contiene al menos un número
    for (int i = 0; contrasena[i] != '\0'; i++) {
        if (contrasena[i] >= '0' && contrasena[i] <= '9') {
            tiene_numero = 1;
            break;
        }
    }

    // Verificar si contiene al menos un caracter especial
    for (int i = 0; contrasena[i] != '\0'; i++) {
        if ((contrasena[i] >= 33 && contrasena[i] <= 47) || (contrasena[i] >= 58 && contrasena[i] <= 64) ||
            (contrasena[i] >= 91 && contrasena[i] <= 96) || (contrasena[i] >= 123 && contrasena[i] <= 126)) {
            tiene_caracter_especial = 1;
            break;
        }
    }

    // Verificar todas las condiciones
    if (tiene_mayuscula && tiene_minuscula && tiene_numero && tiene_caracter_especial && es_sunny_125) {
        printf("Contraseña válida.\n");
    } else {
        printf("La contraseña no cumple con los requisitos. El programa se cerrará.\n");
        exit(0); // Cerrar el programa
    }
}