#include "Advinhacao/advinhacao.c"
#include "Forca/forca.c"
#include "Pac_Man/pac_man.c"

void start_application() {
  int index, alive = 1;

  while (alive) {
    index = summary_message();

    switch (index) {
      case 0: alive = 0;
              break;
      case 1: adivinhacao();
              break;
      case 2: forca();
              break;
      case 3: pac_man();
              break;

      default: printf("Por favor, escolha um jogo da lista\n");
               break;
    }
  }
}
