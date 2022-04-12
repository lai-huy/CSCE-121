build:
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o main.out Database.cpp Driver.cpp Passport.cpp StatePark.cpp

coverage: clean Database.cpp Driver.cpp Passport.cpp StatePark.cpp
	g++ -std=c++17 -g --coverage -o coverage.out Database.cpp Driver.cpp Passport.cpp StatePark.cpp && ./coverage.out && gcov -mr Database.cpp Driver.cpp Passport.cpp StatePark.cpp

run: clean build
	./main.out

unsanitized: clean Database.cpp Driver.cpp Passport.cpp StatePark.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized.out Database.cpp Driver.cpp Passport.cpp StatePark.cpp

check: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main.out

clean:
	rm -f *.out *.debug *.gcno *.gcda *.gcov