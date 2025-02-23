all: clear_screen compile execute

clear_screen:
	clear

compile:
	gcc main.c `pkg-config --cflags --libs gtk4`

execute:
	./a.out

	
