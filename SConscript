# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/SConscript,v 1.7 2009/09/12 03:49:22 heather Exp $
# Authors: Heather Kelly <heather@lheapop.gsfc.nasa.gov>, Tracy Usher   <usher@slac.stanford.edu>
# Version: LdfConverter-04-04-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('LdfConverterLib', depsOnly = 1)
LdfConverter = libEnv.SharedLibrary('LdfConverter',
                                    listFiles(['src/*.cxx','src/Dll/*.cxx']))

progEnv.AppendUnique(CPPDEFINES = ['_FILE_OFFSET_BITS=64'])
progEnv.Tool('LdfConverterLib')

test_LdfConverter = progEnv.GaudiProgram('test_LdfConverter',
                                         listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerTargets', package = 'LdfConverter',
             libraryCxts = [[LdfConverter, libEnv]],
             testAppCxts = [[test_LdfConverter, progEnv]],
             includes = listFiles(['LdfConverter/*.h']),
             data = listFiles(['data/*']), recursive = True)




