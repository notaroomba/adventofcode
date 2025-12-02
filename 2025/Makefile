# Makefile for Advent of Code 2025
# Compiles and runs numbered C files (1.c, 2.c, 3.c, etc.)

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS =

# Automatically find all numbered .c files
SOURCES = $(wildcard [0-9].c [0-9][0-9].c)
EXECUTABLES = $(SOURCES:.c=.exe)

# Default target
.PHONY: all
all: $(EXECUTABLES)

# Pattern rule to compile any numbered .c file to .exe
%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Run a specific day (usage: make run DAY=1)
.PHONY: run
run:
ifndef DAY
	@echo "Usage: make run DAY=<number>"
	@echo "Example: make run DAY=1"
else
	@$(MAKE) $(DAY).exe
	@echo "Running day $(DAY)..."
	@./$(DAY).exe
endif

# Clean all executables
.PHONY: clean
clean:
	rm -f $(EXECUTABLES)

# List all available days
.PHONY: list
list:
	@echo "Available days:"
	@echo "$(SOURCES:.c=)"

# Help message
.PHONY: help
help:
	@echo "Advent of Code 2025 Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make all          - Compile all numbered C files"
	@echo "  make run DAY=N    - Compile and run day N (e.g., make run DAY=1)"
	@echo "  make N.exe        - Compile specific day N"
	@echo "  make clean        - Remove all executables"
	@echo "  make list         - List all available days"
	@echo "  make help         - Show this help message"
