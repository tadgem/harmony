import os
import subprocess
import sys
import platform

relevant_file_extensions = [".h", ".hpp", ".c", ".cpp", ".cc", ".cxx"]

def enumerate_sub_directories(dir):
    subfolders = [ f.path for f in os.scandir(dir) if f.is_dir() ]
    for subdir in subfolders:
        subfolders += enumerate_sub_directories(subdir)
    return list(dict.fromkeys(subfolders))

def gather_sources_in_directory(dir):
    return []

def main():
    start_directory = sys.argv[1]
    print("Format Sources : Start Directory : " + start_directory)
    subdirs = enumerate_sub_directories(start_directory)
    for subdir in subdirs:
        print("Format Soureces : Sub-Directory : " + subdir)

if __name__ == '__main__':
    main()