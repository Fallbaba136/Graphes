CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = tp3
SOURCES = src/tp3.cpp src/matrice.cpp src/fifo.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)