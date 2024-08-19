CXX = g++

CXXFLAGS = -g -Wall -std=c++17

TARGET = voltorb_flip

SOURCES = main.cpp Board.cpp Cell.cpp RowColInfo.cpp helpers.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)