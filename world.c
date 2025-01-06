#include "world.h"

/*MENU DO JOGO*/

menu_t* IniMenu (ALLEGRO_BITMAP *personagem1[], ALLEGRO_BITMAP *cenarios[], ALLEGRO_BITMAP *cansados[], ALLEGRO_BITMAP *sprite[], ALLEGRO_BITMAP *mapa_st)
{
	menu_t *menu = malloc (sizeof (menu_t));
	if (!menu) return NULL;

	for (int i = 0; i < 4; i ++)
	{
		menu->cenarios[i] = cenarios[i];
		menu->personagens[i] = personagem1[i];
		menu->cansados[i] = cansados[i];
		menu->sprite[i] = sprite[i];
	}

	menu->mapa = mapa_st;
	menu->cenario = NULL;
	menu->selecionado1 = NULL;
	menu->selecionado2 = NULL;
	menu->cansado1 = NULL;
	menu->cansado2 = NULL;
	menu->contador = 0;
	menu->loading_menu = 1;
	menu->rodadas = 0;
	menu->menu_musica = al_load_audio_stream ("opening.flac", 4, 4096);
	menu->rodada_musica = al_load_audio_stream ("batalha.flac", 4, 4096);
	menu->seleciona_player_musica = al_load_audio_stream ("selecao.flac", 4, 4096);

	al_attach_audio_stream_to_mixer (menu->menu_musica, al_get_default_mixer ());
	al_attach_audio_stream_to_mixer (menu->rodada_musica, al_get_default_mixer ());
	al_attach_audio_stream_to_mixer (menu->seleciona_player_musica, al_get_default_mixer ());

	return menu;
}

void apresenta_menu_players_cenarios (menu_t *menu, ALLEGRO_EVENT menu_events, ALLEGRO_EVENT_QUEUE *event_menu, ALLEGRO_FONT *fonte)
{
	int largura_cenario = 0;
    int altura_cenario = 0;

	al_wait_for_event (event_menu, &menu_events);

	al_set_audio_stream_playing (menu->menu_musica, 0);
	al_set_audio_stream_playing (menu->rodada_musica, 0);
	al_set_audio_stream_playing (menu->seleciona_player_musica, 1);

    al_clear_to_color (al_map_rgb (0, 0, 128));
    al_draw_bitmap (menu->mapa, 500, 50, 0);														//desenha o mapa
    al_draw_scaled_bitmap (menu->personagens[0], 0, 0, 70, 100, 680, 600, 2*70, 2*100, 0);			//desenha ryu
    al_draw_scaled_bitmap (menu->personagens[1], 0, 0, 70, 100, 822, 600, 2*70, 2*100, 0);			//desenha ken
    al_draw_scaled_bitmap (menu->personagens[2], 0, 0, 70, 100, 964, 600, 2*70, 2*100, 0);			//desenha chunli
    al_draw_scaled_bitmap (menu->personagens[3], 0, 0, 70, 100, 1106, 600, 2*70, 2*100, 0);			//desenha feilong

	if (!menu->cenario)
    {
        largura_cenario = al_get_bitmap_width (menu->cenarios[menu->contador]);
        altura_cenario = al_get_bitmap_height (menu->cenarios[menu->contador]);
        al_draw_scaled_bitmap (menu->cenarios[menu->contador], 0, 0, largura_cenario, altura_cenario, 20, 75, largura_cenario/4, altura_cenario/4, 0);
    }
    else
    {
        al_draw_text (fonte, al_map_rgb (0, 0, 0), 20, 35, 0, "Selecionado");
        al_draw_scaled_bitmap (menu->cenario, 0 , 0, largura_cenario, altura_cenario, 20, 75, largura_cenario/4, altura_cenario/4, 0);
    }

	if (!menu->selecionado1)
    {
        al_draw_text (fonte, al_map_rgb (0, 0, 0), 1500, 455, 0, "Player 1");
        al_draw_scaled_bitmap (menu->personagens[menu->contador], 0, 0, 70, 70, 1500, 500, 5*70, 5*70, 1);
    }
    else
    {
        al_draw_text (fonte, al_map_rgb (0, 0, 0), 1500, 455, 0, "Player 1 - OK");
        al_draw_scaled_bitmap (menu->selecionado1, 0, 0, 70, 70, 1500, 500, 5*70, 5*70, 1);
    }

	if (!menu->selecionado2)
    {
        al_draw_text (fonte, al_map_rgb (0, 0, 0), 150, 455, 0, "Player2");
        al_draw_scaled_bitmap (menu->personagens[menu->contador], 0, 0, 70, 70, 150, 500, 5*70, 5*70, 0);
    }
    else
    {
        al_draw_text (fonte, al_map_rgb (0, 0, 0), 150, 455, 0, "Player2 - OK");
        al_draw_scaled_bitmap (menu->selecionado2, 0, 0, 70, 70, 150, 500, 5*70, 5*70, 0);
    }

	if (menu_events.keyboard.keycode == ALLEGRO_KEY_SPACE)
	{
		menu->loading_menu = 0;
		al_set_audio_stream_playing (menu->seleciona_player_musica, 0);
	}

	if (menu_events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
        menu->loading_menu = 0; 
    else if (menu_events.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
        menu->loading_menu = 0; 

	else if (menu_events.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (menu_events.keyboard.keycode == ALLEGRO_KEY_P)
			{
                menu->selecionado1 = menu->personagens[menu->contador];
                menu->cansado1 = menu->cansados[menu->contador];
                menu->player1 = init_player (menu->sprite[menu->contador], 50, 0, LARG, ALTU, 1700, 500, 1, menu->contador);
            }

            if (menu_events.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                menu->selecionado2 = menu->personagens[menu->contador];
                menu->cansado2 = menu->cansados[menu->contador];
                menu->player2 = init_player (menu->sprite[menu->contador], 50, 0, LARG, ALTU, 20, 500, 0, menu->contador);
            }

            if (menu_events.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                menu->contador++;
                if (menu->contador >= 4) menu->contador = 0;
            }

            if (menu_events.keyboard.keycode == ALLEGRO_KEY_B)
                menu->cenario = menu->cenarios[menu->contador];
        }

    al_flip_display ();
}
/*
void lista_golpes_ryu ()
{

}
*/
void lista_golpes_ken ()
{

}

void lista_golpes_chunli ()
{

}

void lista_golpes_feilong ()
{

}

void destroi_equipe ()
{
}
