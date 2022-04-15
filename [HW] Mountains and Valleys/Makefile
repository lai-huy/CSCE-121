build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out functions.cpp mountains_valleys.cpp

coverage: clean functions.cpp mountains_valleys.cpp
	g++ -std=c++17 -g --coverage -o coverage.out functions.cpp mountains_valleys.cpp && ./coverage.out && gcov -mr functions.cpp mountains_valleys.cpp

run: clean build
	./main.out

unsanitized: clean functions.cpp mountains_valleys.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out functions.cpp mountains_valleys.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov