# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/LdfConverter/LdfConverterLib.py,v 1.4 2009/08/31 18:22:08 jrb Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['LdfConverter'])
    env.Tool('ldfReaderLib')	
    env.Tool('GlastSvcLib')
    env.Tool('EventLib')
    env.Tool('addLibrary', library = env['gaudiLibs'])

    if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
        env.Tool('findPkgPath', package = 'AdfEvent') 
        env.Tool('findPkgPath', package = 'LdfEvent') 
        env.Tool('findPkgPath', package = 'EbfWriter') 
def exists(env):
    return 1;
