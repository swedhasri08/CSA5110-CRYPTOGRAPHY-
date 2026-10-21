#include <stdio.h>
#include <string.h>

int main() {
    char cipher[100], plain[100];
    int i, c, p;
    int a = 3, b = 15;

    printf("Enter ciphertext: ");
    scanf(" %[^\n]", cipher);

    for (i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            c = cipher[i] - 'A';

            // Inverse of a = 3 modulo 26 is 9
            p = (9 * (c - b + 26)) % 26;

            plain[i] = p + 'A';
        }
        else {
            plain[i] = cipher[i];
        }
    }

    plain[i] = '\0';

    printf("Decrypted text: %s\n", plain);

    return 0;
}
