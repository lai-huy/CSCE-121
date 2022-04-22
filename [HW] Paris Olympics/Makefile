files = main.cpp parallel_tracks.cpp

run: clean build
	./main.out < ./tests/bad_tests.txt
	./main.out < ./tests/good_test_01.txt
	./main.out < ./tests/good_test_02.txt
	./main.out < ./tests/good_test_03.txt
	./main.out < ./tests/good_test_04.txt
	./main.out < ./tests/good_test_05.txt

build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out $(files)

coverage: clean $(files)
	g++ -std=c++17 -g --coverage -o coverage.out $(files)
	./coverage.out < ./tests/bad_tests.txt
	./coverage.out < ./tests/good_test_01.txt
	./coverage.out < ./tests/good_test_02.txt
	./coverage.out < ./tests/good_test_03.txt
	./coverage.out < ./tests/good_test_04.txt
	./coverage.out < ./tests/good_test_05.txt
	gcov -mr $(files)

unsanitized: clean $(files)
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out $(files)

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./unsanitized.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov *.s
