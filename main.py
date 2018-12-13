## -*- coding: utf-8 -*-

import base64
import time
import sys
import threading
import io
import random
import string
import os
import json
import signal
import socks
# import asyncio
import requests
import PIL.Image
from bs4 import BeautifulSoup
# from python3_anticaptcha import NoCaptchaTaskProxyless
import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

import scheme
import setting
import solvers


# ====== Макросы макросики ======
CHARS = string.ascii_uppercase + string.digits
TEXT_CHARS = string.ascii_uppercase + string.digits + string.ascii_lowercase + (string.whitespace * 10) + string.punctuation
NAME_SIZE = 14
badproxies = []


# ====== Шапка ======
def show_logo():
	os.system('cls' if os.name == 'nt' else 'clear')
	print("\n*************************************************")
	print("*	2CH.HK WIPE MACHINE - ReCaptcha edition	*")
	print("*	 Только для внутреннего использования	  *")
	print("*		Оригинальный проект: glow_stick		*")
	print("*	  Быдлокод: owodelta, kobato, arelive	  *")
	print("*			cryptostimor, tsunamaru			*")
	print("*************************************************")


# ====== Отключение ======
def safe_quit(sig=0, frame=0):
	print("\n\nЖду, пока обновится лист с проксичками...")

	f = open("proxies", "r+")
	d = f.readlines()
	f.seek(0)

	for i in d:
		if i.rstrip() not in badproxies:
			f.write(i)

	f.truncate()
	f.close()

	print(str(len(badproxies)), "плохих проксичек почищено!")
	print("Выключаюсь...")

	os._exit(0)

# ====== Обработка клавиш ======
def eternal_input():
	while True:
		print("Choose your option")
		choice = input("[S]tatistics, [Q]uit, [C]lear parasha\n")
		choice = choice.rstrip()
		try:
			if choice.lower() == "s" or choice.lower() == "ы":
				Stats.printStats()
			elif choice.lower() == "q" or choice.lower() == "й":
				safe_quit()
				badproxies.clear()
			elif choice.lower() == "c" or choice.lower() == "с":
				badproxies.clear()
				print("Параша почищена")
			else:
				print("Ты пишешь хуйню")
		except Exception as e:
			pass


# ====== Стата ======
class Stats:

	numOfProxies = 0
	numOfThreads = 0
	postsSent = 0
	captchasSolved = 0

	def setProxies(self, amount):
		Stats.numOfProxies = amount

	def setnumOfThreads(self, amount):
		Stats.numOfThreads = amount

	def incCaptchas(self):
		Stats.captchasSolved += 1

	def incPosts(self):
		Stats.postsSent += 1

	def printStats(self):
		print("=====================================")
		print("Проксичек осталось:\t", str(Stats.numOfProxies - len(badproxies)))
		print("Начальные потоки:\t", str(Stats.numOfThreads))
		print("Каптч решено:\t\t", str(Stats.captchasSolved))
		print("Плохие проксички:\t", str(len(badproxies)))
		print("Текущие потоки:\t\t", str(threading.active_count()))
		#print("Создано тредов/постов: ", posti, "\n")
		if threading.active_count() <= 2:
			print("ALL THREADS FINISHED, PRESS \"Q\"")
		print("=====================================\n")


# ====== API капчи сосача ======
class Captcha:

	def __init__(self, proxy, agent, board, thread, solver, TIMEOUT):
		#self.api = "https://2ch.hk/api/captcha/2chaptcha/"
		self.api = "https://2ch.hk/api/captcha/recaptcha/id"
		self.proxy = proxy
		self.agent = agent
		self.board = board
		self.thread = thread
		self.solver = solver
		self.TIMEOUT
		captcha = requests.get(self.api + "id?board=" + self.board + "&thread=" + self.thread, proxies=self.proxy, headers=self.agent, timeout=self.TIMEOUT, verify=False).json()
		self.id = captcha["id"]
		self.image = requests.get(self.api + "image/" + self.id, proxies=self.proxy, headers=self.agent, timeout=self.TIMEOUT, verify=False).content

	def solve(self):
		print(self.proxy["http"], "solving captcha")
		self.value = self.solver.solve(self.image)
		return (None, self.id), (None, self.value)

	def verify(self):
		return requests.get(self.api + "check/" + self.id + '?value=' + self.value, proxies=self.proxy, headers=self.agent, verify=False, timeout=self.TIMEOUT).json()["result"] == 1


