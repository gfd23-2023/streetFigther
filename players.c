#include "players.h"

/*MOVIMENTAÇÃO BÁSICA DOS JOGADORES*/

//al_draw_scaled_bitmap (ALLEGRO_BITMAP *sprite, float sx, float sy, float sw, float sh, float dx, float dy, float dw, float dw, int flags);
//al_draw_bitmap_region (ALLEGRO_BITMAO *sprite, float sx, float sy, float sw, float sh, float dx, float dy, int flags);
// frame = (frame + 1) % (qunatidade de sprites);

mapa_sprite** preenche_matriz (int i, player_t *player)
{
	/*Ryu e Ken*/
	if ((i == 0) || (i == 1))
	{
		/*Parado - largura = 50 - altura = 100*/
	    player->mapa[0][0].frame_x = 0;
		player->mapa[0][0].frame_y = 10;
		player->mapa[0][0].altura = 90;
		player->mapa[0][0].largura = 50;

	    player->mapa[0][1].frame_x = 50;
		player->mapa[0][1].frame_y = 10;
		player->mapa[0][1].altura = 90;
        player->mapa[0][1].largura = 50;

	    player->mapa[0][2].frame_x = 100;
		player->mapa[0][2].frame_y = 10;
		player->mapa[0][2].altura = 90;
        player->mapa[0][2].largura = 50;

	    player->mapa[0][3].frame_x = 150;
		player->mapa[0][3].frame_y = 10;
		player->mapa[0][3].altura = 90;
        player->mapa[0][3].largura = 50;

//		player1->hurtbox->x = 6;
//        player1->hurtbox->y = 105; 
//        player1->hurtbox->altura = 77;
//        player1->hurtbox->largura = 37;

		/*Andando - largura = 50 - altura = 90*/
	    player->mapa[1][0].frame_x = 0;
		player->mapa[1][0].frame_y = 100;
		player->mapa[1][0].altura = 90;
        player->mapa[1][0].largura = 50;

	    player->mapa[1][1].frame_x = 50;
		player->mapa[1][1].frame_y = 100;
		player->mapa[1][1].altura = 90;
        player->mapa[1][1].largura = 50;

	    player->mapa[1][2].frame_x = 100;
		player->mapa[1][2].frame_y = 100;
		player->mapa[1][2].altura = 90;
        player->mapa[1][2].largura = 50;

	    player->mapa[1][3].frame_x = 150;
		player->mapa[1][3].frame_y = 100;
		player->mapa[1][3].altura = 90;
        player->mapa[1][3].largura = 50;

	    /*Pulando - largura = 50 - altura = 95*/
		player->mapa[2][0].frame_x = 0;
	    player->mapa[2][0].frame_y = 200;
		player->mapa[2][0].altura = 95;
        player->mapa[2][0].largura = 50;

		player->mapa[2][1].frame_x = 50;
	    player->mapa[2][1].frame_y = 200;
		player->mapa[2][1].altura = 95;
        player->mapa[2][1].largura = 50;

	    player->mapa[2][2].frame_x = 100;
		player->mapa[2][2].frame_y = 200;
		player->mapa[2][2].altura = 95;
        player->mapa[2][2].largura = 50;

	    /*Agachando - largura = 50 - altura = 80*/
		player->mapa[3][0].frame_x = 0;
		player->mapa[3][0].frame_y = 292;
		player->mapa[3][0].altura = 80;
        player->mapa[3][0].largura = 50;

	    /*Socando - largura = 75 - altura = 90*/
		player->mapa[4][0].frame_x = 0;
	    player->mapa[4][0].frame_y = 370;
		player->mapa[4][0].altura = 90;
        player->mapa[4][0].largura = 75;

		/*Chute 1 - largura = 80 - altura = 90*/
	    player->mapa[5][0].frame_x = 0;
	    player->mapa[5][0].frame_y = 460;
		player->mapa[5][0].altura = 90;
        player->mapa[5][0].largura = 80;

	    player->mapa[5][1].frame_x = 80;
		player->mapa[5][1].frame_y = 460;
		player->mapa[5][1].altura = 90;
        player->mapa[5][1].largura = 80;

	    /*Chute 2 - largura = 80 - altura = 95*/
		player->mapa[6][0].frame_x = 0;
	    player->mapa[6][0].frame_y = 555;
		player->mapa[6][0].altura = 95;
        player->mapa[6][0].largura = 80;

		player->mapa[6][1].frame_x = 80;
	    player->mapa[6][1].frame_y = 552;
		player->mapa[6][1].altura = 95;
        player->mapa[6][1].largura = 80;

		player->mapa[6][2].frame_x = 160;
	    player->mapa[6][2].frame_y = 535;
		player->mapa[6][2].altura = 95;
        player->mapa[6][2].largura = 80;

		player->mapa[6][3].frame_x = 80;
	    player->mapa[6][3].frame_y = 552;
		player->mapa[6][3].altura = 95;
        player->mapa[6][3].largura = 80;

		player->mapa[6][4].frame_x = 0;
	    player->mapa[6][4].frame_y = 555;
		player->mapa[6][4].altura = 95;
        player->mapa[6][4].largura = 80;

		/*Especial - largura = 80 - altura = 90*/
		player->mapa[7][0].frame_x = 4;
		player->mapa[7][0].frame_y = 650;
		player->mapa[7][0].largura = 80;
		player->mapa[7][0].altura = 90;

		player->mapa[7][1].frame_x = 83;
        player->mapa[7][1].frame_y = 650;
        player->mapa[7][1].largura = 80;
        player->mapa[7][1].altura = 90;

	    /*Projétil - largura = 50 - altura = 60*/
		player->mapa[8][0].frame_x = 0;
	    player->mapa[8][0].frame_y = 750;
		player->mapa[8][0].altura = 60;
        player->mapa[8][0].largura = 50;

		player->mapa[8][1].frame_x = 60;
	    player->mapa[8][1].frame_y = 750;
		player->mapa[8][1].altura = 60;
        player->mapa[8][1].largura = 50;

		player->mapa[8][2].frame_x = 455;
	    player->mapa[8][2].frame_y = 750;
		player->mapa[8][2].altura = 60;
        player->mapa[8][2].largura = 50;

		/*Levando Dano - largura = 65 - altura = 90*/
	    player->mapa[9][0].frame_x = 0;
		player->mapa[9][0].frame_y = 810;
		player->mapa[9][0].altura = 90;
        player->mapa[9][0].largura = 65;

	    player->mapa[9][1].frame_x = 65;
		player->mapa[9][1].frame_y = 810;
		player->mapa[9][1].altura = 90;
        player->mapa[9][1].largura = 65;

		/*Caindo - largura = 80 - altura = 80*/
	    player->mapa[10][0].frame_x = 0;
		player->mapa[10][0].frame_y = 900;
		player->mapa[10][0].altura = 80;
        player->mapa[10][0].largura = 80;

	    player->mapa[10][1].frame_x = 80;
		player->mapa[10][1].frame_y = 900;
		player->mapa[10][1].altura = 80;
        player->mapa[10][1].largura = 80;

	    player->mapa[10][2].frame_x = 150;
		player->mapa[10][2].frame_y = 900;
		player->mapa[10][2].altura = 80;
        player->mapa[10][2].largura = 80;

	    player->mapa[10][3].frame_x = 250;
		player->mapa[10][3].frame_y = 900;
		player->mapa[10][3].altura = 80;
        player->mapa[10][3].largura = 80;

	    /*Vencedor - largura = 50 - altura = 121*/
		player->mapa[11][0].frame_x = 0;
	    player->mapa[11][0].frame_y = 1000;
		player->mapa[11][0].altura = 121;
        player->mapa[11][0].largura = 50;

		player->mapa[11][1].frame_x = 50;
	    player->mapa[11][1].frame_y = 1000;
		player->mapa[11][1].altura = 121;
        player->mapa[11][1].largura = 50;
	}

	/*Chun Li*/
	if (i == 2)
	{
		/*Parada*/
		player->mapa[0][0].frame_x = 10;
        player->mapa[0][0].frame_y = 9;
		player->mapa[0][0].altura = 80;
        player->mapa[0][0].largura = 50;

		player->mapa[0][1].frame_x = 64;
        player->mapa[0][1].frame_y = 9;
		player->mapa[0][1].altura = 80;
		player->mapa[0][1].largura = 50;

		player->mapa[0][2].frame_x = 115;
        player->mapa[0][2].frame_y = 9;
        player->mapa[0][2].altura = 80;
        player->mapa[0][2].largura = 50;

		player->mapa[0][3].frame_x = 169;
        player->mapa[0][3].frame_y = 9;
        player->mapa[0][3].altura = 80;
        player->mapa[0][3].largura = 50;

		/*Andando*/
		player->mapa[1][0].frame_x = 12;
        player->mapa[1][0].frame_y = 105;
        player->mapa[1][0].altura = 80;
        player->mapa[1][0].largura = 50;

		player->mapa[1][1].frame_x = 70;
        player->mapa[1][1].frame_y = 105;
        player->mapa[1][1].altura = 80;
        player->mapa[1][1].largura = 50;

		player->mapa[1][2].frame_x = 123;
        player->mapa[1][2].frame_y = 105;
        player->mapa[1][2].altura = 80;
        player->mapa[1][2].largura = 50;

		player->mapa[1][3].frame_x = 188;
        player->mapa[1][3].frame_y = 105;
        player->mapa[1][3].altura = 80;
        player->mapa[1][3].largura = 50;

		/*Pulando*/
		player->mapa[2][0].frame_x = 16;
        player->mapa[2][0].frame_y = 204;
        player->mapa[2][0].altura = 95;
        player->mapa[2][0].largura = 36;

		player->mapa[2][1].frame_x = 54;
        player->mapa[2][1].frame_y = 204;
        player->mapa[2][1].altura = 60;
        player->mapa[2][1].largura = 36;

		player->mapa[2][0].frame_x = 16;
        player->mapa[2][0].frame_y = 204;
        player->mapa[2][0].altura = 95;
        player->mapa[2][0].largura = 36;

		/*Agachando*/
		player->mapa[3][0].frame_x = 5;
        player->mapa[3][0].frame_y = 300;
        player->mapa[3][0].altura = 86;
        player->mapa[3][0].largura = 50;

		/*Socando*/
		player->mapa[4][0].frame_x = 155;
        player->mapa[4][0].frame_y = 387;
        player->mapa[4][0].altura = 80;
        player->mapa[4][0].largura = 82;

		/*Chute 1*/
		player->mapa[5][0].frame_x = 264;
        player->mapa[5][0].frame_y = 590;
        player->mapa[5][0].altura = 80;
        player->mapa[5][0].largura = 53;

		player->mapa[5][1].frame_x = 323;
        player->mapa[5][1].frame_y = 590;
        player->mapa[5][1].altura = 80;
        player->mapa[5][1].largura = 90;

		/*Chute 2*/
		player->mapa[6][0].frame_x = 15;
        player->mapa[6][0].frame_y = 590;
        player->mapa[6][0].altura = 80;
        player->mapa[6][0].largura = 45;

		player->mapa[6][1].frame_x = 71;
        player->mapa[6][1].frame_y = 590;
        player->mapa[6][1].altura = 80;
        player->mapa[6][1].largura = 47;

		player->mapa[6][2].frame_x = 123;
        player->mapa[6][2].frame_y = 590;
        player->mapa[6][2].altura = 80;
        player->mapa[6][2].largura = 76;

		player->mapa[6][3].frame_x = 203;
        player->mapa[6][3].frame_y = 590;
        player->mapa[6][3].altura = 80;
        player->mapa[6][3].largura = 53;

		player->mapa[6][4].frame_x = 15;
        player->mapa[6][4].frame_y = 590;
        player->mapa[6][4].altura = 80;
        player->mapa[6][4].largura = 45;

		/*Especial (não vai ficar aqui)*/
		player->mapa[7][0].frame_x = 65;
		player->mapa[7][0].frame_y = 710;
		player->mapa[7][0].largura = 60;
		player->mapa[7][0].altura  = 90;

		player->mapa[7][1].frame_x = 185;
        player->mapa[7][1].frame_y = 710;
        player->mapa[7][1].largura = 65;
        player->mapa[7][1].altura  = 90;

		/*Levando Dano*/
		player->mapa[9][1].frame_x = 76;
        player->mapa[9][1].frame_y = 831;
        player->mapa[9][1].altura = 74;
        player->mapa[9][1].largura = 60;

		/*Caindo*/
		player->mapa[10][0].frame_x = 25;
        player->mapa[10][0].frame_y = 928;
        player->mapa[10][0].altura = 52;
        player->mapa[10][0].largura = 50;

		player->mapa[10][1].frame_x = 83;
        player->mapa[10][1].frame_y = 919;
        player->mapa[10][1].altura = 62;
        player->mapa[10][1].largura = 56;

		player->mapa[10][2].frame_x = 144;
        player->mapa[10][2].frame_y = 919;
        player->mapa[10][2].altura = 62;
        player->mapa[10][2].largura = 55;

		player->mapa[10][3].frame_x = 205;
        player->mapa[10][3].frame_y = 954;
        player->mapa[10][3].altura = 32;
        player->mapa[10][3].largura = 80;

		/*Vencedora*/
		player->mapa[11][0].frame_x = 20;
        player->mapa[11][0].frame_y = 1048;
        player->mapa[11][0].altura = 92;
        player->mapa[11][0].largura = 45;

		player->mapa[11][1].frame_x = 124;
        player->mapa[11][1].frame_y = 1002;
        player->mapa[11][1].altura = 88;
        player->mapa[11][1].largura = 48;
	}

	/*Fei Long*/
	if (i == 3)
	{
		/*Parado*/
		player->mapa[0][0].frame_x = 4;
		player->mapa[0][0].frame_y = 4;
		player->mapa[0][0].altura = 81;
		player->mapa[0][0].largura = 50;

		player->mapa[0][1].frame_x = 60;
        player->mapa[0][1].frame_y = 4;
        player->mapa[0][1].altura = 81;
        player->mapa[0][1].largura = 50;

		player->mapa[0][2].frame_x = 115;
        player->mapa[0][2].frame_y = 4;
        player->mapa[0][2].altura = 81;
        player->mapa[0][2].largura = 50;

		player->mapa[0][3].frame_x = 175;
        player->mapa[0][3].frame_y = 4;
        player->mapa[0][3].altura = 81;
        player->mapa[0][3].largura = 50;

		/*Andando*/
		player->mapa[1][0].frame_x = 7;
        player->mapa[1][0].frame_y = 111;
        player->mapa[1][0].altura = 90;
        player->mapa[1][0].largura = 50;

		player->mapa[1][1].frame_x = 53;
        player->mapa[1][1].frame_y = 111;
        player->mapa[1][1].altura = 90;
        player->mapa[1][1].largura = 42;

		player->mapa[1][2].frame_x = 100;
        player->mapa[1][2].frame_y = 111;
        player->mapa[1][2].altura = 90;
        player->mapa[1][2].largura = 45;

		player->mapa[1][3].frame_x = 147;
        player->mapa[1][3].frame_y = 111;
        player->mapa[1][3].altura = 88;
        player->mapa[1][3].largura = 42;

		/*Pulando*/
		player->mapa[2][0].frame_x = 10;
        player->mapa[2][0].frame_y = 210;
        player->mapa[2][0].altura = 90;
        player->mapa[2][0].largura = 30;

		player->mapa[2][1].frame_x = 60;
        player->mapa[2][1].frame_y = 220;
        player->mapa[2][1].altura = 50;
        player->mapa[2][1].largura = 32;

		player->mapa[2][2].frame_x = 10;
        player->mapa[2][2].frame_y = 210;
        player->mapa[2][2].altura = 90;
        player->mapa[2][2].largura = 30;

		/*Agachando*/
		player->mapa[3][0].frame_x = 5;
        player->mapa[3][0].frame_y = 304;
        player->mapa[3][0].altura = 90;
        player->mapa[3][0].largura = 48;

		/*Socando*/
		player->mapa[4][0].frame_x = 130;
        player->mapa[4][0].frame_y = 408;
        player->mapa[4][0].altura = 90;
        player->mapa[4][0].largura = 65;

		/*Chute 1*/
		player->mapa[5][0].frame_x = 0;
        player->mapa[5][0].frame_y = 517;
        player->mapa[5][0].altura = 282;
        player->mapa[5][0].largura = 46;

		player->mapa[5][1].frame_x = 133;
        player->mapa[5][1].frame_y = 502;
        player->mapa[5][1].altura = 105;
        player->mapa[5][1].largura = 65;

		/*Chute 2*/
		player->mapa[6][0].frame_x = 6;
        player->mapa[6][0].frame_y = 628;
        player->mapa[6][0].altura = 93;
        player->mapa[6][0].largura = 63;

		player->mapa[6][1].frame_x = 75;
        player->mapa[6][1].frame_y = 625;
        player->mapa[6][1].altura = 89;
        player->mapa[6][1].largura = 57;

		player->mapa[6][2].frame_x = 135;
        player->mapa[6][2].frame_y = 653;
        player->mapa[6][2].altura = 52;
        player->mapa[6][2].largura = 80;

		player->mapa[6][3].frame_x = 220;
        player->mapa[6][3].frame_y = 637;
        player->mapa[6][3].altura = 83;
        player->mapa[6][3].largura = 70;

		player->mapa[6][4].frame_x = 293;
        player->mapa[6][4].frame_y = 649;
        player->mapa[6][4].altura = 62;
        player->mapa[6][4].largura = 42;

		/*Especial (não vai ficar aqui)*/

		/*Levando Dano*/
		player->mapa[9][1].frame_x = 62;
        player->mapa[9][1].frame_y = 744;
        player->mapa[9][1].altura = 75;
        player->mapa[9][1].largura = 50;

		/*Caindo*/
		player->mapa[10][0].frame_x = 12;
        player->mapa[10][0].frame_y = 845;
        player->mapa[10][0].altura = 76;
        player->mapa[10][0].largura = 43;

		player->mapa[10][1].frame_x = 70;
        player->mapa[10][1].frame_y = 852;
        player->mapa[10][1].altura = 65;
        player->mapa[10][1].largura = 55;

		player->mapa[10][2].frame_x = 128;
        player->mapa[10][2].frame_y = 855;
        player->mapa[10][2].altura = 55;
        player->mapa[10][2].largura = 62;

		player->mapa[10][3].frame_x = 197;
        player->mapa[10][3].frame_y = 898;
        player->mapa[10][3].altura = 30;
        player->mapa[10][3].largura = 73;
	}

	return player->mapa;
}

