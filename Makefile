debug:
	g++ *.cpp -static -g -std=c++11 -o main
release:
	g++ *.cpp -O2 -std=c++11 -o main
clean:
	rm -f main
	rm -f group_evaluation/*
