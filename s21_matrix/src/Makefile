OS = $(shell uname)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
AR = ar
AR_FLAGS = rc
COV = --coverage
LCOV_FLAG = -fprofile-arcs -ftest-coverage

current_dir = $(shell pwd)

OBJ_DIR = obj
LIB = s21_matrix.a
LIB_DIR = matrix
LIB_SRC = $(wildcard $(LIB_DIR)/*.c)
LIB_SRC_H = $(wildcard *.h)
LIB_OBJ = $(LIB_SRC:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST = test
TEST_DIR = test
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_SRC_H = $(wildcard $(TEST_DIR)/*.h)
TEST_OBJ = $(TEST_SRC:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)

REPORT_DIR = report
REPORT_IND = index.html

BUILD_DIR = build
CLEAN = clean

CLANG_FILE=../materials/linters/.clang-format

CHECK_FLAG = -lcheck  -lm  -lpthread
COV_DIR = .
ifeq ($(OS), Linux)
	CHECK_FLAG += -lsubunit
	COV_DIR = ./$(BUILD_DIR)
endif

ifeq ($(OS), Darwin)
    CHECK_FLAG += -L/ -D OS_MAC
endif

.DEFAULT_GOAL = all
.PHONY: clean

all: $(LIB) $(TEST) gcov_report

rebuild: $(CLEAN) all

$(CLEAN):
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	rm -f $(LIB) 
	rm -rf report

$(LIB): $(OBJ_DIR) $(LIB_OBJ) 
	$(AR) $(AR_FLAGS) $@ $(LIB_OBJ)

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c 
		$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
		$(CC) $(CFLAGS)  -I. -I$(TEST_DIR)/ -c $< -o $@

$(TEST): $(OBJ_DIR) $(TEST_OBJ) $(LIB) $(BUILD_DIR)
	$(CC) $(LCOV_FLAG) -I. -L. $(LIB) $(TEST_OBJ) $(LIB_SRC) -o $(BUILD_DIR)/$@ $(CHECK_FLAG)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

gcov_report: $(TEST)
	./$(BUILD_DIR)/$(TEST)
	rm -rf $(REPORT_DIR)
	mkdir $(REPORT_DIR) 
	lcov -t "Test_functons" -o $(REPORT_DIR)/test-funct.info -c -d $(COV_DIR)
	genhtml -o $(REPORT_DIR) $(REPORT_DIR)/test-funct.info
	rm $(COV_DIR)/*.gcda $(COV_DIR)/*.gcno

clang-check: clang-init
	clang-format -n $(LIB_SRC) $(LIB_SRC_H)
	clang-format -n $(TEST_SRC) $(TEST_SRC_H)
	rm -rf .clang-format

clang-fix: clang-init
	clang-format -i $(LIB_SRC) $(LIB_SRC_H)
	clang-format -i $(TEST_SRC) $(TEST_SRC_H)
	rm -rf .clang-format

clang-init:
	cp $(CLANG_FILE) .

check: clang-check cppcheck
	
cppcheck:
	cppcheck --check-config --enable=all --force --suppress=missingIncludeSystem -I. $(LIB_SRC) $(LIB_SRC_H) $(TEST_SRC) $(TEST_SRC_H)