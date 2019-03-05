all: doc clean exemple test affichage 	

exemple: mainExemple.o Image.o Pixel.o
	g++ -g -W -Wall obj/mainExemple.o obj/Image.o obj/Pixel.o -o bin/exemple -lSDL2

test: mainTest.o Pixel.o
	g++ -g -W -Wall obj/mainTest.o obj/Image.o obj/Pixel.o -o bin/test -lSDL2

affichage: mainAffichage.o obj/Image.o obj/Pixel.o
	g++ -g -W -Wall obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage -lSDL2 -lSDL2_image

mainExemple.o: src/mainExemple.cpp src/Image.h
	g++ -g -W -Wall -c src/mainExemple.cpp -o obj/mainExemple.o

mainTest.o: src/mainTest.cpp src/Image.h src/Pixel.h
	g++ -g -W -Wall -c src/mainTest.cpp -o obj/mainTest.o

mainAffichage.o: src/mainAffichage.cpp src/Image.h src/Pixel.h
	g++ -g -W -Wall -c src/mainAffichage.cpp -o obj/mainAffichage.o

Image.o: src/Image.h src/Image.cpp src/Pixel.h 
	g++ -g -W -Wall -c src/Image.cpp -o obj/Image.o -I /usr/include/SDL2/ -lSDL2 -lSDL2_image

Pixel.o: src/Pixel.h src/Pixel.cpp
	g++ -g -W -Wall -c src/Pixel.cpp -o obj/Pixel.o

doc: src/Pixel.h src/Image.h src/mainAffichage.cpp src/mainExemple.cpp src/mainTest.cpp doc/image.doxy
	doxygen doc/image.doxy 

clean:
	rm -f obj/*.o obj/Debug/src/*.o bin/test bin/affichage bin/exemple
