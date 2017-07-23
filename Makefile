CXX = g++14								
CXXFLAGS = -g -Wall -Werror -std=c++11 -MMD				
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}			

OBJECTS1 = Card.o Deck.o Enchantment.o Minion.o Player.o Ritual.o Spell.o airElemental.o apprenticeSummoner.o ascii_graphics.o ascii_graphics.o auraOfPower.o banish.o blizzard.o darkRitual.o disenchant.o earthElemental.o fireElemental.o giantStrength.o magicFatigue.o masterSummoner.o novicePyromancer.o potionSeller.o raiseDead.o recharge.o silence.o standstill.o unsummon.o 	
EXEC = main							

OBJECTS = ${OBJECTS1} 
EXECS = ${EXEC1} 
DEPENDS = ${OBJECTS:.o=.d}							

.PHONY : all clean

all : ${OBJECTS1}

${EXEC} : ${OBJECTS1}								
	${CXX} $^ -o $@

${OBJECTS} : ${MAKEFILE_NAME}							

-include ${DEPENDS}							

clean :										
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}
