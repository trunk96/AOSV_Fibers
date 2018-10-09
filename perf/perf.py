import subprocess
import sys
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) > 1 and sys.argv[1] == "-exec":

    s = list()

    for i in range(0, 15):
        result = subprocess.run(['../benchmark/2018-fibers/test', '550'], stdout = subprocess.PIPE)
        a = result.stdout.decode('utf-8').split('\n')[2];
        s.append(a)
        print(a)

    f = open("work_time.txt", "w");
    for str in s:
        f.write(str)
    f.close()

elif len(sys.argv) > 1 and sys.argv[1] == "-execusr":

    s = list()

    for i in range(0, 15):
        result = subprocess.run(['../benchmark/2018-fibers/test', '550'], stdout = subprocess.PIPE)
        a = result.stdout.decode('utf-8').split('\n')[2];
        s.append(a)
        print(a)

    f = open("work_time_user.txt", "w");
    for str in s:
        f.write(str)
    f.close()

else:
    f1 = open("work_time.txt", "r");
    f2 = open("work_time_user.txt", "r");

    l1 = list()
    l2 = list()

    for line in f1:
        l1.append(float(line.split(':')[1].strip()));
    for line2 in f2:
        l2.append(float(line2.split(':')[1].strip()));

    plt.xlabel("Iteration")
    plt.ylabel("Time (per-fiber)")
    plt.title("Execution time plot")
    plt.plot(range(1, len(l1)+1),[pt for pt in l1], marker='o', linestyle='--', label="Kernel")
    plt.plot(range(1, len(l2)+1),[pt2 for pt2 in l2], marker='o', linestyle='--', label="User")
    plt.legend()
    plt.show()
    plt.ylabel("Time (per-fiber)")
    plt.boxplot([l1, l2], showmeans=True)
    x_axis = np.arange(1, 3, 1)
    plt.xticks(x_axis, ["kernel", "user"])

    plt.show()
