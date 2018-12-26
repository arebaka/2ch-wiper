## -*- coding: utf-8 -*-

import base64
import time
import requests
import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

from tools import *

class CaptchaSolver_XCaptcha:

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

class CaptchaSolver_captchaguru:

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

class CaptchaSolver_anticaptcha:

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

