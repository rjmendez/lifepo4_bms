import matplotlib.pyplot as plt
import sys, datetime
all_raw = open(sys.argv[1], 'r')

time = str(datetime.datetime.now()).replace(' ', '_').replace(':','-')

cell0v = []
cell1v = []
cell2v = []
cell3v = []
totalv = []

for line in all_raw:
    if 'voltage cell 0: ' in line:
        cell0v.append(float(line.replace('voltage cell 0: ', '')[:-4]))
    if 'voltage cell 1: ' in line:
        cell1v.append(float(line.replace('voltage cell 1: ', '')[:-4]))
    if 'voltage cell 2: ' in line:
        cell2v.append(float(line.replace('voltage cell 2: ', '')[:-4]))
    if 'voltage cell 3: ' in line:
        cell3v.append(float(line.replace('voltage cell 3: ', '')[:-4]))
    if 'voltage total: ' in line:
        totalv.append(float(line.replace('voltage total: ', '')[:-4]))
plt.figure(figsize=(15, 15))
plt.tight_layout()
plt.plot(totalv)
plt.savefig(time+'_total_voltage.png')
plt.clf()
plt.figure(figsize=(15, 15))
plt.tight_layout()
plt.plot(cell0v, color='blue')
plt.plot(cell1v, color='red')
plt.plot(cell2v, color='green')
plt.plot(cell3v, color='cyan')
plt.xlabel('C0 = blue C1 = red C2 = green C3 = cyan')
plt.savefig(time+'_cell_voltage.png')
#plt.show()