all: clean affichage

affichage: main.o obj/Affichage.o
	g++ -g -W -Wall obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage -lSDL2 -lSDL2_image

main.o: src/main.cpp src/Affichage.cpp src/Affichage.h
	g++ -g -W -Wall -c src/main.cpp -o obj/main.o

affichage.o: src/Affichage.cpp
	g++ -g -W -Wall -c src/Affichage.cpp -o obj/Affichage.o -I /usr/include/SDL2/ -lSDL2

clean:
	rm -f obj/*.o obj/Debug/src/*.o bin/affichage bin/exemple
