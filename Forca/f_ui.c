void wellcome_msg_forca() {
  __clean_screen();
  printf("----------------------------------------------------\n");
  printf("              The Forca - C Version                 \n");
  printf("----------------------------------------------------\n");
  __break_lines(1);
  __press_to_continue();
  __clean_screen();
}

void word_chosed_message() {
  __clean_screen();
  printf("I've just choose the secret word, take a guess...\n");
  __break_lines(1);
  __press_to_continue();
}

void forca_loser_message(char secretWord[20]) {
  __clean_screen();
  printf("----------------------------------------------------\n");
  printf("           You've lost your chances ;-;             \n");
  printf("----------------------------------------------------\n");
  __break_lines(1);
  printf("The word were: %s\n", secretWord);
  __break_lines(1);
  __press_to_continue();
}

void forca_winner_message() {
  __clean_screen();
  printf("----------------------------------------------------\n");
  printf("                    YOU WON!!                       \n");
  printf("----------------------------------------------------\n");
  __press_to_continue();
}

void game_status_forca(int tries, int wrong_guesses, char secretWord[20], char guesses[20]) {
  __clean_screen();
  printf("Chances left: %d\nNumber of letters: %d\nYour guesses: %s", CHANCES - wrong_guesses, strlen(secretWord), guesses);
  __break_lines(1);

  for (int i = 0; i < strlen(secretWord); i++) {
    int has = 0;

    for (int j = 0; j < tries; j++) {
      if (guesses[j] == secretWord[i]) {
        has = 1;
        break;
      }
    }

    if (has) {
      printf("%c ", secretWord[i]);
    }else {
      printf("_ ");
    }
  }

  __break_lines(1);
}
