modules = item.o tas.o matrix.o point.o

main: $(modules)
	gcc -o main main.c $(modules)

matrix.o: matrix.c matrix.h
	gcc -c matrix.c

point.o: point.c point.h
	gcc -c point.c

tas.o: tas.c tas.h
	gcc -c tas.c

item.o: item.c item.h
	gcc -c item.c

charmachine.o: charmachine.c charmachine.h
	gcc -c charmachine.c

tokenmachine.o: tokenmachine.c tokenmachine.h
	gcc -c tokenmachine.c

io.o: io.c io.h
	gcc -c io.c

clean:
	rm *.o *.exe