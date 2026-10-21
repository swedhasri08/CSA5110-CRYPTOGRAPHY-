#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    char key[] = "CIPHERABDGJKLMNOQSTUVWXYZ";
    int i;

    printf("Enter plaintext: ");
    scanf(" %[^\n]", text);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = key[text[i] - 'a'];

        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'];
    }

    printf("Ciphertext: %s\n", text);

    return 0;
}
