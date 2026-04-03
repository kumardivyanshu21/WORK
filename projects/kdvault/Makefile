# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
TARGET = kdvault
SRCS = src/main.cpp src/vaultfile.cpp
OBJS = $(SRCS:.cpp=.o)

# The "all" rule (Default)
all: $(TARGET)

# Link the object files to create the final app
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the mess
clean:
	rm -f src/*.o $(TARGET)