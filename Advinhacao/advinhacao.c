#include "ui.c"
#include "logica.c"
#define LIFES 5

void adivinhacao() {
  int level = 1;
  wellcome_msg_guessing();
  start_the_game(LIFES, level);
}
