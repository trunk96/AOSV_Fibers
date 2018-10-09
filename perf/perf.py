import subprocess
import sys
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) > 1 and sys.argv[1] == "-exec":

    s = list()

    for i in range(0, 15):
        result = subprocess.run(['../benchmark/2018-fibers/test', str((i+1)*32)], stdout = subprocess.PIPE)
        a = result.stdout.decode('utf-8').split('\n')[2];
        s.append(a)
        print(a)

    f = open("work_time.txt", "w");
    for str in s:
        f.write(str+"\n")
    f.close()

elif len(sys.argv) > 1 and sys.argv[1] == "-execusr":

    s = list()

    for i in range(0, 15):
        result = subprocess.run(['../benchmark/2018-fibers/test', str((i+1)*32)], stdout = subprocess.PIPE)
        a = result.stdout.decode('utf-8').split('\n')[2];
        s.append(a)
        print(a)

    f = open("work_time_user.txt", "w");
    for str in s:
        f.write(str+"\n")
    f.close()

else:
    f1 = open("work_time.txt", "r");
    f2 = open("work_time_user.txt", "r");
    f3 = open("work_time_550.txt", "r");
    f4 = open("work_time_user_550.txt", "r")

    l1 = list()
    l2 = list()
    l3 = list()
    l4 = list()

    for line in f1:
        l1.append(float(line.split(':')[1].strip()));
    for line in f2:
        l2.append(float(line.split(':')[1].strip()));
    for line in f3:
        l3.append(float(line.split(':')[1].strip()));
    for line in f4:
        l4.append(float(line.split(':')[1].strip()));

    plt.xlabel("Iteration")
    plt.ylabel("Time (per-fiber)")
    plt.title("Execution time plot")
    plt.plot(range(1, len(l1)+1),[pt for pt in l1], marker='o', linestyle='--', label="Kernel")
    plt.plot(range(1, len(l2)+1),[pt2 for pt2 in l2], marker='o', linestyle='--', label="User")
    plt.legend()
    plt.show()
    plt.ylabel("Time (per-fiber)")
    plt.boxplot([l3, l4], showmeans=True)
    x_axis = np.arange(1, 3, 1)
    plt.xticks(x_axis, ["kernel", "user"])

    plt.show()
