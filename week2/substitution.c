#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool valid_key(string key);
bool has_duplicate_letters(string key);

int main(int argc, string argv[])
{
    // Verify correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key thoroughly
    if (!valid_key(key))
    {
        return 1;
    }

    // Get plaintext input
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Encrypt plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            // Uppercase mapping
            int index = c - 'A';
            char cipher = toupper(key[index]);
            printf("%c", cipher);
        }
        else if (islower(c))
        {
            // Lowercase mapping
            int index = c - 'a';
            char cipher = tolower(key[index]);
            printf("%c", cipher);
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

// Validate that key is 26 alphabetic characters and has no duplicates
bool valid_key(string key)
{
    int length = strlen(key);

    // Must be exactly 26 characters
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Check alphabetic only
    for (int i = 0; i < length; i++)
    {
        if (!isalpha((unsigned char) key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    // Check for repeated letters
    if (has_duplicate_letters(key))
    {
        printf("Key must not contain duplicate characters.\n");
        return false;
    }

    return true;
}

// Detect duplicate letters in a key
bool has_duplicate_letters(string key)
{
    bool used[26] = {false};

    for (int i = 0; key[i] != '\0'; i++)
    {
        char c = toupper(key[i]);
        int index = c - 'A';

        if (used[index])
        {
            return true;
        }

        used[index] = true;
    }

    return false;
}
