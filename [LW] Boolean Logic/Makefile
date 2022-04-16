build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out test.cpp boolean_functions.cpp

coverage: clean test.cpp boolean_functions.cpp
	g++ -std=c++17 -g --coverage -o coverage.out test.cpp boolean_functions.cpp && ./coverage.out && gcov -mr test.cpp boolean_functions.cpp

run: clean build
	./main.out

unsanitized: clean test.cpp boolean_functions.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out test.cpp boolean_functions.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov