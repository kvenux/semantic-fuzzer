import sys
import re
#import argparse
import scandir
import shutil
import random
#import ipdb
import time
import pickle
import os


def save_obj(obj, name):
    with open(name + '.pkl', 'wb') as f:
        pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)

def load_obj(name):
    with open(name + '.pkl', 'rb') as f:
        return pickle.load(f)

dic = load_obj("ASAN_out")
print(len(dic))
flt_dic = {}

for k,v in dic.items():
    lines = k.split("\n")
    err_type = lines[1].split(" ")[2]
    #print(lines[1])
    items = lines[1].split(" ")
    if "LeakSanitizer" in items[1]:
        pass
    elif "AddressSanitizer" in items[1]:
        err_type = items[2]
        if err_type == "heap-buffer-overflow":
            stk = k.split("\n\n")
            new_key = "{} {}".format(err_type, lines[4])
            if new_key in flt_dic:
                flt_dic[new_key] += v
            else:
                flt_dic[new_key] = v
        else:
            #print(err_type)
            #print(k)
            err_line = " ".join(lines[3].split(" ")[-2:])
            new_key = "{} {}".format(err_type, err_line)
            #print(new_key)
            if new_key in flt_dic:
                flt_dic[new_key] += v
            else:
                flt_dic[new_key] = v


print(len(flt_dic))
for k,v in flt_dic.items():
    print(k, len(v))
    print(v[-1])
    print(v)
    #for val in v:
        #print(val)
    name = v[0].split("/")[-1]
    dst = "new_xst/{}/{}".format("heap-buffer-overflow", name)
    #shutil.copy(v[0], dst)

            #print(k)
    #print(err_type)
    #if "detected" in err_type:
        #print(k)
