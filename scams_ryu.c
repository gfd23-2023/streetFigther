#include "scams_ryu.h"

mapa_sprite* reconhece_golpe_especial (int i)
{
	printf ("id = %d\n", i);
	especiais = malloc (15 * sizeof (mapa_sprite));
	if (!especiais) 
	{
		printf ("erro ao alocar vetor de especiais\n");
		return NULL;
	}

	/*Ryu, Ken, Chun Li - Hadouken (Projétil)*/
	if ((i == 0) || (i == 1) || (i == 2))
	{
		especiais[0].frame_x = 6;
		especiais[0].frame_y = 750;
		especiais[0].largura = 40;
		especiais[0].altura = 50;

		especiais[1].frame_x = 55;
        especiais[1].frame_y = 760;
        especiais[1].largura = 40;
        especiais[1].altura = 30;

		especiais[2].frame_x = 100;
        especiais[2].frame_y = 755;
        especiais[2].largura = 55;
        especiais[2].altura = 30;

		especiais[3].frame_x = 170;
        especiais[3].frame_y = 755;
        especiais[3].largura = 55;
        especiais[3].altura = 30;

		especiais[4].frame_x = 230;
        especiais[4].frame_y = 755;
        especiais[4].largura = 65;
        especiais[4].altura = 30;

		especiais[5].frame_x = 408;
        especiais[5].frame_y = 745;
        especiais[5].largura = 42;
        especiais[5].altura = 55;

		especiais[6].frame_x = 449;
        especiais[6].frame_y = 750;
        especiais[6].largura = 41;
        especiais[6].altura = 50;
	};

	/*Fei Long - Sei lá o nome do golpe*/	
	if (i == 3)
	{
		especiais[0].frame_x = 4;
		especiais[0].frame_y = 1000;
		especiais[0].largura = 58;
		especiais[0].altura = 103;

		especiais[1].frame_x = 67;
        especiais[1].frame_y = 1000;
        especiais[1].largura = 52;
        especiais[1].altura = 103;

		especiais[2].frame_x = 123;
        especiais[2].frame_y = 1000;
        especiais[2].largura = 49;
        especiais[2].altura = 103;

		especiais[3].frame_x = 175;
        especiais[3].frame_y = 1000;
        especiais[3].largura = 77;
        especiais[3].altura = 103;

		especiais[4].frame_x = 259;
        especiais[4].frame_y = 1000;
        especiais[4].largura = 36;
        especiais[4].altura = 103;

		especiais[5].frame_x = 298;
        especiais[5].frame_y = 1000;
        especiais[5].largura = 42;
        especiais[5].altura = 103;

		especiais[6].frame_x = 344;
        especiais[6].frame_y = 1000;
        especiais[6].largura = 47;
        especiais[6].altura = 103;

		especiais[7].frame_x = 395;
        especiais[7].frame_y = 1000;
        especiais[7].largura = 47;
        especiais[7].altura = 103;

		especiais[8].frame_x = 445;
        especiais[8].frame_y = 1000;
        especiais[8].largura = 56;
        especiais[8].altura = 103;

		especiais[9].frame_x = 485;
        especiais[9].frame_y = 1000;
        especiais[9].largura = 42;
        especiais[9].altura = 103;

		especiais[10].frame_x = 123;
        especiais[10].frame_y = 1000;
        especiais[10].largura = 49;
        especiais[10].altura = 103;

		especiais[11].frame_x = 67;
        especiais[11].frame_y = 1000;
        especiais[11].largura = 52;
        especiais[11].altura = 103;
	}

	return especiais;
}


void restaura_vida (player_t *player)
{
	player->vida = 100;
}

int verifica_vida (player_t *player)
{
	if (player->vida <= 0)
	{
		player->anima = 0;
		return 1;
	}

	else return 0;
}

