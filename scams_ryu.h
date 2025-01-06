#ifndef __SCAMS_RYU__
#define __SCAMS_RYU__

#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include "Joystick.h"
#include "players.h"

mapa_sprite *especiais;

//preenche o vetor de especiais
mapa_sprite* reconhece_golpe_especial (int i);

//Faz a vida do personagem voltar para 100
void restaura_vida (player_t *player);

//1 = morreu
//0 = está vivo
int verifica_vida (player_t *player);

//Imprime as barras de vida na tela
void barra_de_vida (player_t *player1, player_t *player2, ALLEGRO_BITMAP *id1, ALLEGRO_BITMAP *id2, ALLEGRO_BITMAP *cansado1, ALLEGRO_BITMAP *cansado2);

//golpeia e chuta
int ataca (player_t *atacante, player_t *vitima);

void hadouken (player_t *player1, player_t *player2);

void desenha_projetil (player_t *player, ALLEGRO_BITMAP *projetil);

//desconta a vida
void atualiza_ataque (player_t *player1, player_t *player2);

//animação do player caindo no chão
void player_morreu (player_t *player);
#endif
