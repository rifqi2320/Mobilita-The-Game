CC_FLAGS:= -Wall

SOURCES:=$(wildcard ../src/*.c)
SOURCES:=$(subst ../src/main.c,,$(SOURCES))
OBJECTS:=$(patsubst %.c, %.o, $(SOURCES))
OBJECTS:=$(patsubst ../src/%, %, $(OBJECTS))
DRIVERS:=$(wildcard driver_*.c)
DRIVERS:=$(patsubst %.c, %.exe, $(DRIVERS))

main : $(OBJECTS) $(DRIVERS)
	
%.o : ../src/%.c
	gcc $(CC_FLAGS) -c $< -o $@

%.exe : %.c
	gcc $(CC_FLAGS) $(OBJECTS) $< -o $@

clean:
	rm *.o *.exe