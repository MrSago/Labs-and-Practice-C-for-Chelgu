all: build start

SNK=.\SnakeFunctions\Draw.c .\SnakeFunctions\Graphics.c .\SnakeFunctions\SnakeDifficult.c .\SnakeFunctions\SnakeGameOver.c .\SnakeFunctions\SnakeKB.c .\SnakeFunctions\SnakeMove.c .\SnakeFunctions\SnakeWorldGen.c .\SnakeFunctions\SnakeWorldSize.c

build:
	gcc -O3 -ansi -o prog.exe .\main.c .\MenuSelection.c ${SNK} -lwinmm

start:
	.\prog.exe