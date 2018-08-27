char guesses[26] = "";
char secretWord[20];
int tries = 0;

void clear_score() {
  tries = 0;
  memset(guesses, 0, sizeof guesses);
}

void raffle_word() {
  FILE* f;
  f = fopen("Forca/words.txt", "r");

  if (f == 0) {
    printf("Something is wrong with the words file! But you still can play!\n");
    exit(1);
  }

  int num_words;
  fscanf(f,"%d", &num_words);

  srand(time(0));
  int random_line = rand() % num_words;

  for (int i = 0; i < random_line; i++) {
    fscanf(f,"%s",secretWord);
  }


  fclose(f);

  word_chosed_message();
}

int check_if_won_or_lost(int wrong_guesses, int* win,int* lose) {
  if (wrong_guesses >= CHANCES) {
    (*lose) = 1;
    forca_loser_message(secretWord);
  }

  int letters_matching = 0;
  for (int i = 0; i < strlen(secretWord); i++) {
    for (int j = 0; j < strlen(guesses); j++) {
      if (secretWord[i] == guesses[j]) {
        letters_matching++;
      }
    }
  }

  if (letters_matching >= strlen(secretWord)) {
    (*win) = 1;
    forca_winner_message();
  }
}

int already_tried(){
  for (int h = 0; h < strlen(guesses); h++) {
    if (guesses[h] == guesses[tries]) {
      return 1;
    }
  }
  return 0;
}

void proccess_letter_or_word(char guess, int* wrong_guesses) {
  int already_inputed;
  already_inputed = already_tried();
  if (!already_inputed) {
    guesses[tries] = guess;

    int exists = 0;
    for (int g = 0; g < strlen(secretWord); g++) {
      if (secretWord[g] == guesses[tries]) {
        exists = 1;
        break;
      }
    }
    if (!exists) (*wrong_guesses)++;
  }

}

void ask_for_letter_or_word(int* wrong_guesses) {
    char guess;
    printf("Entre com seu chute:\n");
    scanf(" %c", &guess);
    guess = toupper(guess);

    proccess_letter_or_word(guess,wrong_guesses);
}

int start_game_forca() {

  clear_score();
  int win = 0;
  int lose = 0;
  int wrong_guesses = 0;

  wellcome_msg_forca();
  raffle_word();

  do {

    game_status_forca(tries, wrong_guesses, secretWord, guesses);

    ask_for_letter_or_word(&wrong_guesses);

    tries++;

    check_if_won_or_lost(wrong_guesses, &win, &lose);

  } while(!win && !lose);

  return 0;
}
