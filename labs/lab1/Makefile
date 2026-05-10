SRC_DIR = src
BUILD_DIR = build
CXX = g++ -g
OBJS = $(BUILD_DIR)/rect.o $(BUILD_DIR)/my_string.o $(BUILD_DIR)/barrel.o $(BUILD_DIR)/matrix.o $(BUILD_DIR)/text_wrapper.o
SRC_DIR = src
MAIN_NAME = lab1

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	$(CXX) -c -o $@ $<

$(SRC_DIR)/text_wrapper.hpp: $(SRC_DIR)/my_string.hpp

$(BUILD_DIR)/debug.out: $(SRC_DIR)/$(MAIN_NAME).cpp $(OBJS)
	$(CXX) -o $@ $^

$(BUILD_DIR)/leaks.out: $(SRC_DIR)/$(MAIN_NAME).cpp $(OBJS)
	$(CXX) -o $@ $^ -fsanitize=address

debug: $(BUILD_DIR)/debug.out
	gdb ./$(BUILD_DIR)/debug.out

run: $(BUILD_DIR)/debug.out
	./$(BUILD_DIR)/debug.out
	
leaks: $(BUILD_DIR)/leaks.out
	./$(BUILD_DIR)/leaks.out


build/test_rect_basic_methods.out: tests/test_rect_basic_methods.cpp build/rect.o
	g++ -g -o build/test_rect_basic_methods.out tests/test_rect_basic_methods.cpp build/rect.o

build/test_rect_properties.out: tests/test_rect_properties.cpp build/rect.o
	g++ -g -o build/test_rect_properties.out tests/test_rect_properties.cpp build/rect.o

build/test_rect_operations.out: tests/test_rect_operations.cpp build/rect.o
	g++ -g -o build/test_rect_operations.out tests/test_rect_operations.cpp build/rect.o

build/test_bounding_rect.out: tests/test_bounding_rect.cpp build/rect.o
	g++ -g -o build/test_bounding_rect.out tests/test_bounding_rect.cpp build/rect.o

debug: build/debug.out
	gdb ./build/debug.out

run: build/debug.out
	./build/debug.out

leaks: build/leaks.out
	./build/leaks.out

test: build/test_rect_basic_methods.out build/test_rect_properties.out build/test_rect_operations.out build/test_bounding_rect.out 
	./build/test_rect_basic_methods.out
	./build/test_rect_properties.out
	./build/test_rect_operations.out
	./build/test_bounding_rect.out
	