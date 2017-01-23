#include <stdio.h>

int main(void)
{
    char *v[] = {"abc", "efg", "jkl"};
    char **p;
    p = v;
    printf("%c\n", *++p[0]);
    printf("%c\n", (*++p)[0]);
    return 0;
}
