# Maze-Generetor-and-seperate-solver

This C++ project provides a maze generator and solver, offering an interactive experience with mazes of various sizes. The generator employs a recursive algorithm to create mazes, while the solver uses a depth-first search approach to find the path from the start (A) to the end (B).

## Features

- **Maze Generation**: Create mazes of customizable dimensions, choosing from predefined widths and heights.
- **Interactive Console Display**: Visualize generated mazes with clear and aesthetically represented paths.
- **Text File Export**: Save maze configurations, including solved mazes, in text files for further analysis or sharing.
- **Easy Execution**: A convenient batch file (`execute_maze.bat`) is provided for simple execution with a double-click.

## Usage

1. Run `execute_maze.bat` to generate a maze and view it in the console.
2. Input maze dimensions (width and height) as instructed.
3. The generator will create a maze, displaying it with start (A) and end (B) points.
4. The solver will attempt to find and display the solution path.

## File Structure

- **maze_generator.cpp**: Source code for the maze generation.
- **maze_solver.cpp**: Source code for the maze solving.
- **execute_maze.bat**: Batch file for easy execution.
- **Maze array.txt**: Text file storing maze configurations.
- **Solved maze.txt**: Text file storing solved maze configurations.

## Dependencies

- C++ Standard Library

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to contribute, report issues, or provide feedback!

Happy exploring through the mazes!


![Generatod maze](https://user-images.githubusercontent.com/95247831/200484780-d9e64b44-65d9-417f-8b99-f7b8a298b7ba.png)

![Storing generatod maze in a txt file for solver to refer](https://user-images.githubusercontent.com/95247831/200484788-b50c0f8b-7a19-49f6-9a11-aee4bbf7d82c.png)

![Solved maze using solver](https://user-images.githubusercontent.com/95247831/200484785-193b5cd5-8ebf-4148-9fa9-36133bdbdd4f.png)
