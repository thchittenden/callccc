TEST_SRCS := $(wildcard tests/*.c)
TEST_BINS := $(TEST_SRCS:.c=)

all: callcc.dylib callcc.o

callcc.dylib: callcc.c
	@mkdir -p bin
	gcc -dynamiclib -o bin/libcallcc.dylib callcc.c

callcc.o: callcc.c
	@mkdir -p bin
	gcc -c -o bin/callcc.o callcc.c

tests: callcc.o $(TEST_BINS)

$(TEST_BINS):%:%.c
	gcc -I. -o $@ bin/callcc.o $<
