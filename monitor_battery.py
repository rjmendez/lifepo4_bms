import serial, time, os, sys
serial_input = serial.Serial('/dev/ttyACM0', 115200)
logfile = open(sys.argv[1], 'w')

while 1:
	serial_line = serial_input.readline()
	logfile.write(serial_line)
	if 'voltage cell 0: ' in serial_line:
        cell0v = (float(line.replace('voltage cell 0: ', '')[:-4]))
    if 'voltage cell 1: ' in serial_line:
        cell1v = (float(line.replace('voltage cell 1: ', '')[:-4]))
    if 'voltage cell 2: ' in serial_line:
        cell2v = (float(line.replace('voltage cell 2: ', '')[:-4]))
    if 'voltage cell 3: ' in serial_line:
        cell3v = (float(line.replace('voltage cell 3: ', '')[:-4]))
    if 'voltage total: ' in serial_line:
        totalv = (float(line.replace('voltage total: ', '')[:-4]))
    