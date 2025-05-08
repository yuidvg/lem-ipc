#Compiler Preferences
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS_LEAK = -g -fsanitize=leak
CFLAGS_DEBUG = -g -DDEBUG

OBJ_DIR = obj
DEBUG_OBJ_DIR = $(OBJ_DIR)/debug

BIN = libft.a
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
INCLUDE_DIR = include

BIN_DEBUG = libftdebug.a
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c, $(DEBUG_OBJ_DIR)/%.o, $(SRC))
DEBUG_INCLUDE = $(INCLUDE_DIR)

all: $(BIN)
$(BIN): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

debug: $(BIN_DEBUG)
$(BIN_DEBUG): $(DEBUG_OBJ)
	ar rcs $@ $^

$(DEBUG_OBJ): $(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS_DEBUG) -I$(SRC_DIR) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEBUG_OBJ)

fclean: clean
	rm -f $(BIN) $(BIN_DEBUG)

re: fclean
	@$(MAKE) all

.PHONY: fclean all re clean debug
