#include "Splash.h"
#include "Object.h"
using namespace std;
int Object::act_water(Direction fromwhere, Actor fromwho) {
	// TODO
	int cnt = 0;
	if(fromwho == PLAYER || fromwho == WATER) {
		size += 1;
	}
	else {
		size -= 1;
	}
	if(size < 1) {
		splash->map[x][y] = new Object();
		splash->map[x][y]->set2void(x, y, splash);
	}
	else if(size > 3) {
			splash->map[x][y] = new Object();
			splash->map[x][y]->set2void(x, y, splash);
			cnt += 1;
			if(x == 0) {
				if(y == 0) {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					cnt += obj1->act(LEFT, WATER);
					cnt += obj2->act(UP, WATER);
				}
				else if(y == splash->size - 1) {
					Object *obj1 = splash->map[x][y - 1];
					Object *obj2 = splash->map[x + 1][y];
					cnt += obj1->act(RIGHT, WATER);
					cnt += obj2->act(UP, WATER);
				}
				else {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x][y - 1];
					cnt += obj1->act(LEFT, WATER);
					cnt += obj2->act(UP, WATER);
					cnt += obj3->act(RIGHT, WATER);
				}
			}
			else if(x == splash->size - 1) {
				if(y == 0) {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x - 1][y];
					cnt += obj1->act(LEFT, WATER);
					cnt += obj2->act(DOWN, WATER);
				}
				else if(y == splash->size - 1) {
					Object *obj1 = splash->map[x][y - 1];
					Object *obj2 = splash->map[x - 1][y];
					cnt += obj1->act(RIGHT, WATER);
					cnt += obj2->act(DOWN, WATER);
				}
				else {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x - 1][y];
					Object *obj3 = splash->map[x][y - 1];
					cnt += obj1->act(LEFT, WATER);
					cnt += obj2->act(DOWN, WATER);
					cnt += obj3->act(RIGHT, WATER);
				}
			}
			else {
				if(y == 0) {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x - 1][y];
					cnt += obj1->act(LEFT, WATER);
					cnt += obj2->act(UP, WATER);
					cnt += obj3->act(DOWN, WATER);
				}
				else if(y == splash->size - 1) {
					Object *obj1 = splash->map[x][y - 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x - 1][y];
					cnt += obj1->act(RIGHT, WATER);
					cnt += obj2->act(UP, WATER);
					cnt += obj3->act(DOWN, WATER);
				}
				else {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x][y - 1];
					Object *obj4 = splash->map[x - 1][y];
					cnt += obj1->act(LEFT, WATER);
					cnt += obj2->act(UP, WATER);
					cnt += obj3->act(RIGHT, WATER);
					cnt += obj4->act(DOWN, WATER);
				}
			}
	}
	return cnt;
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	// TODO
	int cnt = 0;
	if(fromwho == PLAYER) {
		cout << "Error: Cannot act a Void." << endl;
	}
	else if(fromwho == WATER) {
		if(fromwhere == LEFT) {
			if(y + 1 <= splash->size - 1) {
				for(int i = y + 1; i <= splash->size - 1; i ++) {
					if(splash->map[x][i]->type != T_VOID) {
						cnt += splash->map[x][i]->act(LEFT, WATER);break;
					}
				}
			}
		}
		if(fromwhere == RIGHT) {
			if(y - 1 >= 0) {
				for(int i = y - 1; i >= 0; i --) {
					if(splash->map[x][i]->type != T_VOID) {
						cnt += splash->map[x][i]->act(RIGHT, WATER);break;
					}
				}
			}
		}
		if(fromwhere == UP) {
			if(x + 1 <= splash->size - 1) {
				for(int i = x + 1; i <= splash->size - 1; i ++) {
					if(splash->map[i][y]->type != T_VOID) {
						cnt += splash->map[i][y]->act(UP, WATER);break;
					}
				}
			}
		}
		if(fromwhere == DOWN) {
			if(x - 1 >= 0) {
				for(int i = x - 1; i >= 0; i --) {
					if(splash->map[i][y]->type != T_VOID) {
						cnt += splash->map[i][y]->act(DOWN, WATER);break;
					}
				}
			}
		}
	}
	else {
		if(fromwhere == LEFT) {
			if(y + 1 <= splash->size - 1) {
				for(int i = y + 1; i <= splash->size - 1; i ++) {
					if(splash->map[x][i]->type != T_VOID) {
						cnt += splash->map[x][i]->act(LEFT, TOXIC);break;
					}
				}
			}
		}
		if(fromwhere == RIGHT) {
			if(y - 1 >= 0) {
				for(int i = y - 1; i >= 0; i --) {
					if(splash->map[x][i]->type != T_VOID) {
						cnt += splash->map[x][i]->act(RIGHT, TOXIC);break;
					}
				}
			}
		}
		if(fromwhere == UP) {
			if(x + 1 <= splash->size - 1) {
				for(int i = x + 1; i <= splash->size - 1; i ++) {
					if(splash->map[i][y]->type != T_VOID) {
						cnt += splash->map[i][y]->act(UP, TOXIC);
						break;
					}
				}
			}
		}
		if(fromwhere == DOWN) {
			if(x - 1 >= 0) {
				for(int i = x - 1; i >= 0; i --) {
					if(splash->map[i][y]->type != T_VOID) {
						cnt += splash->map[i][y]->act(DOWN, TOXIC);
						break;
					}
				}
			}
		}
	}
	return cnt;
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	// TODO
	if(fromwho == PLAYER) {
		cout << "Error: Cannot act a Barrier." << endl;
	}
	else {

	}
	return 0;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	// TODO
	int cnt = 0;
	if(fromwho == PLAYER || fromwho == TOXIC) {
		size += 1;
	}
	else {
		size -= 1;
	}
	if(size < 1) {
		splash->map[x][y] = new Object();
		splash->map[x][y]->set2void(x, y, splash);
	}
	else if(size > 3) {
			splash->map[x][y] = new Object();
			splash->map[x][y]->set2void(x, y, splash);
			cnt -= 1;
			if(x == 0) {
				if(y == 0) {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					cnt += obj1->act(LEFT, TOXIC);
					cnt += obj2->act(UP, TOXIC);
				}
				else if(y == splash->size - 1) {
					Object *obj1 = splash->map[x][y - 1];
					Object *obj2 = splash->map[x + 1][y];
					cnt += obj1->act(RIGHT, TOXIC);
					cnt += obj2->act(UP, TOXIC);
				}
				else {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x][y - 1];
					cnt += obj1->act(LEFT, TOXIC);
					cnt += obj2->act(UP, TOXIC);
					cnt += obj3->act(RIGHT, TOXIC);
				}
			}
			else if(x == splash->size - 1) {
				if(y == 0) {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x - 1][y];
					cnt += obj1->act(LEFT, TOXIC);
					cnt += obj2->act(DOWN, TOXIC);
				}
				else if(y == splash->size - 1) {
					Object *obj1 = splash->map[x][y - 1];
					Object *obj2 = splash->map[x - 1][y];
					cnt += obj1->act(RIGHT, TOXIC);
					cnt += obj2->act(DOWN, TOXIC);
				}
				else {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x - 1][y];
					Object *obj3 = splash->map[x][y - 1];
					cnt += obj1->act(LEFT, TOXIC);
					cnt += obj2->act(DOWN, TOXIC);
					cnt += obj3->act(RIGHT, TOXIC);
				}
			}
			else {
				if(y == 0) {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x - 1][y];
					cnt += obj1->act(LEFT, TOXIC);
					cnt += obj2->act(UP, TOXIC);
					cnt += obj3->act(DOWN, TOXIC);
				}
				else if(y == splash->size - 1) {
					Object *obj1 = splash->map[x][y - 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x - 1][y];
					cnt += obj1->act(RIGHT, TOXIC);
					cnt += obj2->act(UP, TOXIC);
					cnt += obj3->act(DOWN, TOXIC);
				}
				else {
					Object *obj1 = splash->map[x][y + 1];
					Object *obj2 = splash->map[x + 1][y];
					Object *obj3 = splash->map[x][y - 1];
					Object *obj4 = splash->map[x - 1][y];
					cnt += obj1->act(LEFT, TOXIC);
					cnt += obj2->act(UP, TOXIC);
					cnt += obj3->act(RIGHT, TOXIC);
					cnt += obj4->act(DOWN, TOXIC);
				}
			}
	}
	return cnt;
}