/*Controle do estado dos botões
 *1 = pressionado
 *0 = liberado*/

#ifndef __JOYSTICK__
#define __JOYSTICK__

typedef struct {
	unsigned char right;
	unsigned char left;
	unsigned char up;
	unsigned char down;
	unsigned char punch;
	unsigned char kick;
	unsigned char kick2;
	unsigned char hurted;
	unsigned char special;
} joystick;

joystick* joystick_create ();

void joystick_right (joystick *player);

void joystick_left (joystick *player);

void joystick_up (joystick *player);

void joystick_down (joystick *player);

void joystick_destroy (joystick *player);

void joystick_punch (joystick *player);

void joystick_kick (joystick *player);

void joystick_kick2 (joystick *player);

void joystick_hurted (joystick *player);

void joystick_special (joystick *player);

#endif
