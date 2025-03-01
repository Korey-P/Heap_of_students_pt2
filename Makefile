CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = student_db

OBJ = main.o student.o address.o date.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp student.h address.h date.h
	$(CXX) $(CXXFLAGS) -c main.cpp

student.o: student.cpp student.h address.h date.h
	$(CXX) $(CXXFLAGS) -c student.cpp

address.o: address.cpp address.h
	$(CXX) $(CXXFLAGS) -c address.cpp

date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c date.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
