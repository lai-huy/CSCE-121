files = LinkedList.cpp main.cpp Node.cpp TemperatureData.cpp TemperatureDatabase.cpp

run: clean build
	./main.out "temps.dat" "queries.dat"

build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out $(files)

coverage: clean $(files)
	g++ -std=c++17 -g --coverage -o coverage.out $(files)
	./coverage.out
	gcov -mr $(files)

unsanitized: clean $(files)
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out $(files)

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./unsanitized.out "temps.dat" "queries.dat"

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov *.s sorted.* results.dat
