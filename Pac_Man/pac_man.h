#ifndef _PACMAN_H_
#define _PACMAN_H_

#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define GIVEUP_COMMAND 'o'

int end();
void move(char command);
int is_a_valid_command(char command);
void move_ghost();
void reset_pac();
void game_over_pac();
void pac_game_status(int mode);
int set_ghost_direction(int currentX, int currentY, int* finalX, int* finalY, char ghost);

#endif
