# Notes from Beej's C Textbook

## Building

[Source](https://beej.us/guide/bgc/html/split/hello-world.html)

Building One File
```
gcc -o hello hello.c
```

Building Multiple Files in One Executable
If your source is broken up into multiple files, you can compile them all together (almost as if they were one file, but the rules are actually more complex than that) by putting all the .c files on the command line:
```
gcc -o awesomegame ui.c characters.c npc.c items.c
```

and they’ll all get built together into a big executable.

