#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void find_scoreBoard(char *dosya_adi);

void saveScoreNormalMode(const char *nickname, int score)
{
    FILE *file = fopen("databaseNormalMode.csv", "a"); // 'a' mode appends to the end of the file
    if (file != NULL)
    {
        fprintf(file, "%s,%d\n", nickname, score);
        fclose(file);
        printf("Score has been saved.\n");
    }
    else
    {
        printf("Failed to create file.\n");
    }
}

void saveScoreClueMode(const char *nickname, int score)
{
    FILE *file = fopen("databaseClueMode.csv", "a"); // 'a' mode appends to the end of the file
    if (file != NULL)
    {
        fprintf(file, "%s,%d\n", nickname, score);
        fclose(file);
        printf("Score has been saved.\n");
    }
    else
    {
        printf("Failed to create file.\n");
    }
}

void showScoresNormalMode()
{
    FILE *file = fopen("databaseNormalMode.csv", "r");
    if (file != NULL)
    {
        char line[100]; // A buffer to read the line
        // Skip header line
        fgets(line, sizeof(line), file);
        printf("Nicknames and Scores:\n");
        printf("%-20s %s\n", "Nickname", "Score");
        while (fgets(line, sizeof(line), file) != NULL)
        {
            // Splits a line wtih a comma
            char *token = strtok(line, ",");
            // Print the first column (nickname)
            printf("%-20s ", token);
            // Get and print the next column (score)
            token = strtok(NULL, ",");
            printf("%s", token);
        }
        fclose(file);
    }
    else
    {
        printf("Error reading data.\n");
    }
}

void showScoresClueMode()
{
    FILE *file = fopen("databaseClueMode.csv", "r");
    if (file != NULL)
    {
        char line[100]; // A buffer to read the line
        // Skip header line
        fgets(line, sizeof(line), file);
        printf("Nicknames and Scores:\n");
        printf("%-20s %s\n", "Nickname", "Score");
        while (fgets(line, sizeof(line), file) != NULL)
        {
            // Splits a line wtih a comma
            char *token = strtok(line, ",");
            // Print the first column (nickname)
            printf("%-20s ", token);
            // Get and print the next column (score)
            token = strtok(NULL, ",");
            printf("%s", token);
        }
        fclose(file);
    }
    else
    {
        printf("Error reading data.\n");
    }
}

#endif
