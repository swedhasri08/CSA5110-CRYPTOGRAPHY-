#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[26];
    int i;

    printf("Enter plaintext: ");
    scanf(" %[^\n]", text);

    printf("Enter 26-letter substitution key: ");
    scanf("%s", key);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'];
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = key[text[i] - 'a'];
    }

    printf("Ciphertext: %s\n", text);

    return 0;
}
