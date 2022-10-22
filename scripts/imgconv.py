# This file contains a simple script for converting images to GBA headers
# This will take a standard JPEG image and convert it to a Bitmap
# It will then use Jasper Vinj's grit tool to output GBA source files for the raw image data
# This raw data will be used by our C code and compiled into the GBA binary
#
# Author: Josh McIntyre
#
import argparse
import os
import subprocess

from PIL import Image

# Define the output directory for our final C files
OUTPUT_DIR = "source/"

# Convert the jpegs
def convert_jpeg_to_bitmap(files):
    
    new_files = []
    for f in files:
        img = Image.open(f)
        img = img.resize((240,160))

        new_path = os.path.splitext(f)[0] + ".bmp"
        img.save(new_path)
        new_files.append(new_path)
    return new_files

# Convert the bitmaps
def convert_bitmaps_to_csource(files):
    for f in files:
        subprocess.run(f"grit {f} -gb -gB16")
        
# The main entry point for the program
def main():

    # Fetch the filenames as command-line arguments
    parser = argparse.ArgumentParser(description="Convert image files to GBA-usable C source files")
    parser.add_argument("files", type=str, nargs="+", help="Files to convert")
    args = parser.parse_args()
    files = args.files

    # Convert JPEGs -> bitmap
    files = convert_jpeg_to_bitmap(files)
    
    # Convert the bitmaps -> c source files
    convert_bitmaps_to_csource(files)
    
if __name__ == "__main__":
    main()

