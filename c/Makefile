EXEC = main

BINDIR = bin
INCDIR = inc
SRCDIR = src
OBJDIR = obj

CC = gcc
INCL = -I$(INCDIR)
CFLAGS = -g -Wall

SRCFILES = $(wildcard $(SRCDIR)/*.c)
OBJFILES = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCFILES))

$(BINDIR)/$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

run:
	./$(BINDIR)/$(EXEC)

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*$(EXEC) core *~
