#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pac_man.h"
// #include "map.h" //UNCOMMENT THIS
#include "map.c" // DELETE THIS

MAP m;
POSITION pac;

void pac_game_status(int mode) {
  system("cls");
  if (mode == 0) {
    printf("                 YOUR SCORE: %d   \n", SCORE);
    printf("                GHOSTS LEFT: %d   \n", GHOSTS);
    printf("              Press 'o' to give up\n");
    printf("\n");
  } else if (mode == 1) {
    if (DEAD || GIVEUP) {
      printf("+-------------------------------------------+\n");
      printf("                  GAME OVER                  \n");
      printf("                TOTAL SCORE: %d              \n", SCORE);
      printf("+-------------------------------------------+\n");
    } else if (ATE_ALL) {
      printf("+-------------------------------------------+\n");
      printf("                   YOU WIN!\n                \n");
      printf("                TOTAL SCORE: %d\n            \n", SCORE);
      printf("+-------------------------------------------+\n");
    }
  }
  print_map(&m);
}

int set_ghost_direction(int currentX, int currentY, int* finalX, int* finalY, char ghost) {
  int options[4][2] = {
    {currentX, currentY+1},
    {currentX+1, currentY},
    {currentX, currentY-1},
    {currentX-1, currentY}
  };

  srand(time(0));

  for (int i = 0; i < 10; i++) {
    int position = rand() % 4;
    if (ghost == CRAZY_GHOST) {
      if (can_step_on(&m, options[position][0], options[position][1], &ghost)) {
        *finalX = options[position][0];
        *finalY = options[position][1];

        return 1;
      }
    }
  }
  return 0;
}

void move_ghost() {
  GHOSTS = 0;

  MAP copy;

  copy_map(&copy, &m);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {

      if (is_ghost(copy.matrix[i][j])) {

        int finalX, finalY;
        char ghost = copy.matrix[i][j];
        GHOSTS++;

        if (ghost == CRAZY_GHOST){
          if (set_ghost_direction(i, j, &finalX, &finalY, ghost)){
            walk_by(&m, finalX, finalY, i, j, CRAZY_GHOST);
          }
        }
      }
    }
  }

  set_free(&copy);
}

void reset_pac() {
  PACMAN = 'O';
  SUPER = 0;
  DEAD = 0;
  SCORE = 0;
  GIVEUP = 0;
}

int end(){
  return DEAD || no_snacks_left(&m) || GIVEUP;
}

int is_a_valid_command(char command){
  return command == LEFT ||
      command == UP ||
      command == DOWN ||
      command == RIGHT ||
      command == GIVEUP_COMMAND;
}

void move(char command) {
  command = tolower(command);

  if (!is_a_valid_command(command))
      return;

  int nextY = pac.y;
  int nextX = pac.x;

  switch (command) {
    case LEFT:
        nextY--;
        break;
    case UP:
        nextX--;
        break;
    case RIGHT:
        nextY++;
        break;
    case DOWN:
        nextX++;
        break;
    case GIVEUP_COMMAND:
        GIVEUP = 1;
        break;
  }

  if (is_on_the_edge(&m, nextX, nextY)) return;
  if (!can_step_on(&m, nextX, nextY, &PACMAN)) return;
  walk_by(&m, nextX, nextY, pac.x, pac.y, PACMAN);
  pac.x = nextX;
  pac.y = nextY;
}

void game_over_pac() {
    pac_game_status(1);
    reset_pac();
}

int pac_man() {

  load_map(&m);
  find_in_the_map(&m, &pac, PACMAN);

  do {

    pac_game_status(0);

    char command;
    command = getche();
    move(command);
    move_ghost();

  }while(!end());

  game_over_pac(1);
  set_free(&m);

  system("pause");

  return 0;
}
