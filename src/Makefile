DRIVERS := $(wildcard modules/*/driver_*.c)
MODULES := $(filter-out $(DRIVERS), $(wildcard modules/*/*.c))
OBJECTS := $(patsubst %.c,%.o, $(MODULES))
DRIVERS_EXE := $(patsubst %.c, %.exe, $(DRIVERS))
EXECUTABLE := main

all: $(OBJECTS) $(DRIVERS) main

driver: $(DRIVERS)

%.o : %.c
	gcc -c $< -o $@

driver_%.c: $(OBJECTS)
	gcc $(OBJECTS) $@ -o $(patsubst %.c, %, $@)

main: $(OBJECTS) main.c
	gcc $(OBJECTS) main.c -o $@

clean:
	rm *.exe
	rm modules/*/*.exe
	rm modules/*/*.o