#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "callcc.h"

int pipes[2];
pid_t child;

__attribute__((noreturn)) void throw(int val) {
    write(pipes[1], &val, sizeof(val));
    int status;
    waitpid(child, &status, 0);
    exit(status);
}

int callcc(handler_t handler) {
    // Create a pipe and fork. 
    pipe(pipes);
    child = fork();
    if (child == 0) {
        // In child.
        close(pipes[1]);
        int value;
        if (read(pipes[0], &value, sizeof(int)) <= 0) {
            // Parent exited normally.
            exit(0);
        } else {
            // Parent threw.
            return value;
        }
    } else {
        // In parent.
        close(pipes[0]);
        return handler(throw);
    }   
}

