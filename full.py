## -*- coding: utf-8 -*-

try:
	# import base64
	import time
	import sys
	import threading
	import io
	import random
	import string
	import os
	import json
	import signal
	#import socks
	# import asyncio
	import requests
	import PIL.Image
	# from python3_anticaptcha import NoCaptchaTaskProxyless
	from bs4 import BeautifulSoup
	import urllib3
	urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
except Exception:
	print("Нет необходимых модулей, братишка, иди ставь.")
	input()
	exit()





# ====== Отключение ======
def safe_quit(badproxies, forbiddenproxy, sig=0, frame=0):
	print("\n\nЖду, пока обновится лист с проксичками...")

	f = open("proxies", "r+")
	d = f.readlines()
	f.seek(0)

	for i in d:
		if i.rstrip() not in badproxies:
			f.write(i)

	f.truncate()
	f.close()

	d = open("forbidden.csv", "a")
	for proxy in forbiddenproxy:
		d.write(proxy + '\n')
	d.close()

	print(str((len(badproxies) - len(forbiddenproxy))), "забаненых проксичек почищено!")
	print(str(len(forbiddenproxy)), "запрещенных проксичек почищено!")
	print("Выключаюсь...")

	os._exit(0)

# ====== Обработка клавиш ======
def eternal_input(badproxies, forbiddenproxy):
	while True:
		print("Choose your option")
		choice = input("[S]tatistics, [Q]uit, [C]lear parasha\n")
		choice = choice.rstrip()
		try:
			if choice.lower() == "s" or choice.lower() == "ы":
				Stats.printStats(badproxies, forbiddenproxy)
			elif choice.lower() == "q" or choice.lower() == "й":
				safe_quit(badproxies, forbiddenproxy)
				badproxies.clear()
				forbiddenproxy.clear()
			elif choice.lower() == "c" or choice.lower() == "с":
				badproxies.clear()
				print("Параша почищена")
			else:
				print("Ты пишешь хуйню")
		except Exception as e:
			print(e)


# ====== Стата ======
class Stats:

	numOfProxies = 0
	numOfThreads = 0
	postsSent = 0
	captchasSolved = 0

	def setProxies(amount):
		Stats.numOfProxies = amount

	def setnumOfThreads(amount):
		Stats.numOfThreads = amount

	def incCaptchas():
		Stats.captchasSolved += 1

	def incPosts():
		Stats.postsSent += 1

	def printStats(badproxies, forbiddenproxy):
		print("=====================================")
		print("Проксичек осталось:\t", str(Stats.numOfProxies - len(badproxies)))
		print("Начальные потоки:\t", str(Stats.numOfThreads))
		print("Каптч решено:\t\t", str(Stats.captchasSolved))
		print("Забаненые проксички:\t", str((len(badproxies) - len(forbiddenproxy))))
		print("Доступ запрещен:\t", str(len(forbiddenproxy)))
		print("Текущие потоки:\t\t", str(threading.active_count()))
		#print("Создано тредов/постов: ", posti, "\n")
		if threading.active_count() <= 2:
			print("ALL THREADS FINISHED, PRESS \"Q\"")
		print("=====================================\n")





# ====== Модель доски ======
class Catalog:

	def __init__(self, board):
		self.board = board  # доска
		print("Скачиваю доску", self.board)
		self.schema = json.loads(requests.get(''.join(["https://2ch.hk/", board, "/catalog.json"])).text)  # DOM доски
		self.threadsCount = len(self.schema["threads"])  # число активных тредов на доске


# ====== Прикрепление к посту ======
class Media:

	def __init__(self, name, path):
		self.name = name  # имя прикрепления
		self.path = path  # путь на сервере к прикреплению
		self.cached = False  # флаг загрузки прикрепления на комп с вайпалкой

	# === загрузка прикрепления с сосача ===
	def download(self):
		if self.cached == False:
			self.file = requests.get("https://2ch.hk"+self.path).content  # сам файл прикрепления
			self.cached = True


