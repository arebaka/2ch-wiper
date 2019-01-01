## -*- coding: utf-8 -*-

import base64
import sys

source = open(sys.argv[1],"rb").read()
output = base64.b64encode(source)
output = [output[piece:piece+3500] for piece in range(0, len(output), 3500)]

with open("base64","wb") as file:
	for row in output:
		file.write(row)
		file.write(bytes("\n", "utf-8"))
