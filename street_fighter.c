/*código principal
 *criação do display
 *fila de eventos*/

#include "world.h"						//contém a tela de início, a escolha dos jogadores e dos cenários
#include "Joystick.h"					//contém o estado das teclas de movimentação
#include "players.h"					//contém a estrutura dos jogadores e as movimentações
#include "scams_ryu.h"					//contém os golpes do ryu
#include "scams_ken.h"					//contém os golpes do ken

#define LARG 50
#define ALTU 121

int main ()
{
	/*Inicializações da biblioteca Allegro*/
	al_init ();
	al_init_font_addon ();
	al_init_ttf_addon ();
	al_init_image_addon ();
	al_install_keyboard ();
	al_init_acodec_addon ();
	al_install_audio ();
	al_init_primitives_addon ();

	//Reservando Samples de áudio
	al_reserve_samples (1);

	/*Cria um display com as dimensões MAX_X e MAX_Y*/
	ALLEGRO_DISPLAY *display = al_create_display (MAX_X, MAX_Y);
	al_set_window_position (display, 200, 200);

	/*Adiciona o ícone do jogo na tela*/
	ALLEGRO_BITMAP *icon = al_load_bitmap ("./icone.png");
	al_set_display_icon (display, icon);

	/*Adiciona as fontes*/
	ALLEGRO_FONT *fonte = al_load_font ("./fonte_st.ttf", 30, 0);

	/*Carrega sprites dos personagens*/
	ALLEGRO_BITMAP *ryu = al_load_bitmap ("./ryu_official.png");
	ALLEGRO_BITMAP *menuRyu = al_load_bitmap ("./menu_ryu.png");
	ALLEGRO_BITMAP *ryuCansado = al_load_bitmap ("./ryu_derrotado.png");

	ALLEGRO_BITMAP *ken	= al_load_bitmap ("./ken_official.png");
	ALLEGRO_BITMAP *menuKen = al_load_bitmap ("./menu_ken.png");
	ALLEGRO_BITMAP *kenCansado = al_load_bitmap ("./ken_derrotado.png");

	ALLEGRO_BITMAP *chunli = al_load_bitmap ("./chunli_official.png");
	ALLEGRO_BITMAP *menuChun = al_load_bitmap ("./menu_chunli.png");
	ALLEGRO_BITMAP *chunliCansada = al_load_bitmap ("./chunli_derrotada.png");

	ALLEGRO_BITMAP *feilong = al_load_bitmap ("./feilong_official.png");
	ALLEGRO_BITMAP *menuFeil = al_load_bitmap ("./menu_feilong.png");
	ALLEGRO_BITMAP *feilongCansado = al_load_bitmap ("./feilong_derrotado.png");

	ALLEGRO_BITMAP *cansados[4] = {ryuCansado, kenCansado, chunliCansada, feilongCansado};
	ALLEGRO_BITMAP *personagem1[4] = {menuRyu, menuKen, menuChun, menuFeil};
	ALLEGRO_BITMAP *sprites[4] = {ryu, ken, chunli, feilong};

	/*Cenários*/
	ALLEGRO_BITMAP *mapa = al_load_bitmap ("./mapa.png");
	ALLEGRO_BITMAP *cenario1 = al_load_bitmap ("./cenario1.png");
	ALLEGRO_BITMAP *cenario2 = al_load_bitmap ("./cenario2.png");
	ALLEGRO_BITMAP *cenario3 = al_load_bitmap ("./cenario3.png");
	ALLEGRO_BITMAP *cenario4 = al_load_bitmap ("./cenario4.png");
	ALLEGRO_BITMAP *cenarios[4] = {cenario1, cenario2, cenario3, cenario4};

	/*Inicializa o Menu*/
	menu_t *menu = IniMenu (personagem1, cenarios, cansados, sprites, mapa);

	/*Relógio*/
	ALLEGRO_TIMER *timer = al_create_timer (1.0 / 10.0);
	ALLEGRO_TIMER *timer_menu = al_create_timer (1.0 / 10.0);

	/*Cria a fila de eventos*/
	ALLEGRO_EVENT_QUEUE *event_menu = al_create_event_queue ();
	al_register_event_source (event_menu, al_get_display_event_source (display));
    al_register_event_source (event_menu, al_get_timer_event_source (timer_menu));
    al_register_event_source (event_menu, al_get_keyboard_event_source ());
	al_start_timer (timer_menu);

	int jogando = 1;
	int loading_menu = 1;
	int display_largura = al_get_display_width (display);
    int display_altura = al_get_display_height (display);
	
	/*Zera a reprodução de todas as músicas*/
	al_set_audio_stream_playing (menu->menu_musica, 0);
	al_set_audio_stream_playing (menu->rodada_musica, 0);
    al_set_audio_stream_playing (menu->seleciona_player_musica, 0);

	/*Laço da tela de início*/
	ALLEGRO_EVENT menu_events;
	while (loading_menu)
	{	
		al_wait_for_event (event_menu, &menu_events);
		al_set_audio_stream_playing (menu->menu_musica, 1);

		if (menu_events.keyboard.keycode == ALLEGRO_KEY_SPACE) loading_menu = 0;
		else if (menu_events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			loading_menu = 0;
			jogando = 0;
		}
		else if (menu_events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			loading_menu = 0; 
			jogando = 0;
		}
		else if (menu_events.type == ALLEGRO_EVENT_TIMER)
		{
			al_draw_bitmap (icon, 500, 0, 0);
			al_flip_display ();
		}
		else if (menu_events.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			al_set_audio_stream_playing(menu->menu_musica, 0);
			break;
		}
	}

	/*Escolha dos personagens e
	 *escolha dos cenários*/
    while (menu->loading_menu)
		apresenta_menu_players_cenarios (menu, menu_events, event_menu, fonte);

	al_draw_bitmap (menu->cenario, 0, 0, 0);
	al_flip_display ();

	/*Inicia a fila de eventos e o timer do laço principal*/
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue ();
	al_register_event_source (event_queue, al_get_display_event_source (display));
	al_register_event_source (event_queue, al_get_timer_event_source (timer));
	al_register_event_source (event_queue, al_get_keyboard_event_source ());
	al_start_timer (timer);

	/*Controle da animação*/
	int vida1 = 0, vida2 = 0;

	al_flush_event_queue (event_menu);

	ALLEGRO_EVENT event; 
	while (jogando || menu->loading_menu)
	{
		al_wait_for_event (event_queue, &event);

		if (!menu->loading_menu)
			al_set_audio_stream_playing (menu->rodada_musica, 1);
		else
			al_set_audio_stream_playing (menu->rodada_musica, 0);

		if (menu->loading_menu == 0) al_flush_event_queue (event_menu);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			jogando = 0;
			menu->loading_menu = 0;
		}
		else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
            jogando = 0;
			menu->loading_menu = 0;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER)
		{
			vida1 = verifica_vida (menu->player1);
            vida2 = verifica_vida (menu->player2);

			if ((vida1 || vida2) && (!menu->loading_menu))
			{
				restaura_vida (menu->player1);
                restaura_vida (menu->player2);

				menu->rodadas = 0;
			}

			if ((!vida1) && (!vida2))
			{
				atualiza_posicao (menu->player1, menu->player2, event);
				atualiza_ataque (menu->player1, menu->player2);
				inverte_players (menu->player1, menu->player2);

				al_draw_bitmap (menu->cenario, 0, 0, 0);
				
				if (menu->selecionado1 && menu->selecionado2 && menu->cansado1 && menu->cansado2)
					barra_de_vida (menu->player1, menu->player2, menu->selecionado1, menu->selecionado2, menu->cansado1, menu->cansado2);
				
				vida1 = verifica_vida (menu->player1);
				vida2 = verifica_vida (menu->player2);
				player_morreu (menu->player1);
				player_morreu (menu->player2);
			

				player_em_alerta (menu->player1);
				player_em_alerta (menu->player2);
			}

			if (menu->selecionado1 && menu->selecionado2)
			{
				desenha_player (menu->player1, menu->player1->flag);
				desenha_player (menu->player2, menu->player2->flag);
				desenha_projetil (menu->player1, ryu);
				desenha_projetil (menu->player2, ryu);
			}

			if (vida1)
			{
				menu->rodadas++;
				menu->player2->vitorias++;
                al_draw_text (fonte, al_map_rgb (0, 0, 0), display_largura/2, display_altura/2, ALLEGRO_ALIGN_CENTRE,
                            "Batalha - FIM - VENCEDOR: PLAYER 2");
			}
			else if (vida2)
			{
				menu->rodadas++;
				menu->player1->vitorias++;
				al_draw_text (fonte, al_map_rgb (0, 0, 0), display_largura/2, display_altura/2, ALLEGRO_ALIGN_CENTRE,
                                    "Batalha - FIM - VENCEDOR: PLAYER 1");
			}

			if ((vida1 || vida2) && (menu->rodadas <= 2))
			{
				if ((menu->contador + 1) > 3) menu->contador = 0;
				else menu->contador++;

				menu->cenario = menu->cenarios[menu->contador];

				restaura_vida (menu->player1);
                restaura_vida (menu->player2);
                menu->player1->pos_x = 1700;
                menu->player2->pos_x = 20;
				estado_inicial (menu->player1, 1);
                estado_inicial (menu->player2, 0);

				al_flip_display ();

				al_rest (3);
				al_flush_event_queue (event_queue);
			}

			if (menu->rodadas >= 3)
			{
				menu->rodadas = 0;
				if (menu->player1->vitorias > menu->player2->vitorias)
				{
					al_draw_text (fonte, al_map_rgb (0, 0, 0), display_largura/2, display_altura/2 + 50, ALLEGRO_ALIGN_CENTRE,
                                    "VENCEDOR - PLAYER 1");
				}
				else
				{
					al_draw_text (fonte, al_map_rgb (0, 0, 0), display_largura/2, display_altura/2 + 50, ALLEGRO_ALIGN_CENTRE,
                                    "VENCEDOR - PLAYER 2");
				}

				al_flip_display ();

				al_rest (3);
				al_flush_event_queue (event_queue);
				
				estado_inicial (menu->player1, 1);
                estado_inicial (menu->player2, 0);

				menu->selecionado1 = NULL;
				menu->selecionado2 = NULL;
				menu->cansado1 = NULL;
				menu->cansado2 = NULL;
				menu->cenario = NULL;

				vida1 = 0;
				vida2 = 0;

				menu->loading_menu = 1;

				al_flush_event_queue (event_menu);
			}

			if (!menu->selecionado1 || !menu->selecionado2 || !menu->cenario)
			{
				apresenta_menu_players_cenarios (menu, menu_events, event_menu, fonte);
				al_flip_display ();
			}

			al_flip_display ();
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN || event.type == ALLEGRO_EVENT_KEY_UP)
		{
			/*Movimentação padrão e golpes*/
			if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) joystick_left (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) joystick_right (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_UP) joystick_up (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_DOWN) joystick_down (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_P) joystick_punch (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) joystick_kick (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_L) joystick_kick2 (menu->player1->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) joystick_special (menu->player1->control);

			if (event.keyboard.keycode == ALLEGRO_KEY_D) joystick_right (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_A) joystick_left (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_W) joystick_up (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_S) joystick_down (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_TAB) joystick_punch (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_Q) joystick_kick (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_E) joystick_kick2 (menu->player2->control);
			if (event.keyboard.keycode == ALLEGRO_KEY_Z) joystick_special (menu->player2->control);
		}

	}

	/*Para a reprodução das músicas*/
	al_set_audio_stream_playing (menu->menu_musica, 0);
	al_set_audio_stream_playing (menu->rodada_musica, 0);
	al_set_audio_stream_playing (menu->seleciona_player_musica, 0);

	/*Destroi os arquivos de áudio*/
	al_destroy_audio_stream (menu->menu_musica);
	al_destroy_audio_stream (menu->rodada_musica);
	al_destroy_audio_stream (menu->seleciona_player_musica);

	/*Jogadores*/
	destroi_player (menu->player1);
	destroi_player (menu->player2);
	al_destroy_bitmap (menuRyu);
	al_destroy_bitmap (menuKen);
	al_destroy_bitmap (menuChun);
	al_destroy_bitmap (menuFeil);
	al_destroy_bitmap (ryuCansado);
	al_destroy_bitmap (kenCansado);
	al_destroy_bitmap (chunliCansada);
	al_destroy_bitmap (feilongCansado);

	/*Cenários*/
	al_destroy_bitmap (mapa);
	al_destroy_bitmap (icon);
	al_destroy_bitmap (cenario1);
	al_destroy_bitmap (cenario2);
	al_destroy_bitmap (cenario3);
	al_destroy_bitmap (cenario4);

	/*Demais estruturas*/
	al_destroy_display (display);
	al_destroy_font (fonte);
	al_destroy_event_queue (event_queue);
	al_destroy_event_queue (event_menu);
	al_destroy_timer (timer);
	al_destroy_timer (timer_menu);
	al_uninstall_keyboard ();
	al_uninstall_audio ();
}
