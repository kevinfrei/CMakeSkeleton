# CMakeSkeleton
A simple little CMake skeleton project with both a shared library &
a static library. It works *mostly* how I want it to. The main thing it doesn't
do right now is that the shared library still depends on the shared library,
and doesn't get it's own copy of the .o's from the .a that's produced. This may
just be due to my non-understanding of Linux/Mac .a's & .so's/.dylib's. (I know
how to do it on Windows for DLL's)

** *This hasn't yet been tested at all on Windows.* **

Here's how I build it (starting from the root ``CMakeSkeleton`` directory).
1. Configure it:
```sh
mkdir ../build; cd ../build
cmake ../CMakeSkeleton -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=True -DCMAKE_INSTALL_PREFIX=$HOME/tmp
```
2. Build it:
```sh
ninja && ninja install
```
3. After you've done this, you can get [Nuclide](https://nuclide.io/) to give you red squigglies and
some basic code navigation by doing this (from inside the ``CMakeSkeleton``
directory:)
```
ln -s ../build/compile_commands.json compile_commands.json
```
