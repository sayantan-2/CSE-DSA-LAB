import json

# Read JSON file
with open("questions.json") as f:
    data = json.load(f)

questions = data

# Create files folder
import os

os.makedirs("questions", exist_ok=True)

# Extract question text
for q in questions:
    question_text = q["question_text"]

    # Create file name
    file_name = "questions/" + str(q["question_number"]) + ".txt"

    # Write to text file
    with open(file_name, "w") as f:
        f.write(question_text)

print("Questions saved in text files")
