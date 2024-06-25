#create a program that can receive a file and highlight the text in it to a specific number of lines
#and then output the highlighted text to a new file
#the program should be able to handle the following cases:
#1. the file does not exist
#2. the file exists but is empty
#3. the file exists and has content
#4. the file exists and has content but the number of lines to highlight is greater than the number of lines in the file
#5. the file exists and has content but the number of lines to highlight is less than the number of lines in the file
#6. the file exists and has content but the number of lines to highlight is equal to the number of lines in the file
#7. the file exists and has content but the number of lines to highlight is equal to 0
#8. the file exists and has content but the number of lines to highlight is less than 0

import os
import sys

def highlight_text(file_path, num_lines):
    if not os.path.exists(file_path):
        print("File does not exist")
        return

    with open(file_path, 'r') as file:
        lines = file.readlines()

    if len(lines) == 0:
        print("File is empty")
        return

    if num_lines < 0:
        print("Number of lines to highlight should be greater than or equal to 0")
        return

    if num_lines == 0:
        with open(file_path, 'w') as file:
            file.write("")

    if num_lines >= len(lines):
        highlighted_lines = lines
    else:
        highlighted_lines = lines[:num_lines]

    highlighted_text = ''.join(highlighted_lines)

    with open('highlighted_text.txt', 'w') as file:
        file.write(highlighted_text)

    print("Highlighted text has been saved to highlighted_text.txt")