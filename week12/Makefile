default: main.o sorter.o
    g++ main.o sort.o -o default

sorter.o:
	g++ -c sorter.cpp

sort: sorter.o
	g++ -c sorter main.cpp sorter.o

clean:
	rm -f sorter*.o default


output: main.o sorter.o
    g++ main.o sorter.o -o output

main.o: main.cpp
    g++ -c main.cpp

sorter.o: sorter.cpp sorter.h
    g++ -c sorter.cpp

clean:
    rm *.o output


helloworld: main.o hello.o world.o
        cc -o helloworld main.o hello.o world.o # Line starts with TAB!

main.o: main.c
        cc -c main.c

hello.o: hello.c
        cc -c hello.c

clean:
        rm -rf  *.o helloworld *~ *.core core 