# ====== Существующий пост ======
class Post:

	def __init__(self, schema, mode, triggerForm):
		self.ID = str(schema["num"])  # номер поста на доске
		self.comment = self.set_comment(schema["comment"], mode, triggerForm)  # текст поста
		self.sage = self.set_sage(schema)  # флаг сажи
		self.num = schema["number"]  # номер поста в треде (с 1)
		self.medias = []  # прикрепления
		for media in schema["files"]:
			self.medias.append(Media(media["name"], media["path"]))
		print("Триггернулась на", ">>"+self.ID)

	# === форматирование текста поста ===
	def set_comment(self, text, mode, triggerForm):
		# === замена <br> на \n ===
		text = text.replace("<br>", "\n")
		# === разметка жирного ===
		text = text.replace("<strong>", "[b]")
		text = text.replace("</strong>", "[/b]")
		# === разметка курсива ===
		text = text.replace("<em>", "[i]")
		text = text.replace("</em>", "[/i]")
		# === разметка надстрочного ===
		text = text.replace("<sup>", "[sup]")
		text = text.replace("</sup>", "[/sup]")
		# === разметка подстрочного ===
		text = text.replace("<sub>", "[sub]")
		text = text.replace("</sub>", "[/sub]")
		# === разметка моноширинного ===
		text = text.replace("<code>", "[code]")
		text = text.replace("</code>", "[/code]")

		# === удаление ссылок на посты, либо метки (OP) ===
		if mode == 7 and triggerForm == 0:
			text = text.replace(" (OP)", "")
			soup = BeautifulSoup(text, features="html.parser")
		else:
			soup = BeautifulSoup(text, features="html.parser")
			for a in soup.find_all("a", {"class": "post-reply-link"}):
				a.decompose()

		# === разметка подчёркиваний ===
		for u in soup.find_all("span", {"class": "u"}):
			u.replace_with("[u]"+u.get_text()+"[/u]")
		# === разметка надчёркиваний ===
		for o in soup.find_all("span", {"class": "o"}):
			o.replace_with("[o]"+o.get_text()+"[/o]")
		# === разметка спойлеров ===
		for spoiler in soup.find_all("span", {"class": "spoiler"}):
			spoiler.replace_with("[spoiler]"+spoiler.get_text()+"[/spoiler]")
		# === разметка зачёркнутого ===
		for s in soup.find_all("span", {"class": "s"}):
			s.replace_with("[s]"+s.get_text()+"[/s]")

		# === сохранение ===
		return str(soup.get_text()).lstrip('\n').rstrip('\n')

	# === определение флага сажи ===
	def set_sage(self, schema):
		return True if schema["email"].find("mailto:sage") == -1 else False


# ====== Модель треда ======
class Thread:

	def __init__(self, board, ID, mode, triggerForm):
		self.board = board  # доска
		self.ID = ID  # номер треда на доске
		print("Скачиваю тред", self.ID)
		self.schema = json.loads(requests.get(''.join(["https://2ch.hk/", board, "/res/", ID, ".json"])).text)  # DOM треда
		self.postsCount = self.schema["posts_count"] + 1  # число постов в треде
		self.lastID = str(self.schema["max_num"])  # номер последнего поста треда
		self.posts = self.download_posts(mode, triggerForm)  # посты
		self.loaf = ""  # "батон"
		for postNum in range(min(len(self.posts), 30)):
			self.loaf += (">>"+self.posts[postNum].ID+" ")

	# === загрузка DOM постов ===
	def download_posts(self, mode, triggerForm):
		posts = []
		for post in self.schema["threads"][0]["posts"]:
			posts.append(Post(post, mode, triggerForm))
		return posts






# ====== Запись логов ======
def activate_debug(logMode):
	import logging
	print("\n*** DEBUG MODE ACTIVATED ***")
	if logMode == 1:
		logging.basicConfig(filename='LOG.txt', level=logging.DEBUG)
	elif logMode == 2:
		logging.basicConfig(level=logging.DEBUG)