player_t* init_player (ALLEGRO_BITMAP *spritesheet, short int frame_x, short int frame_y, short int l, short int h, short int px, float py, int flag, int i)
{
	if (px < 0 || (px + l) > MAX_X || (py + h) > MAX_Y || py < 0)
	{
		printf ("Tentativa de criar jogador fora do display\n");
		return NULL;
	}

	player_t *player;

	player = malloc (sizeof (player_t));
	if (!player)
	{
		printf ("Erro ao alocar memória para o jogador\n");
		return NULL;
	}

	player->id = i;
	player->sprite = spritesheet;
	player->frame_atual_x = frame_x;
	player->frame_atual_y = frame_y;
	player->anima = 0;
	player->largura = l;
	player->altura = h;	
	player->pos_x = px;
	player->pos_y = py;
	player->velocidade_y = IMPULSO;
	player->no_chao = 1;
	player->flag = flag;
	player->vitorias = 0;
	player->vida = 100;
	player->movimento_iniciado = 0;

	player->hitbox = malloc (sizeof (hitbox_t));
	player->hurtbox = malloc (sizeof (hurtbox_t));
	if (!player->hitbox || !player->hurtbox)
	{
		printf ("Erro ao alocar caixas\n");
		return NULL;
	}

	player->hitbox->x = 0;
	player->hitbox->y = 0;
	player->hitbox->altura = 0;
	player->hitbox->largura = 0;
	player->hurtbox->x = 0;
	player->hurtbox->y = 0;
	player->hurtbox->altura = 0;
	player->hurtbox->largura = 0;
	player->especial_iniciado = 0;

	player->control = joystick_create ();

	player->projetil = malloc (sizeof (projetil_t));
	player->projetil->x = player->pos_x;
	player->projetil->y = player->pos_y;

	player->mapa = malloc (sizeof (mapa_sprite*) * 12);
	for (int i = 0; i < 12; i++)
		player->mapa[i] = malloc (sizeof (mapa_sprite) * 5);
	
	player->mapa = preenche_matriz (i, player);

	return player;
}

