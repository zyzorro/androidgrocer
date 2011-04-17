#!/usr/bin/python

def f(a, L=[]):
	L.append(a)
	return L

def f1(a,L=None):
	if L is None:
		L=[]
	L.append(a)
	return L

if __name__ =="__main__":
	print f(1)
	print f(2)
