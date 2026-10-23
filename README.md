# SVG Project
A C command-line application to create 2D geometric shapes and export them to an SVG file.

---
 
## Features

**Shapes**: Rectangles/Square, Ellipses/Circles, and Lines.

**Styling**: Custom RGB colors (fill and stroke), translation, and rotation angle.

**Interactive Menu**: Terminal UI to add, modify, delete, and export shapes.

**SVG Export**: Saves your scene to draw.svg.

-  *Makefile*
- *README.md*
- **include/**     *Header files (.h)*
- **src/**         *Source files (.c)*

---

## Build & Run

### Prerequisites

- gcc (C99 support)
- make

---

## Commands :

**Compile :**
make build

**Run :**
make run

**Clean :**
make clean 

---

## Usage

**1.** Run ./projet_svg or make run to open the main menu:

**2.** Create a form - Add a Rectangle, Ellipse, or Line with custom colors and transformations.

**3.** Modify a form - Edit an existing shape by index.

**4.** Delete a form - Remove a shape by index.

**5.** Export SVG - Save all shapes to draw.svg ($800 \times 600$ canvas).

**6.** Exit - Quit the program.