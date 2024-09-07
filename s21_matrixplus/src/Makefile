OS = $(shell uname)
CC := g++
CPP_FLAGS := -Wall -Werror -Wextra -std=c++17 
CPP_FLAGS_TESTING := -lgtest -lgtest_main -pthread -lsubunit
CPP_FLAGS_GCOV := -fprofile-arcs -ftest-coverage
LCOV_FLAG := --no-external
ifeq ($(OS), Darwin)
	CPP_FLAGS_TESTING := -lgtest
	LCOV_FLAG := --no-external --ignore-errors inconsistent
endif
SOURCES := s21_matrix_oop.cpp
OBJECTS := $(SOURCES:.cpp=.o)
SOURCES_TEST := test_matrix_oop.cpp
OBJECTS_TEST := $(SOURCES_TEST:.cpp=.o)
S21MATRIXPLUS := s21_matrix_oop.a
FLAG_VALGRIND := --trace-children=yes --tool=memcheck --leak-check=yes  --track-origins=yes -s

all: $(S21MATRIXPLUS) test gcov_report

clean:
	rm -fr coverage_report
	rm -f *.log
	rm -f *.gcda *.gcno *.info
	rm -f $(OBJECTS_TEST)
	rm -f $(OBJECTS);
	rm -f $(S21MATRIXPLUS)
	rm -f *.out
	rm -rf a.out.dSYM

$(S21MATRIXPLUS): $(SOURCES) $(OBJECTS)
	ar rcs $(S21MATRIXPLUS) $(OBJECTS)
	rm -f *.o

.cpp.o:
	$(CC) $(CPP_FLAGS) -c $< -o $@ 

test: clean 
	make $(S21MATRIXPLUS) CPP_FLAGS="$(CPP_FLAGS_TESTING)"
	$(CC) $(CPP_FLAGS) -g $(SOURCES_TEST) $(S21MATRIXPLUS) $(CPP_FLAGS_TESTING) $(CPP_FLAGS_GCOV) 
	./a.out
	
gcov_report: clean 
	$(CC) $(CPP_FLAGS) -g $(SOURCES_TEST) $(SOURCES) $(CPP_FLAGS_TESTING) $(CPP_FLAGS_GCOV)
	./a.out
	lcov --gcov-tool gcov  --capture --directory . --output-file coverage.info --test-name gcov_report $(LCOV_FLAG)
	genhtml coverage.info -o coverage_report
	open coverage_report/index.html

valgrind_test: clean test
	valgrind  $(FLAG_VALGRIND) ./a.out

cppcheck:
	cppcheck --check-config --enable=all --force --suppress=missingIncludeSystem -I. *.cpp *.hpp

clang_check: clang_init
	clang-format -n *.cpp *.hpp
	rm -rf .clang-format

clang_fix: clang_init
	clang-format -i *.cpp *.hpp
	rm -rf .clang-format

clang_init:
	cp ../materials/linters/.clang-format .