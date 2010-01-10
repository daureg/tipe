#! /usr/bin/env python
# vim: set fileencoding=utf-8 :
# pylint: disable-msg=W0312
import sys, hashlib, datetime
if __name__ == "__main__":
	name = "r"+hashlib.sha224(datetime.datetime.today().ctime()).hexdigest()[:3]
	i=0
	with open(sys.argv[1]) as f:
		for line in f:
			print("%s[%d] = %s;"%(name,i,line.strip()))
			i+=1
	sys.exit()
