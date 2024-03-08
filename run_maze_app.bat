@echo off

REM Compile and run the maze generator
g++ maze_generator.cpp -o maze_generator.exe
maze_generator.exe

REM Compile and run the maze solver
g++ maze_solver.cpp -o maze_solver.exe
maze_solver.exe

REM Pause to keep the console window open
pause
