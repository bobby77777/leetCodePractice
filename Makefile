SRC_DIR := src/leetcode
BUILD_DIR := build/bin

C_SRCS := $(wildcard $(SRC_DIR)/*.c)
CPP_SRCS := $(wildcard $(SRC_DIR)/*.cpp)

C_BINS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(C_SRCS))
CPP_BINS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%,$(CPP_SRCS))
TARGETS := $(C_BINS) $(CPP_BINS)

CC := cc
CXX := c++
CFLAGS := -Wall -Wextra
CXXFLAGS := -std=c++17 -Wall -Wextra

.PHONY: all clean list run help

all: $(TARGETS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

list:
	@printf '%s\n' $(notdir $(basename $(C_SRCS))) $(notdir $(basename $(CPP_SRCS))) | sort

run:
ifndef FILE
	$(error FILE is required. Example: make run FILE=1 or make run FILE=1_twoSum)
endif
	@matches=$$(ls $(SRC_DIR)/$(FILE)_*.c $(SRC_DIR)/$(FILE)_*.cpp $(SRC_DIR)/$(FILE).c $(SRC_DIR)/$(FILE).cpp 2>/dev/null); \
	if [ -z "$$matches" ]; then \
		echo "No source file found for '$(FILE)' in $(SRC_DIR)"; \
		exit 1; \
	fi; \
	count=$$(echo "$$matches" | wc -w); \
	if [ "$$count" -gt 1 ]; then \
		echo "Multiple matches for '$(FILE)': $$matches"; \
		exit 1; \
	fi; \
	src="$$matches"; \
	base=$$(basename "$$src"); \
	name="$${base%.*}"; \
	$(MAKE) "$(BUILD_DIR)/$$name" && "./$(BUILD_DIR)/$$name"

clean:
	rm -rf build/*

help:
	@echo "make all            Build all LeetCode files"
	@echo "make list           List available problem targets"
	@echo "make run FILE=name  Build and run one problem"
	@echo "make clean          Remove generated build output"
