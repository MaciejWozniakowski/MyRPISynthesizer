IDIR = ../include/
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = ./obj
LDIR = ../lib/

LIBS = -lasound

_DEPS = midi_handling.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.c midi_handling.c
OBJ = $(patsubst %.c, $(ODIR)/%.o, $(_OBJ))  # Correcting this line to reflect object files

# Ensure obj directory exists
$(ODIR):
	mkdir -p $(ODIR)

# Compile source files to object files
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Link object files into the final executable
all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
