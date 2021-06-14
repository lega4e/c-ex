build: main.c
	gcc -o main main.c -Wall

run: build
	main

child: child.c
	gcc -o child child.c -Wall

clean:
	rm main 

rerun: clean run
