# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/SConscript,v 1.5.6.4 2011/03/29 04:44:01 heather Exp $
# Authors: Heather Kelly <heather@lheapop.gsfc.nasa.gov>, Tracy Usher   <usher@slac.stanford.edu>
# Version: LdfConverter-04-04-06

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
