#ifndef CALLCC_H_
#define CALLCC_H_

// The continuation type.
typedef void cont_t(int) __attribute__((noreturn));

// The callcc handler.
typedef int handler_t(cont_t);

// Calls the given handler with the current continuation. This continuation
// may be invoked at most once.
int callcc(handler_t);

#endif
