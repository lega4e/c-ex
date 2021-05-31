all: main ychild schild

main: main.c
	gcc -o main main.c -Wall

ychild: ychild.c
	gcc -o ychild ychild.c -Wall

schlid: schild.c
	gcc -o schild schild.c -Wall

run: main
	main

clean:
	-rm main ychild schild

rerun: clean run
