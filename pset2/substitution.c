#include <stdio.h>
#include <cs50.h>
#include <string.h>

string cipher(string text, string key);
bool validate(string key, int n);

int main(int argc, string argv[])
{

    if (argc <= 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int n = strlen(key);
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    } else {
        bool keyIsValid = validate(key, n);
        if (keyIsValid) {
            string textToCipher = get_string("plaintext: ");
            string cipherText = cipher(textToCipher, key);
            printf("ciphertext: %s\n", cipherText);
            return 0;
        } else {
            printf("Key must contain only Alphabetic characters.\n");
            return 1;
        }
    }
}

bool validate(string key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((int)key[i] > 47 && (int)key[i] < 58) {
            return false;
        }
    }
    string aux = key;
    for (int i = 0; i < n; i++)
    {
        char c = key[i];
        for (int j = 0; j < n; j++)
        {
            if (aux[j] == c && j != i)
            {
                return false;
            }
        }
    }
    return true;
}

string cipher(string text, string key)
{
    int n = strlen(text);
    string cipherText = text;

    for (int i = 0; i < n; i++)
    {
        int charCode = (int)text[i];

        // Is the text MAYUS?
        if (charCode > 64 && charCode < 91) {
            charCode = (int)key[charCode - 65];

            // Is the key MAYUS?
            if (charCode > 64 && charCode < 91) {
                cipherText[i] = (char)charCode;
            } else {
                charCode -= 32;
                cipherText[i] = (char)charCode;
            }

        // Is the text minus?
        } else if (charCode > 96 && charCode < 123) {
            charCode = (int)key[charCode - 97];

            // Is the key minus?
            if (charCode > 96 && charCode < 123) {
                cipherText[i] = (char)charCode;
            } else {
                charCode += 32;
                cipherText[i] = (char)charCode;
            }
        } else {
            cipherText[i] = text[i];
        }
    }
    return cipherText;
}