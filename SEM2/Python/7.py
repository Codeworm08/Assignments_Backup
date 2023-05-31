import os

def generate_file_paths(directory):
    file_paths = []

    for root, _, files in os.walk(directory):
        #print(root)
        for file in files:
            #print(file)
            file_path = os.path.join(root, file)
            file_paths.append(file_path)

    return file_paths


directory_path = input("Enter directory path:")
print(directory_path)
file_paths = generate_file_paths(directory_path)


for file_path in file_paths:
    print(file_path)
