import configparser
import os

from core.func import *

print(os.path.abspath(os.path.dirname(os.path.abspath(__file__))) + "/config.ini")
config = configparser.ConfigParser()
config.read(os.path.abspath(os.path.dirname(os.path.abspath(__file__))) + "/config.ini", encoding="utf-8")

add(1, 2, config=config)
hello(config=config)
