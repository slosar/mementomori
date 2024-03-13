all: mementol mementor

mementol: memento.c
	gcc -O3 -DLAMPEDUSA -o mementol memento.c

mementor: memento.c
	gcc -O3 -DREMLER -o mementor memento.c

