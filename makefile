UNAME := $(shell uname -m)

ifeq ($(UNAME), x86_64)
	LALLEG     := -L/usr/lib/x86_64-linux-gnu -lalleg
endif

ifeq ($(UNAME), i386)
	LALLEG     := -L/usr/lib/i386-linux-gnu -lalleg
endif

ifeq ($(UNAME), i686)
	LALLEG     := -L/usr/lib/i386-linux-gnu -lalleg
endif

CC       := gcc
TARGET   := exec
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
CFLAGS   := -g -Wall -Wextra
LIBS     := -L/usr/lib -lm $(LALLEG)
INCLUDE  := -I/usr/include/
SRC      :=                    \
	$(wildcard *.c)             #\
	#$(wildcard src/*.c)         \
	#$(wildcard src/module1/*.c) \
	#$(wildcard src/module2/*.c)

HEADERS  :=                        \
	$(wildcard *.h)                 #\
	#$(wildcard headers/*.h)         \
	#$(wildcard headers/module1/*.h) \
	#$(wildcard headers/module2/*.h)

OBJECTS := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

.PHONY: all build debug release clean mrproper

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CFLAGS += -DDEBUG -Werror
debug: all

release: CFLAGS += -O2
release: all

clean:
	@rm -rvf $(OBJ_DIR)

mrproper: clean
	@rm -rvf $(BUILD)
