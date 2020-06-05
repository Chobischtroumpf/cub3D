# cub3D
simple raycasting project from 42cursus
## Compilation rules

`make` to compile everything needs to be run at least once before you can test the other commands
`make cub3d` will only compile my code, without the graphical library  
`make minilibx` will compile the graphical library  
`make clean` will remove all the object files, while leaving the executable untouched  
`make clean_cub3d` wil remove my code's object files  
`make clean_libft` will remove the libft's object files  
`make clean_minilibx` will remove the minilibx's object files  
`make re` will remove all the object files  
`make re_cub3d` wil remove my code's object files and executable file and recompile them  
`make re_libft` will remove the libft's object files and library file and recompile them  
`make re_minilibx` will remove the minilibx's object files and library file and recompile them  
`make fclean` will remove all the object files and executables  
`make fclean_cub3d` wil remove my code's object files and executable file  
`make fclean_libft` will remove the libft's object files and library file  
`make fclean_minilibx` will remove the minilibx's object files and library  

## Execution rules 

to execute the program, you will need to run it like so :
`./cub3D <file name(almost optional)> <optional flag>`  

the file name has to be a .cub file that follows these rules :
- Map:  
  - The map must be composed of only 4 possible characters:
  - 0 for an empty space
  - 1for a wall
  - 2 for an item
  - N, S, E or W for the player’s start position and spawning orientation.
  - This is a simple valid map:  
      ```
      111111  
      100101  
      102001  
      1100N1  
      111111
     ```
  - the Map HAS to be the very last thing in your file
- Resolution:  
  - identifier: R  
  - x render size  
  - y render size  
- North texture:  
  - identifier:NO  
  - path to the north texure  
- South texture: 
  - identifier: SO
  - path to the south texure
- West texture:
  - identifier: WE  
  - path to the west texure  
- East texture:  
  - identifier: EA  
  - path to the east texure  
- Sprite texture:  
  - identifier: S  
  - path to the sprite texure  
- Floor color:  
  - identifier: F  
  - R,G,B colors in range [0,255] : 0, 255, 255
- Ceilling color:
  - identifier: C
  - R,G,B colors in range [0,255] : 0, 255, 255  
  
the possible option to add after the file name is one, and its the following : `--save`  
the option will start the rendering engine and save the first image rendered by the engine as a .bmp file, it will then stop the program


### side note :
the program can also be executed by itself, without any arguments, unfortunately, I am not finished with my tests, and I cannot guarantee the program will work as it should
