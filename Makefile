#
# Makefile
#
# MathEngine
# Author: Daniel Rill
# Date : 10.05.2021
#

CXX=g++
CXXFLAGS = -g -Wall -Wextra -std=c++11 -pedantic


TARGET = main
OBJECTS = \
    Constants.h \
    E4DVector.o \
    E4DMatrix.o \
	
all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)
	
$(TARGET): $(TARGET).o $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^
	
