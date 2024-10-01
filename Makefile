CC = g++ -Wall -Werror -Wextra -g -std=c++17
COVFLAGS = -fprofile-arcs -ftest-coverage
GTEST_LIB := $(shell pkg-config --libs gtest)
INCLUDE := $(shell pkg-config --cflags gtest)
BUILD_DIR = build
SANITIZE_FLAGS = -fsanitize=address

OPENOS = vi
ifeq ($(shell uname -s), Linux)
	OPENOS = xdg-open
	LCOV_GCOV = lcov --capture --directory $(BUILD_DIR) --output-file gcov_reportd/coverage.info --no-external
	GENHTML = genhtml gcov_reportd/coverage.info --output-directory gcov_reportd
endif
ifeq ($(shell uname -s), Darwin)
	OPENOS = open
	LCOV_GCOV = lcov --capture --directory $(BUILD_DIR) --output-file gcov_reportd/coverage.info --ignore-errors source,usage,inconsistent,unused --include 'library/*.h'
	GENHTML = genhtml gcov_reportd/coverage.info --output-directory gcov_reportd --ignore-errors inconsistent,corrupt
endif

SRCS := $(wildcard src/*.cpp)
TEST_SRCS := $(wildcard src/tests/*.cpp)
ALL_SRCS := $(SRCS) $(TEST_SRCS)

TEST_OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))

all: gcov_report

gcov_report: test
	$(BUILD_DIR)/test
	@mkdir -p gcov_reportd
	$(LCOV_GCOV)
	$(GENHTML)
	@$(OPENOS) ./gcov_reportd/index.html

$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(COVFLAGS) -c $< -o $@ $(INCLUDE) -I./library

test: clean $(TEST_OBJS)
	$(CC) $(COVFLAGS) $(TEST_OBJS) -o $(BUILD_DIR)/test $(GTEST_LIB)

style:
	@cp ../materials/linters/.clang-format .
	clang-format -i tests/*.cpp library/*.h
	@rm -rf .clang-format

valgrind:
	$(BUILD_DIR)/test
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(BUILD_DIR)/test > valgrind.log 2>&1

sanitize: clean
	@mkdir -p $(BUILD_DIR)
	$(CC) $(SANITIZE_FLAGS) $(ALL_SRCS) -o $(BUILD_DIR)/test_sanitize $(INCLUDE) -I./library $(GTEST_LIB)
	$(BUILD_DIR)/test_sanitize

clean:
	@rm -rf $(BUILD_DIR) gcov_reportd