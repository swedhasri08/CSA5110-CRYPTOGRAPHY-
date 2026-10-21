#include <stdio.h>
#include <string.h>

int main() {
    char cipher[] =
    "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 "
    "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* "
    ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 "
    "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    char symbols[] = "53‡†0)6*;48¶].:?(";
    char letters[] = "AGODL SITHV WYEUR";

    int i, j;

    for (i = 0; cipher[i] != '\0'; i++) {
        for (j = 0; symbols[j] != '\0'; j++) {
            if (cipher[i] == symbols[j]) {
                printf("%c", letters[j]);
                break;
            }
        }

        if (symbols[j] == '\0')
            printf("%c", cipher[i]);
    }

    return 0;
}
