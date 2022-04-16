build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out nth_root.cpp test_nth_root.cpp

coverage: clean nth_root.cpp test_nth_root.cpp
	g++ -std=c++17 -g --coverage -o coverage.out nth_root.cpp test_nth_root.cpp && ./coverage.out && gcov -mr nth_root.cpp test_nth_root.cpp

run: clean build
	./main.out

unsanitized: clean nth_root.cpp test_nth_root.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out nth_root.cpp test_nth_root.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov