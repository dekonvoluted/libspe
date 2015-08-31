> This file is part of libSPE, a C++ library to interface with SPE files.
>
> Copyright (c) 2012 Karthik Periagaram <karthik.periagaram@gmail.com>
>
> libSPE is free software: you can redistribute it and/or modify
> it under the terms of the GNU General Public License as published by
> the Free Software Foundation, either version 3 of the License, or
> (at your option) any later version.
>
> libSPE is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
> GNU General Public License for more details.
>
> You should have received a copy of the GNU General Public License
> along with libSPE. If not, see <http://www.gnu.org/licenses/>.

This is a simple demonstration of libSPE to get you started.
We will read data and metadata from some sample SPE files and output them.

# Files

The demo directory should come with two SPE files.
The first is a long exposure image of a flame.
The second is a series of 500 spectra binned over the entire chip.

    demo/
    |- demo.cpp
    |- CMakeLists.txt
    |- image.spe
    |- spectrum.spe

# Usage

Here are the steps to compile and run the demo:

1. Build libspe according to instructions in ../

2. Create a build directory and switch into it

        mkdir build
        cd build/

3. Run cmake and make

        cmake ..
        make install

4. Go back to the demo/ directory and run demo

        cd ..
        ./demo

If all went well, you should see the output from the demo code on the screen.
Additionally, the average data will be written out to a `.dat` file in the same directory.

