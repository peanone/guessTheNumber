// AUTOMATION

#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"
#include "playNormalMode.h"
#include "playClueMode.h"
#include "scoreBoard.h"

// #define MAX_NICKNAME_SIZE 50
// #define FILENAME "database.txt"

int automation()
{
    // char nickname[NICKNAME_SIZE];
    int decision;
    int sub_decision;
    int mode_decision;
    int score_desicion;

    printf("\n\033[1;35mYou are very welcome. The program generates a random number and asks the user to guess it. It shows the range of the number according to the user's    guess. \033[0m\n");

    while (1)
    {

        printf("\n\033[1;35mMake your decision:\n 1) How to play\n 2) Play\n 3) Score Board\n 4) Exit\033[0m\n\n"); // menu

        get_input(&decision);

        //! Menu
        switch (decision)
        {
        case 1:
            // Info
            while (1)
            {
                printf("\nWelcome. The program generates a random number and asks the player to guess it. It shows the range of the number according to the player's guess. \n\n1) Normal Mode: In Normal Mode, the user tries to reach the correct result by trial and error. The player only needs to enter the number. Incorrect answers subtract -1 point from the player's score. \n2) Clue Mode: In Clue Mode the player is asked to enter numbers. The player has the right to receive hints at any time. The score is determined according to hints and attempts.\n\nPlease press 3 to go back\n");

                get_input(&sub_decision);

                if (sub_decision == 3)
                {
                    break;
                }
                else
                {
                    printf("\nPlease enter a valid number.\n");
                }
            }
            break;

        case 2:

            //! gameModes

            while (1)
            {
                printf("\n\033[1;35mGame Modes:\n\n1) Normal Mode\n2) Clue Mode\n3) Go Back\033[0m\n");

                get_input(&mode_decision);

                // modeMenu
                switch (mode_decision)
                {
                case 1:
                    // Normal Mode
                    playNormalMode();
                    break;
                case 2:
                    // Clue Mode
                    playClueMode();
                    break;
                case 3:
                    // Go Back
                    break;
                default:
                    printf("\nPlease enter a valid number.\n");
                    break;
                }
                if (mode_decision == 3)
                {
                    break;
                }
            }
            break;

        case 3:
            //! Score board

            while (1)
            {
                printf("\n\033[1;35m\n1) Normal Mode Scores\n2) Clue Mode Scores\n3) Go Back\033[0m\n");

                get_input(&score_desicion);

                if (score_desicion == 1)
                {
                    showScoresNormalMode();
                }
                else if (score_desicion == 2)
                {
                    showScoresClueMode();
                }
                else if (score_desicion == 3)
                {
                    break;
                }
                else
                {
                    printf("\nPlease enter a valid number.\n");
                }
            }
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nPlease enter a valid number.\n");
            break;
        }
    }
    return 0;
}