connectn.out: main.o input_val.o chessboard.o play.o win.o
	gcc -g -Wall -Werror -o connectn.out main.o input_val.o chessboard.o play.o win.o

main.o: main.c input_val.h chessboard.h play.h
	gcc -g -Wall -Werror -c main.c

input_val.o: input_val.c input_val.h
	gcc -g -Wall -Werror -c input_val.c

chessboard.o: chessboard.c chessboard.h
	gcc -g -Wall -Werror -c chessboard.c

play.o: play.c play.h chessboard.h win.h
	gcc -g -Wall -Werror -c play.c

win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c

clean:
	rm -f *.o *.out