# Raylib C Template

### My additions to [tsoding/raylib-template](https://github.com/tsoding/raylib-template/),


## Adaptive integer scaling

This template has an adaptive integer scaling system, like you'd see with emulators of older low-res consoles. It multiplies the original render resolution to fit the window size as it changes, but sticks to integer multiples.

For example, if your render resolution is 320 x 240, having a window size of 720 x 720 will only allow for 2x scale, making the render texture draw at 640 x 480.


## Camera system

Standard Camera2D at 1.0 zoom that is already configured to keep the player centered and follow as it moves.


## Compiling and running your game

In order to compile your game with nob.h, you must first compile `nob.c` because it is what executes the compilation of the game.

Modifying `"main"` on line 15 of `nob.c` will change the name of the executable that your game is compiled into, for example:

```c
cmd_append(&cmd, "-o", "Game Name", "main.c");
```

Compile `nob.c` by running:

```console
cc -o nob nob.c
```

Then simply execute the compiled `nob` binary to compile `main`:

```console
./nob
```

Now, you can run your project by running the compiled :

```console
./main
```


## Congratulations!

You are now an independent game developer!