# ====== Постинг ======
class Post:

	def __init__(self, proxy, agent, board, thread, solver):
		self.proxy = {"http": proxy, "https": proxy, "socks4": proxy, "socks5": proxy}
		self.agent = {"User-Agent": agent}
		self.board = board
		self.thread = thread
		self.solver = solver
		self.buffer = {}
		self.params = []
		self.params.append(("task", (None, "post")))
		self.params.append(("board", (None, self.board)))
		self.params.append(("thread", (None, self.thread)))
		self.params.append(("usercode", (None, "")))
		self.params.append(("code", (None, "")))
		#self.params["captcha_type"] = (None, "2chaptcha")
		self.params.append(("captcha_type", (None, "recaptcha")))
		self.params.append(("oekaki_image", (None, "")))
		self.params.append(("oekaki_metadata", (None, "")))
#		self.params["g-recaptcha-response"] = (None, "")
#		self.params["formimages"] = []

		self.set_headers()
#		self.set_subject("test")

	def set_headers(self):
		self.headers = {}
		self.headers["Host"] = "2ch.hk"
		self.headers.update(self.agent)
		self.headers["Accept"] = "application/json, text/javasctipt, */*; q=0.01"
		self.headers["Accept-Language"] = "ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3"
		self.headers["Accept-Encoding"] = "gzip, deflate, br"
		self.headers["Referer"] = str("https://2ch.hk/" + self.board + "/res/" + self.thread + ".html")
		self.headers["X-Requested-With"] = "XMLHttpRequest"
