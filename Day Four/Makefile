CXX      := -g++
CXXFLAGS := -std=c++11 -pedantic-errors -O0 -g
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
INCLUDE  := -Iinclude/
SRC      :=                      \
	$(wildcard src/*.cpp)         \
	$(wildcard src/test_menu/*.cpp)         \
	$(wildcard src/hc_socket/*.cpp)         \
	$(wildcard src/hc_server/*.cpp)         \
	$(wildcard src/hc_client/*.cpp)         \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS) -lpthread

.PHONY: all build clean

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf build/*