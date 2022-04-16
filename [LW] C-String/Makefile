build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out main.cpp cstring.cpp

coverage: clean main.cpp cstring.cpp
	g++ -std=c++17 -g --coverage -o coverage.out main.cpp cstring.cpp && ./coverage.out && gcov -mr main.cpp cstring.cpp

run: clean build
	./main.out

unsanitized: clean main.cpp cstring.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out main.cpp cstring.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov