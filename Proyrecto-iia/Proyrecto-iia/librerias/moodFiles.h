//Librerias de C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//Mis librerias 
#include "struct.h"

void read_teams_from_file(char* filename, Team* teams) {
    //Variables auxiliares 
    char buffer[MAX_NAME_LENGTH];
    int team_index = 0;
    FILE* file = fopen(filename, "r");
    //Si el archivo "filename" no existe entonces cierra la funcion  
    if (!file) {
        printf("No se puede abrir el archivo %s.\n", filename);
        return;
    }
    //Revisa si existe una linea de texto en el txt
    while (fgets(buffer, MAX_NAME_LENGTH, file)){
        // eliminar el caracter de nueva linea
        strtok(buffer, "\n");
        // asignar el nombre del equipo a la estructura correspondiente
        strcpy(teams[team_index].name, buffer);
        team_index++;
        if (team_index == NUM_TEAMS) 
            break;
    }
}

void read_players_from_file(char* filename, Player* players) {
    //Variables auxiliares 
    char buffer[MAX_NAME_LENGTH];
    int player_index = 0;
    FILE* file = fopen(filename, "r");
    //Si el archivo "filename" no existe entonces cierra la funcion  
    if (!file) {
        printf("No se puede abrir el archivo %s.\n", filename);
        return;
    }
    //Revisa si existe una linea de texto en el txt
    while (fgets(buffer, MAX_NAME_LENGTH, file)){
        // eliminar el caracter de nueva linea
        strtok(buffer, "\n");
        // asignar el nombre del equipo a la estructura correspondiente
        strcpy(players[player_index].name, buffer);
        player_index++;
        if (player_index == MAX_PLAYERS) 
            break;
    }
}