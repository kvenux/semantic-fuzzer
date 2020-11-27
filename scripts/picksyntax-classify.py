import os
import sys
import re
import argparse
import scandir
import shutil
import random
#import ipdb
import time
import pickle

if os.name == 'posix' and sys.version_info[0] < 3:
    import subprocess32 as subprocess
else:
    import subprocess

def save_obj(obj, name ):
    with open(name + '.pkl', 'wb') as f:
        pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)

def load_obj(name ):
    with open(name + '.pkl', 'rb') as f:
        return pickle.load(f)

class Pick(object):
    def __init__(self, jsparser, sourcedir, targetdir):
        self.jsparser = jsparser
        self.sourcedir = sourcedir
        self.targetdir = targetdir
        if not os.path.exists(self.targetdir):
            os.mkdir(self.targetdir)
        #self.filter = re.compile("SyntaxError|ReferenceError|TypeError")
        self.filter = re.compile("[E|e][R|r][R|r][O|o][R|r]")
        self.dic = {}
        self.pick()
        #self.syntex_check()

    def pick(self):
        count = 0
        for dirName, _, fileList in scandir.walk(self.sourcedir):
            random.shuffle(fileList)
            # for fname in fileList:
            for i in range(len(fileList)):
                fname = fileList[i]
                try:
                    name = os.path.join(dirName, fname)
                    #print("[-] %s"%name)
                    print("{}/{} {}".format(i, len(fileList), name))
                    self.syntex_check(name)
                    #print "==============", count, "================"
                    count = count + 1
                except Exception as e:
                    print("pick error:%s"%e)

    def syntex_check(self, name):
        try:
            base_name = os.path.basename(name)
            target_name = os.path.join(self.targetdir, base_name)
            #print(name)
            if os.path.exists(target_name):
                return
            try:
                #print([self.jsparser, name])
                cmd = "{} {}".format(self.jsparser, name)
                child = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                output, err = child.communicate(timeout=1)
                err = err.decode("utf-8")
                output = err.split("\n")
                output_list = output
                idx = len(output_list)
                for i in range(len(output_list)):
                    line = output_list[i]
                    if "======================" in line:
                        idx = i
                        break
                asan_err = "\n".join(output_list[idx:])
                #print("idx: ", idx, asan_err)
                if idx == len(output_list):
                    return

                if asan_err in self.dic:
                    self.dic[asan_err].append(name)
                else:
                    self.dic[asan_err] = [name]
            except Exception as e:
                #print("child.kill() error:%s"%e)
                child.kill()
                outs, errs = child.communicate()
                return
        except Exception as e:
            print("syntex check error:%s"%e)

if __name__ == '__main__':
    print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) )

    parser = argparse.ArgumentParser()
    parser.add_argument("-j", "--jsparser", type=str,
                        default="/root/mfuzzer/fuzzilli/bin/jsc",
                        help="javascript interpreter")
    parser.add_argument("-s", "--sourcedir", type=str, default="fixed", help="source directory")
    parser.add_argument("-t", "--targetdir", type=str, default="fixedformat", help="target directory")
    args = parser.parse_args()
    pick = Pick(jsparser=args.jsparser, sourcedir=args.sourcedir, targetdir=args.targetdir)
    #print(pick.dic)
    save_obj(pick.dic, "ASAN_out")


    res = []
    for k,v in pick.dic.items():
        #print(k,v[0])
        new_key = k.split("\n")
        new_key = "\n".join(new_key[1:5])
        if "Direct leak " in new_key:
            continue
        print(new_key, len(v))
        res.append(new_key)

        #print(v[0])
        #src = v[0]
        #name = src.split("/")[-1]
        #dst = "new_crash/{}".format(name)
        #shutil.copy(src, dst)
    print(len(res))

    print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) )

