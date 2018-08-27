int raffle_number(int max) {
  shots_introduction(max);
  srand(time(0));
  int numero = rand() % (max + 1 - 0) + 0;
  return numero;
}

int start_the_game(int LIFES, int level) {
  int guess = -1, keep = 1;
  int tries = 0;
  int max_number = 1 * pow(10,level);
  int score = 0;

  while (keep) {
    int secretNumber = raffle_number(max_number);

    while (1) {
      game_status(LIFES,level,tries,score);
      guess = ask_for_guess(max_number, secretNumber, guess);

      if (guess == secretNumber) {
        score += 100 * level;
        congrats(score);
        break;
      } else if (tries == LIFES) {
        if (score < 0) score = 0;
        break;
      } else {
        score -= 20;
        tries++;
      }
    }

    if (keep_playing()) {
      level++;
      tries = 0;
    } else {
      keep = 0;
    }

  }
}
