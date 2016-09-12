#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools


def get_type():
	return "LIBRARY"

def get_desc():
	return "Algorithm generic"

def get_licence():
	return "APACHE-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return ["Mr DUPIN Edouard <yui.heero@gmail.com>"]

def get_version():
	return [0,2,"dev"]

def create(target, module_name):
	my_module = module.Module(__file__, module_name, get_type())
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
		'algue/base64.h',
		'algue/sha1.h',
		'algue/sha512.h',
		'algue/md5.h',
		])
	my_module.add_path(tools.get_current_path(__file__))
	return my_module


