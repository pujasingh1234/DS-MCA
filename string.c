#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str); // Get the length of the string
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        // Swap characters at start and end
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move pointers
        start++;
        end--;
    }
}

int main() {
    char str[100]; // Declare a string with a max size of 100

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a string with spaces
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character if present

    printf("Original string: %s\n", str);

    reverseString(str); // Call the function to reverse the string

    printf("Reversed string: %s\n", str);

    return 0;
}
