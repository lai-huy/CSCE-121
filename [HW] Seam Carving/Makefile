files = functions.cpp seamcarving.cpp

run: clean build
	./main.out Fishing175X117.ppm 170 110

build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out $(files)

coverage: clean $(files)
	g++ -std=c++17 -g --coverage -o coverage.out $(files)
	./coverage.out Fishing175X117.ppm 170 110
	gcov -mr $(files)

unsanitized: clean $(files)
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out $(files)

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./unsanitized.out Fishing175X117.ppm 170 110

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov *.s
