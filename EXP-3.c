#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;
    char c;

    for (i = 0; key[i] != '\0'; i++) {
        c = toupper(key[i]);
        if (c == 'J') c = 'I';

        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }

    for (c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;

        if (!used[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char c, int *row, int *col) {
    int i, j;

    if (c == 'J') c = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
}

int main() {
    char key[50], text[100], result[200];
    int i, r1, c1, r2, c2, k = 0;

    printf("Enter key: ");
    scanf("%s", key);

    createMatrix(key);

    printf("Enter plaintext: ");
    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i++)
        text[i] = toupper(text[i]);

    for (i = 0; text[i] != '\0'; i += 2) {
        char a = text[i];
        char b = text[i + 1];

        if (b == '\0') b = 'X';
        if (a == b) {
            b = 'X';
            i--;
        }

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2) {
            result[k++] = matrix[r1][(c1 + 1) % 5];
            result[k++] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) {
            result[k++] = matrix[(r1 + 1) % 5][c1];
            result[k++] = matrix[(r2 + 1) % 5][c2];
        }
        else {
            result[k++] = matrix[r1][c2];
            result[k++] = matrix[r2][c1];
        }
    }

    result[k] = '\0';

    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    printf("\nCiphertext: %s\n", result);

    return 0;
}
