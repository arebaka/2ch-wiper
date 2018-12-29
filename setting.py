## -*- coding: utf-8 -*-

import os
import requests
import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

from scheme import *
from tools import *

# ====== Запись логов ======
def activate_debug(logMode):
	import logging
	print("\n*** DEBUG MODE ACTIVATED ***")
	if logMode == 1:
		logging.basicConfig(filename='LOG.txt', level=logging.DEBUG)
	elif logMode == 2:
		logging.basicConfig(level=logging.DEBUG)


## args:
# 1 - доска
# 2 - тред (или "0", если доску)
# 3 - флаг хаоса и тред для постинга (-1, если без хаоса, 0, если шрапнельный хаос)
# 4 - число потоков (или 0, если 1 пост в 5 минут)
# 5 - номер вывода логов (или 0, если без них)
# 6 - номер решателя
# 7 - ключ (или "0" для казенного)
# 8 - число повторов прокси
# 9 - режим вайпалки
# 10 - минимальный номер разбана (или -1, если не 8 режим)
# 11 - максимальный номер разбана (или -1, если не 8 режим)
# 12 - номер режима триггера (или 0, если доску или просто без него)
# 13 - число тредов для шрапнели (или 0, если без неё)
# 14 - минимальное число постов в тредах для шрапнели (или -1, если без неё или с указанием тредов)
# 15 - номер вида прикреплений (или 0, если дэ или просто без них)
# 16 - подкаталог прикреплений (или "0", если из корня)
# 17 - число прикреплений (или -1, если из постов)
# 18 - номер режима сажи
# 19 - уровень шакала от 0 до 100
# 20 - флаг цветного шакала
# 21 - флаг аффинного шакала
# 22 - флаг конвертации в PNG с альфа-каналом
# 23 итд - треды для шрапнели при ручном указании

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
		if args[21] == "1": self.shakalAffine = True  # флаг аффинного шакала
		if args[22] == "1": self.toPNG = True  # флаг конвертации в PNG

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
