#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c usart.c dht.c bh1750.c i2c.c ec.c bmp.c esp.c filter.c rtc.c utils.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/usart.o ${OBJECTDIR}/dht.o ${OBJECTDIR}/bh1750.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/ec.o ${OBJECTDIR}/bmp.o ${OBJECTDIR}/esp.o ${OBJECTDIR}/filter.o ${OBJECTDIR}/rtc.o ${OBJECTDIR}/utils.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/usart.o.d ${OBJECTDIR}/dht.o.d ${OBJECTDIR}/bh1750.o.d ${OBJECTDIR}/i2c.o.d ${OBJECTDIR}/ec.o.d ${OBJECTDIR}/bmp.o.d ${OBJECTDIR}/esp.o.d ${OBJECTDIR}/filter.o.d ${OBJECTDIR}/rtc.o.d ${OBJECTDIR}/utils.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/usart.o ${OBJECTDIR}/dht.o ${OBJECTDIR}/bh1750.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/ec.o ${OBJECTDIR}/bmp.o ${OBJECTDIR}/esp.o ${OBJECTDIR}/filter.o ${OBJECTDIR}/rtc.o ${OBJECTDIR}/utils.o

# Source Files
SOURCEFILES=main.c usart.c dht.c bh1750.c i2c.c ec.c bmp.c esp.c filter.c rtc.c utils.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328P
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/e7b95801c5cb0a93ed47d7c72850d40ceabd6bbb .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/usart.o: usart.c  .generated_files/flags/default/eb21102480c795e9f5aae380fca768ccd8b732a6 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usart.o.d 
	@${RM} ${OBJECTDIR}/usart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/usart.o.d" -MT "${OBJECTDIR}/usart.o.d" -MT ${OBJECTDIR}/usart.o -o ${OBJECTDIR}/usart.o usart.c 
	
${OBJECTDIR}/dht.o: dht.c  .generated_files/flags/default/1489f5847a004b7ce5454c79e048afa47a75f4d7 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/dht.o.d 
	@${RM} ${OBJECTDIR}/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/dht.o.d" -MT "${OBJECTDIR}/dht.o.d" -MT ${OBJECTDIR}/dht.o -o ${OBJECTDIR}/dht.o dht.c 
	
${OBJECTDIR}/bh1750.o: bh1750.c  .generated_files/flags/default/cbc2f3d7c4d0f806cc739a658abba752c0666537 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bh1750.o.d 
	@${RM} ${OBJECTDIR}/bh1750.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/bh1750.o.d" -MT "${OBJECTDIR}/bh1750.o.d" -MT ${OBJECTDIR}/bh1750.o -o ${OBJECTDIR}/bh1750.o bh1750.c 
	
${OBJECTDIR}/i2c.o: i2c.c  .generated_files/flags/default/f2f20bd1ab284d6e27476c284caf4501d9731f58 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/i2c.o.d" -MT "${OBJECTDIR}/i2c.o.d" -MT ${OBJECTDIR}/i2c.o -o ${OBJECTDIR}/i2c.o i2c.c 
	
${OBJECTDIR}/ec.o: ec.c  .generated_files/flags/default/502b70dd153cd4b384a741848207999c70d97fa7 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ec.o.d 
	@${RM} ${OBJECTDIR}/ec.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ec.o.d" -MT "${OBJECTDIR}/ec.o.d" -MT ${OBJECTDIR}/ec.o -o ${OBJECTDIR}/ec.o ec.c 
	
${OBJECTDIR}/bmp.o: bmp.c  .generated_files/flags/default/e103cb5bbfa2fc3122f6909ace541fbf10b15dc1 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bmp.o.d 
	@${RM} ${OBJECTDIR}/bmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/bmp.o.d" -MT "${OBJECTDIR}/bmp.o.d" -MT ${OBJECTDIR}/bmp.o -o ${OBJECTDIR}/bmp.o bmp.c 
	
${OBJECTDIR}/esp.o: esp.c  .generated_files/flags/default/87a26639f06b4724b25e2573230ce3597ee9866c .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/esp.o.d 
	@${RM} ${OBJECTDIR}/esp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/esp.o.d" -MT "${OBJECTDIR}/esp.o.d" -MT ${OBJECTDIR}/esp.o -o ${OBJECTDIR}/esp.o esp.c 
	
${OBJECTDIR}/filter.o: filter.c  .generated_files/flags/default/357ea531dd37e32598fc14c84a285bac3671ab21 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/filter.o.d 
	@${RM} ${OBJECTDIR}/filter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/filter.o.d" -MT "${OBJECTDIR}/filter.o.d" -MT ${OBJECTDIR}/filter.o -o ${OBJECTDIR}/filter.o filter.c 
	
${OBJECTDIR}/rtc.o: rtc.c  .generated_files/flags/default/3225fea0741559e2576a01ecdfa7336f7e7de2f1 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtc.o.d 
	@${RM} ${OBJECTDIR}/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/rtc.o.d" -MT "${OBJECTDIR}/rtc.o.d" -MT ${OBJECTDIR}/rtc.o -o ${OBJECTDIR}/rtc.o rtc.c 
	
