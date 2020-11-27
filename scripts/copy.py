import shutil
import os
path = "crashes"
files = os.listdir(path)
files = [os.path.join(path, val) for val in files]
#print(files)

for val in files:
    if "id:" in val:
        idx = val.split(":")[1].split(",")[0]
        print(idx)
        target = "{}/{}".format("crashes_copy", idx)
        shutil.copy(val, target)
