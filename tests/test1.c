#include <stdio.h>
#include "callcc.h"

cont_t* cont;

int handler(cont_t ccont) {
    cont = ccont;
    return -1;
}

int main() {
    int res = callcc(handler);
    printf("%d\n", res);
    if (res < 0) {
        cont(2);
    }
}
