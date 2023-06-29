flags=-Wall -Werror -Wextra 

all: s21_cat

s21_cat:
	gcc $(flags) s21_cat.c -o s21_cat
checks:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_cat.c
tests:
	sh cat_tests.sh