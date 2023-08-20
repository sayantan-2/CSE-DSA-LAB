import json

with open("output.json") as f:
    data = json.load(f)

for i in range(1, 11):
    filename = str(i) + ".txt"

    with open(filename, "w") as f:
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
