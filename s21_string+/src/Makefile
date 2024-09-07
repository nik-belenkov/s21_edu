CC = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra -std=c11 $(DEBUG)
AR = ar
AR_FLAGS = rcs

current_dir = $(shell pwd)

OBJ_DIR = obj
LIB = s21_string.a
LIB_DIR = string
LIB_SRC = $(wildcard $(LIB_DIR)/*.c)
LIB_SRC_H = $(wildcard *.h)
LIB_OBJ = $(LIB_SRC:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST = test
TEST_DIR = test
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_SRC_H = $(wildcard $(TEST_DIR)/*.h)
TEST_OBJ = $(TEST_SRC:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)

BUILD_DIR = build
CLEAN = clean

CLANG_FILE=../materials/linters/.clang-format

.DEFAULT_GOAL = all
.PHONY: clean

all:  clean $(LIB) $(TEST) gcov_report

rebuild: $(CLEAN) all

$(CLEAN):
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	rm -rf $(LIB)
	rm -rf report.*

$(LIB): $(OBJ_DIR) $(LIB_OBJ) 
	$(AR) $(AR_FLAGS) $@ $(LIB_OBJ)

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c 
		$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
		$(CC) $(CFLAGS) -I. -c $< -o $@

CHECK_FLAG = -lcheck

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
    CHECK_FLAG += -D OS_MAC
else
    CHECK_FLAG += -D OS_LINUX -lpthread -pthread -lrt -lm -lsubunit
endif

$(TEST): $(TEST_OBJ) $(LIB) $(BUILD_DIR)
	$(CC)  -I. -L. --coverage $(LIB) $(TEST_OBJ) $(LIB_SRC) -o $(BUILD_DIR)/$@ $(CHECK_FLAG)
	./build/test

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

gcov_report: test
	gcov tests-s21_*.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o report.html

clang-check: clang-init
	clang-format -n $(LIB_SRC) $(LIB_SRC_H)
	clang-format -n $(TEST_SRC) $(TEST_SRC_H)

clang-fix: clang-init
	clang-format -i $(LIB_SRC) $(LIB_SRC_H)
	clang-format -i $(TEST_SRC) $(TEST_SRC_H)

clang-init:
	cp $(CLANG_FILE) .

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

valgrind:
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TEST)