cmake_minimum_required (VERSION 3.25)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{PS2DEV})
    set(CMAKE_TOOLCHAIN_FILE $ENV{PS2DEV}/share/ps2dev.cmake CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define PS2DEV to point to your SDK path!")
  endif()
endif()

set(PROJECT_NAME PSXDOOM)
project(${PROJECT_NAME} LANGUAGES C ASM)
include("${PS2DEV}/share/ps2dev.cmake" REQUIRED)
INCLUDE_DIRECTORIES("${PS2SDK}/iop/include")
set(GAME_SRC_DIR "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wreturn-type -O2 -g")

set(SOURCES
    ${GAME_SRC_DIR}/d_main.c
	${GAME_SRC_DIR}/info.c
	${GAME_SRC_DIR}/sprinfo.c
	${GAME_SRC_DIR}/g_game.c
	${GAME_SRC_DIR}/p_base.c
	${GAME_SRC_DIR}/p_ceilng.c
	${GAME_SRC_DIR}/p_change.c
	${GAME_SRC_DIR}/p_doors.c
	${GAME_SRC_DIR}/p_enemy.c
	${GAME_SRC_DIR}/p_floor.c
	${GAME_SRC_DIR}/p_inter.c
	${GAME_SRC_DIR}/p_lights.c
	${GAME_SRC_DIR}/p_map.c
	${GAME_SRC_DIR}/p_maputl.c
	${GAME_SRC_DIR}/p_mobj.c
	${GAME_SRC_DIR}/p_move.c
	${GAME_SRC_DIR}/p_plats.c
	${GAME_SRC_DIR}/p_pspr.c
	${GAME_SRC_DIR}/p_setup.c
	${GAME_SRC_DIR}/p_shoot.c
	${GAME_SRC_DIR}/p_sight.c
	${GAME_SRC_DIR}/p_slide.c
	${GAME_SRC_DIR}/p_spec.c
	${GAME_SRC_DIR}/p_switch.c
	${GAME_SRC_DIR}/p_telept.c
	${GAME_SRC_DIR}/p_tick.c
	${GAME_SRC_DIR}/p_user.c
	${GAME_SRC_DIR}/r_phase1.c
	${GAME_SRC_DIR}/r_phase2.c
	${GAME_SRC_DIR}/r_data.c
	${GAME_SRC_DIR}/r_main.c
	${GAME_SRC_DIR}/vsprintf.c
	${GAME_SRC_DIR}/w_wad.c
	${GAME_SRC_DIR}/psx_file.c
	${GAME_SRC_DIR}/z_zone.c
	${GAME_SRC_DIR}/psxmain.c
	${GAME_SRC_DIR}/l_main.c
	${GAME_SRC_DIR}/t_main.c
	${GAME_SRC_DIR}/m_main.c
	${GAME_SRC_DIR}/c_main.c
	${GAME_SRC_DIR}/pw_main.c
	${GAME_SRC_DIR}/cf_main.c
	${GAME_SRC_DIR}/m_password.c
	${GAME_SRC_DIR}/st_main.c
	${GAME_SRC_DIR}/am_main.c
	${GAME_SRC_DIR}/in_main.c
	${GAME_SRC_DIR}/f_main.c
	${GAME_SRC_DIR}/o_main.c
	#${GAME_SRC_DIR}/m_fixed.c
	${GAME_SRC_DIR}/m_fixed.s
	${GAME_SRC_DIR}/tables.c
	${GAME_SRC_DIR}/psxcd.c
	${GAME_SRC_DIR}/s_sound.c
	${GAME_SRC_DIR}/psxspu.c
	${GAME_SRC_DIR}/psxcmd.c
	${GAME_SRC_DIR}/wessapip.c
	${GAME_SRC_DIR}/wessapi.c
	${GAME_SRC_DIR}/wessarc.c
	${GAME_SRC_DIR}/wessapit.c
	${GAME_SRC_DIR}/wessseq.c
	${GAME_SRC_DIR}/seqload.c
	${GAME_SRC_DIR}/lcdload.c
	${GAME_SRC_DIR}/wessapim.c
	${GAME_SRC_DIR}/seqloadr.c
	${GAME_SRC_DIR}/wessbase.c
	${GAME_SRC_DIR}/snmain.s
)

add_executable(${PROJECT_NAME}.elf ${SOURCES})