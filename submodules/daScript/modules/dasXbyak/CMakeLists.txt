IF(WIN32)
	SET(DAS_XBYAK_SUPPORTED TRUE)
ELSE()
	SET(DAS_XBYAK_SUPPORTED FALSE)
ENDIF()

IF (DAS_XBYAK_SUPPORTED AND (NOT DAS_XBYAK_INCLUDED) AND ((NOT ${DAS_XBYAK_DISABLED}) OR (NOT DEFINED DAS_XBYAK_DISABLED)))
    SET(DAS_XBYAK_INCLUDED TRUE)
    MESSAGE(STATUS "dasXbyak module included.")

	SET(DAS_XBYAK_DIR ${CMAKE_SOURCE_DIR}/modules/dasXbyak)

	SET(XBYAK_DIR ${CMAKE_SOURCE_DIR}/modules/dasXbyak/xbyak/xbyak)

    LIST(APPEND CMAKE_MODULE_PATH ${DAS_XBYAK_DIR})

	SET(DAS_XBYAK_INCLUDE_DIR ${DAS_XBYAK_DIR}/xbyak)

	# libDasModuleXbyak
	SET(DAS_XBYAK_BIND_DIR ${DAS_XBYAK_DIR})
	SET(DAS_XBYAK_BIND_MODULE_SRC
		${DAS_XBYAK_BIND_DIR}/src/need_dasXBYAK.h
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.h
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.cpp
	# user include
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.main.cpp
	# generated binding includes
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.alias.add.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.dummy.add.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.enum.add.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.enum.class.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.enum.decl.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.enum.decl.cast.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.struct.add.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.struct.postadd.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.struct.class.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.struct.decl.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.struct.impl.inc
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.struct.cast.inc
	# generated functions
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_1.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_2.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_3.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_4.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_5.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_6.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_7.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_8.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_9.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_10.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_11.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_12.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_13.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_14.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_15.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_16.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_17.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_18.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_19.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_20.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_21.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_22.cpp
		${DAS_XBYAK_BIND_DIR}/src/dasXBYAK.func_23.cpp
	)

	ADD_MODULE_LIB(libDasModuleXbyak)
	ADD_MODULE_CPP(dasXBYAK)
	# ADD_MODULE_NATIVE(stbimage_boost)
	ADD_LIBRARY(libDasModuleXbyak ${DAS_XBYAK_BIND_MODULE_SRC})
	TARGET_LINK_LIBRARIES(libDasModuleXbyak ${XBYAK_LIBRARIES})
	# ADD_DEPENDENCIES(libDasModuleXbyak)
	TARGET_INCLUDE_DIRECTORIES(libDasModuleXbyak PUBLIC ${DAS_XBYAK_INCLUDE_DIR})
	SETUP_CPP11(libDasModuleXbyak)

	ADD_MODULE_DAS(dasxbyak dasxbyak xbyak_boost)
	ADD_MODULE_DAS(dasxbyak dasxbyak xbyak_boost)

	ADD_MODULE_DAS(jit jit jit_x86_64_alloc_regs)
	ADD_MODULE_DAS(jit jit jit_x86_64_regs)
	ADD_MODULE_DAS(jit jit jit_x86_64_generate_base)
	ADD_MODULE_DAS(jit jit jit_x86_64_generate)
	ADD_MODULE_DAS(jit jit jit_x86_64_common)
	ADD_MODULE_DAS(jit jit jit_x86_64_test)
	ADD_MODULE_DAS(jit jit jit_x86_64)

	SET(DAS_ZYCONFIG_DIR ${CMAKE_SOURCE_DIR}/modules/dasXbyak/zydis/msvc)

	SET(DAS_ZYDIS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/modules/dasXbyak/zydis/include)
	SET(DAS_ZYDIS_SRC_DIR ${CMAKE_SOURCE_DIR}/modules/dasXbyak/zydis/src)

	SET(DAS_ZYCORE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/modules/dasXbyak/zydis/dependencies/zycore/include)
	SET(DAS_ZYCORE_SRC_DIR     ${CMAKE_SOURCE_DIR}/modules/dasXbyak/zydis/dependencies/zycore/src)

	# libDasModuleZydis
	SET(DAS_ZYDIS_MODULE_SRC
		${DAS_XBYAK_DIR}/src/dasZydis.h
		${DAS_XBYAK_DIR}/src/dasZydis.cpp
	)

	# zcore
	SET(DAS_ZYCORE_SRC
		${DAS_ZYCORE_SRC_DIR}/Allocator.c
		${DAS_ZYCORE_SRC_DIR}/ArgParse.c
		${DAS_ZYCORE_SRC_DIR}/Bitset.c
		${DAS_ZYCORE_SRC_DIR}/Format.c
		${DAS_ZYCORE_SRC_DIR}/List.c
		${DAS_ZYCORE_SRC_DIR}/String.c
		${DAS_ZYCORE_SRC_DIR}/Vector.c
		${DAS_ZYCORE_SRC_DIR}/Zycore.c
		${DAS_ZYCORE_SRC_DIR}/API/Memory.c
		${DAS_ZYCORE_SRC_DIR}/API/Process.c
		${DAS_ZYCORE_SRC_DIR}/API/Synchronization.c
		${DAS_ZYCORE_SRC_DIR}/API/Terminal.c
		${DAS_ZYCORE_SRC_DIR}/API/Thread.c
	)

	SET(DAS_ZYDIST_SRC
		${DAS_ZYDIS_SRC_DIR}/Decoder.c
		${DAS_ZYDIS_SRC_DIR}/DecoderData.c
		${DAS_ZYDIS_SRC_DIR}/Formatter.c
		${DAS_ZYDIS_SRC_DIR}/FormatterATT.c
		${DAS_ZYDIS_SRC_DIR}/FormatterBase.c
		${DAS_ZYDIS_SRC_DIR}/FormatterBuffer.c
		${DAS_ZYDIS_SRC_DIR}/FormatterIntel.c
		${DAS_ZYDIS_SRC_DIR}/Generated
		${DAS_ZYDIS_SRC_DIR}/MetaInfo.c
		${DAS_ZYDIS_SRC_DIR}/Mnemonic.c
		${DAS_ZYDIS_SRC_DIR}/Register.c
		${DAS_ZYDIS_SRC_DIR}/SharedData.c
		${DAS_ZYDIS_SRC_DIR}/String.c
		${DAS_ZYDIS_SRC_DIR}/Utils.c
		${DAS_ZYDIS_SRC_DIR}/Zydis.c
	)

	ADD_MODULE_LIB(libDasModuleZydis)
	ADD_MODULE_CPP(Zydis)
	ADD_LIBRARY(libDasModuleZydis ${DAS_ZYDIS_MODULE_SRC} ${DAS_ZYCORE_SRC} ${DAS_ZYDIST_SRC})
	TARGET_LINK_LIBRARIES(libDasModuleZydis ${ZYDIS_LIBRARIES})
	# ADD_DEPENDENCIES(libDasModuleZydis)
	TARGET_INCLUDE_DIRECTORIES(libDasModuleZydis PUBLIC ${ZYDIS_INCLUDE_DIR} ${DAS_XBYAK_DIR}
		${DAS_ZYCONFIG_DIR}
		${DAS_ZYCORE_INCLUDE_DIR} ${DAS_ZYDIS_INCLUDE_DIR} ${DAS_ZYDIS_SRC_DIR}
	)
	TARGET_COMPILE_DEFINITIONS(libDasModuleZydis PUBLIC -DZYCORE_STATIC_DEFINE)
	TARGET_COMPILE_DEFINITIONS(libDasModuleZydis PUBLIC -DZYDIS_STATIC_DEFINE)
	SETUP_CPP11(libDasModuleZydis)

ENDIF()
