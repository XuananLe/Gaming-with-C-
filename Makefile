all:
		g++ main.cpp Define.h -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -g; ./a.out
