#include <stdio.h>

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf(" %[^\n]", text);

    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';

        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
    }

    printf("Ciphertext: %s\n", text);

    return 0;
}
