# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/SConscript,v 1.18 2012/01/16 21:24:11 heather Exp $
# Authors: Heather Kelly <heather@lheapop.gsfc.nasa.gov>, Tracy Usher   <usher@slac.stanford.edu>
# Version: LdfConverter-04-05-02

Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='LdfConverter', toBuild='component')
LdfConverter=libEnv.ComponentLibrary('LdfConverter',
                                     listFiles(['src/*.cxx']))

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
