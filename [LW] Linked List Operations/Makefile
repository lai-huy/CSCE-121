build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out tests.cpp linked_list.cpp

coverage: clean tests.cpp linked_list.cpp
	g++ -std=c++17 -g --coverage -o coverage.out tests.cpp linked_list.cpp && ./coverage.out && gcov -mr tests.cpp linked_list.cpp

run: clean build
	./main.out

unsanitized: clean tests.cpp linked_list.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -S -o unsanitized.out tests.cpp linked_list.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov
