srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")

  conf.check_cxx(cxxflags = '-g');
  conf.check_cxx(cxxflags = '-Wall');
  
  conf.check(lib='mecab', libpath=['/usr/lib', '/usr/local/lib'], uselib_store='MECAB')

def build(bld):
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.target = "mecab"
  obj.source = "mecab.cc"
  obj.uselib = "MECAB"
