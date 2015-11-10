# call/ccc

## Synopsis

This is an implementation of call/cc in C. It's very similar to setjmp/longjmp 
but does not rely on compiler wizardry to get things right. 

## Code Example

The following trivial example will print 3 to the console:

```
#include "callcc.h"

int handler(cont_t cont) {
    cont(3);
    return 0;
}

int main() {
    int res = callcc(handler);   
    printf("%d\n", res);
    return 0;
}
```

## Motivation

Peirce's law should be more than just be a logical proposition.