void estado_inicial (player_t *player, int flag)
{
	player->control->punch = 0;
	player->control->kick = 0;
	player->control->kick2 = 0;
	player->control->special = 0;
	player->control->hurted = 0;
	player->flag = flag;

//	player->anima = 0;
	player->movimento_iniciado = 0;
}

void movimenta_player (player_t *player, short int deslocamento, short int trajetoria, short int max_x, short int max_y, ALLEGRO_EVENT event)
{
	if (trajetoria == 0)		/*Esquerda*/
	{
		/*Controla o avanço na spritesheet*/
		if (player->no_chao) 
		{
			if (player->anima > 3) player->anima = 0;
			
			player->largura = player->mapa[1][player->anima].largura;
            player->altura = player->mapa[1][player->anima].altura;

			player->frame_atual_x = player->mapa[1][player->anima].frame_x;
			player->frame_atual_y = player->mapa[1][player->anima].frame_y;

			player->anima++;
		}

		if (((player->pos_x - deslocamento) * PASSO) >= 0) player->pos_x = player->pos_x - deslocamento * PASSO;
		else player->pos_x = 0;
	}
	else if (trajetoria == 1)	/*Direita*/
	{
		/*Controla o avanço na spritesheet*/
		if (player->no_chao)
        {
			if (player->anima > 3) player->anima = 0;

			player->largura = player->mapa[1][player->anima].largura;
            player->altura = player->mapa[1][player->anima].altura;

			player->frame_atual_x = player->mapa[1][player->anima].frame_x;
			player->frame_atual_y = player->mapa[1][player->anima].frame_y;

			player->anima++;
        }

		if (((player->pos_x + 4*player->largura) + deslocamento * PASSO) <= max_x) player->pos_x = player->pos_x + deslocamento * PASSO;
		else player->pos_x = max_x - 4*player->largura;
	}
	else if (trajetoria == 2)	/*Para cima*/
	{
		if (!player->no_chao)
		{
			player->velocidade_y = player->velocidade_y + 5*GRAVIDADE;
			player->pos_y = player->pos_y + 3*player->velocidade_y;

			if (player->velocidade_y == 0)
			{
				player->frame_atual_x = player->mapa[2][1].frame_x;
				player->frame_atual_y = player->mapa[2][1].frame_y;
			}

			if (player->control->down)
			{
				player->pos_y = CHAO;
				player->no_chao = 1;
			}

			if (player->velocidade_y == -IMPULSO || ((player->pos_y + player->velocidade_y) > CHAO))	//player->pos_y >= CHAO
			{
				player->pos_y = CHAO;
				player->no_chao = 1;
			}
		}
	}
	if (trajetoria == 3)	/*Para baixo*/
	{
		player->altura = player->mapa[3][0].altura;
		player->frame_atual_x = player->mapa[3][0].frame_x;
		player->frame_atual_y = player->mapa[3][0].frame_y;
		if (((player->pos_y + 4*player->altura) + deslocamento * PASSO) <= 400) player->pos_y = player->pos_y + deslocamento * PASSO;
		if ((player->pos_y + player->altura) + deslocamento * PASSO > 400) player->pos_y = 500;
	}
}

