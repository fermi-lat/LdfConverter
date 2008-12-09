# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/LdfConverter/LdfConverterLib.py,v 1.1 2008/08/15 21:42:36 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['LdfConverter'])
    env.Tool('ldfReaderLib')	
    env.Tool('GlastSvcLib')
    env.Tool('EventLib')
def exists(env):
    return 1;
