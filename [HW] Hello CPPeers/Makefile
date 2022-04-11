build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp

coverage: clean Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp
	g++ -std=c++17 -g --coverage -o coverage.out Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp && ./coverage.out && gcov -mr Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp

run: clean build
	./main.out

unsanitized: clean Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov