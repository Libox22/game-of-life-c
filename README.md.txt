Game of Life in C

Implementation of **John Conway's Game of Life** in C.  
This program simulates the evolution of a population on a 2D grid according to four simple rules.

---

Rules
1. A **live** cell with fewer than **2 neighbors** dies (underpopulation).  
2. A **live** cell with more than **3 neighbors** dies (overpopulation).  
3. A **live** cell with **2 or 3 neighbors** survives.  
4. A **dead** cell with exactly **3 neighbors** becomes alive.

---

Features
* Dynamic grid size (1–50 rows, 1–100 columns)  
* Random initial population (configurable probability)  
* Animated console output for each generation  
* Input validation  
* Configurable number of cycles (default: **200**)

---

Example Execution
For best visibility, set the console to full screen.

Enter rows (1–50) and cols (1–100): 20 50
Rows: 20, Cols: 50

---

Build & Run (Windows)
gcc main.c -o gameoflife
./gameoflife

Note: a precompiled executable is not included.
You need a C compiler such as GCC/MinGW.

---

Customization
Initial probability of live cells: edit fillMatrix()
Lower value → more live cells
Higher value → fewer live cells

Number of generations: change the while (i < 200) condition.

---

Project Structure
├── main.c       # Source code
├── README.md    # Documentation

---

References
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life -Wikipedia


✍️ Author: Liborio Mattia Pasqualino
📅 Year: 2025