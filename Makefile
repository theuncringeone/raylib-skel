CXX := g++
CXXFLAGS := -Wall -g

ifeq ($(OS),Windows_NT)
    EXECNAME := john.exe
	LINKING := -L./lib -lraylib -lwinmm -lgdi32
else
    EXECNAME := john
	LINKING := -L./lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

link_and_clean: build_main
	$(CXX) $(CXXFLAGS) "main.o" "john.o" -o $(EXECNAME) $(LINKING)
	rm -r *.o

build_main: build_john
	$(CXX) $(CXXFLAGS) -c "src/main.cpp" 

build_john:
	$(CXX) $(CXXFLAGS) -c "src/john.cpp"
