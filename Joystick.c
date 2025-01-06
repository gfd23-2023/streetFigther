#include <stdlib.h>
#include "Joystick.h"

joystick* joystick_create ()
{ 
	joystick *player = malloc (sizeof (joystick));
	if (!player) return NULL;

	player->right = 0;
	player->left = 0;
	player->up = 0;
	player->down = 0;
	player->punch = 0;
	player->kick = 0;
	player->kick2 = 0;
	player->hurted = 0;
	player->special = 0;

	return player;
}

void joystick_right (joystick *player)
{ player->right = player->right ^ 1;}	// ^ é o xor

void joystick_left (joystick *player)
{ player->left = player->left ^ 1;}

void joystick_up (joystick *player)
{ player->up = player->up ^ 1;}

void joystick_down (joystick *player)
{ player->down = player->down ^ 1;}

void joystick_punch (joystick *player)
{ player->punch = player->punch ^ 1;}

void joystick_kick (joystick *player)
{ player->kick = player->kick ^ 1;}

void joystick_kick2 (joystick *player)
{ player->kick2 = player->kick2 ^ 1;}

void joystick_hurted (joystick *player)
{ player->hurted = player->hurted ^ 1;}

void joystick_special (joystick *player)
{	player->special = player->special ^ 1;}

void joystick_destroy (joystick *player)
{ free (player);}
