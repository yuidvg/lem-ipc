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
TEST_DIR = test

# Unit Tests
UNIT_TEST_BIN = $(BIN_DIR)/unit_test.out

UNIT_TEST_OBJ_DIR = $(OBJ_DIR)/unit_test
UNIT_TEST_OBJ = $(patsubst $(UNIT_TEST_DIR)/%.c,$(UNIT_TEST_OBJ_DIR)/%.o,$(UNIT_TEST_SRC))

UNIT_TEST_DIR = $(TEST_DIR)/unit
UNIT_TEST_SRC = $(UNIT_TEST_DIR)/test.c $(UNIT_TEST_DIR)/munit.c

# E2E Tests
E2E_TEST_BIN = $(BIN_DIR)/e2e_test.out

E2E_TEST_OBJ_DIR = $(OBJ_DIR)/e2e_test
E2E_TEST_OBJ = $(patsubst $(E2E_TEST_DIR)/%.c,$(E2E_TEST_OBJ_DIR)/%.o,$(E2E_TEST_SRC))

E2E_TEST_DIR = $(TEST_DIR)/e2e
E2E_TEST_SRC = $(E2E_TEST_DIR)/test.c $(E2E_TEST_DIR)/munit.c

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

run-test: run-unit-test run-e2e-test
test: $(UNIT_TEST_BIN) $(E2E_TEST_BIN)

run-unit-test: $(UNIT_TEST_BIN)
	./$(UNIT_TEST_BIN)
debug-unit-test: $(UNIT_TEST_BIN)
	gdb $(UNIT_TEST_BIN)
unit-test: $(UNIT_TEST_BIN)


run-e2e-test: $(E2E_TEST_BIN)
	./$(E2E_TEST_BIN)
e2e-test: $(E2E_TEST_BIN)


clean:
	rm -rf $(DEBUG_BIN) $(DEBUG_OBJ) $(TEST_BIN) $(TEST_OBJ) $(APP_BIN) $(APP_OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: clean
	$(MAKE) all

.PHONY: all app debug test clean re run-test run-unit-test run-e2e-test debug-unit-test unit-test e2e-test

# Debug
$(DEBUG_BIN): $(DEBUG_OBJ)
	$(CC) $(CFLAGS) -o $@ $(DEBUG_OBJ) -L$(LIBFT_DIR) -lft
$(DEBUG_OBJ): $(DEBUG_OBJ_DIR)/%.o: $(DEBUG_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(APP_INCLUDE) $< -o $@

# Unit Tests
$(UNIT_TEST_BIN): $(UNIT_TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(UNIT_TEST_OBJ) -L$(LIBFT_DIR) -lft
$(UNIT_TEST_OBJ): $(UNIT_TEST_OBJ_DIR)/%.o: $(UNIT_TEST_DIR)/%.c
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
