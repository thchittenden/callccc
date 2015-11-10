TEST_SRCS := $(wildcard tests/*.c)
TEST_BINS := $(TEST_SRCS:.c=)

all: callcc.dylib 

callcc.dylib: callcc.c
	@mkdir -p bin
	gcc -dynamiclib -o bin/libcallcc.dylib callcc.c

tests: callcc.dylib $(TEST_BINS)

$(TEST_BINS):%:%.c
	gcc -I. -Lbin -lcallcc -o $@ $<
