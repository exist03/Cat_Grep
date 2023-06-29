flags=-Wall -Werror -Wextra

all: s21_grep

s21_grep:
	gcc $(flags) s21_grep.c -o s21_grep
checks:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_grep.c