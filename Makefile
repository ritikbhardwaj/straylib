# Compiler
CXX := clang++

# paths
BUILD_PATH := build
OBJ_PATH := obj
SRC_PATH := src
INCLUDE_PATH := include
LIB_PATH := lib

# Compile
CXXFLAGS := -g -I $(INCLUDE_PATH) -std=c++11
COBJFLAGS :=

# Link
LDFLAGS := -L $(LIB_PATH) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LDLIBS := -lraylib

TARGET_NAME := app
ifeq ($(OS), Windows_NT)
	TARGET_NAME := $(addsuffix .exe, $(TARGET_NAME))
endif
TARGET := $(BUILD_PATH)/$(TARGET_NAME)
TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*, .cpp)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ)

CLEAN_LIST := $(TARGET) $(DISTCLEAN_LIST)

default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CXX) $(CXXFLAGS) $(COBJFLAGS) -c -o $@ $<

# phony rules
.PHONY: run
run:
	./$(TARGET)

.PHONY: makedir
makedir:
	@mkdir -p $(BUILD_PATH) $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
