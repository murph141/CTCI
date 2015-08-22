GCC = gcc
PARAMS = #Override in command line (or here) is parameters are present
DIRECTORY = #(Override in command line (or here) if you want to compile a different directory
CFLAGS = -Werror -Wbad-function-cast -Wall -Wshadow -ggdb3
SOURCES = main.c
OBJS = $(SOURCES:.c=.o)
HDRS = includes/*.h
EXECUTABLE = $(SOURCES:.c=)
LOGFILE = log
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --log-file=$(DIRECTORY)/$(LOGFILE) --track-origins=yes

.PHONY: clean test all run

all: $(DIRECTORY)/$(SOURCES) $(DIRECTORY)/$(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

test: all
	$(VALGRIND) $(DIRECTORY)/$(EXECUTABLE) $(PARAMS)

run: all
	./$(DIRECTORY)/$(EXECUTABLE) $(PARAMS)

clean:
	rm -f $(DIRECTORY)/$(OBJS) $(DIRECTORY)/$(EXECUTABLE) $(DIRECTORY)/$(LOGFILE)
