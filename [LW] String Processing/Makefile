files = calculator.cpp deobfuscate.cpp filter.cpp palindrome.cpp password.cpp

run: clean
	for file in $(files) ; do \
		g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out $$file ; \
		./main.out ; \
	done

coverage: clean $(files)
	g++ -std=c++17 -g --coverage -o coverage.out $(files)
	./coverage.out
	gcov -mr $(files)

unsanitized: clean $(files)
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out $(files)

check: clean unsanitized
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./unsanitized.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov *.s