void barra_de_vida (player_t *player1, player_t *player2, ALLEGRO_BITMAP *id1, ALLEGRO_BITMAP *id2, ALLEGRO_BITMAP *cansado1, ALLEGRO_BITMAP *cansado2)
{
	al_draw_rectangle (462, 30, 862, 50, al_map_rgb (0, 0, 0), 2);

	if (!(verifica_vida (player2)))
	{
		if (player2->vida <= 25)
		{
			al_draw_scaled_bitmap (cansado2, 0, 0, 68, 100, 312, 30, 2*70, 2*100, 0);
			al_draw_filled_rectangle (462, 30, 4*player2->vida + 462, 50, al_map_rgb (255, 0, 0));
		}
		else
		{
			al_draw_scaled_bitmap (id2, 0, 0, 68, 100, 312, 30, 2*70, 2*100, 0);
			al_draw_filled_rectangle (462, 30, 4*player2->vida + 462, 50, al_map_rgb (0, 255, 0));
		}
	}
	else 
		al_draw_scaled_bitmap (cansado2, 0, 0, 68, 100, 312, 30, 2*70, 2*100, 0);

    al_draw_rectangle (1062, 30, 1462, 50, al_map_rgb (0, 0, 0), 2);

	if (!(verifica_vida (player1)))
	{
		if (player1->vida <= 25)
		{
			al_draw_scaled_bitmap (cansado1, 0, 0, 68, 100, 1470, 30, 2*70, 2*100, 1);
			al_draw_filled_rectangle (1062, 30, 4*player1->vida + 1062, 50, al_map_rgb (255, 0, 0));
		}
		else
		{
			al_draw_scaled_bitmap (id1, 0, 0, 68, 100, 1470, 30, 2*70, 2*100, 1);
			al_draw_filled_rectangle (1062, 30, 4*player1->vida + 1062, 50, al_map_rgb (0, 255, 0));
		}
	}
	else
		al_draw_scaled_bitmap (cansado1, 0, 0, 68, 100, 1470, 30, 2*70, 2*100, 1);
}

int ataca (player_t *player1, player_t *player2)
{
    int p2_fim;
    int p2_ini;

    int h1_ini;
    int h1_fim;

	if (player1->flag)
	{
		p2_ini = player2->pos_x + player2->hurtbox->x;
	    p2_fim = p2_ini + player2->hurtbox->largura;

		h1_ini = player1->pos_x - player1->hitbox->x;
		h1_fim = h1_ini - player1->hitbox->largura;
	}
	else
	{
		p2_ini = player2->pos_x - player2->hurtbox->x;
        p2_fim = p2_ini - player2->hurtbox->largura;

        h1_ini = player1->pos_x + player1->hitbox->x;
        h1_fim = h1_ini + player1->hitbox->largura;
	}

	if (((h1_ini >= p2_fim) && (h1_ini <= p2_ini)) || (((h1_ini <= p2_fim)) &&  (h1_ini >= p2_ini))) return 1;
	return 0;
}

/*Player1 ataca - Player2 leva dano (ou não)*/
void hadouken (player_t *player1, player_t *player2)
{
	especiais = reconhece_golpe_especial (player1->id);

	player1->projetil->frame_x = especiais[player1->anima].frame_x;
	player1->projetil->frame_y = especiais[player1->anima].frame_y;
	player1->projetil->largura = especiais[player1->anima].largura;
	player1->projetil->altura  = especiais[player1->anima].altura;

	/*Projétil para a direita*/
	if (!player1->flag)		//canto esquerdo da tela
	{
		/*Colidiu com o jogador*/
		if (((player1->projetil->x + player1->projetil->largura) > player2->pos_x) && (player1->projetil->x < player2->pos_x) &&
				(player2->pos_y + player2->altura) > (player1->projetil->y + player1->projetil->altura))
		{
			player1->projetil->frame_x = especiais[6].frame_x;
			player1->projetil->frame_y = especiais[6].frame_y;
			player1->projetil->largura = especiais[6].largura;
			player1->projetil->altura  = especiais[6].altura;

			player2->frame_atual_x = player2->mapa[9][1].frame_x;
            player2->frame_atual_y = player2->mapa[9][1].frame_y;

			if (!player2->control->hurted) joystick_hurted (player2->control);

			if (player2->pos_x - player1->pos_x <= 200) player2->vida = player2->vida - 70;
			else player2->vida = player2->vida - 40;

			player1->movimento_iniciado = 0;
            player1->especial_iniciado = 0;
            player1->vida = player1->vida - 10;
		}
		/*Colidiu com a Tela*/
		else if ((player1->projetil->x + player1->projetil->largura) > MAX_X)
		{
			player1->projetil->frame_x = especiais[6].frame_x;
            player1->projetil->frame_y = especiais[6].frame_y;
            player1->projetil->largura = especiais[6].largura;
            player1->projetil->altura  = especiais[6].altura;

			player1->movimento_iniciado = 0;
            player1->especial_iniciado = 0;
            player1->vida = player1->vida - 10;
		}
		/*Não colidiu com nenhum dos dois*/
		else
			player1->projetil->x = player1->projetil->x + 50;			//deslocamento;
			
	}

	/*Projétil para a esquerda*/
	if (player1->flag)		//canto direito da tela
	{
		/*Colidiu com o jogador*/
		if ((player1->projetil->x < (player2->pos_x + player2->largura)) && (player1->projetil->x > player2->pos_x) &&
				(player2->pos_y + player2->altura) > (player1->projetil->y + player1->projetil->altura))
		{
			player1->projetil->frame_x = especiais[6].frame_x;
            player1->projetil->frame_y = especiais[6].frame_y;
            player1->projetil->largura = especiais[6].largura;
            player1->projetil->altura  = especiais[6].altura;

			player2->frame_atual_x = player2->mapa[9][1].frame_x;
            player2->frame_atual_y = player2->mapa[9][1].frame_y;

            if (!player2->control->hurted) joystick_hurted (player2->control);

            if (player2->pos_x - player1->pos_x <= 200) player2->vida = player2->vida - 70;
            else player2->vida = player2->vida - 40;

			player1->movimento_iniciado = 0;
			player1->especial_iniciado = 0;
			player1->vida = player1->vida - 10;
		}
		/*Colidiu com a tela*/
		else if (player1->projetil->x < 0)
		{
			player1->projetil->frame_x = especiais[6].frame_x;
            player1->projetil->frame_y = especiais[6].frame_y;
            player1->projetil->largura = especiais[6].largura;
            player1->projetil->altura  = especiais[6].altura;

			player1->movimento_iniciado = 0;
            player1->especial_iniciado = 0;
            player1->vida = player1->vida - 10;
		}
		/*Colidiu com nenhum dos dois*/
		else
			player1->projetil->x = player1->projetil->x - 50;
	}

	if (player1->anima < 5) player1->anima++;
	printf ("logo após incrementar = %d\n", player1->anima);

	if (player1->anima == 6)
	{
		printf ("ENTREI \n");
		player1->movimento_iniciado = 0;
		player1->especial_iniciado = 0;
		player1->vida = player1->vida - 10;
	}
}

