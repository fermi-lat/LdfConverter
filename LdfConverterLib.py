# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/LdfConverter/LdfConverterLib.py,v 1.3 2009/01/23 00:20:58 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['LdfConverter'])
    env.Tool('ldfReaderLib')	
    env.Tool('GlastSvcLib')
    env.Tool('EventLib')
    env.Tool('addLibrary', library = env['gaudiLibs'])
def exists(env):
    return 1;
