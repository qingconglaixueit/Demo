ocs:libtest.a
	gcc test.c -o 9632.bin -L./ -ltest
libtest.a:math.o odd.o
	ar -crv libtest.a math.o odd.o
math.o:
	gcc math.c -c
odd.o:
	gcc odd.c -c
clean:
	rm *.o 9632.bin *.a
