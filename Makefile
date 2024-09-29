connectn.out: connectn.o play.o win.o board.o input_val.o
	gcc -g -Wall -Werror -Wextra -o connectn.out connectn.o play.o win.o board.o input_val.o

connectn.o: connectn.c play.h win.h board.h input_val.h
	gcc -g -Wall -Werror -Wextra -c connectn.c

play.o: play.c play.h input_val.h
	gcc -g -Wall -Werror -Wextra -c play.c

win.o: win.c win.h
	gcc -g -Wall -Werror -Wextra -c win.c

board.o: board.c board.h
	gcc -g -Wall -Werror -Wextra -c board.c

input_val.o: input_val.c input_val.h
	gcc -g -Wall -Werror -Wextra -c input_val.c

clean:
	rm -f *.o *.out