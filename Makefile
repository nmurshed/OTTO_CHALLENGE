
output: main.cpp
	g++ main.cpp -std=c++14 -o solution_executable

clean: 
	rm -rf solution_executable