#		self.headers["Content-Type"] = str("multipart/form-data; boundary=--------------------------" + ''.join(str(random.randint(0, 9)) for _ in range(28)))
#   с этой штукой макаба отвечает: {'Error': -2, 'Reason': 'Доска не существует.'}. надо выкопать алгоритм для boundary
		self.headers["Content-Length"] = "15000000"
		self.headers["Cookie"] = ""
		self.headers["Connection"] = "keep-alive"

	def prepare(self, TIMEOUT):
		try:
			#self.params["2chaptcha_id"], self.params["2chaptcha_value"] = Captcha(self.proxy, self.agent, self.board, self.thread, self.solver).solve()
			self.buffer["2chaptcha_id"], self.buffer["g-recaptcha-response"] = Captcha(self.proxy, self.agent, self.board, self.thread, self.solver, TIMEOUT).solve()
			self.params.append(("g-recaptcha-response", self.buffer["g-recaptcha-response"]))
			self.params.append(("2chaptcha_id", self.buffer["2chaptcha_id"]))
			print(self.proxy["http"], "solved")
			return True
		except Exception as e:
			print(e)
			return False

	def set_subject(self, text):
		self.params.append(("subject", (None, text)))

	def set_text(self, text):
		self.params.append(("comment", (None, text)))
		
	def set_sage(self):
		self.params.append(("email", (None, "sage")))
		self.params.append(("sage", (None, "on")))

	def set_image(self, file_name):
		image = PIL.Image.open(file_name).convert("RGB")
		width, height = image.size
		for x in range(random.randint(1, 10)): image.putpixel((random.randint(0, width-1), random.randint(0, height-1)), (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))
		image = image.crop((0 + random.randint(0, 10), 0 + random.randint(0, 10), width-1 - random.randint(0, 10), height-1 - random.randint(0, 10)))
		image_bytes = io.BytesIO()
		image.save(image_bytes, "JPEG", quality=60 + random.randint(10, 30), optimize=bool(random.getrandbits(1)), progressive=bool(random.getrandbits(1)))
		image.close()

		file_name_displayed = str(''.join(str(random.randint(0, 9)) for _ in range(NAME_SIZE-1)) + "0")
		file_name_displayed += ".jpg"
		self.params.append(("formimages[]", (file_name_displayed, image_bytes.getvalue(), "image/jpeg")))

	def set_video(self, file_name):
		if file_name.find(".mp4") != -1: ext = "mp4"
		elif file_name.find(".webm") != -1: ext = "webm"

		video = open(file_name, "rb")
		video_bytes = video.read()
		video.close()

		file_name_displayed = str(''.join(str(random.randint(0, 9)) for _ in range(NAME_SIZE-1)) + "0")
		file_name_displayed += str("." + ext)
		self.params.append(("formimages[]", (file_name_displayed, video_bytes, str("video/" + ext))))

	def set_media(self, mediaName, media):
		file_name_displayed = str(''.join(str(random.randint(0, 9)) for _ in range(NAME_SIZE-1)) + "0")

		if mediaName.find(".jpg") != -1 or mediaName.find(".png") != -1 or mediaName.find(".gif") != -1:
			image = PIL.Image.frombytes(media).convert("RGB")
			width, height = image.size
			for x in range(random.randint(1, 10)): image.putpixel((random.randint(0, width-1), random.randint(0, height-1)), (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))
			image = image.crop((0 + random.randint(0, 10), 0 + random.randint(0, 10), width-1 - random.randint(0, 10), height-1 - random.randint(0, 10)))
			image_bytes = io.BytesIO()
			image.save(image_bytes, "JPEG", quality=60 + random.randint(10, 30), optimize=bool(random.getrandbits(1)), progressive=bool(random.getrandbits(1)))
			image.close()

			if mediaName.find(".jpg") != -1:
				mediaType = "image/jpeg"
				file_name_displayed += ".jpg"
			elif mediaName.find(".png") != -1:
				mediaType = "image/png"
				file_name_displayed += ".png"
			elif mediaName.find(".gif") != -1:
				mediaType = "image/gif"
				file_name_displayed += ".gif"

		elif mediaName.find(".mp4") != -1:
			mediaType = "video/mp4"
			file_name_displayed += ".mp4"
		elif mediaName.find(".webm") != -1:
			mediaType = "video/webm"
			file_name_displayed += ".webm"
		else:
			mediaType = "image"
			file_name_displayed += ".jpg"

		self.params.append(("formimages[]", (file_name_displayed, media, mediaType)))

	def send(self, TIMEOUT, PAUSE):
		response = {}
		try:
			print(self.proxy["http"], "posting")
			wait_time = random.randint(6, 15)
			time.sleep(PAUSE)
			response = requests.post("https://2ch.hk/makaba/posting.fcgi?json=1", files=self.params, proxies=self.proxy, headers=self.headers, timeout=TIMEOUT, verify=False).json()
			Stats.incPosts()
			Stats.printStats()
			return response['Status'] == 'OK', response
		except Exception as e:
			print(e)
			return False, response


