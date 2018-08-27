#include "a_ui.c"
#include "a_logica.c"
#define LIFES 5

void adivinhacao() {
  int level = 1;
  wellcome_msg_guessing();
  start_the_game(LIFES, level);
}
