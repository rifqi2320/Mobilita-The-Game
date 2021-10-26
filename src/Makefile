modules = item.o

main: $(modules)
	gcc -o main main.c $(modules)

item.o: item.c item.h
	gcc -c item.c

clean:
	rm *.o *.exe