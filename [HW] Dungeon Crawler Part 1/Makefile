build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out -S tests.cpp

coverage: clean tests.cpp
	g++ -std=c++17 -g --coverage -o coverage.out tests.cpp && ./coverage.out && gcov -mr tests.cpp

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov