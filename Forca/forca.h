#define CHANCES 6

void wellcome_msg_forca();
int start_game_forca();
void raffle_word();
void word_chosed_message();
void clear_score();
void game_status_forca(int tries, int wrong_guesses, char secretWord[20], char guesses[20]);
void ask_for_letter_or_word(int* wrong_guesses);
int already_tried();
void proccess_letter_or_word(char guess, int* wrong_guesses);
int check_if_won_or_lost(int wrong_guesses, int* win,int* lose);
void forca_loser_message(char secretWord[20]);
void forca_winner_message();