${OBJECTDIR}/utils.o: utils.c  .generated_files/flags/default/88dd1f8dbcff381f770e6316046e518fa1316691 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/utils.o.d 
	@${RM} ${OBJECTDIR}/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/utils.o.d" -MT "${OBJECTDIR}/utils.o.d" -MT ${OBJECTDIR}/utils.o -o ${OBJECTDIR}/utils.o utils.c 
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/6a1c97618896bb5e64d5c7ae1b0a6d17f1978af8 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/usart.o: usart.c  .generated_files/flags/default/faaa20c5e3d4e290d51fdc6d1a65f878950957a8 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usart.o.d 
	@${RM} ${OBJECTDIR}/usart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/usart.o.d" -MT "${OBJECTDIR}/usart.o.d" -MT ${OBJECTDIR}/usart.o -o ${OBJECTDIR}/usart.o usart.c 
	
${OBJECTDIR}/dht.o: dht.c  .generated_files/flags/default/a85ebc29c75cad0b72934dbed5520eeb7ac79e4f .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/dht.o.d 
	@${RM} ${OBJECTDIR}/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/dht.o.d" -MT "${OBJECTDIR}/dht.o.d" -MT ${OBJECTDIR}/dht.o -o ${OBJECTDIR}/dht.o dht.c 
	
${OBJECTDIR}/bh1750.o: bh1750.c  .generated_files/flags/default/fb318e67cb3ae5b0a75cc33e70cb225c7e38a3f0 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bh1750.o.d 
	@${RM} ${OBJECTDIR}/bh1750.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/bh1750.o.d" -MT "${OBJECTDIR}/bh1750.o.d" -MT ${OBJECTDIR}/bh1750.o -o ${OBJECTDIR}/bh1750.o bh1750.c 
	
${OBJECTDIR}/i2c.o: i2c.c  .generated_files/flags/default/607103081366c9e1559dd7f328ddf3bbc401c9ea .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/i2c.o.d" -MT "${OBJECTDIR}/i2c.o.d" -MT ${OBJECTDIR}/i2c.o -o ${OBJECTDIR}/i2c.o i2c.c 
	
${OBJECTDIR}/ec.o: ec.c  .generated_files/flags/default/e4c0d4b2be2f9b8ec2a5e9a929d54eafdbf456f5 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ec.o.d 
	@${RM} ${OBJECTDIR}/ec.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ec.o.d" -MT "${OBJECTDIR}/ec.o.d" -MT ${OBJECTDIR}/ec.o -o ${OBJECTDIR}/ec.o ec.c 
	
${OBJECTDIR}/bmp.o: bmp.c  .generated_files/flags/default/cbca0d74f5e88e110c05e88c3a44bdb1dfd418f8 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bmp.o.d 
	@${RM} ${OBJECTDIR}/bmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/bmp.o.d" -MT "${OBJECTDIR}/bmp.o.d" -MT ${OBJECTDIR}/bmp.o -o ${OBJECTDIR}/bmp.o bmp.c 
	
${OBJECTDIR}/esp.o: esp.c  .generated_files/flags/default/451e395d78e3946ee21abcf95fd422a2f1981c92 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/esp.o.d 
	@${RM} ${OBJECTDIR}/esp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/esp.o.d" -MT "${OBJECTDIR}/esp.o.d" -MT ${OBJECTDIR}/esp.o -o ${OBJECTDIR}/esp.o esp.c 
	
${OBJECTDIR}/filter.o: filter.c  .generated_files/flags/default/beb09a2c3e499267c280456e85dcfdce3ae14541 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/filter.o.d 
	@${RM} ${OBJECTDIR}/filter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/filter.o.d" -MT "${OBJECTDIR}/filter.o.d" -MT ${OBJECTDIR}/filter.o -o ${OBJECTDIR}/filter.o filter.c 
	
${OBJECTDIR}/rtc.o: rtc.c  .generated_files/flags/default/3cb93dd02f06e5b8b1d2ef0b907677e07fefb1a7 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtc.o.d 
	@${RM} ${OBJECTDIR}/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/rtc.o.d" -MT "${OBJECTDIR}/rtc.o.d" -MT ${OBJECTDIR}/rtc.o -o ${OBJECTDIR}/rtc.o rtc.c 
	
${OBJECTDIR}/utils.o: utils.c  .generated_files/flags/default/ce0d3ef65c4ec1580782b9f21ac8a3ba049b02e8 .generated_files/flags/default/d8eafc7eb14b8fddc629f2f6a79e8becd4a12353
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/utils.o.d 
	@${RM} ${OBJECTDIR}/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/utils.o.d" -MT "${OBJECTDIR}/utils.o.d" -MT ${OBJECTDIR}/utils.o -o ${OBJECTDIR}/utils.o utils.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/src.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
