import subprocess

s = list()

for i in range(0, 15):
    result = subprocess.run(['../benchmark/2018-fibers/test', '550'], stdout = subprocess.PIPE)
    a = result.stdout.decode('utf-8').split('\n')[2];
    s.append(a)
    print(a)

f = open("work_time_user.txt", "a");
for str in s:
    f.write(str)
f.close()
