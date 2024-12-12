#include <stdio.h>
#include <ctype.h>

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int shift) {
    // Loop through each character of the message
    int i = 0;
    while (message[i] != '\0') {
        // Check if the character is a lowercase letter
        if (islower(message[i])) {
            // Apply the shift and wrap around if necessary
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
        // Check if the character is an uppercase letter
        else if (isupper(message[i])) {
            // Apply the shift and wrap around if necessary
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        // Move to the next character
        i++;
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *message, int shift) {
    // Loop through each character of the message
    int i = 0;
    while (message[i] != '\0') {
        // Check if the character is a lowercase letter
        if (islower(message[i])) {
            // Apply the reverse shift and wrap around if necessary
            message[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
        }
        // Check if the character is an uppercase letter
        else if (isupper(message[i])) {
            // Apply the reverse shift and wrap around if necessary
            message[i] = (message[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Move to the next character
        i++;
    }
}

int main() {
    char message[100];
    int shift, choice;

    // Prompt the user to enter the message to be encrypted or decrypted
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);  // Read the message with spaces

    // Ask the user for the shift value
    printf("Enter the shift value (integer): ");
    scanf("%d", &shift);

    // Ask the user if they want to encrypt or decrypt
    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the chosen operation
    if (choice == 1) {
        encrypt(message, shift);  // Encrypt the message
        printf("Encrypted message: %s", message);  // Display the encrypted message
    } else if (choice == 2) {
        decrypt(message, shift);  // Decrypt the message
        printf("Decrypted message: %s", message);  // Display the decrypted message
    } else {
        printf("Invalid choice! Please enter 1 for encryption or 2 for decryption.\n");
    }

    return 0;  // End of program
}
