#include <stdio.h>
#include <cs50.h>
#include <string.h>

long countLetters(string s, long n);
long countSentences(string s, long n);
long countWords(string s, long n);
float calculateLettersPer100Words(long letters, long words);
float calculateSentencesPer100Words(long sentences, long words);
float colemanLiau(float L, float S);

int main(void)
{
    string textToGrade = get_string("Please enter a text to grade\n");

    long length = strlen(textToGrade);
    // count letters
    long letters = countLetters(textToGrade, length);
    // count sentences
    long sentences = countSentences(textToGrade, length);
    // count words
    long words = countWords(textToGrade, length);
    // calculate average of letters per a 100 words
    float lettersPer100Words = calculateLettersPer100Words(letters, words);
    // calculate average of sentences per 100 words
    float sentencesPer100Words = calculateSentencesPer100Words(sentences, words);
    // apply Coleman-Liau formula
    // index = round to the nearest whole number
    float index = colemanLiau(lettersPer100Words, sentencesPer100Words);
    // return index that grades the text
    if(index < 1)
    {
        printf("Before Grade 1\n");
    } else if(index > 15)
    {
        printf("Grade 16+\n");
    } else
    {
        printf("Grade %.0f\n", index);
    }
}

long countLetters(string s, long n)
{
    long counter = 0;
    for( int i = 0; i < n; i++)
    {
        if(s[i] != '?' && s[i] != '.' && s[i] != ',' && s[i] != ' ' && s[i] != '!' && s[i] != '\'')
        {
            counter++;
        }
    }
    return counter;
}

long countSentences(string s, long n)
{
    long counter = 0;
    for( int i = 0; i < n; i++)
    {
        if(s[i] == '?' || s[i] == '.' || s[i] == '!')
        {
            counter++;
        }
    }
    return counter;
}

long countWords(string s, long n)
{
    long counter = 0;
    for( int i = 0; i < n; i++)
    {
        if(s[i] == ' ')
        {
            counter++;
        }
    }
    return counter + 1;
}

float calculateLettersPer100Words(long letters, long words)
{
    float lettersPer100Words = (float)letters / ((float)words / 100);
    return lettersPer100Words;
}

float calculateSentencesPer100Words(long sentences, long words)
{
    float sentencesPer100Words = (float)sentences / ((float)words / 100);
    return sentencesPer100Words;
}

float colemanLiau(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}