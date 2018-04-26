*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 2321          
*  HW#       :  Programming Assignment 1            
*  Due Date  :  Feb 12, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
A simple version of Conway's Game of Life on a 30x30 board where cells live or die based on a certain
set of rules.  If a cell is alive and has less than 2 live neighbors, the cell dies, if it has 2 or 3 
live neighbors, the cell lives to the next generation, if the cell has 4 or more neighbors, the cell dies.
If a cell is dead and has exactly 3 live neighbors, a new cell is spawned in the next generation.



*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
Creates an instance of class GameOfLife and has a menu to ask the user whether they want a randomly
seeded board or a predefined seeded board then asks if they want to run by single iterations or by
a set number of iterations.
  
Name:  GameOfLife.cpp
Contains member functions for class GameOfLife that run the game.

Name:  GameOfLife.h
Contains class declaration for class GameOfLife and class Cell
 
Name:  Cell.cpp
Contains default constructors for class Cell.

   
*******************************************************
*  Circumstances of programs
*******************************************************


The program compiles and runs successfully on Visual Studio Community and csegrid.

Developed on Visual Studio Community 2015 14.0.25431.01 Update 3.



*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WongPA1]

   Now you should see a directory named homework with the files:
        main.cpp
	Cell.cpp
	GameOfLife.cpp
	GameOfLife.h
        Readme.txt
	seedin.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WongPA1] 

    Compile the program by:
    % ls -la Game*
    % g++ -std=c++11 GameOfLife.cpp Cell.cpp Main.cpp -o game

3. Run the program by:
   % ./game


