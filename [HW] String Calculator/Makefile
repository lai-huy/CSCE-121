files = main.cpp string_calculator.cpp

run: clean build
	./main.out

build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out $(files)

coverage: clean $(files)
	g++ -std=c++17 -g --coverage -o coverage.out $(files)
	./coverage.out
	gcov -mr $(files)

unsanitized: clean $(files)
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out $(files)

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./unsanitized.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov *.s
