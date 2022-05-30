#!/usr/bin/env python

import os
import sys
import requests

'''
Get all emoji from emoji-api and output them to a file
'''

key = '1d2cc22d2fd68ec41688b738743e7400f8a46bc0'
url = 'https://emoji-api.com/emojis?access_key='+key
out = 'emojilist'

def getem():
    res = requests.get(url)
    json = res.json()
    return json

def main():
    json = getem()
    
    with open(out, "w") as file:
        for emoji in json:
            file.write(f"{emoji['character']} - {emoji['unicodeName']}\n")


if __name__ == '__main__':
    main()
    sys.exit(0)
