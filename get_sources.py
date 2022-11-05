import os
from os import walk

includes = []
sources = []

def cleanPath(path):
    cleanPath = path.replace("\\", "/")
    return cleanPath

def getIncludes(dir):
    for r, d, f in os.walk(dir):
        for subdir in d:
            getIncludes(r + "/" + subdir)

        for file in f:
            if file.endswith(".h"):
                includes.append(cleanPath(r + "/" + file))
            if file.endswith(".hpp"):
                includes.append(cleanPath(r + "/" + file))
        

def getSources(dir):
    for r, d, f in os.walk(dir):
        for subdir in d:
            getSources(r + "/" + subdir)

        for file in f:
            if file.endswith(".cpp"):
                sources.append(cleanPath(r + "/" + file))

getIncludes("harmony")
getSources("harmony")
clean_includes = list(set(includes))
clean_sources = list(set(sources))

clean_includes.sort()
clean_sources.sort()

print("includes:")
for include in clean_includes:
    print(include)

print("sources:")
for source in clean_sources:
    print(source)