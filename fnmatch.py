import fnmatch as fn

# Sample list of filenames
files = [
    'data1.txt',
    'data2.txt',
    'image1.png',
    'image2.jpg',
    'report.pdf',
    'notes.docx',
    'data_backup_2023.zip',
    'data1.csv',
    'README.md'
]

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

# Using fnmatch to filter files
for pattern in patterns:
    matched_files = [f for f in files if fn.fnmatch(f, pattern)]
    print(f"Pattern: {pattern} -> Matched files: {matched_files}")

# Python program to illustrate
# fnmatch.fnmatch(filename, pattern)
import fnmatch

pattern = 'fnmatch_*.py'
print ('Pattern :', pattern )
print()

files = os.listdir('.')
for name in files:
    print ('Filename: %-25s %s' % (name, fnmatch.fnmatch(name, pattern))
