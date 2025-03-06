# orientation-week2-bst

![GitHub repo size](https://img.shields.io/github/repo-size/ysnanako/orientation-week2-bst)
![GitHub last commit](https://img.shields.io/github/last-commit/ysnanako/orientation-week2-bst)

This project is part of the **National Cheng Kung University (NCKU) - VLSI/CAD Group "Smart Electronic Design Automation Laboratory"** orientation, focusing on **Binary Search Tree (BST) with Simulated Annealing (SA)** for **module placement optimization**.

## 📖 Table of Contents

- [Project Overview](#project-overview)
- [Input Format](#input-format)
- [Output Format](#output-format)
- [Project Structure](#project-structure)
- [BST Operations & SA Optimization](#bst-operations--sa-optimization)
- [Example Execution](#example-execution)
- [Generated Plots](#generated-plots)
- [Contribution Guide](#contribution-guide)
- [Contact Information](#contact-information)

## 📝 Project Overview

This project implements a **Binary Search Tree (BST) for module placement** while utilizing **Simulated Annealing (SA) to optimize placement efficiency**. The primary objective is to achieve **optimized module placement within a fixed outline** by **minimizing Half-Perimeter Wire Length (HPWL)**.

### **Key Features:**
1. **Parsing input files for circuit module data**.
2. **BST-based module insertion with contour tracking**.
3. **Operations: Rotation, Deletion, Swap, and Placement Adjustments**.
4. **Simulated Annealing (SA) for optimal placement search**.
5. **Output files for visualization and validation**.

## 📄 Input Format

This project follows a specific **YAL-based input format**:
- **.yal** - Contains circuit modules and dimensions.

📄 **Example Input File**
```
MODULE bk1 DIMENSIONS 100 200
MODULE bk2 DIMENSIONS 150 100
...
```

## 📄 Output Format

After execution, the program generates **BST-based placement results**:
- **.m** - MATLAB script for visualization.

## 🧰 Project Structure

📂 orientation-week2-bst/  
│── 📂 src/ # (fm.cpp, fm.h, parser.cpp, parser.h, and main.cpp)  
│── 📂 obj/ # (ignored)  
│── 📄 benchmark.yal # (ignored)  
│── 📄 benchmark.m # (ignored)  
│── 🖥️ BST # (ignored)  
│── 🔧 Makefile  
│── 📜 README.md  
│── 📜 .gitignore  

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
./BST input.yal output.m
```

## 🖼️ Generated Plots
Below are the generated plots from the `matlab` output: 

**init**  
![initial](https://github.com/user-attachments/assets/9fc6dba6-4e92-478f-8bbc-7dd48dccb0c2)  
**sa**  
![sa2](https://github.com/user-attachments/assets/11e01aec-11b2-4d90-bc43-764f43d55d6a)  

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
