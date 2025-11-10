# FdF - Fil de Fer

This project, completed as part of the 42 School curriculum, involves creating a graphical wireframe representation of a 3D terrain from a map file (.fdf).

The program reads a file describing a terrain as a grid of altitude points (X, Y, and Z coordinates) and displays it in isometric projection in a graphical window, using the MiniLibX library.

## Features:

- **Map Parsing:** The program takes a .fdf file as an argument. It parses this file, verifies that the format is correct (lines of equal length, only valid numbers), and stores the points.

- **Data Structure:** The map points are stored in a linked list (t_stack). Each point contains its coordinates x, y, its value (the altitude z), as well as pointers to its neighbors (next and next_down) to form a grid.

- **3D Projection:** Converts the 3D coordinates (x, y, z) from the map into 2D coordinates for screen display using an isometric projection.

- **Graphical Rendering:** Uses the MiniLibX library to open a window and display the wireframe grid.

- **Line Drawing:** Implements Bresenham's line algorithm to efficiently draw lines pixel by pixel between the different points of the grid.

- **Color Management:** Applies a simple color gradient based on the altitude (z value) of the points, using one color for low points and another for high points.

- **Zoom and Centering:** The program automatically calculates a zoom level and an offset to ensure the map is centered and visible in the window, regardless of its size.

- **Event Management:** Handles basic events such as closing the window (via the red cross) or pressing the Esc key to exit the program cleanly.

## Compilation

To compile the project, use the provided Makefile.

````bash
make
````

This will generate the ````fdf```` executable.

## Usage

To run the program, execute the ````fdf```` executable, passing it the path to a valid map file in .fdf format as an argument.

````bash
./fdf map.fdf
````

## Controls

- **````Esc```` Key:** Closes the window and exits the program cleanly.
- **Window's Red Cross:** Closes the window and exits the program.
