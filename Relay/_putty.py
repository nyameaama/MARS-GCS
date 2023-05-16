import serial
import time
from _format import format_

z1baudrate = 115200
z1port = '/dev/ttyUSB0'  # set the correct port before run it

z1serial = serial.Serial(port=z1port, baudrate=z1baudrate)
z1serial.timeout = 2  # set read timeout
# print z1serial  # debug serial.
print(z1serial.is_open)  # True for opened
if z1serial.is_open:
    while True:
        size = z1serial.inWaiting()
        if size:
            data = z1serial.read(size)
            format_(data)
        else:
            print('no data')
        time.sleep(0.5)
else:
    print('z1serial not open')
z1serial.close()  # close z1serial if z1serial is open.