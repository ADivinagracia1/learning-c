https://www.youtube.com/watch?v=xf2W1wZozbk&t=1s

### Installing Dependancies
```

sudo apt-get install libglfw3 libglfw3-dev -y
sudo apt-get -y install cmake pkg-config
sudo apt-get install 
git clone https://github.com/cococry/leif.git
cd leif/ && ./install.sh 
rm -rf lief
```

### Building the project
```
gcc -o todo todo.c -lglfw -lGL -lleif -lclipboard
``` 

when building with GCC, you need to link the installed libraries to build the executable