## General
____________

### Author
* Josh McIntyre

### Website
* jmcintyre.net

### Overview
* SlideBoy is an image conversion and GameBoy Advance graphics demo

## Development
________________

### Git Workflow
* master for releases (merge development)
* development for bugfixes and new features

### Building (Python and Prebuilt Firmware)
* make build
Build the application
* make clean
Clean the build directory

### Features
* Image conversion script that resizes images and converts to GBA .h/.s C source filesystem
* GameBoy Advance slideshow that rotates bitmap images

### Requirements
* Requires Python
* Requires devKitPro GameBoy Advance Tools
* Requires grit tool by Coranac

### Platforms
* Windows (Python image converter using grit)
* GameBoy Advance (final slideshow)

## Usage
____________

### Image Conversion
* Load images into the res directory and name imgN (img1, img2, img3)
* Run `make img` to convert images to C source files for the GameBoy Advance

### SlideShow compilation
* After running image conversion steps, run `make` to build a GBA binary

### SlideShow usage
* Load `slideboy.gba` using your favorite GameBoy Advance emulator
* Images will rotate periodically