void atualiza_posicao (player_t *player1, player_t *player2, ALLEGRO_EVENT event)
{
	if (player1->control->left)
	{
		player1->hurtbox->x = 6;
		player1->hurtbox->y = 105;
		player1->hurtbox->altura = 77;
		player1->hurtbox->largura = 37;

		movimenta_player (player1, 3, 0, MAX_X, MAX_Y, event);
		if (colide_players (player1, player2)) movimenta_player (player1, -3, 0, MAX_X, MAX_Y, event);
	}
	if (player1->control->right)
	{
		player1->hurtbox->x = 6;
        player1->hurtbox->y = 105;
        player1->hurtbox->altura = 77;
        player1->hurtbox->largura = 37;

		movimenta_player (player1, 3, 1, MAX_X, MAX_Y, event);
		if (colide_players (player1, player2)) movimenta_player (player1, -3, 1, MAX_X, MAX_Y, event);
	}
	if (player1->control->up && player1->no_chao)
	{
		player1->hurtbox->x = 10;
        player1->hurtbox->y = 200;
        player1->hurtbox->altura = 95;
        player1->hurtbox->largura = 35;

		player1->anima = 0;
		player1->no_chao = 0;
		player1->largura = player1->mapa[2][0].largura;
		player1->altura = player1->mapa[2][0].altura;
		player1->frame_atual_x = player1->mapa[2][0].frame_x;
		player1->frame_atual_y = player1->mapa[2][0].frame_y;
		player1->velocidade_y = IMPULSO;
	}
	if (!player1->no_chao)
	{
		movimenta_player (player1, 1, 2, MAX_X, MAX_Y, event);
		if (colide_players (player1, player2)) movimenta_player (player1, -1, 2, MAX_X, MAX_Y, event);
	}
	if (player1->control->down)	
	{
		movimenta_player (player1, 1, 3, MAX_X, MAX_Y, event);
	}
	if (player2->control->left)
	{
		player2->hurtbox->x = 6;
        player2->hurtbox->y = 105;
        player2->hurtbox->altura = 77;
        player2->hurtbox->largura = 37;

		movimenta_player (player2, 3, 0, MAX_X, MAX_Y, event);
		if (colide_players (player1, player2)) movimenta_player (player2, -3, 0, MAX_X, MAX_Y, event);
	}
	if (player2->control->right)
	{
		player2->hurtbox->x = 6;
        player2->hurtbox->y = 105;
        player2->hurtbox->altura = 77;
        player2->hurtbox->largura = 37;

        movimenta_player (player2, 3, 1, MAX_X, MAX_Y, event);
		if (colide_players (player1, player2)) movimenta_player (player2, -3, 1, MAX_X, MAX_Y, event);
	}
	if (player2->control->up && player2->no_chao)
	{
		player2->hurtbox->x = 10;
        player2->hurtbox->y = 200;
        player2->hurtbox->altura = 95;
        player2->hurtbox->largura = 35;

		player2->anima = 0;
        player2->no_chao = 0;
		player2->largura = player2->mapa[2][0].largura;
		player2->altura = player2->mapa[2][0].altura;
        player2->frame_atual_x = player2->mapa[2][0].frame_x;
		player2->frame_atual_y = player2->mapa[2][0].frame_y;
        player2->velocidade_y = IMPULSO;
	}
	if (!player2->no_chao)
	{
		movimenta_player (player2, 1, 2, MAX_X, MAX_Y, event);
		if (colide_players (player1, player2)) movimenta_player (player2, -1, 2, MAX_X, MAX_Y, event);
	}
	if (player2->control->down)
	{
        movimenta_player (player2, 1, 3, MAX_X, MAX_Y, event);
	}
}

