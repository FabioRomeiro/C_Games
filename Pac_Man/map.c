#include "map.h"

int is_ghost(char character) {
  if (character == RIGHT_GHOST ||
      character == LEFT_GHOST ||
      character == CRAZY_GHOST)
    return 1;
  return 0;
}

void copy_map(MAP* copy, MAP* origin) {
  copy->rows = origin->rows;
  copy->columns = origin->columns;

  allocate_map(copy);
  for (int i = 0; i < origin->rows; i++) {
    strcpy(copy->matrix[i], origin->matrix[i]);
  }
}

void find_in_the_map(MAP* m, POSITION* p, char c) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      if (m->matrix[i][j] == c) {
        p->x = i;
        p->y = j;
        break;
      }
    }
  }
}

int is_on_the_edge(MAP* m, int nextMoveX, int nextMoveY){
  if (nextMoveX >= m->rows) return 1;
  if (nextMoveY >= m->columns) return 1;
  return 0;
}

void switch_super() {
  if (SUPER) {
    SUPER = 0;
    PACMAN = 'O';
  } else {
    SUPER = 1;
    PACMAN = 'G';
  }
}

int is_wall(char c) {
  return (c == UPBOT_WALL ||
          c == SIDE_WALL ||
          c == EDGE_WALL);
}

int is_snack(char c) {
  return (c == SNACK || c == SUPER_SNACK);
}

int can_step_on(MAP* m, int nextMoveX, int nextMoveY, char* character){
  char nextMove = m->matrix[nextMoveX][nextMoveY];

  if (DEAD){
    return 0;
  } else if ((*character) == PACMAN){
   if (is_snack(nextMove)){
      if (nextMove == SUPER_SNACK)
        switch_super();
      SCORE++;
    } else if(is_ghost(nextMove) && !SUPER){
      DEAD = 1;
      PACMAN = EMPTY;
    } else if(is_ghost(nextMove) && SUPER){
        SCORE += 50;
        switch_super();
    }
  } else if (is_ghost((*character))) {
    if (nextMove == PACMAN && SUPER) {
      (*character) = EMPTY;
      switch_super();
    } else if (nextMove == PACMAN && !SUPER){
      DEAD = 1;
      PACMAN = EMPTY;
    } else if (is_ghost(nextMove)) {
      return 0;
    }
  }

  if (is_wall(nextMove))
    return 0;

  return 1;
}

int no_snacks_left(MAP* m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      if (m->matrix[i][j] == SNACK || m->matrix[i][j] == SUPER_SNACK)
        return 0;
    }
  }
  ATE_ALL = 1;
  return 1;
}

void walk_by(MAP* m, int nextMoveX, int nextMoveY, int currentX, int currentY, char character) {
    if (character == PACMAN && DEAD)
      m->matrix[nextMoveX][nextMoveY] = m->matrix[nextMoveX][nextMoveY];
    else
      m->matrix[nextMoveX][nextMoveY] = character;
    m->matrix[currentX][currentY] = EMPTY;
}

void allocate_map(MAP* m) {
    m->matrix = malloc(sizeof(char*) * m->rows);
    for (int i = 0; i < m->rows; i++) {
      m->matrix[i] = malloc(sizeof(char) * (m->columns+1));
    }
}

void set_free(MAP* m){
  for (int i = 0; i < m->rows; i++) {
    free(m->matrix[i]);
  }
  free(m->matrix);
}

void load_map(MAP* m) {
  FILE* f;
  f = fopen("Pac_Man/map.txt","r");
  if(f==0) {
    printf("Failed on file reading\n");
    exit(1);
  }

  fscanf(f,"%d %d %d", &(m->rows), &(m->columns), &GHOSTS);

  allocate_map(m);

  for (int i = 0; i < 18; i++) {
    fscanf(f,"%s", m->matrix[i]);
  }

  fclose(f);
}

void print_map(MAP* m) {
  for (int j = 0; j<17; j++) {
    printf("%s\n", m->matrix[j]);
  }
}
