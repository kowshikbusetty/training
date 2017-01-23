#include <stdlib.h>
#include "a.h"
struct a {
    struct b *m;
    int n;
} p;

int main()
{
    p.m = malloc (8);
    p.m->h = 9;

    return 0;

}
