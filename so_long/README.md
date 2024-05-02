# <div align="center"> SO LONG </div>

## Summary 🐬
So_Long is a small 2D game project designed to improve your skills in computer graphics. The goal is to create a basic game using textures, sprites, and other gameplay elements. You will use the MiniLibX library, which provides tools for window management, event handling, colors, and textures. This project will help you enhance your C programming skills, use basic algorithms, and conduct information research.

## MiniLibX Introduction 📚
The MiniLibX is a graphics library developed internally at 42 school. It includes essential tools for opening windows, creating images, and handling keyboard and mouse events. It's designed to be simple and efficient, making it ideal for projects like So_Long.

## Project Requirements 📋
- Create a 2D game where a character escapes after collecting all collectibles on the map.
- Use W, A, S, and D keys to move the character up, down, left, and right.
- Implement collision detection with walls to prevent the character from moving through them.
- Display the current number of movements in the shell.
- Use a top-down or profile 2D view for the game.
- The game does not have to be real-time.
- Use MiniLibX's image functions for displaying graphics.

## Usage 💡
```bash
./so_long path_to_map_file
```

## Controls  🎛️
- Use W, A, S, and D keys to move the character.
- Press ESC or close the window to exit the game.

## Overview of my so_long 🗺️
<img width="550" height="450" alt="Screen Shot 2024-05-02 at 1 41 55 PM" src="https://github.com/belmqadem/42_Cursus_Projects/assets/133147080/902950f2-8173-4709-b33b-1f593b333b6d">

## Theme 🎨
The game's theme is inspired by "Greed Island" from the "Hunter x Hunter" series, featuring the main character Gon. The collectibles in the game are cards.

## Compiling on Linux
If you want to compile the project on Linux, you will need to install the MiniLibX library. You can follow these steps:

1. Install the required packages:
```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

2. Clone the MiniLibX repository and compile it:
```bash
git clone https://github.com/42Paris/minilibx-linux.git mlx
cd mlx
make
```

3. Include the required headers in your object files
```
INCLUDES = -I/usr/include -Imlx
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
```

4. link the required libraries:
```
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
```
