void wellcome_msg_guessing() {
  __clean_screen();
  printf("----------------------------------------------------\n");
  printf("             Guessing Game - C Version              \n");
  printf("----------------------------------------------------\n");
  __break_lines(1);
  __press_to_continue();
  __clean_screen();
}

void shots_introduction(int max) {
  __clean_screen();
  printf("I've just choose a number BETWEEN 0 AND %d, take a guess...\n", max);
  __break_lines(1);
}

void game_status(int lifes, int level, int tries, int score) {
  printf("Lifes left: %d\nLevel: %d\nScore: %d\n", lifes - tries, level, score);
  __break_lines(1);
}

int ask_for_guess(int max, int secretNumber, int last_guess) {
  int guess;
  if (last_guess != -1) printf("Try a %snumber\n", (last_guess > secretNumber) ? "SMALLER " : "LARGER " );

  printf("Make your choice, remember: BETWEEN 0 and %d\n", max);
  scanf("%d", &guess);
  __clean_screen();
  return guess;
}

void congrats(int score) {
  printf("********************************************************\n");
  printf("  Congratulations!! You did it, your score by now: %d   \n", score);
  printf("********************************************************\n");
  __break_lines(1);
  __press_to_continue();
}

int keep_playing() {
  char ans = 'x';
  __clean_screen();
  printf("Do you wanna keep playing and increase your score? (Y/N)\n");
  scanf("%s", &ans);

  return (tolower(ans) == 'y');
}
