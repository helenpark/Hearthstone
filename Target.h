#define _TARGET_H__
#include <vector>
#include <string>
#include <memory>
#include <utility>

class Target { // abstract class

	std::string type;
	int health;

	public:
	virtual int getHit(int ap) = 0; // pass the AP of minion and return final hp after taking hit
	std::string getType();

	virtual ~Target()=0;
};

#endif

