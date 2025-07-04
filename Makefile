EXEC = algoritmos_ordem
CXX = g++
CXXFLAGS = -Wall -O2

SRC = main.cpp \
      bubble_sort.cpp \
      insertion_sort.cpp \
      selection_sort.cpp \
      merge_sort.cpp \
      quick_sort.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

clean:
	rm -f $(EXEC) *.o