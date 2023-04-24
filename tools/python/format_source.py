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
    raw_files = [ f.path for f in os.scandir(dir) if f.is_file() ]
    files = []

    for rawfile in raw_files:
        if any(substring in rawfile for substring in relevant_file_extensions):
            files.append(rawfile)
    return files

def gather_all_sources(subdirs):
    files_to_format = []
    for subdir in subdirs:
        files = gather_sources_in_directory(subdir)
        for file in files:
            files_to_format.append(file)
    return files_to_format

def execute_clang_tidy(sources):
    for source in sources:
        print("Source : " + source)


def main():
    start_directory = sys.argv[1]
    print("Format Sources : Start Directory : " + start_directory)
    subdirs = enumerate_sub_directories(start_directory)
    files_to_format = gather_all_sources(subdirs)
    execute_clang_tidy(files_to_format)


if __name__ == '__main__':
    main()