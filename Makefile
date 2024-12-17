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
LIST_DIR = $(ADT_DIR)/list
SETMAP_DIR = $(ADT_DIR)/setmap
STACK_DIR = $(ADT_DIR)/stack
LINKEDLIST_DIR = $(ADT_DIR)/listlinier
ROOT_SRCS = misc.c

# Output executable
OUTPUT = main.exe

# Source files
SRCS = $(ROOT_SRCS) \
       $(ARRAY_DIR)/array.c \
       $(ARRAYDIN_DIR)/arraydin.c \
       $(QUEUE_DIR)/queue.c \
       $(CMD_DIR)/store_req.c \
       $(CMD_DIR)/store_sup.c \
       $(CMD_DIR)/store_rmv.c \
       $(CMD_DIR)/store_list.c \
       $(CMD_DIR)/tebakangka.c \
       $(CMD_DIR)/start.c \
       $(CMD_DIR)/load.c \
       $(CMD_DIR)/login.c \
       $(CMD_DIR)/logout.c \
       $(CMD_DIR)/register.c \
       $(CMD_DIR)/wishlist_add.c \
       $(CMD_DIR)/wishlist_swap.c \
       $(CMD_DIR)/wishlist_clear.c \
       $(CMD_DIR)/wishlist_show.c \
       $(CMD_DIR)/wishlist_remove_ver1.c \
       $(CMD_DIR)/wishlist_remove_ver2.c \
       $(CMD_DIR)/cart_add.c \
       $(CMD_DIR)/cart_remove.c \
       $(CMD_DIR)/cart_show.c \
       $(CMD_DIR)/cart_pay.c \
       $(CMD_DIR)/history.c \
       $(CMD_DIR)/save.c \
       $(CMD_DIR)/help.c \
       $(CMD_DIR)/work.c \
       $(CMD_DIR)/work_challenge.c \
       $(CMD_DIR)/wordl399.c \
       $(CMD_DIR)/main.c \
       $(CMD_DIR)/quit.c \
       $(SETMAP_DIR)/map.c \
       $(STACK_DIR)/stack.c \
       $(LINKEDLIST_DIR)/dplinkedlist.c \
       $(MESINKATA_DIR)/mesinkata.c \
       $(MESINKAR_DIR)/mesinkarakter.c \
       $(CMD_DIR)/profile.c \


# Object files (replace .c with .o in SRCS)
OBJS = $(SRCS:.c=.o)

# Include headers
INCLUDES = -I$(SRC_DIR) -I$(HDR_DIR) -I$(ARRAY_DIR) -I$(ARRAYDIN_DIR) -I$(QUEUE_DIR) -I$(MESINKATA_DIR) -I$(MESINKAR_DIR) -I$(LIST_DIR)

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
	cmd /C "del /Q main.exe misc.o src\Command\history.o src\Command\wishlist_show.o src\Command\wishlist_clear.o src\Command\cart_pay.o src\Command\cart_show.o src\Command\cart_remove.o src\Command\cart_add.o src\Command\profile.o src\Command\wishlist_remove_ver2.o src\Command\wishlist_remove_ver1.o src\Command\wishlist_swap.o src\Command\wishlist_add.o src\Command\quit.o src\Command\wordl399.o src\Command\work_challenge.o src\Command\login.o src\Command\logout.o src\Command\register.o src\Command\tebakangka.o src\Command\save.o src\Command\help.o src\Command\main.o src\Command\store_list.o src\Command\load.o src\Command\work.o src\Command\store_req.o src\Command\start.o src\Command\store_sup.o src\Command\store_rmv.o src\ADT\array\array.o src\ADT\arraydin\arraydin.o src\ADT\queue\queue.o src\ADT\mesinkata\mesinkata.o src\ADT\mesinkarakter\mesinkarakter.o src\ADT\listlinier\dplinkedlist.o src\ADT\setmap\map.o src\ADT\stack\stack.o"

run: $(OUTPUT)
	.\$(OUTPUT)

# Phony targets
.PHONY: all clean