all: score addGame
score: Scoreboard.h Scoreboard.cpp
	g++ -std=c++11 Scoreboard.cpp -o score
clean:
	rm -f score addGame
addGame: AddGame.cpp
	g++ -std=c++11 AddGame.cpp -o addGame
add: addGame
	cat stats.txt
	./addGame stats.txt
stats:	score
	cat stats.txt
	./score stats.txt
