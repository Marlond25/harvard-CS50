#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

bool validate(long input);
string typeOfCard(long input);
int getDiggit(int index, long input);

int main(void) {
    long input = get_long("Please provide a number to evaluate!\n");

    bool inputIsValid = validate(input);

    if (inputIsValid) {
        printf("%s", typeOfCard(input));
    } else {
        printf("INVALID\n");
    }
}

bool validate(long input) {
    int length = floor(log10(labs(input))) + 1;
    long lastDigit;
    long sumOdds = 0;
    long sumEvens = 0;
    bool consider = false;

    for (int i = 0; i < length; i++) {

        // Get the las digit from credit card number
        lastDigit = input % 10;

        // Check whether to consider this digit or not
        if (consider) {
            long sumDigitsFromProduct = 0;
            // printf("Considering: %li\n", lastDigit); // For Debugging

            // Calculate the product of lasDigit and 2
            long product = lastDigit * 2;

            // Calculate the length of the product
            int productLength = floor(log10(labs(product))) + 1;

            // Is the length of the product greater than one?
            if (productLength > 1) {
                long newProduct = product;

                // If it is, then locate every digit and add them together
                for (int c = 0; c < productLength; c++) {
                    long productDigit = newProduct % 10;
                    // printf("%li %li\n", productDigit, newProduct); // For Debugging
                    sumDigitsFromProduct += productDigit;
                    newProduct = newProduct / 10;
                }
            } else {
                sumDigitsFromProduct = product;
            }
            sumOdds += sumDigitsFromProduct;
        } else {
            sumEvens += lastDigit;
        }

        // Update input for next iteration
        input = input / 10;

        // Toggle diggit to consider
        consider = !consider;
    }
    long sumTotal = sumOdds + sumEvens;
    long lastDigitFromSumTotal = sumTotal % 10;

    // Constraints from hypothesis
    if (lastDigitFromSumTotal == 0 && length > 12 && length < 17) {
        return true;
    } else {
        return false;
    }
}

string typeOfCard(long input) {
    int diggit = getDiggit(1, input);

    if (diggit == 4) {
        return "VISA\n";
    }
    int first = getDiggit(1, input);
    int second = getDiggit(2, input);
    int firstTwo = (first * 10) + second;
    if (firstTwo == 34 || firstTwo == 37) {
        return "AMEX\n";
    } else if (firstTwo > 50 && firstTwo < 56) {
        return "MASTERCARD\n";
    }
    return "INVALID\n";
}

int getDiggit(int index, long input) {
    int length = floor(log10(labs(input))) + 1;
    int lastDigit;
    for (int i = length; i > 0; i--) {
        if (i == index) {
            return input % 10;
        }
        input = input / 10;
    }
    return -1;
}