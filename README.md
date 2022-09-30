# Game of Life
Made for Mathematics introduction to computer science classes at MIMUW in the winter semester of 2019/2020.
## Usage:

Compile the file, e.g. with gcc:
```
gcc zycie.c -o zyc
```
And simply run it as follows:
```
./zyc
```
## Description:
Rules are the same as for Conway's Game of Life.
If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors. If the cell is dead, then it springs to life only in the case that it has 3 live neighbors.

## Examples:
```
*******GRA W ZYCIE*******
MENU:
What do you want to do?
1. Enter the board manually
2. Read the board from file
3. Generate a random board
4. Change theme (1-4)
0. Exit 
```

```
Available themes:
1. ■  
2. X    O  
3. @   
4. ■    ¤  
enter the theme number 
```

```
╔══════════════════════════════╗
║ ■  ■  ■           ■     ■    ║
║ ■  ■           ■  ■  ■  ■    ║ 
║       ■     ■  ■  ■     ■    ║ 
║       ■           ■  ■  ■  ■ ║ 
║ ■  ■  ■  ■  ■  ■  ■     ■    ║ 
║             ■        ■     ■ ║ 
║    ■     ■     ■  ■  ■       ║ 
║ ■              ■     ■       ║ 
║ ■     ■  ■              ■  ■ ║ 
║    ■     ■  ■  ■     ■  ■    ║
╚══════════════════════════════╝ 
INTERFACE
1. One step
2. 5 steps
3. 10 steps 
4. Make a step every n sec (float)
5. Change cell value (x,y)  
6. Save the board state to a file
0. Menu
```
