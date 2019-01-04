## -*- coding: utf-8 -*-

import base64
import sys

source = open(sys.argv[1]).read()
output = base64.b64encode(bytes(source, "utf-8"))
output = [output[piece:piece+3500] for piece in range(0, len(output), 3500)]

with open(sys.argv[1]+"-base64","wb") as file:
	for row in output:
		file.write(row)
		file.write(bytes("\n", "utf-8"))
