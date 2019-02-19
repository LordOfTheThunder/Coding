# Company: Google
# Question:
"""
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.
"""
# Example: For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes)

# Solution: Iterate over the string. First split the string by \n to get all the entries. Then iterate over them and update
# a list containing the current dir each time a new entry appears

def longestPath(path_str):
    if not path_str:
        return 0
    dirs, max_len = [None], 0
    for token in path_str.split('\n'):
        tabs = 0
        while token[tabs] == '\t':
            tabs += 1
        if tabs > len(dirs):
            raise RuntimeError('Bad path string')

        if tabs == len(dirs): # go one level deeper
            if '.' in dirs[-1]:
                raise RuntimeError('Bad path string')
            dirs.append(None) # make room for new path item
        else:
            dirs = dirs[:tabs + 1]

        dirs[-1] = str.strip(token)
        max_len = max(max_len, len('/'.join(dirs))) if '.' in dirs[-1] else max_len

    return max_len


if __name__ == "__main__":
    print(longestPath('dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext'))
    pass
