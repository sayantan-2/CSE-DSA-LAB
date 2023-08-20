import json
import os

with open("output.json") as f:
    data = json.load(f)

# Create output folder if doesn't exist
if not os.path.exists("output"):
    os.makedirs("output")

for i in range(1, 11):
    filename = str(i) + ".txt"
    file_path = os.path.join("output", filename)

    with open(file_path, "w") as f:
        inputs = data[f"program_{i}"]["input"]
        output = data[f"program_{i}"]["output"]

        for line in inputs:
            f.write(line + "\n")

        f.write("\n")

        if isinstance(output, list):
            for line in output:
                f.write(line + "\n")
        else:
            f.write(output)
