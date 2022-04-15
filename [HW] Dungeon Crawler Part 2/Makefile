build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out dungeoncrawler.cpp helper.cpp logic.cpp

coverage: clean dungeoncrawler.cpp helper.cpp logic.cpp
	g++ -std=c++17 -g --coverage -o coverage.out dungeoncrawler.cpp helper.cpp logic.cpp && ./coverage.out && gcov -mr dungeoncrawler.cpp helper.cpp logic.cpp

run: clean build
	./main.out

unsanitized: clean dungeoncrawler.cpp helper.cpp logic.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out dungeoncrawler.cpp helper.cpp logic.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov