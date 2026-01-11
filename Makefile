all: bar.o cocktail.o ingredient.o main.o
	g++ bar.o cocktail.o ingredient.o main.o -o Programme

bar.o: bar.cpp
	g++ -c bar.cpp

cocktail.o: cocktail.cpp
	g++ -c cocktail.cpp

ingredient.o: ingredient.cpp
	g++ -c ingredient.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f bar.o cocktail.o ingredient.o main.o Programme