# ====== Конфигурация ======
class Setup:

	def __init__(self, args):
		if int(args[5]) != 0:
			activate_debug(int(args[5]))
		self.cpFile, self.bansFile, self.fullFile = self.set_encoding()  # файлы с пастами

		self.board = args[1]  # доска
		self.thread = args[2]  # тред
		self.chaos = args[3]  # хаос / тред для постинга
		self.potocksCount = int(args[4])  # число потоков
		self.TIMEOUT, self.PAUSE = self.set_consts(self.potocksCount)  # таймаут, пауза

		self.solver, self.key, self.keyreq = self.set_key(int(args[6]), args[7])  # солвер, ключ, статус ключа
		self.proxyRepeatsCount = int(args[8])  # число повторов прокси
		self.mode, self.pastes, self.bigPaste = self.set_mode(int(args[9]))  # режим вайпалки, пасты

		if self.mode == 8:
			self.minBan = int(args[10])  # минимальный ID бана
			self.maxBan = int(args[11])  # максимальный ID бана

		self.catalog = 0  # ¯\_(ツ)_/¯
		self.threads = []

		if self.thread != "0":
			self.triggerForm, self.shrapnelCharge, self.targetThread = self.set_trigger(int(args[12]), int(args[13]), int(args[14]), args)  # режим триггера, число тредов шрапнели
		else:
			self.triggerForm = 0
			self.shrapnelCharge = 0

		self.mediaKind, self.mediaPaths, self.mediasCount = self.set_media(int(args[15]), args[16], int(args[17]))  # тип прикреплений, число прикреплений к треду
		
		self.sageMode = int(args[18])  # режим сажи
		
		self.shakalPower = int(args[19])  # уровень шакала
		if args[20] == "1": self.shakalColor = True  # флаг цветного шакала
		else: self.shakalColor = False
		if args[21] == "1": self.shakalAffine = True  # флаг аффинного шакала
		else: self.shakalAffine = False
		if args[22] == "1": self.toPNG = True  # флаг конвертации в PNG
		else: self.toPNG = False

	# === определение ОС и кодировки ===
	def set_encoding(self):
		self.cpFile = "texts.txt"
		self.bansFile = "bans.txt"
		self.fullFile = "parasha.txt"
		return self.cpFile, self.bansFile, self.fullFile

	# === установка паузы между постами и таймаута ===
	def set_consts(self, potocksCount):
		if potocksCount == 0:
			TIMEOUT = 60
			PAUSE = 60
			self.potocksCount = 4
		else:
			TIMEOUT = 10
			PAUSE = 20
		return TIMEOUT, PAUSE

	# === получение казённого ключа ===
	def get_key(self, solver):
		if solver == 0:
			solverStr = "xcaptcha"
			print("Пытаюсь получить казеный ключ для икскаптчи...")
		elif solver == 1:
			solverStr = "gurocaptcha"
			print("Пытаюсь получить казеный ключ для гурокаптчи...")
		elif solver == 2:
			solverStr = "anticaptcha"
			print("Пытаюсь получить казеный ключ для антикапчи...")

		keyreq = requests.get('https://2ch-ri.ga/captcha/'+solverStr)
		if keyreq.status_code == 200 and len(keyreq.text) == 32:
			print("Ключ загружен!")
			key = keyreq.text
		elif keyreq.status_code == 404 or len(keyreq.text) == 0:
			print("Ключ недоступен!")
			exit()
		else:
			print("Получен неожиданный ответ от сервера:", keyreq, keyreq.text)
			exit()
		self.set_key(solver, key)
		return key, keyreq

	# === валидация ключа ===
	def set_key(self, solver, key):
		if key == "0":
			key, keyreq = self.get_key(solver)
		elif len(key) == 32:
			print("Верифицируем ключ...")
			if solver == 0:
				keyStatus = requests.get("http://x-captcha2.ru/res.php?key=" + key + "&action=getbalance")
				if keyStatus.status_code == 200:
					if keyStatus.text == "ERROR_KEY_USER":
						print("Ключ не существует!")
						exit()
					elif keyStatus.text == "ERROR_PAUSE_SERVICE":
						print("Сервер на профилактике, используй другой солвер.")
						exit()
					keyxc = keyStatus.text
					keyxc = keyxc.split("|")
					print("Ключ подтверждён, ваш баланс:", keyxc[1])
				elif keyStatus.status_code == 500:
					print("Икскапча заблокировала твой IP, перезагрузи роутер!")
					exit()

			elif solver == 1 or solver == 2:
				if solver == 1:
					keyStatus = requests.post("https://api.captcha.guru/getBalance", json={"clientKey": key}, verify=False).json()
				else:
					keyStatus = requests.post("https://api.anti-captcha.com/getBalance", json={"clientKey": key}, verify=False).json()
				if (keyStatus["errorId"] == 0):
					print("Ключ подтверждён, ваш баланс:", (keyStatus["balance"]))
				elif (keyStatus["errorId"] == 1):
					if (keyStatus["errorDescription"] == "ERROR_KEY_DOES_NOT_EXIST"):
						print("Ключ не существует!")
						exit()
					else:
						print(keyStatus["errorDescription"])
						exit()
			keyreq = 0
		else:
			print("Неправильно введен ключ!")
			exit()
		return solver, key, keyreq

	# === установка режима вайпалки ===
	def set_mode(self, mode):
		if mode == 4:
			with open(self.cpFile, 'r', encoding='utf-8') as file:
				pastes = file.read()
				pastes = pastes.split("\n\n")
				bigPaste = 0
		elif mode == 8:
			with open(self.bansFile, 'r', encoding='utf-8') as file:
				pastes = file.read()
				pastes = pastes.split("\n\n")
				bigPaste = 0
		elif mode == 6:
			bigPaste = ""
			with open(self.fullFile, 'r', encoding='utf-8') as file:
				govno = [row.strip() for row in file]
			bigPaste = '\xa0'.join(govno)
			bigPaste += '\xa0'
			pastes = 0
		else:
			pastes = 0
			bigPaste = 0
		return mode, pastes, bigPaste

	# === установка триггера ===
	def set_trigger(self, form, shrapnelCharge, minPostsCount, args):
		if shrapnelCharge == 0: # and self.thread > 1
			self.threads.append(Thread(self.board, self.thread, self.mode, form))
		elif shrapnelCharge > 0: # and self.thread > 0
			self.catalog = Catalog(self.board)
			if minPostsCount == -1:
				for i in range(shrapnelCharge):
					self.threads.append(Thread(self.board, args[23+i], self.mode, form))
			else:
				i = 0
				for thread in self.catalog.schema["threads"]:
					if int(thread["posts_count"]) >= minPostsCount:
						self.threads.append(Thread(self.board, str(thread["num"]), self.mode, form))
						i += 1
						if i == shrapnelCharge:
							break
				shrapnelCharge = i

		if self.chaos != "-1" and self.chaos != "0":
			targetThread = Thread(self.board, self.chaos, self.mode, form)
		else:
			targetThread = self.threads[0]

		return form, shrapnelCharge, targetThread

	# === установка прикреплений ===
	def set_media(self, mediaKind, mediaGroup, mediasCount):
		mediaPaths = []
		if mediaKind != 0:
			if mediaKind > 1:
				self.TIMEOUT += 30
			if mediaKind < 3:
				if mediaKind == 1:
					mediaDir = "images"
				elif mediaKind == 2:
					mediaDir = "videos"
				if len(mediaGroup) > 0 and mediaGroup != "0":
					mediaDir += "/"
					mediaDir += mediaGroup
				for media in os.listdir("./"+mediaDir):
					if media.endswith(".jpg") or media.endswith(".png") or media.endswith(".gif") or media.endswith(".bmp") or media.endswith(".mp4") or media.endswith(".webm"):
						mediaPaths.append("./"+mediaDir+"/"+media)
				if mediasCount == 0:
					mediaKind = 0

			elif self.shrapnelCharge == 0:
				for post in self.threads[0].posts:
					for media in post.medias:
						print("Скачиваю ", media.name, "("+str(post.num)+"/"+str(self.threads[0].postsCount)+" пост)")
						media.download()
			else:
				self.TIMEOUT += 60
		else:
			mediasCount = 0
		return mediaKind, mediaPaths, mediasCount







