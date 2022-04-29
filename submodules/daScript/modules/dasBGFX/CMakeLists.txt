
IF ((NOT DAS_BGFX_INCLUDED) AND ((NOT ${DAS_BGFX_DISABLED}) OR (NOT DEFINED DAS_BGFX_DISABLED)))
    SET(DAS_BGFX_INCLUDED TRUE)
    MESSAGE(STATUS "dasBgfx module included.")

	SET(DAS_BGFX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX)
	SET(DAS_BGFX_KHRONOS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/3rdparty/khronos)
	SET(DAS_BGFX_DX12_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/3rdparty/dxsdk/include)

    IF(APPLE)
        SET(DAS_BGFX_COMPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/include/compat/osx)
    ELSEIF(WIN32)
	    SET(DAS_BGFX_COMPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/include/compat/msvc)
    ENDIF()

	SET(DAS_BGFX_ASTC_CODEC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bimg/3rdparty/astc-codec/include)

	SET(DAS_BX_INCLUDE_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/include)
	SET(DAS_BGFX_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/include)
	SET(DAS_BIMG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bimg/include)

	SET(DAS_BX_3P_INCLUDE_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/3rdparty)
	SET(DAS_BGFX_3P_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/3rdparty)
	SET(DAS_BIMG_3P_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasBGFX/bgfx/bimg/3rdparty)


    LIST(APPEND CMAKE_MODULE_PATH ${DAS_BGFX_DIR})

    IF(APPLE)
    	# libBGFX
    	SET(LIB_BGFX_SRC
    		${DAS_BGFX_DIR}/bgfx/bgfx/src/amalgamated.mm
    		${DAS_BGFX_DIR}/bgfx/bx/src/amalgamated.cpp
    		${DAS_BGFX_DIR}/bgfx/bimg/src/image.cpp
    		${DAS_BGFX_DIR}/bgfx/bimg/src/image_gnf.cpp
    	)
    ELSE()
    	# libBGFX
    	SET(LIB_BGFX_SRC
    		#${DAS_BGFX_DIR}/bgfx/bgfx/src/amalgamated.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/bgfx.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/debug_renderdoc.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/dxgi.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/glcontext_egl.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/glcontext_glx.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/glcontext_wgl.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/glcontext_html5.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/nvapi.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_agc.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_d3d11.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_d3d12.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_d3d9.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_gl.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_gnm.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_noop.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_nvn.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_vk.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/renderer_webgpu.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/shader.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/shader_dx9bc.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/shader_dxbc.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/shader_spirv.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/topology.cpp
			${DAS_BGFX_DIR}/bgfx/bgfx/src/vertexlayout.cpp
			#${DAS_BGFX_DIR}/bgfx/bx/src/amalgamated.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/allocator.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/bounds.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/bx.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/commandline.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/crtnone.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/debug.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/dtoa.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/easing.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/file.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/filepath.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/hash.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/math.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/mutex.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/os.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/process.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/semaphore.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/settings.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/sort.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/string.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/thread.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/timer.cpp
			${DAS_BGFX_DIR}/bgfx/bx/src/url.cpp
			#
    		${DAS_BGFX_DIR}/bgfx/bimg/src/image.cpp
    		${DAS_BGFX_DIR}/bgfx/bimg/src/image_gnf.cpp
    	)
    ENDIF()

	# libDasModuleBGFX
	SET(DAS_BGFX_BIND_DIR ${DAS_BGFX_DIR})
	SET(DAS_BGFX_BIND_MODULE_SRC
		${DAS_BGFX_BIND_DIR}/src/need_dasBGFX.h
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.h
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.cpp
	# user include
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.main.cpp
	# generated binding includes
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.alias.add.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.dummy.add.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.enum.add.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.enum.class.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.enum.decl.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.enum.decl.cast.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.struct.add.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.struct.postadd.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.struct.class.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.struct.decl.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.struct.impl.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.struct.cast.inc
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.const.inc
	# generated functions
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_1.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_2.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_3.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_4.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_5.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_6.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_7.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_8.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_9.cpp
		${DAS_BGFX_BIND_DIR}/src/dasBGFX.func_10.cpp
	)

	IF(APPLE)
		ADD_DEFINITIONS(-DBGFX_CONFIG_MULTITHREADED=0)
	ENDIF()

	ADD_MODULE_LIB(libDasModuleBGFX)
	ADD_MODULE_CPP(dasBGFX)
	# ADD_MODULE_NATIVE(stbimage_boost)
	ADD_LIBRARY(libDasModuleBGFX ${DAS_BGFX_BIND_MODULE_SRC} ${LIB_BGFX_SRC})
	TARGET_LINK_LIBRARIES(libDasModuleBGFX ${BGFX_LIBRARIES})
	# ADD_DEPENDENCIES(libDasModuleBGFX)
	target_compile_definitions(libDasModuleBGFX PUBLIC -DBIMG_DECODE_ASTC=0)
	TARGET_INCLUDE_DIRECTORIES(libDasModuleBGFX PUBLIC
		${DAS_BX_INCLUDE_DIR} 	${DAS_BX_3P_INCLUDE_DIR}
		${DAS_BGFX_INCLUDE_DIR} ${DAS_BGFX_3P_INCLUDE_DIR}
		${DAS_BIMG_INCLUDE_DIR} ${DAS_BIMG_3P_INCLUDE_DIR}
		${DAS_BGFX_COMPAT_DIR}
		${DAS_BGFX_KHRONOS_DIR}
		${DAS_BGFX_DX12_DIR}
		${DAS_BGFX_ASTC_CODEC_DIR}
	)
	SETUP_CPP11(libDasModuleBGFX)

	IF(APPLE)
		target_compile_options(libDasModuleBGFX PUBLIC -Wno-tautological-constant-compare)
		target_compile_options(libDasModuleBGFX PUBLIC -Wno-gnu-zero-variadic-macro-arguments)
	ENDIF()

	ADD_MODULE_DAS(dasbgfx dasbgfx bgfx_boost)
	ADD_MODULE_DAS(dasbgfx dasbgfx bgfx_boost_internal)
	ADD_MODULE_DAS(dasbgfx dasbgfx bgfx_ttf)
	ADD_MODULE_DAS(dasbgfx dasbgfx bgfx_gen)
	ADD_MODULE_DAS(dasbgfx dasbgfx glsl_bgfx)
	ADD_MODULE_DAS(dasbgfx dasbgfx glsl_internal_bgfx)

	SET(DAS_IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/dasImgui)
	IF(EXISTS "${DAS_IMGUI_DIR}/CMakeLists.txt")
		MESSAGE("Adding BGFX support for IMGUI")
		SET(imgui_INCLUDE_DIR ${DAS_IMGUI_DIR}/imgui)
		SET(DAS_BGFX_IMGUI_MODULE_SRC
			${DAS_BGFX_DIR}/src/dasBGFXImgui.h
			${DAS_BGFX_DIR}/src/dasBGFXImgui.cpp
		)
		# libDasModuleBGFX
		SET(DAS_BGFX_IMGUI_IMPLEMENTATION_SRC
			${DAS_BGFX_DIR}/src/imgui/imgui_bgfx.cpp
			${DAS_BGFX_DIR}/src/imgui/imgui_bgfx.h
		)
		ADD_MODULE_LIB(libDasModuleBGFXImgui)
		ADD_LIBRARY(libDasModuleBGFXImgui ${DAS_BGFX_IMGUI_MODULE_SRC} ${DAS_BGFX_IMGUI_IMPLEMENTATION_SRC})
		#TARGET_LINK_LIBRARIES(libDasModuleBGFXImgui ${imgui_LIBRARIES})
		# ADD_DEPENDENCIES(libDasModuleBGFXImgui)
		TARGET_INCLUDE_DIRECTORIES(libDasModuleBGFXImgui PUBLIC
			${imgui_INCLUDE_DIR} ${DAS_BGFX_DIR}
			${DAS_BGFX_INCLUDE_DIR} ${DAS_BGFX_COMPAT_DIR}
			${DAS_BX_INCLUDE_DIR}
		)
		SETUP_CPP11(libDasModuleBGFXImgui)
		ADD_MODULE_CPP(BGFXImgui)
 	ENDIF()
ENDIF()
