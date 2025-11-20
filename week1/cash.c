#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }

    // Calculate how many dimes you should give customer
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }

    // Calculate how many nickels you should give customer
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }

    // Calculate how many pennies you should give customer
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }

    // Add the number of coins
    int coins = quarters + dimes + nickels + pennies;

    // Show number of coins
    printf("%i\n", coins);

    return 0;

}