class CaptchaSolver_XCaptcha_2ch:

	def __init__(self, key, keyreq):
		self.api = "http://x-captcha2.ru/in.php"
		self.key = key
		print("Solver 'X-Captcha' initialized with key: " + self.key)

	def solve(self, image, badproxies):

		while True:
			task = (('key', self.key), ('method', 'userrecaptcha'), ('googlekey', '6LeQYz4UAAAAAL8JCk35wHSv6cuEV5PyLhI6IxsM'), ('pageurl', 'https://2ch.hk/b/'))
			data = requests.post(self.api, data=task, verify=False)

			response = data.text
			response = response.split("|")

			if (response[0] == "OK"):

				while True:
					solveData = requests.get("http://x-captcha2.ru/res.php?key=" + self.key + "&id=" + response[1])
					solveResponse = solveData.text 
					solveResponse = solveResponse.split("|")

					if (solveResponse[0] == "OK"):
						Stats.incCaptchas()
						return solveResponse[1]

					time.sleep(3)
			time.sleep(3)

class CaptchaSolver_captchaguru_2ch:

	def __init__(self, key, keyreq):
		self.api = "https://api.captcha.guru/"
		self.key = key
		print("Solver 'captcha.guru' initialized with key: " + self.key)

	def solve(self, image, badproxies):
		task = {}
		task["type"] = "NoCaptchaTask"
		task["websiteURL"] = "https://2ch.hk/b/"
		task["websiteKey"] = "6LeQYz4UAAAAAL8JCk35wHSv6cuEV5PyLhI6IxsM"
		data = requests.post(self.api + "createTask", json={"clientKey": self.key, "task": task}, verify=False).json()
		if (data["errorId"] == 0):
			while True:
				response = requests.post(self.api + "getTaskResult", json={"clientKey" : self.key, "taskId" : str(data["taskId"])}, verify=False).json()
				if (response["status"] == "ready"):
					return response["solution"]["gRecaptchaResponse"]
				time.sleep(3)
		time.sleep(3)

class CaptchaSolver_anticaptcha_2ch:

	def __init__(self, key, keyreq):
		self.api = "http://api.anti-captcha.com/"
		self.key = key
		print("Solver 'anti-captcha' initialized with key: " + self.key)

	def solve(self, image, badproxies):
		task = {}
		task["type"] = "ImageToTextTask"
		task["body"] = base64.b64encode(image).decode("utf-8")
		task["phrase"] = False
		task["case"] = False
		task["numeric"] = 1
		task["math"] = False
		task["minLength"] = 6
		task["maxLength"] = 6
		data = requests.post(self.api + "createTask", json={"clientKey": self.key, "task": task}, verify=False).json()
		if (data["errorId"] == 0):
			while True:
				response = requests.post(self.api + "getTaskResult", json={"clientKey" : self.key, "taskId" : str(data["taskId"])}, verify=False).json()
				if (response["status"] == "ready"):
					return response["solution"]["text"]
				time.sleep(3)






# ====== X-капча ======
class CaptchaSolver_XCaptcha_re:

	def __init__(self, key, keyreq):
		self.api = "http://x-captcha2.ru/in.php"
		self.key = key
		try:
			if keyreq.status_code == 200:
				print("Solver 'X-Captcha' initialized with key: [ДАННЫЕ УДАЛЕНЫ]")
		except Exception:
			print("Solver 'X-Captcha' initialized with key: " + self.key)

	def solve(self, image, badproxies, forbiddenproxy):

		while True:
			task = (('key', self.key), ('method', 'userrecaptcha'), ('googlekey', '6LeQYz4UAAAAAL8JCk35wHSv6cuEV5PyLhI6IxsM'), ('pageurl', 'https://2ch.hk/b/'))
			data = requests.post(self.api, data=task, verify=False)

			response = data.text
			response = response.split("|")

			if (response[0] == "OK"):

				while True:
					solveData = requests.get("http://x-captcha2.ru/res.php?key=" + self.key + "&id=" + response[1])
					solveResponse = solveData.text 
					solveResponse = solveResponse.split("|")

					if (solveResponse[0] == "OK"):
						Stats.incCaptchas()
						return solveResponse[1]

					time.sleep(3)
			elif data.text == "ERROR_KEY_USER":
				print("\nОшибка ключа, не могу продолжать работу...")
				safe_quit(badproxies, forbiddenproxy)
			time.sleep(3)


