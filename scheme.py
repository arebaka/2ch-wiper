
class Catalog:

	def __init__(self, board):
		self.board = board
		self.schema = json.loads(requests.get(''.join(["https://2ch.hk/", board "/catalog.json"])).text)
		self.threadsCount = len(self.schema["threads"])


class Media:

	def __init__(self, name, path):
		self.name = name
		self.path = path
		self.cached = False

	def download(self):
		if self.cached == False:
			self.file = requests.get("https://2ch.hk"+self.path).content
			self.cached = True


class Post:

	def __init__(self, schema):
		self.ID = schema["num"]
		self.set_comment(schema["comment"])
		self.set_sage(schema)
		self.medias = []
		for media in schema["files"]:
			self.medias.append(Media(media["name"], media["path"]))
		print("Триггернулась на", ">>"+self.ID)
			
	def set_comment(self, text):
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
		if profil == 7 and moremore == 0:
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
		self.comment = str(soup.get_text()).lstrip('\n')

	def set_sage(self, schema):
		if schema["email"].find("mailto:sage") == -1:
			self.sage = False
		else:
			self.sage = True


class Thread:

	def __init__(self, board, ID):
		self.board = board
		self.ID = ID
		self.schema = json.loads(requests.get(''.join(["https://2ch.hk/", sys.argv[1], "/res/", threadID, ".json"])).text)
		self.postsCount = schema["posts_count"] + 1
		self.lastID = schema["max_num"]
		self.posts = []
		for post in schema["threads"][0]["posts"]:
			self.posts.append(Post(post))
		self.loaf = "";
		for postNum in min(len(self.posts), 30):
			self.loaf += (">>"+self.posts[postNum]["num"]+" ")




