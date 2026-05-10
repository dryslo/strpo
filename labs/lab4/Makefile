SRC_DIR = src
BUILD_DIR = build
CXX = g++ -g
OBJS = $(BUILD_DIR)/Circle.o $(BUILD_DIR)/List.o
MAIN_NAME = main



$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	$(CXX) -c -o $@ $<


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
