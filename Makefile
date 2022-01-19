# Compiler / Linker configs
CC        := gcc
CC_TEST   := g++
TEST_FLAGS:= -std=c++11
CC_FLAGS  := -c         \
             -W         \

# Directories
SRC_DIR      := src
INCLUDE_DIR  := include
LIB_DIR      := lib
BIN_DIR      := bin
OBJ_DIR      := build
TESTS_DIR    := tests
TEMPLATE_DIR := templates
PREFIX       := /usr/local

# Filenames
TARGET       := main
TEST_TARGET  := tests.out
SRC          := $(wildcard $(SRC_DIR)/*.c)
H_SRC        := $(wildcard $(INCLUDE_DIR)/*.h)
OBJ          := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#
# Compilation and linking
#
all: binFolder objFolder $(TARGET)

$(TARGET): $(OBJ)
	@echo "🚀 Building binary \"$@\" using GCC linker..."
	@$(CC) $^ -o $(BIN_DIR)/$@
	@echo "🎇 Build complete!"

$(TEST_TARGET):
	@echo "🚀 Building test binary \"$@\" using G++ linker..."
	@$(CC_TEST) $(TEST_FLAGS) $(TESTS_DIR)/*.cpp -o $(BIN_DIR)/$@
	@echo "🎇 Build complete!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "🪛  Compiling object file: $@..."
	@$(CC) $(CC_FLAGS) $< -I $(INCLUDE_DIR)/ -o $@

objFolder:
	@mkdir -p $(OBJ_DIR)

binFolder:
	@mkdir -p $(BIN_DIR)

# Cleaning binaries and static libraries (object files)
clean:
	@echo "🧹 Cleaning..."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@echo "🧹 Done!"

# Running the project
run:
	@./$(BIN_DIR)/$(TARGET)

# Run tests
test: $(TEST_TARGET)
	@echo "🏃 Running tests:\n"
	@./$(BIN_DIR)/$(TEST_TARGET)

.PHONY: all clean run
