import os
import requests
import scheme

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
# 14 - номер вида прикреплений (или -1, если дэ)
# 15 - подкаталог прикреплений (или 0, если из корня)
# 16 - число прикреплений (или -1, если из постов)
# 17 - номер режима сажи
# 18 итд - треды для шрапнели при ручном указании

# ====== Конфигурация ======
class Setup:

	def __init__(self, args):
		self.cpFile, self.bansFile, self.fullFile = self.set_encoding()  # файлы с пастами

		self.board = args[1]  # доска
		self.thread = args[2]  # тред
		self.potocksCount = int(args[3])  # число потоков

		self.solverType, self.key = self.set_key(int(args[5]), args[6])  # солвер, ключ
		self.proxyRepeatsCount = int(args[7])  # число повторов прокси
		self.wiperMode, self.pastes, self.bigPaste = self.set_mode(int(args[8]))  # режим вайпалки, пасты

		if self.wiperMode == 8:
			self.minBan = int(args[9])  # минимальный ID бана
			self.maxBan = int(args[10])  # максимальный ID бана

		self.catalog = 0  # ¯\_(ツ)_/¯
		self.threads = []

		if self.thread != "0":
			self.triggerForm, self.shrapnelCharge = set_trigger(int(args[11]), int(args[12]), int(args[13]), args)  # режим триггера, число тредов шрапнели

		self.mediaKind, self.mediaPaths, self.mediasCount = self.set_media(int(args[14]), args[15], int(args[16]))  # вид прикреплений, число прикреплений
		
		self.sageMode = int(args[17])  # режим сажи

	# === определение ОС и кодировки ===
	def set_encoding(self):
		if os.name == "nt":
			cpFile = "texts_win.txt"
			bansFile = "bans_win.txt"
			fullFile = "parasha_win.txt"
		else:
			cpFile = "texts_unix.txt"
			bansFile = "bans_unix.txt"
			fullFile = "parasha_unix.txt"
		return cpFile, bansFile, fullFile

	# === получение казённого ключа ===
	def get_key(self, solverType):
		if solverType == 0:
			solverType = "xcaptcha"
			print("Пытаюсь получить казеный ключ для икскаптчи...")
		elif solverType == 1:
			solverType = "gurocaptcha"
			print("Пытаюсь получить казеный ключ для гурокаптчи...")
		elif solverType == 2:
			solverType = "anticaptcha"
			print("Пытаюсь получить казеный ключ для антикапчи...")

		keyreq = requests.get('http://94.140.116.169:8080/captcha/'+solverType)
		if keyreq.status_code == 200 and len(keyreq.text) == 32:
			print("Ключ загружен!")
			key = keyreq.text
		elif keyreq.status_code == 404 or len(keyreq.text) == 0:
			print("Ключ недоступен!")
			exit()
		else:
			print("Получен неожиданный ответ от сервера:", keyreq, keyreq.text)
			exit()
		return key;

	# === валидация ключа ===
	def set_key(self, solverType, key):
		if key == "0":
			key = self.get_key(solverType)
		elif len(KEY) == 32:
			print("Верифицируем ключ...")
			if solverType == 0:
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

			elif solverType == 1 or solverType == 2:
				if solverType == 1:
					keyStatus = requests.post("https://api.captcha.guru/getBalance", json={"clientKey": key}, verify=False).json()
				else:
					keyStatus = requests.post("https://api.anti-captcha.com/getBalance", json={"clientKey": KEY}, verify=False).json()
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
		return solverType, key

	# === установка режима вайпалки ===
	def set_mode(self, mode):
		if mode == 4:
			with open(cpFile) as file:
				pastes = file.read()
				pastes = copyPastes.split("\n\n")
				bigPaste = 0
		elif mode == 8:
			with open(bansFile) as file:
				pastes = file.read()
				pastes = banPastes.split("\n\n")
				bigPaste = 0
		elif mode == 6:
			bigPaste = ""
			with open(fullFile) as file:
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
			self.threads.append(scheme.Thread(self.board, self.thread))
		elif shrapnelCharge > 0: # and self.thread > 0
			self.catalog = scheme.Catalog(self.board)
			if minPostsCount == -1:
				for i in range(shrapnelCharge):
					self.threads.append(scheme.Thread(self.board, args[18+i]))
				else:
					i = 0
					for thread in self.catalog.schema["threads"]:
						if int(thread["posts_count"]) >= minPostsCount:
							self.threads.append(scheme.Thread(self.board, str(thread["num"])))
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
				TIMEOUT += 30
			if mediaKind < 3:
				if mediaKind == 1:
					mediaDir = "images"
				elif mediaKind == 2:
					mediaDir = "videos"
				if len(mediaGroup) > 0:
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
				TIMEOUT += 60
		else:
			mediaKind = 0
		return mediaKind, mediaPaths, mediasCount
