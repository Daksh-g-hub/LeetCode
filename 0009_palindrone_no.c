#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }

    int original = x;  // Store the original number
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;       // Extract the last digit
        reversed = reversed * 10 + digit;  // Build the reversed number
        x /= 10;                 // Remove the last digit
    }

    // Compare the reversed number with the original number
    return original == reversed;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