# ====== Гуру-капча ======
class CaptchaSolver_captchaguru_re:

	def __init__(self, key, keyreq):
		self.api = "https://api.captcha.guru/"
		self.key = key
		try:
			if keyreq.status_code == 200:
				print("Solver 'captcha.guru' initialized with key: [ДАННЫЕ УДАЛЕНЫ]")
		except Exception:
			print("Solver 'captcha.guru' initialized with key: " + self.key)

	def solve(self, image, badproxies, forbiddenproxy):
		task = {}
		task["type"] = "NoCaptchaTask"
		task["websiteURL"] = "https://2ch.hk/b/"
		task["websiteKey"] = "6LeQYz4UAAAAAL8JCk35wHSv6cuEV5PyLhI6IxsM"
		data = requests.post(self.api + "createTask", json={"clientKey": self.key, "task": task}, verify=False).json()
		if (data["errorId"] == 0):
			while True:
				response = requests.post(self.api + "getTaskResult", json={"clientKey" : self.key, "taskId" : str(data["taskId"])}, verify=False).json()
				if (response["status"] == "ready"):
					return response["solution"]["gRecaptchaResponse"]
				time.sleep(3)
		elif (data["errorId"] == 1):
			if (data["errorDescription"] == "ERROR_KEY_DOES_NOT_EXIST"):
				print("\nКлюч отозван, не могу продолжать работу...")
				safe_quit(badproxies, forbiddenproxy)
			elif (data["errorDescription"] == "ERROR_ZERO_BALANCE"):
				print("\nЗакончились деньги на капче, не могу продолжать работу...")
				safe_quit(badproxies, forbiddenproxy)
			elif (data["errorDescription"] == "ERROR_NO_SLOT_AVAILABLE"):
				print("\nНет свободных индуссов на сервере, таймаут 10 секунд...")
				time.sleep(7)
			else:
				print("\nПроизошла неведомая ебаная хуйня, сорян. Вот ответ от сервера:", (data["errorDescription"]))
				safe_quit(badproxies, forbiddenproxy)
		time.sleep(3)


# ====== Антикапча ======
class CaptchaSolver_anticaptcha_re:

	def __init__(self, key, keyreq):
		self.api = "http://api.anti-captcha.com/"
		self.key = key
		try:
			if keyreq.status_code == 200:
				print("Solver 'anti-captcha' initialized with key: [ДАННЫЕ УДАЛЕНЫ]")
		except Exception:
			print("Solver 'anti-captcha' initialized with key: " + self.key)

	def solve(self, image, badproxies, forbiddenproxy):
		task = {}
		task["type"] = "NoCaptchaTaskProxyless"
		# пока так, позже прикручу передачу наших проксичек
		task["websiteURL"] = "https://2ch.hk/b/"
		task["websiteKey"] = "6LeQYz4UAAAAAL8JCk35wHSv6cuEV5PyLhI6IxsM"
		data = requests.post(self.api + "createTask", json={"clientKey": self.key, "task": task}, verify=False).json()
		if (data["errorId"] == 0):
			while True:
				response = requests.post(self.api + "getTaskResult", json={"clientKey" : self.key, "taskId" : str(data["taskId"])}, verify=False).json()
				if (response["status"] == "ready"):
					return response["solution"]["gRecaptchaResponse"]
				time.sleep(3)
		elif (data["errorId"] == 1):
			if (data["errorDescription"] == "ERROR_KEY_DOES_NOT_EXIST"):
				print("\nКлюч отозван, не могу продолжать работу...")
				safe_quit(badproxies, forbiddenproxy)
			elif (data["errorDescription"] == "ERROR_ZERO_BALANCE"):
				print("\nЗакончились деньги на капче, не могу продолжать работу...")
				safe_quit(badproxies, forbiddenproxy)
			else:
				print("\nПроизошла неведомая ебаная хуйня, сорян. Вот ответ от сервера:", (data["errorDescription"]))
				safe_quit(badproxies, forbiddenproxy)
		time.sleep(3)






# ====== Макросы макросики ======
CHARS = string.ascii_uppercase + string.digits
TEXT_CHARS = string.ascii_uppercase + string.digits + string.ascii_lowercase + (string.whitespace * 10) + string.punctuation
NAME_SIZE = 14
badproxies = []
forbiddenproxy = []


# ====== Шапка ======
def show_logo():
	os.system('cls' if os.name == 'nt' else 'clear')
	print("\n*************************************************")
	print("*    2CH.HK WIPE MACHINE - ReCaptcha edition    *")
	print("*     Только для внутреннего использования      *")
	print("*        Оригинальный проект: glow_stick        *")
	print("*      Быдлокод: owodelta, kobato, arelive      *")
	print("*            cryptostimor, tsunamaru            *")
	print("*************************************************")


# ====== API капчи сосача ======
class Captcha:

	def __init__(self, proxy, agent, board, thread, solver, TIMEOUT, captchaType):
		if (captchaType) == "2ch":
			self.api = "https://2ch.hk/api/captcha/2chaptcha/"
		else:
			self.api = "https://2ch.hk/api/captcha/recaptcha/id"
		self.proxy = proxy
		self.board = board
		self.thread = thread
		self.solver = solver
		self.TIMEOUT = TIMEOUT
		self.set_headers(agent)

