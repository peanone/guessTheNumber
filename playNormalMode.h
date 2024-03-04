#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "get_input.h"
#include "scoreBoard.h"

//! ------------------------------------------------------------------------------------------

int playNormalMode()
{
    int lower_bound = 0;
    int upper_bound = 1000;
    int target_number;
    int choosen_input;
    int guess;
    int num_guesses = 0;
    int score = 1000;

    char nickname[100];

    printf("Enter a nickname: ");
    scanf("%99s", nickname);

    srand(time(NULL)); // random
    target_number = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    printf("\nI have picked a number between 0 and 1000. Start guessing!\n");

    do
    {
        printf("\nPrediction Range: \033[1;35m[%d, %d]\033[0m\n", lower_bound, upper_bound);
        printf("Enter your prediction \nEnter \033[1;35m9999 to exit\033[0m\n");
        get_input(&choosen_input);

        if (choosen_input == 9999)
        {
            break;
        }
        if (choosen_input < lower_bound || choosen_input > upper_bound)
        {
            printf("The number you entered is outside the prediction range. Please make a valid guess.\n");
            continue; //? do nothing
        }

        num_guesses++;

        if (choosen_input < target_number)
        {
            printf("You need a \033[1;35mbigger number\033[0m\n");
            lower_bound = choosen_input + 1;
            score--;
        }
        else if (choosen_input > target_number)
        {
            printf("You need a \033[1;35msmaller number\033[0m\n");
            upper_bound = choosen_input - 1;
            score--;
        }
        else
        {
            printf("\n\033[1;35mCongratulations! You found the right number: \033[0m%d\n", target_number);
            // // score += 10; // Doğru tahmin için 10 puan
            break;
        }

        // // Aralık yarıya indiğinde bonus puan
        // // if ((upper_bound - lower_bound) <= 100)
        // // {
        // //    score += 5;
        // //    printf("Aralık daraldı! 5 bonus puan kazandınız.\n");
        // //}
    } while (1);

    // to prevent the score from being negative
    if (score < 0)
    {
        score = 0;
    }

    printf("Total number of guesses:%d\n", num_guesses);
    printf("Your total score: %d\n", score);

    saveScoreNormalMode(nickname, score); //!

    return 0;
}
