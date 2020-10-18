##dir_path = path of the folder from which you want to delete files
dir = "/dir_path"
files_in_directory = os.listdir(dir)
## you can change the file extension to which you want to remove in my case i use .csv
filtered_files = [file for file in files_in_directory if file.endswith(".csv")]

for file in filtered_files:
	path_to_file = os.path.join(dir, file)
	os.remove(path_to_file)