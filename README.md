# CMakeSkeleton
A simple little CMake skeleton project with both a shared library &
a static library. It works *mostly* how I want it to. The main thing it doesn't
do right now is that the shared library still depends on the shared library,
and doesn't get it's own copy of the .o's from the .a that's produced. This may
just be due to my non-understanding of Linux/Mac .a's & .so's/.dylib's. (I know
how to do it on Windows for DLL's)

This hasn't yet been tested at all on Windows.

Here's how I build it (from a different directory):

``cmake ../CMakeSkeleton -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=True -DCMAKE_INSTALL_PREFIX=$HOME/tmp``

and then

``ninja && ninja install``


