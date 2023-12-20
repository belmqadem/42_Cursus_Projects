# Get Next Line Project

## Overview 📝

Welcome to the Get Next Line project! In this assignment, the goal is to program a function that returns a line read from a file descriptor. This project provides an opportunity to work with file descriptors, read operations, and dynamic memory allocation in C.

## Introduction 🚀

The `get_next_line` function is designed to read a line from a file descriptor. This project involves managing file descriptors, handling read operations, and efficiently working with dynamic memory in C.

**Key Learnings:**
- Reading lines from file descriptors.
- Managing multiple file descriptors concurrently.
- Utilizing static variables in C.

## Project Structure 📂

The project includes the following files:

- `get_next_line.c`: The main implementation of the `get_next_line` function.
- `get_next_line_utils.c`: Utility functions used by `get_next_line`.
- `get_next_line.h`: Header file containing function prototypes and definitions.

## Functionality 🔧

The `get_next_line` function reads a line from the specified file descriptor (`fd`). It efficiently manages multiple file descriptors concurrently, making it versatile for various scenarios.

## Usage 🚦

To use the `get_next_line` function in your projects:

1. Include the `get_next_line.h` header file.
2. Call the `get_next_line` function with the desired file descriptor.

## Bonus Part 🌟

In addition to the mandatory requirements, this project offers a bonus part that challenges you to enhance the `get_next_line` function further.

### Bonus Goals 🎯

1. **Single Static Variable:** Develop `get_next_line` using only one static variable.
2. **Multiple File Descriptors:** Enable `get_next_line` to manage multiple file descriptors simultaneously. You should be able to switch between different file descriptors seamlessly.

### Implementation 🚀

#### Single Static Variable

Implementing `get_next_line` using a single static variable demonstrates an efficient and compact solution. It requires careful design to manage state and avoid memory leaks.

#### Multiple File Descriptors

Enhancing `get_next_line` to handle multiple file descriptors adds versatility. You should be able to read from different file descriptors in a non-blocking manner, allowing for more dynamic usage.
