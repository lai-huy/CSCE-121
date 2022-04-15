build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out functions.cpp seamcarving.cpp

coverage: clean functions.cpp seamcarving.cpp
	g++ -std=c++17 -g --coverage -o coverage.out functions.cpp seamcarving.cpp && ./coverage.out && gcov -mr functions.cpp seamcarving.cpp

run: clean build
	./main.out sunset1080X673.ppm 1024 673

unsanitized: clean functions.cpp seamcarving.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out functions.cpp seamcarving.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov