#ifndef _MAP_H_
#define _MAP_H_

int SUPER = 0;
char PACMAN = 'O';
int DEAD = 0;
int ATE_ALL = 0;
int SCORE = 0;
int GHOSTS = 0;
int GIVEUP = 0;

#define RIGHT_GHOST 'K'
#define LEFT_GHOST 'U'
#define CRAZY_GHOST 'C'
#define SUPER_SNACK '*'
#define EMPTY ' '
#define SNACK '.'
#define SIDE_WALL '|'
#define UPBOT_WALL '-'
#define EDGE_WALL '+'

struct map {
  char** matrix;
  int rows, columns;
};

struct position {
  int x,y;
};

typedef struct map MAP;
typedef struct position POSITION;

void allocate_map(MAP* m);
void set_free(MAP* m);
void load_map(MAP* m);
void print_map(MAP* m);
void find_in_the_map(MAP* m, POSITION* p, char c);
int is_on_the_edge(MAP* m, int nextMoveX, int nextMoveY);
void walk_by(MAP* m, int nextMoveX, int nextMoveY, int currentX, int currentY, char character);
int can_step_on(MAP* m, int nextMoveX, int nextMoveY, char* character);
void copy_map(MAP* copy, MAP* origin);
int is_ghost(char character);
int is_wall(char c);
int no_snacks_left(MAP* m);
int is_snack(char c);

#endif
