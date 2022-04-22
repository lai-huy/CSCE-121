run: clean build
	./main.out < ./tests/test_complete_1.txt
	./main.out < ./tests/test_complete_2.txt
	./main.out < ./tests/test_complete_3.txt
	./main.out < ./tests/test_complete_4.txt
	./main.out < ./tests/test_complete_5.txt
	./main.out < ./tests/test_complete_6.txt
	./main.out < ./tests/test_complete_7.txt
	./main.out < ./tests/test_engagement_1.txt
	./main.out < ./tests/test_engagement_2.txt
	./main.out < ./tests/test_engagement_3.txt
	./main.out < ./tests/test_exam_1.txt
	./main.out < ./tests/test_exam_2.txt
	./main.out < ./tests/test_exam_3.txt
	./main.out < ./tests/test_exam_4.txt
	./main.out < ./tests/test_exam_5.txt
	./main.out < ./tests/test_exam_6.txt
	./main.out < ./tests/test_hw_1.txt
	./main.out < ./tests/test_hw_2.txt
	./main.out < ./tests/test_hw_3.txt
	./main.out < ./tests/test_hw_4.txt
	./main.out < ./tests/test_lw_1.txt
	./main.out < ./tests/test_lw_2.txt
	./main.out < ./tests/test_lw_3.txt
	./main.out < ./tests/test_reading_1.txt
	./main.out < ./tests/test_reading_2.txt
	./main.out < ./tests/test_reading_3.txt

build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out grade_calculator.cpp

coverage: clean grade_calculator.cpp
	g++ -std=c++17 -g --coverage -o coverage.out grade_calculator.cpp
	./coverage.out < ./tests/test_complete_1.txt
	./coverage.out < ./tests/test_complete_2.txt
	./coverage.out < ./tests/test_complete_3.txt
	./coverage.out < ./tests/test_complete_4.txt
	./coverage.out < ./tests/test_complete_5.txt
	./coverage.out < ./tests/test_complete_6.txt
	./coverage.out < ./tests/test_complete_7.txt
	./coverage.out < ./tests/test_engagement_1.txt
	./coverage.out < ./tests/test_engagement_2.txt
	./coverage.out < ./tests/test_engagement_3.txt
	./coverage.out < ./tests/test_exam_1.txt
	./coverage.out < ./tests/test_exam_2.txt
	./coverage.out < ./tests/test_exam_3.txt
	./coverage.out < ./tests/test_exam_4.txt
	./coverage.out < ./tests/test_exam_5.txt
	./coverage.out < ./tests/test_exam_6.txt
	./coverage.out < ./tests/test_hw_1.txt
	./coverage.out < ./tests/test_hw_2.txt
	./coverage.out < ./tests/test_hw_3.txt
	./coverage.out < ./tests/test_hw_4.txt
	./coverage.out < ./tests/test_lw_1.txt
	./coverage.out < ./tests/test_lw_2.txt
	./coverage.out < ./tests/test_lw_3.txt
	./coverage.out < ./tests/test_reading_1.txt
	./coverage.out < ./tests/test_reading_2.txt
	./coverage.out < ./tests/test_reading_3.txt
	gcov -mr grade_calculator.cpp

unsanitized: clean grade_calculator.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out grade_calculator.cpp

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./unsanitized.out < ./tests/test_complete_1.txt

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov *.s
