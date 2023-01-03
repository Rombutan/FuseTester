# Fuse resistance tester with pico, HAL effect current sensing, ads1115 and an oled. Probably going to run off of 12v somehow.
<br>

## Building
1. Clone repo
    git clone git@github.com:Rombutan/FuseTester.git --recurse-submodules
2. Move to build dir and compile
    cd FuseTester/build
    cmake ..
    make
3. Plug in your pico while holding down the boot button
4. Copy `FuseTester.uf2` from build dir to your pi pico
