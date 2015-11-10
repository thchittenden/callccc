#include <stdio.h>
#include "callcc.h"

int x = 42;
cont_t* cont;

int handler(cont_t ccont) {
    cont = ccont;
    return -1;
}

int main() {
    int res = callcc(handler);
    printf("%d\n", x);
    x = 0;
    if (res < 0) {
        cont(1);
    }
}
