invert.exe : validate.o color.o main.o create.o display.o search.o save.o update.o
	gcc -o invert.exe validate.o color.o main.o create.o display.o search.o save.o update.o
main.o : main.c
	gcc -c main.c
validate.o : validate.c
	gcc -c validate.c
color.o : color.c
	gcc -c color.c
create.o : create.c
	gcc -c create.c
display.o : display.c
	gcc -c display.c
search.o : search.c
	gcc -c search.c
save.o : save.c
	gcc -c save.c
update.o : update.c
	gcc -c update.c
clean :
	rm *.exe *.o
