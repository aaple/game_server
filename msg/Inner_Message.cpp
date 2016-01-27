#include "Inner_Message.h"


MSG_400001::MSG_400001(void){
	reset();
}

void MSG_400001::serialize(Block_Buffer & w) const {
	w.write_string(module);
}

int MSG_400001::deserialize(Block_Buffer & r) {
	module = r.read_string();
	return 0;
}

void MSG_400001::reset(){
	module.clear();
}
