# Heavily based on https://makefiletutorial.com/
TARGET_EXEC := lorenz

BUILD_DIR := ./build
SRC_DIRS := ./src

# Search for all c files in SRC_DIRS
SRCS := $(shell find $(SRC_DIRS) -name '*.c')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Generate dependancy files
CPPFLAGS := $(INC_FLAGS) -MMD -MP

CFLAGS := -Wall -Wextra -Wpedantic -Werror -Wshadow

# Final build
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile C files
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)
