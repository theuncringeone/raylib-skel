CXX := g++
CXXFLAGS := -Wall -g

ifeq ($(OS),Windows_NT)
    EXECNAME := john.exe
	LINKING := -lraylib -lwinmm -lgdi32
else
    EXECNAME := john
	LINKING := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

link_and_clean: build_main
	$(CXX) $(CXXFLAGS)  "main.o" "john.o" -o $(EXECNAME) $(LINKING)
	rm -r *.o

link_dynamic_and_clean: build_main
	$(CXX) $(CXXFLAGS) "main.o" "john.o" -o $(EXECNAME) $(DYLINKING)
	rm -r *.o

build_main: build_john
	$(CXX) $(CXXFLAGS) -c "src/main.cpp"

build_john:
	$(CXX) $(CXXFLAGS) -c "src/john.cpp"
