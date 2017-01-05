#!/usr/bin/python
import lutin.debug as debug
import lutin.tools as tools


def get_type():
	return "LIBRARY"

def get_desc():
	return "Algorithm generic"

def get_licence():
	return "MPL-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def get_version():
	return "version.txt"

def configure(target, my_module):
	my_module.add_depend(['elog', 'etk', 'crypto'])
	my_module.add_extra_flags()
	my_module.add_src_file([
		'algue/debug.cpp',
		'algue/base64.cpp',
		'algue/sha1.cpp',
		'algue/sha512.cpp',
		'algue/md5.cpp'
		])
	my_module.add_header_file([
		'algue/base64.hpp',
		'algue/sha1.hpp',
		'algue/sha512.hpp',
		'algue/md5.hpp',
		])
	my_module.add_path(".")
	return True


