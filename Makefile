ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc
CFLAGS_COMMON = -Wall -Wextra -Werror
CFLAGS_DEBUG = -g -O0
CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_DEBUG)
MAKE = make

# Build Directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Debug
DEBUG_BIN = $(BIN_DIR)/debug.out

DEBUG_DIR = debug
DEBUG_SRC = $(wildcard $(DEBUG_DIR)/*.c)

DEBUG_OBJ_DIR = $(OBJ_DIR)/debug
DEBUG_OBJ = $(patsubst $(DEBUG_DIR)/%.c,$(DEBUG_OBJ_DIR)/%.o,$(DEBUG_SRC))

# Tests
TEST_BIN = $(BIN_DIR)/test.out

TEST_OBJ_DIR = $(OBJ_DIR)/test
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c,$(TEST_OBJ_DIR)/%.o,$(TEST_SRC))

TEST_DIR = test
TEST_SRC = $(TEST_DIR)/test.c $(TEST_DIR)/munit.c

# App
APP_BIN = $(BIN_DIR)/ #insert here
APP_INCLUDE = include

APP_OBJ_DIR = $(OBJ_DIR)/src
APP_OBJ = $(patsubst $(APP_DIR)/%.c,$(APP_OBJ_DIR)/%.o,$(APP_SRC))

APP_DIR = src
APP_SRC = $(wildcard $(APP_DIR)/*.c)

# Libft
LIBFT_DIR = libft
LIBFT_BIN = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = $(LIBFT_DIR)/include
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)


#-----------------------------------------------------------------------------------------------------------#
# Rules
#-----------------------------------------------------------------------------------------------------------#
all:  $(APP_BIN) $(DEBUG_BIN) $(TEST_BIN)

app: $(APP_BIN)

debug: $(DEBUG_BIN)

test: $(TEST_BIN)

run-test: $(TEST_BIN)
	./$(TEST_BIN)

debug-test: $(TEST_BIN)
	gdb $(TEST_BIN)

clean:
	rm -rf $(DEBUG_BIN) $(DEBUG_OBJ) $(TEST_BIN) $(TEST_OBJ) $(APP_BIN) $(APP_OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: clean
	$(MAKE) all

.PHONY: all app debug test clean re run-test

# Debug
$(DEBUG_BIN): $(DEBUG_OBJ)
	$(CC) $(CFLAGS) -o $@ $(DEBUG_OBJ) -L$(LIBFT_DIR) -lft
$(DEBUG_OBJ): $(DEBUG_OBJ_DIR)/%.o: $(DEBUG_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(APP_INCLUDE) $< -o $@

# Tests
$(TEST_BIN): $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) -L$(LIBFT_DIR) -lft
$(TEST_OBJ): $(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(APP_INCLUDE) $< -o $@

# App
$(APP_BIN): $(LIBFT_BIN) $(APP_OBJ)
	$(CC) $(CFLAGS) -o $@ $(APP_OBJ) -L$(LIBFT_DIR) -lft
$(APP_OBJ): $(APP_OBJ_DIR)/%.o: $(APP_DIR)/%.c
	$(CC) $(CFLAGS) -I$(APP_INCLUDE) -I$(LIBFT_INCLUDE) -c $< -o $@

# Libft
$(LIBFT_BIN):
	$(MAKE) -C $(LIBFT_DIR)

#-----------------------------------------------------------------------------------------------------------#
