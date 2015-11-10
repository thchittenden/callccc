#include <stdio.h>
#include <signal.h>
#include "callcc.h"

void* ptr;
cont_t* cont;
void pf_handler() {
    cont(-1);
}

int is_valid_handler(cont_t _cont) {
    cont = _cont;
    int x = *(volatile int *)ptr;
    (void)x;
    return 0;
}

int is_valid(void* _ptr) {
    ptr = _ptr;
    signal(SIGSEGV, pf_handler);
    return callcc(is_valid_handler);
}

int main() {

    int x;
    printf("0x1337beef: %d\n", is_valid((void*)0x1337beef));
    printf("0xdeadf00d: %d\n", is_valid((void*)0xdeadf00d));
    printf("0x%p: %d\n", (void*)&x, is_valid((void*)&x));

}
