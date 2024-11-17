# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
CMD_DIR = $(SRC_DIR)/Command
HDR_DIR = $(SRC_DIR)/Header
ADT_DIR = $(SRC_DIR)/ADT
ARRAY_DIR = $(ADT_DIR)/array
ARRAYDIN_DIR = $(ADT_DIR)/arraydin
QUEUE_DIR = $(ADT_DIR)/queue
MESINKATA_DIR = $(ADT_DIR)/mesinkata
MESINKAR_DIR = $(ADT_DIR)/mesinkarakter

# Output executable
OUTPUT = store_req.exe

# Source files
SRCS = $(CMD_DIR)/store_req.c \
       $(CMD_DIR)/start.c \
       $(ARRAY_DIR)/array.c \
       $(ARRAYDIN_DIR)/arraydin.c \
       $(QUEUE_DIR)/queue.c \
       $(MESINKATA_DIR)/mesinkata.c \
       $(MESINKAR_DIR)/mesinkarakter.c

# Object files (replace .c with .o in SRCS)
OBJS = $(SRCS:.c=.o)

# Include headers
INCLUDES = -I$(HDR_DIR) -I$(ARRAY_DIR) -I$(ARRAYDIN_DIR) -I$(QUEUE_DIR) -I$(MESINKATA_DIR) -I$(MESINKAR_DIR)

# Default target
all: $(OUTPUT)

# Build the executable
$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build files
clean:
	cmd /C "del /Q src\Command\store_req.o src\Command\start.o src\ADT\array\array.o src\ADT\arraydin\arraydin.o src\ADT\queue\queue.o src\ADT\mesinkata\mesinkata.o src\ADT\mesinkarakter\mesinkarakter.o store_req.exe"

run: $(OUTPUT)
	.\$(OUTPUT)

# Phony targets
.PHONY: all clean