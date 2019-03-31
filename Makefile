
CORE =core/Jeu.cpp core/World.cpp core/Hero.cpp core/Niveau.cpp core/Terrain.cpp core/Projectile.cpp core/Ennemi.cpp core/Point.cpp

SRCS_TXT = $(CORE) txt/main_txt.cpp txt/txtJeu.cpp txt/AffichageTXT.cpp
FINAL_TARGET_TXT = vaporizatorTXT
#DEFINE_TXT = -DJEU_TXT

SRCS_SDL = $(CORE) sdl2/sdlJeu.cpp sdl2/main_sdl.cpp
FINAL_TARGET_SDL = vaporizatorSDL
#DEFINE_SDL = -DJEU_SDL

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw/SDL2-2.0.3/include \
						-Iextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw/SDL2_mixer-2.0.1/i686-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw/SDL2-2.0.3/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_mixer-2.0.1/i686-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif


CC					= g++
LD 					= g++
LDFLAGS  			=   #à compléter ++++++++++++++
CPPFLAGS 			= -g -W -Wall -ggdb   #-O2   # pour optimiser
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc -Isrc/core -Isrc/sdl2 -Itxt

default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL)

make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\txt $(OBJ_DIR)\sdl2 $(OBJ_DIR)\core $(OBJ_DIR)\qt
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR) $(OBJ_DIR)/txt $(OBJ_DIR)/sdl2 $(OBJ_DIR)/core
endif

$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)\txt\*.o $(OBJ_DIR)\sdl2\*.o $(OBJ_DIR)\core\*.o $(BIN_DIR)\$(FINAL_TARGET_TXT).exe $(BIN_DIR)\$(FINAL_TARGET_SDL).exe
else
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL)
endif

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
