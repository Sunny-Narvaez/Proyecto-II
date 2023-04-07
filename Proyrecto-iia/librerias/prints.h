//Librerias de C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//Mis librerias 
#include "struct.h"

void caratula ()
{
  printf ("\n\n\t\tUNIVERSADAD NACIONAL AUTONOMA DE MEXICO");
  printf ("\n\n\t|LICENCIATURA DE MATEMATICAS APLICADS Y COMPUTACION|");
  printf ("\n\n\t\t   Simulador de Quinela de Futbol");
  printf ("\n\n\n\n\n\t\t     Por: Sunny Narvaez Guerrero ");
  printf ("\n\n\n\n\n\t\t\t    GRUPO:2202 \n\n");
  system ("pause");
  system ("cls");
}

void print_teams (Team* teams){
    for (int i = 0; i < NUM_TEAMS; i++){
        printf("\nEl equipo %i se llama: %s \nPuntos: %.2f\n", i + 1, teams[i].name,teams[i].puntos);
        for (int j = 0; j < NUM_PLAYERS; j++){
            printf("\tJugador %i: %s \r\t\t\t\t\t\t\tPts: %.2f\n", j + 1, teams[i].players[j]->name,(teams[i].players[j]->attack+teams[i].players[j]->defense)/2);
        }
        system("pause");
        system("cls");
    }

    system ("pause");
    system ("cls");
}
void print_players (Player* players){
    for (int i = 0; i < MAX_PLAYERS; i++)
        printf("El jugador %i se llama: %s \nPuntos ATK: %.2f \r\t\t\t\tPuntos DEF: %.2f\n\n", i + 1, players[i].name, players[i].attack,players[i].defense);
    system ("pause");
    system ("cls");
}
void print_match_results(Match* matches, int no_matches){
    printf("Match numero %i\n", no_matches+1);
    printf("Ganador: %s \r\t\t\t\tPerdedor: %s\n", matches[no_matches].winner->name,matches[no_matches].loser->name);
    printf("Puntos: %.2f\r\t\t\t\tPuntos: %.2f\n", matches[no_matches].pointsW, matches[no_matches].pointsL);
    printf("Goles: %i\r\t\t\t\tGoles: %i\n\n",matches[no_matches].golesW,matches[no_matches].golesL);
}