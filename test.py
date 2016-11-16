# -*- coding: utf-8 -*-
import unic
import codecs

file = codecs.open("result.txt", 'a', "utf8")
file.write(unic.hello())
#file.write(u'\u0420\u045f\u0421\u0402\u0420\u0451\u0420\u0406\u0420\xb5\u0421\u201a!')
file.close()

print unic.hello()