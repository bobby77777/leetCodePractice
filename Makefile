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
	$(error FILE is required. Example: make run FILE=15_3Sum)
endif
	@src=""
	@for ext in c cpp; do \
		if [ -f "$(SRC_DIR)/$(FILE).$$ext" ]; then \
			src="$(SRC_DIR)/$(FILE).$$ext"; \
			break; \
		fi; \
	done; \
	if [ -z "$$src" ]; then \
		echo "No source file found for $(FILE) in $(SRC_DIR)"; \
		exit 1; \
	fi; \
	$(MAKE) "$(BUILD_DIR)/$(FILE)" && "./$(BUILD_DIR)/$(FILE)"

clean:
	rm -rf build/*

help:
	@echo "make all            Build all LeetCode files"
	@echo "make list           List available problem targets"
	@echo "make run FILE=name  Build and run one problem"
	@echo "make clean          Remove generated build output"
