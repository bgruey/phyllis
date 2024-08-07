import sys
import os

header = \
"""/*
    --filename--

    Description for --filename--

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
"""


def set_header(filepath, filename):
    print(f"Processing {filepath}{filename}.")
    if not (filename.endswith(".c") or filename.endswith(".h")):
        print("  - Skipping non-c file.")
        # Non C code.
        return None
    
    filepath_name = os.path.join(filepath, filename)
    with open(filepath_name) as f:
        lines = f.readlines()
    
    if lines[0].startswith("/*") and filename in lines[1]:
        print("  - Header already set.")
        # Already processed
        return

    if lines[0].startswith("/*"):
        lines.pop(0)
        while "*/" not in lines[0]:
            lines.pop(0)
        lines.pop(0)

    with open(filepath_name, "w") as f:
        f.write(header.replace("--filename--", filename))
        for line in lines:
            f.write(line)


def update_folder(root_dir):
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for subdir in dirnames:
            update_folder(os.path.join(dirpath, subdir))
        for filename in filenames:
            set_header(dirpath, filename)


update_folder(sys.argv[1])
