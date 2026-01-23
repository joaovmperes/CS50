#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key;
    string word;
    int letterpos;
    int islowcase = 0;
    int keylen;
    int isalphabetical = 0;
    int letterused[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // checks if the user sent the correct amount of arguments
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    // stores the key sent in the CLA in the key variable
    key = argv[1];
    // calculates the lenght of the key
    keylen = strlen(key);

    // checks if the key length is valid
    if (keylen != 26)
    {
        printf("invalid key");
        return 1;
    }

    // for loop goes through each character of the key
    for (int i = 0; i < 26; i++)
    {
        // if character is not alphabetical, return 1
        if (!isalpha(key[i]))
        {
            printf("invalid key");
            return 1;
        }
        // if character is uppercase, turns it to lower case
        if (isupper(key[i]))
        {
            key[i] = tolower(key[i]);
        }

        // Looks for repetitive letters. If value in the position of the key's current character is
        // 0, increment the value to register the letter as used.
        if (letterused[key[i] - 'a'] == 0)
        {
            letterused[key[i] - 'a']++;
        }
        // if the value stored in the array is not 0, it means it has been used, so return 1.
        else
        {
            printf("invalid key");
            return 1;
        }
    }

    // receive plaintext from the user and stores it in the word variable
    word = get_string("plaintext: ");

    // prints the indication of where the ciphertext will be
    printf("ciphertext: ");

    // loops through each character of the plaintext
    for (int i = 0, wlen = strlen(word); i < wlen; i++)
    {
        // increments is alphabetical variable if character is alphabetical
        if (isalpha(word[i]))
        {
            isalphabetical++;
        }

        // if word is lowercase, stores the word position in the letterpos variable and increments
        // islowcase variable.
        if (islower(word[i]))
        {
            letterpos = word[i] - 'a';
            islowcase++;
        }
        // else, store the position of the word
        else
        {
            letterpos = word[i] - 'A';
        }

        // if the character is alphabetical and lowercase, print the respective letter in the key as
        // lowercase
        if (isalphabetical == 1 && islowcase == 1)
        {
            printf("%c", key[letterpos]);
        }
        // else if it is a letter and uppercase, print the respective letter in the key as uppercase
        else if (isalphabetical == 1 && islowcase == 0)
        {
            printf("%c", key[letterpos] - 32);
        }
        // else if it is not a letter, print it unchanged
        else
        {
            printf("%c", word[i]);
        }
        // sets both variables to 0 in the end of the loop
        islowcase = 0;
        isalphabetical = 0;
    }

    printf("\n");

    return 0;
}