void player_em_alerta (player_t *player)
{
	if ((!player->control->right) && (!player->control->left) && (player->no_chao) && (!player->control->down) && (!player->control->punch) &&
		(!player->control->kick) && (!player->control->kick2) && (!player->control->hurted) && (!player->control->special) && 
		(!player->especial_iniciado) && (player->vida > 0))
	{
		/*COLOCAR OS VALORES DAS HURTBOX E HITBOX*/

		player->pos_y = CHAO;
		if (player->anima > 3) player->anima = 0;
		player->largura = player->mapa[0][player->anima].largura;
        player->altura = player->mapa[0][player->anima].altura;

		/*Volta para o estado inicial do jogador.
		 *Quando isso não é feito, ele fica em um looping do movimeno realizado
		 *até que um outro seja solicitado.*/
		player->frame_atual_x = player->mapa[0][player->anima].frame_x;
		player->frame_atual_y = player->mapa[0][player->anima].frame_y;

		player->anima++;
	}

	if (player->control->hurted) joystick_hurted (player->control);
}

int colide_players (player_t *player1, player_t *player2)
{
	if (((player2->pos_x + player2->largura) > player1->pos_x) && (player2->pos_x < (player1->pos_x + player1->largura))
			&& (player1->pos_y == player2->pos_y)) return 1;

	if ((player2->pos_x < (player1->pos_x + player1->largura)) && ((player2->pos_x + player2->largura) > player1->pos_x)
			&& (player1->pos_y == player2->pos_y)) return 1;

	if	(((player1->pos_y + player1->altura ) > player2->pos_y) && (player1->pos_y < (player2->pos_y + player2->altura ))
			&& (player1->pos_y != player2->pos_y)) return 1;

	if	(((player2->pos_y + player2->altura ) > player1->pos_y) && (player2->pos_y < (player1->pos_y + player1->altura ))
			&& (player1->pos_y != player2->pos_y)) return 1;

	return 0;
}

