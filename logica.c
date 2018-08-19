#include "Advinhacao/advinhacao.c"

void start_application() {
  int index, alive = 1;

  while (alive) {
    index = summary_message();

    switch (index) {
      case -1: alive = 0;
               break;

      case 1: adivinhacao();
              break;

      default: printf("Por favor, escolha um jogo da lista\n");
               break;
    }
  }
}
