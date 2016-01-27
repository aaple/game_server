#include "Active_Message.h"


MSG_300000::MSG_300000(void){
	reset();
}

void MSG_300000::serialize(Block_Buffer & w) const {
}

int MSG_300000::deserialize(Block_Buffer & r) {
	return 0;
}

void MSG_300000::reset(){
}

MSG_300100::MSG_300100(void){
	reset();
}

void MSG_300100::serialize(Block_Buffer & w) const {
	uint16_t __item_info_vec_vec_size = item_info_vec.size();
	w.write_uint16(__item_info_vec_vec_size);
	for(uint16_t i = 0; i < __item_info_vec_vec_size; ++i) {
		item_info_vec[i].serialize(w);
	}

}

int MSG_300100::deserialize(Block_Buffer & r) {
	uint16_t __item_info_vec_vec_size = r.read_uint16();
	Item_Basic_Info v;
	for(uint16_t i = 0; i < __item_info_vec_vec_size; ++i) {
		if(v.deserialize(r))
			return -1;
		item_info_vec.push_back(v);
	}

	return 0;
}

void MSG_300100::reset(){
	item_info_vec.clear();
}

MSG_300101::MSG_300101(void){
	reset();
}

void MSG_300101::serialize(Block_Buffer & w) const {
	w.write_int8(type);
}

int MSG_300101::deserialize(Block_Buffer & r) {
	type = r.read_int8();
	return 0;
}

void MSG_300101::reset(){
	type = 0;
}

MSG_300102::MSG_300102(void){
	reset();
}

void MSG_300102::serialize(Block_Buffer & w) const {
	w.write_int16(capacity);
	w.write_int32(type);
}

int MSG_300102::deserialize(Block_Buffer & r) {
	capacity = r.read_int16();
	type = r.read_int32();
	return 0;
}

void MSG_300102::reset(){
	capacity = 0;
	type = 0;
}

MSG_300103::MSG_300103(void){
	reset();
}

void MSG_300103::serialize(Block_Buffer & w) const {
	money_info.serialize(w);
}

int MSG_300103::deserialize(Block_Buffer & r) {
	money_info.deserialize(r);
	return 0;
}

void MSG_300103::reset(){
	money_info.reset();
}

MSG_300104::MSG_300104(void){
	reset();
}

void MSG_300104::serialize(Block_Buffer & w) const {
	uint16_t item_index_vec_size = item_index_vec.size();
	w.write_uint16(item_index_vec_size);
	for(uint16_t i = 0; i < item_index_vec_size; ++i) {
		w.write_uint32(item_index_vec[i]);
	}

}

int MSG_300104::deserialize(Block_Buffer & r) {
	uint16_t item_index_vec_size = r.read_uint16();
	for(uint16_t i = 0; i < item_index_vec_size; ++i) {
		uint32_t v = r.read_uint32();
		item_index_vec.push_back(v);
	}
	return 0;
}

void MSG_300104::reset(){
	item_index_vec.clear();
}

MSG_300200::MSG_300200(void){
	reset();
}

void MSG_300200::serialize(Block_Buffer & w) const {
	uint16_t __mail_detail_vec_vec_size = mail_detail_vec.size();
	w.write_uint16(__mail_detail_vec_vec_size);
	for(uint16_t i = 0; i < __mail_detail_vec_vec_size; ++i) {
		mail_detail_vec[i].serialize(w);
	}

}

int MSG_300200::deserialize(Block_Buffer & r) {
	uint16_t __mail_detail_vec_vec_size = r.read_uint16();
	Mail_Detail v;
	for(uint16_t i = 0; i < __mail_detail_vec_vec_size; ++i) {
		if(v.deserialize(r))
			return -1;
		mail_detail_vec.push_back(v);
	}

	return 0;
}

void MSG_300200::reset(){
	mail_detail_vec.clear();
}