void desenha_projetil (player_t *player, ALLEGRO_BITMAP *projetil)
{
	if (player->especial_iniciado)
	{
		al_draw_scaled_bitmap (projetil, player->projetil->frame_x, player->projetil->frame_y, player->projetil->largura, player->projetil->altura,
                            player->projetil->x, player->projetil->y, 4*player->projetil->largura, 4*player->projetil->altura, player->flag);
	}
}

void atualiza_ataque (player_t *player1, player_t *player2)
{
	if (player1->control->punch)
	{
		player1->largura = player1->mapa[4][0].largura;
		player1->altura = player1->mapa[4][0].altura;

		player1->hitbox->x = 50;
		player1->hitbox->y = 387;
		player1->hitbox->altura = 6;
		player1->hitbox->largura = 9;

		player1->hurtbox->x = 6;
		player1->hurtbox->y = 373;
		player1->hurtbox->altura = 78;
		player1->hurtbox->largura = 29;

		player1->frame_atual_x = player1->mapa[4][0].frame_x;
		player1->frame_atual_y = player1->mapa[4][0].frame_y;

		if (ataca (player1, player2))
		{
			player2->frame_atual_x = player2->mapa[9][1].frame_x;
			player2->frame_atual_y = player2->mapa[9][1].frame_y;

			if (!player2->control->hurted) joystick_hurted (player2->control);
		
			player2->vida = player2->vida - 2;
		}
	}

	if (player1->control->kick)
	{
		if (player1->anima >= 2) player1->anima = 0;

		player1->largura = player1->mapa[5][player1->anima].largura;
		player1->altura = player1->mapa[5][player1->anima].altura;

		player1->hurtbox->x = 5;
		player1->hurtbox->y = 464;
		player1->hurtbox->altura = 80;
		player1->hurtbox->largura = 38;

		player1->frame_atual_x = player1->mapa[5][player1->anima].frame_x;
		player1->frame_atual_y = player1->mapa[5][player1->anima].frame_y;
		
		if (player1->anima == 1)
		{
			player1->hitbox->x = 143;
			player1->hitbox->y = 464;
			player1->hitbox->altura = 9;
			player1->hitbox->largura = 9;

			player1->hurtbox->x = 85;
			player1->hurtbox->y = 462;
			player1->hurtbox->altura = 82;
			player1->hurtbox->largura = 45;

			if (ataca (player1, player2))
			{
				player2->frame_atual_x = player2->mapa[9][1].frame_x;
				player2->frame_atual_y = player2->mapa[9][1].frame_y;
				player2->vida = player2->vida - 5;
			}
		}

		if (player1->anima < 1) player1->anima++;
        else player1->anima = player1->anima;
	}

	if (player1->control->kick2)
	{
		if (player1->movimento_iniciado >= 5)
            player1->movimento_iniciado = 0;
		if (player2->anima > 3) player2->anima = 0;
		
		player1->largura = player1->mapa[6][player1->movimento_iniciado].largura;
		player1->altura = player1->mapa[6][player1->movimento_iniciado].altura;

		player1->hurtbox->x = 26;
		player1->hurtbox->y = 557;
		player1->hurtbox->altura = 81;
		player1->hurtbox->largura = 30;

		if (player1->movimento_iniciado == 2)	/*TALVEZ PRECISE D EUM ELSE PARA FAZER AS HITBOXES SUMIREM QUANDO != 2*/
		{
			player1->hitbox->x = 214;
			player1->hitbox->y = 535;
			player1->hitbox->altura = 10;
			player1->hitbox->largura = 12;

			player1->hurtbox->x = 195;
			player1->hurtbox->y = 550;
			player1->hurtbox->altura = 91;
			player1->hurtbox->largura = 33;
		}

		player1->frame_atual_x = player1->mapa[6][player1->movimento_iniciado].frame_x;
		player1->frame_atual_y = player1->mapa[6][player1->movimento_iniciado].frame_y;

		if (ataca (player1, player2))
		{
			player2->frame_atual_x = player2->mapa[10][player2->anima].frame_x;
			player2->frame_atual_y = player2->mapa[10][player2->anima].frame_y;
			player2->largura = player2->mapa[10][player2->anima].largura;
			player2->altura = player2->mapa[10][player2->anima].altura;
			player2->anima++;
			player2->vida = player2->vida - 8;
		}

		player1->movimento_iniciado++;
	}

	if (player1->control->special && (!player1->especial_iniciado))
	{
		player1->anima = 0;
		player1->movimento_iniciado = 0;
		player1->especial_iniciado = 1;
		player1->projetil->x = player1->pos_x;
		player1->projetil->y = player1->pos_y + 10;		//ficar um pouco abaixo da cabeça
	}
	if (player1->especial_iniciado)
	{
		if ((player1->id >=0) && (player1->id <= 2))
		{
			if (player1->movimento_iniciado > 1) player1->movimento_iniciado = 0;

			player1->frame_atual_x = player1->mapa[7][player1->movimento_iniciado].frame_x;
			player1->frame_atual_y = player1->mapa[7][player1->movimento_iniciado].frame_y;
			player1->largura = player1->mapa[7][player1->movimento_iniciado].largura;
			player1->altura = player1->mapa[7][player1->movimento_iniciado].altura;

			if (player1->movimento_iniciado < 1) player1->movimento_iniciado++;
		    else player1->movimento_iniciado = player1->movimento_iniciado;

			hadouken (player1, player2);
		}
		else
		{
			especiais = reconhece_golpe_especial (player1->id);

			player1->frame_atual_x = especiais[player1->movimento_iniciado].frame_x;
			player1->frame_atual_y = especiais[player1->movimento_iniciado].frame_y;
			player1->largura = especiais[player1->movimento_iniciado].largura;
			player1->altura = especiais[player1->movimento_iniciado].altura;

			if (player1->movimento_iniciado > 11)
			{
				player1->movimento_iniciado = 0;
				player1->especial_iniciado = 0;
			}

			if (ataca (player1, player2))
			{
				player2->vida = player2->vida - 50;
				player1->vida = player1->vida - 10;
			}

			player1->movimento_iniciado++;
		}
	}

	if (player2->control->punch)
	{
		player2->largura = player2->mapa[4][0].largura;
        player2->altura = player2->mapa[4][0].altura;

		player2->hitbox->x = 50;
		player2->hitbox->y = 387;
		player2->hitbox->altura = 6;
		player2->hitbox->largura = 9;

		player2->hurtbox->x = 6;
        player2->hurtbox->y = 373;
        player2->hurtbox->altura = 78;
        player2->hurtbox->largura = 29;

        player2->frame_atual_x = player2->mapa[4][0].frame_x;
        player2->frame_atual_y = player2->mapa[4][0].frame_y;

		if (ataca (player2, player1))
		{
			player1->frame_atual_x = player1->mapa[9][1].frame_x;
            player1->frame_atual_y = player1->mapa[9][1].frame_y;

            if (!player1->control->hurted) joystick_hurted (player1->control);

			player1->vida = player1->vida -2;
		}
	}

	if (player2->control->kick)
	{
		if (player2->anima >= 2) player2->anima = 0;

        player2->largura = player2->mapa[5][player2->anima].largura;
        player2->altura = player2->mapa[5][player2->anima].altura;
        player2->frame_atual_x = player2->mapa[5][player2->anima].frame_x;
        player2->frame_atual_y = player2->mapa[5][player2->anima].frame_y;

		player2->hurtbox->x = 5;
        player2->hurtbox->y = 464;
        player2->hurtbox->altura = 80;
        player2->hurtbox->largura = 38;

		if (player2->anima == 1)
        {
            player2->hitbox->x = 143;
            player2->hitbox->y = 464;
            player2->hitbox->altura = 9;
            player2->hitbox->largura = 9;

			player2->hurtbox->x = 85;
            player2->hurtbox->y = 462;
            player2->hurtbox->altura = 82;
            player2->hurtbox->largura = 45;

            if (ataca (player2, player1)) player1->vida = player1->vida - 5;
        }

        if (player2->anima < 1) player2->anima++;
        else player2->anima = player2->anima;
	}

	if (player2->control->kick2)
	{
		if (player2->movimento_iniciado >= 5)
            player2->movimento_iniciado = 0;
        
        player2->largura = player2->mapa[6][player2->movimento_iniciado].largura;
        player2->altura = player2->mapa[6][player2->movimento_iniciado].altura;

		player2->hurtbox->x = 26;
        player2->hurtbox->y = 557;
        player2->hurtbox->altura = 81;
        player2->hurtbox->largura = 30;

		if (player2->movimento_iniciado == 2)   /*TALVEZ PRECISE D EUM ELSE PARA FAZER AS HITBOXES SUMIREM QUANDO != 2*/
        {
            player2->hitbox->x = 214;
            player2->hitbox->y = 535;
            player2->hitbox->altura = 10;
            player2->hitbox->largura = 12;

			player2->hurtbox->x = 195;
            player2->hurtbox->y = 550;
            player2->hurtbox->altura = 91;
            player2->hurtbox->largura = 33;
        }

        player2->frame_atual_x = player2->mapa[6][player2->movimento_iniciado].frame_x;
        player2->frame_atual_y = player2->mapa[6][player2->movimento_iniciado].frame_y;

		if (ataca (player2, player1)) player1->vida = player1->vida - 8;

        player2->movimento_iniciado++;
	}

	if (player2->control->special && (!player2->especial_iniciado))
    {
        player2->anima = 0;
        player2->movimento_iniciado = 0;
        player2->especial_iniciado = 1;
        player2->projetil->x = player2->pos_x;
        player2->projetil->y = player2->pos_y + 10;     //ficar um pouco abaixo da cabeça
    }
	if (player2->especial_iniciado)
    {
        if ((player2->id >=0) && (player2->id <= 2))
        {
            if (player2->movimento_iniciado > 1) player2->movimento_iniciado = 0;

            player2->frame_atual_x = player2->mapa[7][player2->movimento_iniciado].frame_x;
            player2->frame_atual_y = player2->mapa[7][player2->movimento_iniciado].frame_y;
            player2->largura = player2->mapa[7][player1->movimento_iniciado].largura;
            player2->altura = player2->mapa[7][player1->movimento_iniciado].altura;

            if (player2->movimento_iniciado < 1) player2->movimento_iniciado++;
            else player2->movimento_iniciado = player2->movimento_iniciado;

            hadouken (player2, player1);
        }
        else
        {
            especiais = reconhece_golpe_especial (player2->id);

            player2->frame_atual_x = especiais[player2->movimento_iniciado].frame_x;
            player2->frame_atual_y = especiais[player2->movimento_iniciado].frame_y;
            player2->largura = especiais[player2->movimento_iniciado].largura;
            player2->altura = especiais[player2->movimento_iniciado].altura;

            if (player2->movimento_iniciado > 11)
            {
                player2->movimento_iniciado = 0;
                player2->especial_iniciado = 0;
            }

            if (ataca (player1, player2))
            {
                player2->vida = player2->vida - 50;
                player1->vida = player1->vida - 10;
            }

            player2->movimento_iniciado++;
        }
    }
}

void player_morreu (player_t *player)
{
	if (player->anima > 3) player->anima = 0;

	if (verifica_vida (player))
	{
		player->largura = player->mapa[10][player->anima].largura;

		player->frame_atual_x = player->mapa[10][player->anima].frame_x;
		player->frame_atual_y = player->mapa[10][player->anima].frame_y;

		player->anima++;
	}
}
