# cub3D

## Overview
cub3D is a 3D graphics project built with the MiniLibX library, simulating a basic 3D game engine. The project renders a 3D world using raycasting, similar to classic games like Wolfenstein 3D. This version includes bonus features such as animations, mouse movement, and additional interactions.

## Features
- **Raycasting**: A raycasting algorithm is used to render walls, creating a 3D perspective from a 2D map.
- **Textures**: Textured walls are rendered in the 3D environment.
- **Bonus Features**:
  - Mouse movement support for camera rotation.
  - Hand animation that triggers on key press.
  - Smooth animation playback.
  - Doors that interact with the player.
  - Minimap.

## How to Play

1. Movement:
   - `W`, `A`, `S`, `D`: Move the player forward, left, backward, and right, respectively.
   - Mouse movement or arrow keys rotates the camera view.
2. Interactions:
   - Press `F` to play the hand animation once.
   - Press `E` to interact with doors (represented by `D` on map).

## How It Works
### Raycasting
Raycasting is at the heart of the project’s 3D rendering. The `draw_plane` function casts rays from the player's perspective and determines what parts of the environment are visible. Rays continue until they hit a wall (`'1'` in the map) or a door (`'D'`). The `perform_dda` function ensures accurate collision detection along the ray's path.

### Animation
The hand animation is rendered when pressing the `F` key. The animation consists of multiple frames, and each press plays the animation once. The first frame is rendered by default, but pressing `F` triggers the rest of the frames in sequence. The `update_hand_animation` function manages this transition between frames.

### Collision Detection
To avoid passing through walls, the DDA algorithm checks each ray’s direction and calculates how far the player can move without intersecting with a wall. This prevents the player from clipping through walls or doors.

## Installation

### Requirements
- macOS or Linux.
- MiniLibX installed.
- A C compiler (e.g., `gcc` or `cc`).

### Compiling the Project
1. Clone the repository:
```bash
git clone https://github.com/yourusername/cub3D_team.git
cd cub3D_team
```
2. Compile the project:
```bash
make bonus
```
### Running the Game
To run the game, provide a valid `.cub` map file:
```bash
./cub3D_bonus maps/map_bonus.cub
```








