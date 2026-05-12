*This project has been created as part of the 42 curriculum by thaperei, hermarti.*

# miniRT

A minimal ray tracer written in C as part of the 42 curriculum.  
This project introduces the fundamentals of computer graphics, linear algebra, and ray tracing by rendering simple 3D scenes using mathematical calculations.

---

# Table of Contents

- [Description](#description)
- [Features](#features)
- [Project Structure](#project-structure)
- [Instructions](#instructions)
- [Scene Format](#scene-format)
- [Rendering Pipeline](#rendering-pipeline)
- [Technical Concepts](#technical-concepts)
- [Example](#example)
- [Resources](#resources)
- [AI Usage](#ai-usage)
- [Authors](#authors)

---

# Description

miniRT is an educational ray tracing engine developed in C using the MiniLibX graphical library.

The goal of the project is to build a renderer capable of generating images from a scene description file (`.rt`). The renderer simulates how rays of light interact with objects in a virtual 3D world to produce realistic lighting and shading.

The project focuses on:

- Ray-object intersection calculations
- Vector mathematics
- Camera projection
- Lighting models
- Scene parsing
- Rendering pipelines
- Graphics programming fundamentals

The program reads a `.rt` scene file and renders the corresponding image in a graphical window.

---

# Features

## Mandatory Features

- Ambient lighting
- Point light source
- Camera system
- Sphere rendering
- Plane rendering
- Cylinder rendering
- Phong lighting model
- Scene parsing and validation
- Window rendering using MiniLibX

## Bonus Features

- Shadows
- Specular reflections
- Multiple light sources
- Object rotations
- Reflection effects
- Rendering optimizations

---

# Project Structure

```bash
miniRT/
├── include/        # Header files
├── src/            # Source files
├── scenes/         # Example .rt scenes
├── libft/          # Custom utility library
├── minilibx/       # MiniLibX graphics library
├── Makefile
└── README.md
````

---

# Instructions

## Requirements

### Linux

Install dependencies:

```bash
sudo apt update
sudo apt install gcc make xorg libxext-dev libbsd-dev
```

### macOS

Install XQuartz:

```bash
brew install --cask xquartz
```

---

## Clone the Repository

```bash
git clone --recursive https://github.com/thaperei-hermarti/minirt.git
cd minirt
```

---

## Compilation

Compile the project:

```bash
make
```

Available Makefile rules:

```bash
make clean
make fclean
make re
```

---

## Execution

Run the renderer with a scene file:

```bash
./miniRT scenes/mandatory/simple.rt
```

---

# Scene Format

The renderer uses `.rt` files to describe scenes.

Example:

```txt
A 0.2 255,255,255

C -50.0,0,20 0,0,1 70

L -40.0,50.0,0.0 0.6 255,255,255

sp 0.0,0.0,20.6 12.6 10,0,255

pl 0.0,-1.0,0.0 0.0,1.0,0.0 255,0,225

cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```

## Supported Elements

| Identifier | Description   |
| ---------- | ------------- |
| `A`        | Ambient light |
| `C`        | Camera        |
| `L`        | Light source  |
| `sp`       | Sphere        |
| `pl`       | Plane         |
| `cy`       | Cylinder      |
| `co`       | Cone          |
| `hy`       | Hyperboloid   |
| `pa`       | Paraboloid    |
---

# Rendering Pipeline

The rendering process follows these steps:

1. Parse the `.rt` scene file
2. Initialize camera and scene objects
3. Cast rays into the scene
4. Detect ray-object intersections
5. Compute lighting and shading
6. Draw pixels into the image buffer
7. Display the rendered frame

---

# Technical Concepts

## Ray Tracing

Ray tracing simulates the behavior of light by casting rays from the camera into the scene and calculating intersections with objects.

## Linear Algebra

The project relies heavily on:

* Vector addition and subtraction
* Dot products
* Cross products
* Vector normalization
* Geometric calculations

## Lighting

The renderer generally uses:

* Ambient lighting
* Diffuse lighting
* Specular highlights

## Graphics Programming

MiniLibX is used to:

* Create windows
* Draw images
* Manipulate pixels
* Handle keyboard and window events

---

# Example

Example execution:

```bash
./miniRT scenes/mandatory/simple.rt
```

Expected result:

* A rendered 3D scene displayed in a graphical window
* Objects illuminated by scene lighting
* Camera-based perspective rendering

---

# Resources

## Ray Tracing

* The Ray Tracer Challenge — Jamis Buck
* Ray Tracing in One Weekend
  [https://raytracing.github.io/](https://raytracing.github.io/)
* Scratchapixel
  [https://www.scratchapixel.com/](https://www.scratchapixel.com/)

## Graphics and Mathematics

* MiniLibX Documentation
* LearnOpenGL Mathematics
* 3Blue1Brown — Linear Algebra Series

## 42 References

* 42 miniRT subject
* MiniLibX official documentation

---

# AI Usage

AI tools were used for:

* Understanding ray tracing concepts
* Clarifying mathematical formulas
* Debugging vector calculations
* Improving documentation structure
* README formatting assistance

All implementation and final project decisions were completed manually by the project authors.

---

# Authors

* thaperei
* hermarti

---

# License

This project is part of the 42 curriculum and is intended for educational purposes.
