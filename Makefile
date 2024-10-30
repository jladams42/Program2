# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Target executable
TARGET = todo

# Source files
SRC = Drive.cpp linkedList.cpp dataList.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target to build the program
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Test target (if there's a separate test file or process)
test: $(TARGET)
	./$(TARGET) < test_case.txt  # Example command to run the program with test cases

# Phony targets
.PHONY: all clean test
