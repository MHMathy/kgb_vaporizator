
CORE =core/Jeu.cpp core/World.cpp core/Niveau.cpp core/Terrain.cpp core/Hero.cpp core/Point.cpp

SRCS_TXT = $(CORE) txt/main_txt.cpp txt/txtJeu.cpp txt/AffichageTXT.cpp
FINAL_TARGET_TXT = vaporizatorTXT
#DEFINE_TXT = -DJEU_TXT

#SRCS_SDL = $(CORE) sdl2/sdlJeu.cpp sdl2/main_sdl.cpp
#FINAL_TARGET_SDL = pacman_sdl
#DEFINE_SDL = -DJEU_SDL

#INCLUDE_DIR_SDL = -I/usr/include/SDL2
#LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

CC					= g++
LD 					= g++
LDFLAGS  			=
CPPFLAGS 			= -Wall -ggdb   #-O2   # pour optimiser
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc -Isrc/core -Itxt #-Isrc/sdl2

default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) #$(BIN_DIR)/$(FINAL_TARGET_SDL)

make_dir:
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR) $(OBJ_DIR)/txt $(OBJ_DIR)/core #$(OBJ_DIR)/sdl2

$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

#$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o)
#	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@
	#$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_TXT) #$(BIN_DIR)/$(FINAL_TARGET_SDL)

#\
bin/vaporizatorTXT: obj/main_txt.o obj/txtJeu.o obj/AffichageTXT.o\
	g++ -g -W -Wall  obj/main_txt.o obj/txtJeu.o obj/AffichageTXT.o -o bin/vaporizatorTXT\
g++ -g -W -Wall obj/main_txt.o obj/txtJeu.o obj/AffichageTXT.o obj/Jeu.o obj/World.o obj/Niveau.o obj/Terrain.o obj/Hero.o obj/Point.o -o bin/vaporizatorTXT\
\
main_txt.o: src/txt/main_txt.cpp src/txt/AffichageTXT.h src/txt/txtJeu.h\
	g++ -g -W -Wall -c src/txt/main_txt.cpp -o obj/main_txt.o\
\
txtJeu.o: src/txt/txtJeu.cpp src/core/Jeu.h src/core/World.h\
	g++ -g -W -Wall -c src/txt/txtJeu.cpp src/core/World.cpp -o obj/txtJeu.o\
\
AffichageTXT.o: src/txt/AffichageTXT.cpp\
	g++ -g -W -Wall -c src/txt/AffichageTXT.cpp -o obj/AffichageTXT.o\
\
Jeu.o: src/core/Jeu.cpp src/core/World.h\
	g++ -g -W -Wall -c src/core/Jeu.cpp -o obj/vaporizatorTXT.o\
\
World.o: src/core/World.cpp src/core/Hero.h src/core/Niveau.h\
	g++ -g -W -Wall -c src/core/World.cpp -o obj/World.o\
\
Niveau.o:src/core/Niveau.cpp src/core/Terrain.h\
	g++ -g -W -Wall -c src/core/Niveau.cpp -o obj/Niveau.o\
\
Terrain.o:src/core/Terrain.cpp\
	g++ -g -W -Wall -c src/core/Terrain.cpp -o obj/Terrain.o\
\
Hero.o: src/core/Hero.cpp src/core/Point.h\
	g++ -g -W -Wall - c src/core/Hero.cpp -o obk/Hero.o\
\
Point.o: src/core/Point.cpp\
	g++ -g -W -Wall -c src/core/Point.cpp -o obj/Point.o\
\
clean:\
	rm -f obj/*.o obj/Debug/src/*.o\
