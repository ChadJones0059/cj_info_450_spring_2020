output: main.o Account.o Checking.o Savings.o CreditCard.o
	g++ main.o Account.o Checking.o Savings.o CreditCard.o -o output

main.o: main.cpp
	g++ -c main.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

Checking.o: Checking.cpp Checking.h
	g++ -c Checking.cpp

Savings.o: Savings.cpp Savings.h
	g++ -c Savings.cpp

CreditCard.o: CreditCard.cpp CreditCard.h
	g++ -c CreditCard.cpp

clean:
	rm *.o output