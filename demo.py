import serial
import time
print("Start")
port="/dev/rfcomm0"
bluetooth=serial.Serial(port, 9600)

print("connected")
bluetooth.flushInput()

for i in range(1000):
	print("ping")
	bluetooth.write(str.encode(str(i)))
	input_data=bluetooth.readline()
	print(input_data.decode())
	time.sleep(0.1)
bluetooth.close()
print("done")