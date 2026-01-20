#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int k;
    int current_row;
    int height;

    // get user input
    do
    {
        height = get_int("how tall should the pyramid be? (in blocks) ");
    }
    while (height < 1);

    // row
    for (int row = 0; row < height; row++)
    {
        // prints the right amount of spaces (height - current row) before the hashes begin, in each
        // row
        for (current_row = row; current_row < height - 1; current_row++)
        {
            printf(" ");
        }
        // prints the first set of hashes

        for (k = 0; k < row + 1; k++)
        {
            printf("#");
        }

        // prints the spaces beetween the 2 sets of hashes
        printf("  ");

        // prints the second set of hashes after the spaces
        for (k = 0; k < row + 1; k++)
        {
            printf("#");
        }
        ;
        // breaks the line to separate the different rows in the output.
        printf("\n");
    }
}
