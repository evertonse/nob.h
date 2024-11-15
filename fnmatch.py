import glob
import os

# Sample directory (make sure this directory exists and contains files)
directory = 'sample_directory/'  # Adjust this path as needed

# Different patterns to match
patterns = [
    '*.txt',          # Match all .txt files
    '*.jpg',          # Match all .jpg files
    'data*.txt',     # Match files starting with 'data' and ending with .txt
    '*.png',          # Match all .png files
    'data_?.*',       # Match files starting with 'data_' followed by a single character
    'data_??.*',      # Match files starting with 'data_' followed by two characters
    '*.*',            # Match all files with an extension
    'report.*',       # Match files starting with 'report'
    'data[1-2].*'     # Match files starting with 'data' followed by 1 or 2
]

# Using glob to find files
for pattern in patterns:
    matched_files = glob.glob(os.path.join(directory, pattern))
    print(f"Pattern: {pattern} -> Matched files: {matched_files}")

