import PIL.Image
import random
import io
import sys

power = int(sys.argv[2])

for num in range(int(sys.argv[3])):
	image = PIL.Image.open(sys.argv[1]).convert("RGBA")
	width, height = image.size

	for x in range(power): image.putpixel((random.randint(0, width-1), random.randint(0, height-1)), (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))

	if len(sys.argv) == 5 and (sys.argv[4] == "c" or sys.argv[4] == "ac" or sys.argv[4] == "ca"):
		red = random.randint(0, 255)
		dif = abs(red - 127)
		green = random.randint(0, dif)
		if random.randint(0, 1): green = 255 - green
		blue = random.randint(max(0, 255-red-green), min(255, 510-red-green))
		if random.randint(0, 1): red, green = green, red
		if random.randint(0, 1): red, blue = blue, red
		if random.randint(0, 1): blue, green = green, blue
		layer = PIL.Image.new("RGBA", image.size, (red, green, blue, 55))
		image.paste(layer, (0, 0), layer)

	if len(sys.argv) == 5 and (sys.argv[4] == "a" or sys.argv[4] == "ac" or sys.argv[4] == "ca"):
		shakal = (1 + random.randint(0, 100)/1000 - 0.05, 0 + random.randint(0, 100)/1000 - 0.05, 1 + random.randint(0, 100)/1000 - 0.05, 0 + random.randint(0, 100)/1000 - 0.05, 1 + random.randint(0, 100)/1000 - 0.05, 0 + random.randint(0, 100)/1000 - 0.05)
		image = image.transform(image.size, PIL.Image.AFFINE, shakal, resample=PIL.Image.BICUBIC)

#	if random.randint(0, 1):
#		image = image.transpose(PIL.Image.FLIP_LEFT_RIGHT)

	image = image.crop((random.randint(0, power), random.randint(0, power), width-1 - random.randint(0, power), height-1 - random.randint(0, power)))

	image = image.convert("RGB")
	image_bytes = io.BytesIO()
	image.save(image_bytes, "JPEG", quality=60 + random.randint(10, 30), optimize=bool(random.getrandbits(1)), progressive=bool(random.getrandbits(1)))
	image.close()
	with open(str(num)+".jpg","wb") as file:
		file.write(image_bytes.getvalue())
