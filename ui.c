void __clean_screen() {
  system("CLS");
}

void __press_to_continue() {
  system("pause");
}

void __break_lines(int times) {
  for (int i = 0; i <= times; i++) {
    printf("\n");
  }
}

int summary_message() {
  int choise;
  __clean_screen();
  printf("----------------------------------------------------------\n");
  printf("  Compilado de mini games em C - by Fábio Lucas Romeiro   \n");
  printf("----------------------------------------------------------\n");
  __break_lines(1);
  printf("Escolha o jogo:\n (1) = Advinhacao\n (-1) = Sair\n ");
  scanf("%d", &choise);

  return choise;
}
