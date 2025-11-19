#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to verify that a string contains only digits
bool is_valid_key(string s);

int main(int argc, string argv[])
{
    // Ensure exactly one command-line argument for the key
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key from string to integer
    int key = atoi(argv[1]) % 26; // Reduce large keys modulo 26

    // Get plaintext from user
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Iterate over each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            // Shift within 'A'–'Z'
            char shifted = (char) (((c - 'A' + key) % 26) + 'A');
            printf("%c", shifted);
        }
        else if (islower(c))
        {
            // Shift within 'a'–'z'
            char shifted = (char) (((c - 'a' + key) % 26) + 'a');
            printf("%c", shifted);
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

// Returns true if s consists only of digits, false otherwise
bool is_valid_key(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit((unsigned char) s[i]))
        {
            return false;
        }
    }
    return true;
}
