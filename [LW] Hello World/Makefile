run: clean build
	./main.out

build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out hello_world.cpp

coverage: clean hello_world.cpp
	g++ -std=c++17 -g --coverage -o coverage.out hello_world.cpp && ./coverage.out && gcov -mr hello_world.cpp

unsanitized: clean hello_world.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out hello_world.cpp

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov