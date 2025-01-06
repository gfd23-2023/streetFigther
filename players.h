/*Estrutura e movimentação dos jogadores*/

#ifndef __PLAYERS__
#define __PLAYERS__

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Joystick.h"

#define GRAVIDADE 1.0
#define IMPULSO -40.0
#define MAX_X 1920
#define MAX_Y 925
#define CHAO 500
#define PASSO 20

typedef struct {
	int frame_x;
	int frame_y;
	int largura;
	int altura;
} mapa_sprite;

typedef struct {
	int x;
	int y;
	int largura;
	int altura;
} hurtbox_t;

typedef struct {
	int x;
	int y;
	int largura;
	int altura;
} hitbox_t;

typedef struct {
	int x;
	int y;
	int frame_x;
	int frame_y;
	int largura;
	int altura;
} projetil_t;

typedef struct {
	int id;							//0 = ryu/ 1 = ken/ 2 = chun li/ 3 = fei long
	ALLEGRO_BITMAP  *sprite;		//spritesheet
	mapa_sprite **mapa;				//mapeamento das sprites
	short int frame_atual_x;		//posição x na spritesheet
	short int frame_atual_y;		//posição y na spritesheet
	short int anima;				//controla a animação
	short int largura;				//largura do frame
	short int altura;				//altura do frame
	short int pos_x;                //posição x no display
    float pos_y;					//posição y no display
	float velocidade_y;				//velociade no eixo y
	char no_chao;					//0 = no ar/ 1 = no chão
	int flag;						//inverte ou não o desenho
	int vitorias;					//número de vitórias
	int vida;						//vida do jogador
	int movimento_iniciado;			//1 = iniciado/ 0 = não iniciado
	char especial_iniciado;			//0 = não iniciado / 1 = iniciado
	hitbox_t *hitbox;
	hurtbox_t *hurtbox;
	joystick *control;				//estados das teclas
	projetil_t *projetil;
}player_t;

mapa_sprite** preenche_matriz (int i, player_t *player);

//Preenche a estrutura
//spritesheet = sprite, frame_x = frame atual x, frame_y = frame_atual_y, px = pos_x, py = pos_y
player_t* init_player (ALLEGRO_BITMAP *spritesheet, short int frame_x, short int frame_y, short int l, short int h, short int px, float py, int flag, int i);

void estado_inicial (player_t *player, int flag);

void movimenta_player (player_t *player, short int deslocamento, short int trajetoria, short int max_x, short int max_y, ALLEGRO_EVENT event);

void atualiza_posicao (player_t *player1, player_t *player2, ALLEGRO_EVENT event);

void player_em_alerta (player_t *player);

int colide_players (player_t *player1, player_t *player2);

void desenha_player (player_t *player, int flag);

void inverte_players (player_t *player1, player_t *player2);

void destroi_player (player_t* player);

#endif
