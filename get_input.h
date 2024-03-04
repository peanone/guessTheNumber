#ifndef GET_INPUT_H
#define GET_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_input(const char *input)
{
    // Check if the input is empty
    if (strlen(input) == 0)
    {
        printf("Error: Input cannot be empty.\n");
        return 0;
    }

    for (int i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Error: Input must contain only numbers.\n");
            return 0;
        }
    }

    if (input[0] == '-')
    {
        printf("Error: Negative numbers are not allowed.\n");
        return 0;
    }

    if (isspace(input[0]) || isspace(input[strlen(input) - 1]))
    {
        printf("Error: There should be no spaces before or after the number.\n");
        return 0;
    }

    return 1;
}

int get_input(int *number)
{
    char input[100];

    while (1)
    {

        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (is_valid_input(input))
        {
            *number = atoi(input);
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}

// int main()
// {
//     int number;

//     get_input(&number);

//     printf("Entered number: %d\n", number);

//     return 0;
// }

#endif