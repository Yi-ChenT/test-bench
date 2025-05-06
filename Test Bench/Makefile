CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = program

SRCS = main.c test_harness.c logger.c

OBJS = $(SRCS.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
