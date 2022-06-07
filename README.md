# cub3D

## Description
This project is inspired by the world-famous eponymous 90’s game, which
was the first FPS ever. It is used to explore ray-casting. The goal will be to
make a dynamic view inside a maze, in which player have to find his way.

For more detais about this project refer to [**`the subject`**](en.subject.pdf).

## Prerequisites
THe project is using `MiniLibX` library. It is a tiny graphics library and can be used only on macOS. Library source files are located in [`srcs/mlx`](srcs/mlx) directory of this repository.

## Compilation
The project uses the `gcc` compiler in `Makefile`. The resulting binary is called `cub3D`.

```shell
$ (cd srcs && make && cp cub3D ../)
```

## Usage
To start the project just run compiled binary from the root of the repository:
```shell
$ ./cub3D [map file]
```

Map file is a `.cub` file, which contains some settings such as file paths to wall and obstacle sprites and the map of displayed maze. For the format of a map file refer to [**`the subject`**](en.subject.pdf).

There are some examples in [`maps/`](maps) directory of this repository.

## Controls
* `W` `A` `S` `D` keys to move around the maze.
* `←` and `→` directional arrows keys to rotate the view.
* To exit the game, press `ESC` or close the game window.