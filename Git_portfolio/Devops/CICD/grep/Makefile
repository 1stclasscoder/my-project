all: s21_grep

s21_grep: s21_grep.c
	gcc -Wall -Werror -Wextra s21_grep.c -o s21_grep

clean:
	rm -rf s21_grep

test:
	./test_grep.sh
