#include "manager.h"
#include "chef.h"

void Manager::newChef(Chef chef) {
    chefs.push_back(chef);
    cnt += 1;
}

void Manager::order(std::string dish) {
    bool have = false;
    for(int i = 0; i < cnt; i ++) {
        if(chefs[i].isSignatureDish(dish)) {
            have = true;
            chefs[i].cook(dish);
            return;
        }
    }
    if(have == false) {
        chefs[0].cook(dish);
        return;
    }
}
void Manager::order(std::string dish, int id) {
    chefs[id].cook(dish);
    return;
}