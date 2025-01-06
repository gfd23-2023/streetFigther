/*Tela de início
 *Escolha dos jogadores
 *Escolha dos cenários*/

#ifndef __WORLD__
#define __WORLD__

#include <stdio.h>
#include "players.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define LARG 50
#define ALTU 121

typedef struct {
	ALLEGRO_BITMAP *cenarios[4];
	ALLEGRO_BITMAP *personagens[4];
	ALLEGRO_BITMAP *cansados[4];
	ALLEGRO_BITMAP *sprite[4];

	ALLEGRO_BITMAP *cenario;
	ALLEGRO_BITMAP *selecionado1;
	ALLEGRO_BITMAP *selecionado2;
	ALLEGRO_BITMAP *cansado1;
	ALLEGRO_BITMAP *cansado2;

	ALLEGRO_BITMAP *mapa;

	player_t *player1;
	player_t *player2;

	int contador;
	int loading_menu;
	int rodadas;

	ALLEGRO_AUDIO_STREAM *menu_musica;
	ALLEGRO_AUDIO_STREAM *rodada_musica;
	ALLEGRO_AUDIO_STREAM *seleciona_player_musica;
} menu_t;

menu_t* IniMenu (ALLEGRO_BITMAP *personagem1[], ALLEGRO_BITMAP *cenarios[], ALLEGRO_BITMAP *cansados[], ALLEGRO_BITMAP *sprite[], ALLEGRO_BITMAP *mapa_st);

/*Habilita a seleção dos jogadores e dos cenários, respectivamente*/
void apresenta_menu_players_cenarios (menu_t *menu, ALLEGRO_EVENT menu_events, ALLEGRO_EVENT_QUEUE *event_menu, ALLEGRO_FONT *fonte);

/*Apresenta as teclas com os golpes do Ryu
 *tomar cuidado com a diferenciação entre Player1 e Player2*/
void lista_golpes_ryu ();

/*Apresneta as teclas com os golpes do Ken*/
void lista_golpes_ken ();

/*Apresenta as teclas com os golpes da Chun Li*/
void lista_golpes_chunli ();

/*Apresenta as teclas com os golpes do Fei Long*/
void lista_golpes_feilong ();

#endif