# ====== Вайпалка ======
class Wiper:

	def __init__(self, setup, catalog, threads):
		print("\nЗА БУНД И САГУ, ЗА ЧЕСТЬ И ОТВАГУ!")
		# print("Patched by @owodelta / X-Captcha by kobato / patched again by @owodelta")
		self.proxies = [proxy[:-1] for proxy in open("proxies", "r").readlines()]
		random.shuffle(self.proxies)
		Stats.setProxies(len(self.proxies))
		self.agents = [agent[:-1] for agent in open("useragents").readlines()]
		self.board = setup.board
		self.thread = setup.thread
		if setup.solverType == 0:
			self.solver = solvers.CaptchaSolver_XCaptcha(setup.key)
		elif setup.solverType == 1:
			self.solver = solvers.CaptchaSolver_captchaguru(setup.key)
		elif setup.solverType == 2:
			self.solver = solvers.CaptchaSolver_anticaptcha(setup.key)
		self.setup = setup
		self.catalog = catalog
		self.threads = threads

	def trap_replace(self, text):
		if bool(random.getrandbits(1)):
			text = text.replace("А", "A").replace("а", "a")
		if bool(random.getrandbits(1)):
			text = text.replace("Е", "E").replace("е", "e")
		if bool(random.getrandbits(1)):
			text = text.replace("О", "O").replace("о", "o")
		if bool(random.getrandbits(1)):
			text = text.replace("Р", "P").replace("р", "p")
		if bool(random.getrandbits(1)):
			text = text.replace("С", "C").replace("с", "c")
		if bool(random.getrandbits(1)):
			text = text.replace("Х", "X").replace("х", "x")
		if bool(random.getrandbits(1)):
			text = text.replace("В", "B")
		if bool(random.getrandbits(1)):
			text = text.replace("М", "M")
		if bool(random.getrandbits(1)):
			text = text.replace("Н", "H")
		if bool(random.getrandbits(1)):
			text = text.replace("Т", "T")
		if bool(random.getrandbits(1)):
			text = text.replace("у", "y")
		return text

	def send_post(self):
		if (len(self.proxies) == 0): return False
		proxy = self.proxies.pop(0)
		agent = random.choice(self.agents)
		response = {"Error": "proxy"}

		counter = 0

		try:
			#will quit the thread if exception is here. Fixed now.
			while counter < self.setup.proxyRepeatsCount:
				if self.setup.shrapnelCharge == 0:
					threadNum = 0
				else:
					threadNum = random.randint(0, self.setup.shrapnelCharge-1)
					self.thread = self.threads[threadNum].ID

				post = Post(proxy, agent, self.board, self.thread, self.solver)
				if (post.prepare(self.setup.TIMEOUT)):
					charnum = random.randint(1, 100)
					if self.thread != "0":
						black_anus = random.randint(0, len(self.threads[threadNum].posts)-1)  # номер поста для триггера
						white_anus = random.randint(0, len(self.threads[threadNum].posts)-1)  # номер поста для дублирования

					# === берём сначала триггер ===
					if self.setup.triggerForm == 1:
						trigger = ">>" + self.threads[threadNum].lastID + '\n'
					elif self.setup.triggerForm == 2:
						trigger = ">>" + self.threads[threadNum].posts[black_anus].ID + '\n'
					elif self.setup.triggerForm == 3:
						trigger = ">>" + self.threads[threadNum].loaf + '\n'
					elif self.setup.triggerForm == 4:
						trigger = ">>" + self.threads[threadNum].posts[0].ID + '\n'
					elif self.setup.triggerForm == 0:
						trigger = ""

					# === потом текст поста ===
					if self.setup.mode == 1:
						post.set_text(trigger + self.setup.pastes[random.randint(0, 9)])
					elif self.setup.mode == 2:
						post.set_text(trigger)
					elif self.setup.mode == 0:
						post.set_text(trigger + ''.join(random.choice(TEXT_CHARS) for _ in range(charnum)))
					elif self.setup.mode == 3:
						post.set_text(trigger + ("> " + self.threads[threadNum].posts[black_anus].comment).replace("\n", "\n> ").replace("\n> \n", "\n\n"))
					elif self.setup.mode == 4:
						post.set_text(trigger + self.setup.pastes[random.randint(0, len(self.setup.pastes)-1)])
					elif self.setup.mode == 5:
						post.set_text(trigger + "https://2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J")
					elif self.setup.mode == 6:
						post.set_text(trigger + self.setup.bigPaste)
					elif self.setup.mode == 7:
						post.set_text(trigger + self.trap_replace(self.threads[threadNum].posts[white_anus].comment))
					elif self.setup.mode == 8:
						post.set_text(trigger + self.setup.pastes[random.randint(0, len(self.setup.pastes)-1)].replace("BANNUMBER", str(random.randint(self.setup.minBan, self.setup.maxBan))))

					# === до 4 прикреплений ===
					if self.setup.mediaKind > 0:
						try:
							if self.setup.mediaKind == 3:
								if self.setup.shrapnelCharge != 0:
									mediasCount = min(len(self.threads[threadNum].posts[white_anus].medias), 4)
									for media in self.threads[threadNum].posts[white_anus].medias:
										print("Скачиваю", media.name, "("+str(white_anus+1)+" пост "+self.threads[threadNum].ID+" треда)")
										media.download()
								else:
									mediasCount = min(len(self.threads[threadNum].posts[white_anus].medias), 4)
							else:
								mediasCount = self.setup.mediasCount

							for mediaNum in range(mediasCount):
								blue_anus = random.randint(0, self.setup.mediasCount-1)  # номер пикчи или видео с диска
								if self.setup.mediaKind == 1:
									post.set_image(self.setup.mediaPaths[blue_anus])
								elif MEDIA == 2:
									post.set_video(self.setup.mediaPaths[blue_anus])
								elif MEDIA == 3:
									post.set_media(self.threads[threadNum].posts[white_anus].medias[blue_anus].name, self.threads[threadNum].posts[white_anus].medias[blue_anus].file)
						except Exception as e:
							print(e)
							print("Не могу открыть файл, проверь имя.")
							os._exit(-1)

					# === и сажу туды ===
					if self.setup.sageMode == 2:
						if self.threads[threadNum].posts[white_anus].sage == True:
							post.set_sage()
						else:
							post.params.append(("email", (None, "")))
					elif SAGE == 1:
						post.set_sage()
					elif SAGE == 0:
						post.params.append(("email", (None, "")))

					success, response = post.send(self.setup.TIMEOUT, self.setup.PAUSE)
					if success:
						Stats.incPosts()
						post_id = 0
						try:
							post_id = response["Target"]
						except:
							post_id = response["Num"]
						print(proxy + " - success. Post id: " + str(post_id), end=' ')
						if self.setup.shrapnelCharge > 0:
							print("("+self.threads[threadNum].ID+" thread)", end='\n')
						else:
							print(' ', end='\n')
						if self.setup.thread != 0:
							self.threads[threadNum].lastID = str(post_id)

						print(str(proxyRepeatsCount-counter)+" LOOPS LEFT")
						counter += 1
					else:
						print(proxy, "posting failed -", response)

						try:
							if response["Error"] == -6: #or response["Error"] == -4:
								print("Забанили, суки... "+proxy+" в плохой лист")
								badproxies.append(proxy)
								if self.proxies == 0:
									print("Закончились проксички!")
									#raise
								proxy = self.proxies.pop(0)
							elif response["Error"] == -7:
								print("Моча вычищает тред. КОНЧАЮ.")
								safe_quit()
							elif not response:
								print("Ошибка сети, пробуем ещё раз...")
								pass

						except Exception:
							if len(response) > 0:
								print("Таймаут... "+proxy+" в плохой лист")
								badproxies.append(proxy)
								if self.proxies == 0:
									print("Закончились проксички!")
									raise
								proxy = self.proxies.pop(0)

		except Exception as e:
			pass
			print(e)
			print("Removing bad proxy") #no info lol, here's the bug.
			badproxies.append(proxy)

		return True

	def wipe(self, thread_count):
		Stats.setnumOfThreads(thread_count)

		class WiperThread(threading.Thread):

			def __init__(self, wiper):
				threading.Thread.__init__(self)
				self.wiper = wiper

			def run(self):
				self.wiper.send_post()

		class InputThread(threading.Thread):

			def __init__(self):
				threading.Thread.__init__(self)

			def run(self):
				Stats.printStats()
				eternal_input()

		threads = []
		inthr = InputThread()
		inthr.start()
		for i in range(thread_count):
			threads.append(WiperThread(self))
			threads[-1].start()

		for i in range(len(threads)):
			threads[i].join()



setup = setting.Setup(sys.argv)
WiperObj = Wiper(setup, setup.catalog, setup.threads)
signal.signal(signal.SIGINT, safe_quit)
WiperObj.wipe(setup.potocksCount)

safe_quit()