#		os.environ["https_proxy"] = self.proxy["https"]
#		os.environ["http_proxy"] = self.proxy["http"]

		captcha = requests.get(self.api + "id?board=" + self.board + "&thread=" + self.thread, proxies=self.proxy, headers=self.headers, timeout=self.TIMEOUT, verify=False).json()
		self.id = captcha["id"]
		self.image = requests.get(self.api + "image/" + self.id, proxies=self.proxy, headers=self.headers, timeout=self.TIMEOUT, verify=False).content

	def set_headers(self, agent):
		self.headers = {}
		self.headers["Host"] = "2ch.hk"
		self.headers.update(agent)
		self.headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"
		self.headers["Accept-Language"] = "ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3"
		self.headers["Accept-Encoding"] = "gzip, deflate, br"
		self.headers["Connection"] = "keep-alive"
		self.headers["Upgrade-Insecure-Requests"] = "1"

	def solve(self):
		print(self.proxy["http"], "solving captcha")
		self.value = self.solver.solve(self.image, badproxies, forbiddenproxy)
		return (None, self.id), (None, self.value)

	def verify(self):
		return requests.get(self.api + "check/" + self.id + '?value=' + self.value, proxies=self.proxy, headers=self.headers, verify=False, timeout=self.TIMEOUT).json()["result"] == 1


# ====== Постинг ======
class NewPost:

	def __init__(self, proxy, agent, board, thread, solver, captchaType):
		self.proxy = {"http": proxy, "https": proxy}
		self.agent = {"User-Agent": agent}
		self.board = board
		self.thread = thread
		self.solver = solver
		self.captchaType = captchaType
		self.buffer = {}
		self.params = []
		self.params.append(("task", (None, "post")))
		self.params.append(("board", (None, self.board)))
		self.params.append(("thread", (None, self.thread)))
		self.params.append(("usercode", (None, "")))
		self.params.append(("code", (None, "")))
		if self.captchaType == "2ch":
			self.params.append(("captcha_type", (None, "2chaptcha")))
		else:
			self.params.append(("captcha_type", (None, "recaptcha")))
		self.params.append(("oekaki_image", (None, "")))
		self.params.append(("oekaki_metadata", (None, "")))
#		self.params["g-recaptcha-response"] = (None, "")
#		self.params["formimages"] = []

		self.set_headers()
