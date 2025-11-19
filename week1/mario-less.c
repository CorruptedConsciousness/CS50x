#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt the user for height until they give a valid value (1–8)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Outer loop: each iteration prints one row
    for (int row = 0; row < height; row++)
    {
        // Print spaces on the left
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Print hashes (#) for the pyramid
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        // Move to the next line after each row
        printf("\n");
    }
}