void desenha_player (player_t *player, int flag)
{
	al_draw_scaled_bitmap (player->sprite, player->frame_atual_x, player->frame_atual_y, player->largura, player->altura,
                            player->pos_x, player->pos_y, 4*player->largura, 4*player->altura, flag);
}

void inverte_players (player_t *player1, player_t *player2)
{
	if (((!player1->no_chao) || (!player2->no_chao)) && player1->pos_x < (player2->pos_x + player2->largura) && player1->flag)
	{
		player1->flag = player1->flag ^ 1;
		player2->flag = player2->flag ^ 1;
	}
	if (((!player1->no_chao) || (!player2->no_chao)) && player1->pos_x > (player2->pos_x + player2->largura) && (!player1->flag))
	{
        player1->flag = player1->flag ^ 1;
        player2->flag = player2->flag ^ 1;
    }
}

void destroi_player (player_t* player)
{
//	al_destroy_bitmap (player->sprite);

    player->frame_atual_x = 0;
    player->frame_atual_y = 0;
    player->largura = 0;
    player->altura = 0;
    player->pos_x = 0;
    player->pos_y = 0;

	joystick_destroy (player->control);

//	for (int i = 0; i < 12; i++)
//		for (int j = 0; j < 5; j++)
//			free (player->mapa[i][j]);

	free (player->hitbox);
	free (player->hurtbox);

	free (player);
}