#		self.set_subject("Ответ")

	def set_headers(self):
		self.headers = {}
		self.headers["Host"] = "2ch.hk"
		self.headers.update(self.agent)
		self.headers["Accept"] = "application/json, text/javasctipt, */*; q=0.01"
		self.headers["Accept-Language"] = "ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3"
		self.headers["Accept-Encoding"] = "gzip, deflate, br"
		self.headers["Referer"] = str("https://2ch.hk/" + self.board + "/res/" + self.thread + ".html")
		self.headers["X-Requested-With"] = "XMLHttpRequest"
		self.headers["Content-Length"] = str(15000000 + random.randint(0, 100))
		self.headers["Cookie"] = ""
		self.headers["Connection"] = "keep-alive"

	def prepare(self, TIMEOUT):
		try:
			self.buffer["chaptcha_id"], self.buffer["chaptcha_value"] = Captcha(self.proxy, self.agent, self.board, self.thread, self.solver, TIMEOUT, self.captchaType).solve()
			if self.captchaType == "2ch":
				self.params.append(("2chaptcha_id", self.buffer["chaptcha_id"]))
				self.params.append(("2chaptcha_value", self.buffer["chaptcha_value"]))
			else:
				self.params.append(("2chaptcha_id", self.buffer["chaptcha_id"]))
				self.params.append(("g-recaptcha-response", self.buffer["chaptcha_value"]))
			print(self.proxy["http"], "solved")
			return True
		except Exception as e:
			#print(e)
			return False

	def set_subject(self, text):
		self.params.append(("subject", (None, text)))

	def set_text(self, text):
		self.params.append(("comment", (None, text)))
		
	def set_sage(self):
		self.params.append(("email", (None, "sage")))
		self.params.append(("sage", (None, "on")))

	def set_image(self, file_name, shakalPower=0, shakalColor=False, shakalAffine=False, toPNG=False):
		image = self.shakal(file_name, shakalPower, shakalColor, shakalAffine, toPNG)
		file_name_displayed = str(''.join(str(random.randint(0, 9)) for _ in range(NAME_SIZE-1)) + "0")
		if toPNG: file_name_displayed += ".png"
		else: file_name_displayed += ".jpg"
		self.params.append(("formimages[]", (file_name_displayed, image, "image/jpeg")))

	def set_video(self, file_name):
		if file_name.find(".mp4") != -1: ext = "mp4"
		elif file_name.find(".webm") != -1: ext = "webm"

		video = open(file_name, "rb")
		video_bytes = video.read()
		video.close()

		file_name_displayed = str(''.join(str(random.randint(0, 9)) for _ in range(NAME_SIZE-1)) + "0")
		file_name_displayed += str("." + ext)
		self.params.append(("formimages[]", (file_name_displayed, video_bytes, str("video/" + ext))))

	def set_media(self, mediaName, media, shakalPower=0, shakalColor=False, shakalAffine=False, toPNG=False):
		file_name_displayed = str(''.join(str(random.randint(0, 9)) for _ in range(NAME_SIZE-1)) + "0")

		if mediaName.find(".jpg") != -1 or mediaName.find(".png") != -1 or mediaName.find(".gif") != -1 or mediaName.find(".bmp") != -1:
			media = self.shakal(io.BytesIO(media), shakalPower, shakalColor, shakalAffine, toPNG)

			if toPNG:
				mediaType = "image/png"
				file_name_displayed += ".png"
			else:
				mediaType = "image/jpeg"
				file_name_displayed += ".jpg"

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

	def shakal(self, image, power, color=False, affine=False, toPNG=False):
		image = PIL.Image.open(image).convert("RGBA")
		width, height = image.size
		for x in range(power): image.putpixel((random.randint(0, width-1), random.randint(0, height-1)), (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))

		if color:
			red = random.randint(0, 255)
			dif = abs(red - 127)
			green = random.randint(0, dif)
			if random.randint(0, 1): green = 255 - green
			blue = random.randint(max(0, 255-red-green), min(255, 510-red-green))
			if random.randint(0, 1): red, green = green, red
			if random.randint(0, 1): red, blue = blue, red
			if random.randint(0, 1): blue, green = green, blue
			layer = PIL.Image.new("RGBA", image.size, (red, green, blue, 65))
			image.paste(layer, (0, 0), layer)
		if affine:
			shakal = (1 + random.randint(0, 100)/1000 - 0.05, 0 + random.randint(0, 100)/1000 - 0.05, 1 + random.randint(0, 100)/1000 - 0.05, 0 + random.randint(0, 100)/1000 - 0.05, 1 + random.randint(0, 100)/1000 - 0.05, 0 + random.randint(0, 100)/1000 - 0.05)
			image = image.transform(image.size, PIL.Image.AFFINE, shakal, resample=PIL.Image.BICUBIC)

		image = image.crop((random.randint(0, power), random.randint(0, power), width-1 - random.randint(0, power), height-1 - random.randint(0, power)))
		if toPNG:
			image_bytes = io.BytesIO()
			image.save(image_bytes, "PNG", quality=20 + random.randint(10, 30), optimize=bool(random.getrandbits(1)), progressive=bool(random.getrandbits(1)))
		else:
			image = image.convert("RGB")
			image_bytes = io.BytesIO()
			image.save(image_bytes, "JPEG", quality=60 + random.randint(10, 30), optimize=bool(random.getrandbits(1)), progressive=bool(random.getrandbits(1)))
		image.close()
		return image_bytes.getvalue()

	def send(self, TIMEOUT, PAUSE):
		response = {}
		try:
			print(self.proxy["http"], "posting")
			wait_time = random.randint(6, 15)
			time.sleep(PAUSE)
			response = requests.post("https://2ch.hk/makaba/posting.fcgi?json=1", files=self.params, proxies=self.proxy, headers=self.headers, timeout=TIMEOUT, verify=False).json()
			Stats.incPosts()
			Stats.printStats(badproxies, forbiddenproxy)
			return response['Status'] == 'OK', response
		except Exception as e:
			#print(e)
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
		self.setup = setup
		self.catalog = catalog
		self.threads = threads

		self.set_solver(setup.solver)

	def set_solver(self, solver):
		captcha = requests.get("https://2ch.hk/api/captcha/2chaptcha/id?board=b&thread=0", headers={"User-Agent": self.agents[0]}, timeout=self.setup.TIMEOUT, verify=False).json()
		captchaID = captcha["id"]
		image = requests.get("https://2ch.hk/api/captcha/2chaptcha/image/" + captchaID, headers={"User-Agent": self.agents[0]}, timeout=self.setup.TIMEOUT, verify=False).content
		error = open("error.gif","rb")

		if True:#image == error.read():
			self.captchaType = "re"
			if solver == 0:
				self.solver = CaptchaSolver_XCaptcha_re(self.setup.key, self.setup.keyreq)
			elif solver == 1:
				self.solver = CaptchaSolver_captchaguru_re(self.setup.key, self.setup.keyreq)
			elif solver == 2:
				self.solver = CaptchaSolver_anticaptcha_re(self.setup.key, self.setup.keyreq)
		else:
			self.captchaType = "2ch"
			if solver == 0:
				self.solver = CaptchaSolver_XCaptcha_2ch(self.setup.key, self.setup.keyreq)
			elif solver == 1:
				self.solver = CaptchaSolver_captchaguru_2ch(self.setup.key, self.setup.keyreq)
			elif solver == 2:
				self.solver = CaptchaSolver_anticaptcha_2ch(self.setup.key, self.setup.keyreq)

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
					if (self.setup.chaos == "-1"):
						thread = self.threads[0]
					else:
						thread = self.setup.targetThread
				else:
					threadNum = random.randint(0, self.setup.shrapnelCharge-1)
					if (self.setup.chaos == "-1"):
						thread = self.threads[threadNum]
					elif (self.setup.chaos == "0"):
						thread = self.threads[random.randint(0, len(self.threads)-1)]
					else:
						thread = self.setup.targetThread

				post = NewPost(proxy, agent, self.board, thread.ID, self.solver, self.captchaType)
				if (post.prepare(self.setup.TIMEOUT)):
					charnum = random.randint(1, 100)
					if self.thread != "0":
						black_anus = random.randint(1, len(thread.posts)-1)  # номер поста для триггера
						white_anus = random.randint(0, len(self.threads[threadNum].posts)-1)  # номер поста для дублирования

					# === берём сначала триггер ===
					if self.setup.triggerForm == 1:
						trigger = ">>" + thread.lastID + '\n'
					elif self.setup.triggerForm == 2:
						trigger = ">>" + thread.posts[black_anus].ID + '\n'
					elif self.setup.triggerForm == 3:
						trigger = thread.loaf + '\n'
					elif self.setup.triggerForm == 4:
						trigger = ">>" + thread.posts[0].ID + '\n'
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
						post.set_text(trigger + ("> " + thread.posts[black_anus].comment).replace("\n", "\n> ").replace("\n> \n", "\n\n"))
					elif self.setup.mode == 4:
						post.set_text(trigger + self.trap_replace(self.setup.pastes[random.randint(0, len(self.setup.pastes)-1)]))
					elif self.setup.mode == 5:
						post.set_text(trigger + "https://2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J2ch.hk/b/res/MZx7W05J")
					elif self.setup.mode == 6:
						post.set_text(trigger + self.trap_replace(self.setup.bigPaste))
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
								if self.setup.mediaKind != 3:
									blue_anus = random.randint(0, len(self.setup.mediaPaths)-1)  # номер пикчи или видео с диска
								if self.setup.mediaKind == 1:
									post.set_image(self.setup.mediaPaths[blue_anus], self.setup.shakalPower, self.setup.shakalColor, self.setup.shakalAffine, self.setup.toPNG)
								elif self.setup.mediaKind == 2:
									post.set_video(self.setup.mediaPaths[blue_anus])
								elif self.setup.mediaKind == 3:
									post.set_media(self.threads[threadNum].posts[white_anus].medias[mediaNum].name, self.threads[threadNum].posts[white_anus].medias[mediaNum].file, self.setup.shakalPower, self.setup.shakalColor, self.setup.shakalAffine, self.setup.toPNG)
						except Exception as e:
							#print(e)
							print("Не могу скачать / прикрепить файл.")

					# === и сажу туды ===
					if self.setup.sageMode == 2:
						if self.threads[threadNum].posts[white_anus].sage == True:
							post.set_sage()
						else:
							post.params.append(("email", (None, "")))
					elif self.setup.sageMode == 1:
						post.set_sage()
					elif self.setup.sageMode == 0:
						post.params.append(("email", (None, "")))

					success, response = post.send(self.setup.TIMEOUT, self.setup.PAUSE)
					if success:
						Stats.incPosts()
						post_id = 0
						try:
							post_id = response["Target"]
						except:
							post_id = response["Num"]
						if self.setup.shrapnelCharge == 0:
							print(proxy+" - success. Post id: "+str(post_id))
						else:
							print(proxy+" - success. Post id: "+str(post_id)+" ("+thread.ID+" thread)")
						if self.setup.thread != "0":
							self.threads[threadNum].lastID = str(post_id)

						print(str(self.setup.proxyRepeatsCount-counter)+" LOOPS LEFT")
						counter += 1
					else:
						print(proxy, "posting failed -", response)

						try:
							if response["Error"] == -6:
								print("Забанили, суки... "+proxy+" в плохой лист")
								badproxies.append(proxy)
								if len(self.proxies) == 0:
									print("Закончились проксички!")
									counter = self.setup.proxyRepeatsCount
								else:
									proxy = self.proxies.pop(0)
									counter = 0
							elif response["Error"] == -4:
								print("Заносим "+proxy+" в forbidden.csv")
								badproxies.append(proxy)
								forbiddenproxy.append(proxy)
								if len(self.proxies) == 0:
									print("Закончились проксички!")
									counter = self.setup.proxyRepeatsCount
								else:
									proxy = self.proxies.pop(0)
									counter = 0
							elif response["Error"] == -7:
								if self.setup.shrapnelCharge == 0:
									print("Моча вычищает тред. КОНЧАЮ.")
									safe_quit(badproxies, forbiddenproxy)
								else:
									print("Тред "+self.threads[threadNum].ID+" закрылся.")
									del self.threads[threadNum]
									if len(self.threads) == 0:
										print("Все треды закрыты. Це перемога.")
										safe_quit(badproxies, forbiddenproxy)
							elif not response:
								print("Ошибка сети, пробуем ещё раз...")

						except Exception:
							if len(response) > 0:
								print("Таймаут... "+proxy+" в плохой лист")
								badproxies.append(proxy)
								if len(self.proxies) == 0:
									print("Закончились проксички!")
									counter = self.setup.proxyRepeatsCount
								else:
									proxy = self.proxies.pop(0)
									counter = 0
			if not proxy in badproxies:
				self.proxies.push(proxy)

		except Exception as e:
			print(e)
#			badproxies.append(proxy)

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
				Stats.printStats(badproxies, forbiddenproxy)
				eternal_input(badproxies, forbiddenproxy)

		threads = []
		inthr = InputThread()
		inthr.start()
		for i in range(thread_count):
			threads.append(WiperThread(self))
			threads[-1].start()

		for i in range(len(threads)):
			threads[i].join()

try:
	show_logo()

	setup = Setup(sys.argv)
	WiperObj = Wiper(setup, setup.catalog, setup.threads)
	signal.signal(signal.SIGINT, safe_quit)
	WiperObj.wipe(setup.potocksCount)

	safe_quit(badproxies, forbiddenproxy)

except Exception as e:
	print("arelive obosralsya")
	input()

