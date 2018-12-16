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
import tools

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
# 2 - тред
# 3 - число потоков
# 4 - флаг отладки и номер вывода логов
# 5 - номер решателя
# 6 - ключ (или "0" для казенного)
# 7 - число повторов прокси
# 8 - режим вайпалки
# 9 - минимальный номер разбана (или -1)
# 10 - максимальный номер разбана (или -1)
# 11 - номер режима триггера (или -1, если нулевая)
# 12 - число тредов для шрапнели (или 0, если без неё)
# 13 - минимальное число постов в тредах для шрапнели (или -1, если без неё или с указанием тредов)
# 14 - номер вида прикреплений (или 0, если дэ)
# 15 - подкаталог прикреплений (или 0, если из корня)
# 16 - число прикреплений (или -1, если из постов)
# 17 - номер режима сажи
# 18 итд - треды для шрапнели при ручном указании

# ====== Конфигурация ======
class Setup:

	def __init__(self, args):
		if int(args[4]) != 0:
			activate_debug(int(args[4]))
		self.cpFile, self.bansFile, self.fullFile = self.set_encoding()  # файлы с пастами

		self.board = args[1]  # доска
		self.thread = args[2]  # тред
		self.potocksCount = int(args[3])  # число потоков
		self.TIMEOUT, self.PAUSE = self.set_consts(self.potocksCount)  # таймаут, пауза

		self.solver, self.key = self.set_key(int(args[5]), args[6])  # солвер, ключ
		self.proxyRepeatsCount = int(args[7])  # число повторов прокси
		self.mode, self.pastes, self.bigPaste = self.set_mode(int(args[8]))  # режим вайпалки, пасты

		if self.mode == 8:
			self.minBan = int(args[9])  # минимальный ID бана
			self.maxBan = int(args[10])  # максимальный ID бана

		self.catalog = 0  # ¯\_(ツ)_/¯
		self.threads = []

		if self.thread != "0":
			self.triggerForm, self.shrapnelCharge = self.set_trigger(int(args[11]), int(args[12]), int(args[13]), args)  # режим триггера, число тредов шрапнели

		self.mediaKind, self.mediaPaths, self.mediasCount = self.set_media(int(args[14]), args[15], int(args[16]))  # тип прикреплений, число прикреплений к треду
		
		self.sageMode = int(args[17])  # режим сажи

	# === определение ОС и кодировки ===
	def set_encoding(self):
		if os.name == "nt":
			self.cpFile = "texts_win.txt"
			self.bansFile = "bans_win.txt"
			self.fullFile = "parasha_win.txt"
		else:
			self.cpFile = "texts_unix.txt"
			self.bansFile = "bans_unix.txt"
			self.fullFile = "parasha_unix.txt"
		return self.cpFile, self.bansFile, self.fullFile

	def set_consts(self, potocksCount):
		if potocksCount == 0:
			TIMEOUT = 60
			PAUSE = 50
			self.potocksCount = 4
		else:
			TIMEOUT = 3
			PAUSE = 10
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

		keyreq = requests.get('http://94.140.116.169:8080/captcha/'+solverStr)
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
		return key;

	# === валидация ключа ===
	def set_key(self, solver, key):
		if key == "0":
			key = self.get_key(solver)
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
		else:
			print("Неправильно введен ключ!")
			exit()
		return solver, key

	# === установка режима вайпалки ===
	def set_mode(self, mode):
		if mode == 4:
			with open(self.cpFile) as file:
				pastes = file.read()
				pastes = pastes.split("\n\n")
				bigPaste = 0
		elif mode == 8:
			with open(self.bansFile) as file:
				pastes = file.read()
				pastes = pastes.split("\n\n")
				bigPaste = 0
		elif mode == 6:
			bigPaste = ""
			with open(self.fullFile) as file:
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
			self.threads.append(scheme.Thread(self.board, self.thread, self.mode, form))
		elif shrapnelCharge > 0: # and self.thread > 0
			self.catalog = scheme.Catalog(self.board)
			if minPostsCount == -1:
				for i in range(shrapnelCharge):
					self.threads.append(scheme.Thread(self.board, args[18+i], self.mode, form))
				else:
					i = 0
					for thread in self.catalog.schema["threads"]:
						if int(thread["posts_count"]) >= minPostsCount:
							self.threads.append(scheme.Thread(self.board, str(thread["num"]), self.mode, form))
							i += 1
							if i == shrapnelCharge:
								break
					shrapnelCharge = i
		return form, shrapnelCharge

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
					for media in range(len(post.medias)):
						print("Скачиваю ", media.name, "("+str(post.num)+"/"+str(self.threads[0].postsCount)+" пост)")
						media.download()
			else:
				self.TIMEOUT += 60
		else:
			mediaKind = 0
		return mediaKind, mediaPaths, mediasCount
