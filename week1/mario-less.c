#include <stdio.h>
#include <cs50.h>

void print_row(int row, int bricks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        print_row(i + 1, n);
    }
}

void print_row(int row, int bricks)
{
    for (int s = 0; s < bricks - row; s++)
    {
        printf(" ");
    }

    for (int b = 0; b < row; b++)
    {
        printf("#");
    }

    printf("\n");
}
