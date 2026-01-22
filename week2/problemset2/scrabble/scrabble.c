#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word);

int main(void)
{
    // gets both player's words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // calculates the scores of both words and stores it in a variable each
    int word1score = calculate_score(word1);
    int word2score = calculate_score(word2);

    // checks for the winner
    if (word1score > word2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (word1score < word2score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int scores[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int finalscore = 0;

    // loops through the entire word
    for (int i = 0, wordlen = strlen(word); i < wordlen; i++)
    {
        // works if the digit is upper or lower case
        if (islower(word[i]))
        {
            // operates with strings to get to the correct score array position
            finalscore += scores[word[i] - 'a'];
        }
        else if (isupper(word[i]))
        {
            finalscore += scores[word[i] - 'A'];
        }
    }
    return finalscore;
}
