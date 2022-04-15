build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out main.cpp parallel_tracks.cpp

coverage: clean main.cpp parallel_tracks.cpp
	g++ -std=c++17 -g --coverage -o coverage.out main.cpp parallel_tracks.cpp && ./coverage.out && gcov -mr main.cpp parallel_tracks.cpp

run: clean build
	./main.out < ./tests/bad_tests.txt
	./main.out < ./tests/good_test_01.txt
	./main.out < ./tests/good_test_02.txt
	./main.out < ./tests/good_test_03.txt
	./main.out < ./tests/good_test_04.txt
	./main.out < ./tests/good_test_05.txt

unsanitized: clean main.cpp parallel_tracks.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out main.cpp parallel_tracks.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov