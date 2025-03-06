# orientation-week2-bst

![GitHub repo size](https://img.shields.io/github/repo-size/ysnanako/orientation-week2-bst)
![GitHub last commit](https://img.shields.io/github/last-commit/ysnanako/orientation-week2-bst)

This project is part of the **National Cheng Kung University (NCKU) - VLSI/CAD Group** course **"Physical Design for Nanometer IC"**, focusing on **Binary Search Tree (BST) with Simulated Annealing (SA)** for **module placement optimization**.

## 📖 Table of Contents

- [Project Overview](#project-overview)
- [Input Format](#input-format)
- [Output Format](#output-format)
- [Project Structure](#project-structure)
- [BST Operations & SA Optimization](#bst-operations--sa-optimization)
- [Example Execution](#example-execution)
- [Validation](#validation)
- [Contribution Guide](#contribution-guide)
- [Contact Information](#contact-information)

## 📝 Project Overview

This project implements **a Binary Search Tree (BST) for module placement** while utilizing **Simulated Annealing (SA) to optimize placement efficiency**. The primary objective is to achieve **optimized module placement within a fixed outline** by **minimizing Half-Perimeter Wire Length (HPWL)**.

### **Key Features:**
1. **Parsing input files for circuit module data**.
2. **BST-based module insertion with contour tracking**.
3. **Operations: Rotation, Deletion, Swap, and Placement Adjustments**.
4. **Simulated Annealing (SA) for optimal placement search**.
5. **Output files for visualization and validation**.

## 📄 Input Format

This project follows a specific **YAL-based input format**:
- **.yal** - Contains circuit modules and dimensions.
- **Aspect ratio and whitespace constraints** are provided as command-line arguments.

📄 **Example Input File**
```
MODULE bk1 DIMENSIONS 100 200
MODULE bk2 DIMENSIONS 150 100
...
```

## 📄 Output Format

After execution, the program generates **BST-based placement results**:
- **.out** - Contains final module placement coordinates.
- **.txt** - Includes runtime and HPWL evaluation.
- **.m** - MATLAB script for visualization.

## 🧰 Project Structure

📂 orientation-week2-bst/
│── 📂 src/ # (BST.cpp, BST.h, main.cpp, and headers)
│── 📂 obj/ # (ignored)
│── 📂 output/ # (Generated .out, .txt, .m files)
│── 🔧 Makefile
│── 📜 README.md # This file
│── 📜 .gitignore

../📂 benchmarks/ # (located outside the repo)

## 🔹 **BST Operations & SA Optimization**

### **1. BST-based Module Insertion**
- Parses `.yal` file to extract module dimensions.
- Constructs **BST hierarchy** based on predefined placement logic.

### **2. Module Operations**
- **Rotation**: Allows modules to be rotated **90 degrees**.
- **Deletion**: Removes a specific module from the BST.
- **Swap**: Exchanges two modules' positions in the BST.

### **3. Simulated Annealing (SA) Optimization**
- **Initial temperature-based placement exploration**.
- **Cooling schedule to refine the placement solution**.
- **Acceptance probability function to escape local optima**.

## ⚡ **Example Execution**

```bash
./BST_StudentID input.yal 1 10 output.txt output.out output.m
```

## ✅ Validation

### **Legality Check & HPWL Calculation**

- Ensures **no overlaps between modules**.
- Computes total **Half-Perimeter Wire Length (HPWL)**.

```bash
python3 tester.py --case example_circuit
```

## 🤝 Contribution Guide

1. Fork this repository.
2. Create a new branch (`git checkout -b feature-xyz`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the remote branch (`git push origin feature-xyz`).
5. Submit a Pull Request.

## 📬 Contact Information

- 📧 Email: [m16131056@gs.ncku.edu.tw](mailto:m16131056@gs.ncku.edu.tw)
- 🌎 University: [National Cheng Kung University (NCKU)](https://www.ncku.edu.tw)
- 📖 Course: Physical Design for Nanometer IC, Fall 2024
