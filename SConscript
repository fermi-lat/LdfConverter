# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/LdfConverter/SConscript,v 1.15 2011/08/23 17:13:26 heather Exp $
# Authors: Heather Kelly <heather@lheapop.gsfc.nasa.gov>, Tracy Usher   <usher@slac.stanford.edu>
# Version: LdfConverter-04-05-00

Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='LdfConverter', toBuild='component')
LdfConverter = libEnv.SharedLibrary('LdfConverter',
                                    listFiles(['src/*.cxx','src/Dll/*.cxx']))

progEnv.AppendUnique(CPPDEFINES = ['_FILE_OFFSET_BITS=64'])
progEnv.Tool('LdfConverterLib')

test_LdfConverter = progEnv.GaudiProgram('test_LdfConverter',
                                         listFiles(['src/test/*.cxx']),
                                         test = 1, package='LdfConverter')

progEnv.Tool('registerTargets', package = 'LdfConverter',
             libraryCxts = [[LdfConverter, libEnv]],
             testAppCxts = [[test_LdfConverter, progEnv]],
             includes = listFiles(['LdfConverter/*.h']),
             data = listFiles(['data/*'], recursive = True),
             jo = listFiles(['src/*.txt']) + listFiles(['src/test/*.txt']))
