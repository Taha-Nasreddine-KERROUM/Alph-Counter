#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALF 26

struct abc {
    char *a;
    int *b;
    int *c;
};

void strup(char *str, int *s) {
    for (char *p = str, *q = (char *)s; *p; ++p, ++q)
        if (*q == 1)
            *p = toupper(*p);
}

void alpha(char *str) {
    struct abc count;
    count.a = (char *)calloc(ALF, sizeof(char));
    count.b = (int *)calloc(ALF, sizeof(int));
    count.c = (int *)calloc(ALF, sizeof(int));
    if (count.a == NULL || count.b == NULL || count.c == NULL) {
        puts("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    
    int uppercaseFound[ALF] = {0};
    
    for (char *p = str; *p != '\0'; ++p) {
        if (isalpha(*p)) {
            char lower = tolower(*p);
            char *q = strchr(count.a, lower);
            if (q) {
                count.b[q - count.a]++;
            } else {
                int index = lower - 'a';
                if (isupper(*p) && !uppercaseFound[index]) {
                    uppercaseFound[index] = 1;
                    count.c[strlen(count.a)] = 1;
                }
                count.a[strlen(count.a)] = lower;
                q = strchr(count.a, lower);
                count.b[q - count.a]++;
            }
        }
    }

    strup(count.a, count.c);

    for (int i = 0; i < ALF; ++i) {
        if (count.b[i] > 0) {
            printf("%c has been repeated %d times\n", count.a[i], count.b[i]);
        }
    }

    free(count.a);
    free(count.b);
    free(count.c);
}

int main() {
    char *str = (char *)malloc(ALF * 4 * sizeof(char));
    printf("Enter a string: ");
    fgets(str, ALF * 4, stdin);
    alpha(str);
    free(str);
    return 0;
}
