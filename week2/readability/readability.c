#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
void test(void);

int main(void)
{
    string text = get_string("Text: ");
    float L, S;
    int words = count_words(text);

    // calculates L and S
    L = ((float) count_letters(text) * 100) / words;
    S = ((float) count_sentences(text) * 100) / words;

    // calculates the index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // three different ranges for the index to be. Each one has a different print
    if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

// function that counts the amount of words within the text
int count_words(string text)
{
    int wordcounter = 0;
    for (int i = 0, textlen = strlen(text); i < textlen; i++)
    {
        // increments the wordcounter if there is a space or punctuation in the next position
        if (isalpha(text[i]) &&
            ((isblank(text[i + 1]) || ispunct(text[i + 1]) || text[i + 1] == '\0') &&
             text[i + 1] != '\'') &&
            text[i + 1] != '-')
        {
            wordcounter++;
        }
    }
    return wordcounter;
}

// function that counts the amount of letters within the text
int count_letters(string text)
{
    int lettercounter = 0;
    for (int i = 0, textlen = strlen(text); i < textlen; i++)
    {
        // increments the lettercounter if the character is alphabetical
        if (isalpha(text[i]))
        {
            lettercounter++;
        }
    }
    return lettercounter;
}

// function that counts the amount of sentences within the text
int count_sentences(string text)
{
    int sentencecounter = 0;
    for (int i = 0, textlen = strlen(text); i < textlen; i++)
    {
        // increments the sentence counter after sentence-ending punctuation is found
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') &&
            (!ispunct(text[i + 1]) || text[i + 1] == '"' || text[i + 1] == '\''))
        {
            sentencecounter++;
        }
    }
    return sentencecounter;
}
