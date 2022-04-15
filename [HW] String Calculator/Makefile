build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out string_calculator.cpp main.cpp

coverage: clean string_calculator.cpp main.cpp
	g++ -std=c++17 -g --coverage -o coverage.out string_calculator.cpp main.cpp && ./coverage.out && gcov -mr string_calculator.cpp main.cpp

run: clean build
	./main.out

unsanitized: clean string_calculator.cpp main.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out string_calculator.cpp main.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov