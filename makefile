all: my_first_image.c
	gcc my_first_image.c

run: all
	./a.out

clean:
	rm a.out
	rm sample.ppm
