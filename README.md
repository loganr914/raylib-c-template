# Raylib C Template

### My additions to [tsoding/raylib-template](https://github.com/tsoding/raylib-template/)

## Adaptive integer scaling

This template has an adaptive integer scaling system, like you'd see with emulators of older low-res consoles. It multiplies the original render resolution to fit within the current window size while maintaining perfect integer scale. i.e. if your render resolution is 320x240, having a window size of 720x720 will scale the render texture 2

## Camera system

Standard Camera2D at 1.0 zoom that doesn't require any

## Compiling and running your game

Compile ```nob.c``` by running:

```console
$ cc -o nob nob.c
```

Then, run ```nob``` to compile ```main```:

```console
$ ./nob
```

Now, you can run your project with:

```console
$ ./main
```

## Congratulations!

You are now an independent game developer! Make something you're proud of, and remember me when you make it big.