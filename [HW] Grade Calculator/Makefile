build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out grade_calculator.cpp

coverage: clean grade_calculator.cpp
	g++ -std=c++17 -g --coverage -o coverage.out grade_calculator.cpp && ./coverage.out && gcov -mr grade_calculator.cpp

run: clean build
	./main.out < ./tests/test_complete_1.txt
	./main.out < ./tests/test_complete_2.txt
	./main.out < ./tests/test_complete_3.txt
	./main.out < ./tests/test_complete_4.txt
	./main.out < ./tests/test_complete_5.txt
	./main.out < ./tests/test_complete_6.txt
	./main.out < ./tests/test_complete_7.txt
	./main.out < ./tests/test_complete_1.txt
	./main.out < ./tests/test_complete_1.txt
	./main.out < ./tests/test_complete_1.txt

unsanitized: clean grade_calculator.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out grade_calculator.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov