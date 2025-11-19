#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;

    // Prompt until we get a valid positive amount of change
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // Convert dollars to cents (rounding to avoid floating-point issues)
    int cents = round(dollars * 100);

    int coins = 0;

    // Quarters
    coins += cents / 25;
    cents %= 25;

    // Dimes
    coins += cents / 10;
    cents %= 10;

    // Nickels
    coins += cents / 5;
    cents %= 5;

    // Pennies
    coins += cents;

    // Output total number of coins
    printf("%i\n", coins);
}
