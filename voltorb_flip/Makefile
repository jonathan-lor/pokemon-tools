CXX = g++

CXXFLAGS = -g -Wall

TARGET = voltorb_flip

SOURCES = main.cpp Board.cpp Cell.cpp helpers.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)