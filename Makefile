


CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = sorcery
OBJECTS = main.o ascii_graphics.o Board.o  Card.o Deck.o Enchantment.o Minion.o Player.o Ritual.o Spell.o Ability.o airElemental.o apprenticeSummoner.o auraOfPower.o banish.o blizzard.o darkRitual.o disenchant.o earthElemental.o fireElemental.o giantStrength.o magicFatigue.o masterSummoner.o novicePyromancer.o potionSeller.o raiseDead.o recharge.o silence.o standstill.o unsummon.o 

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

