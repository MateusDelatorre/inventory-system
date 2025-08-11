#include "loot_item.h"

void LootItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_item_id", "item_id"), &LootItem::set_item_id);
	ClassDB::bind_method(D_METHOD("get_item_id"), &LootItem::get_item_id);
	ClassDB::bind_method(D_METHOD("set_chance", "chance"), &LootItem::set_chance);
	ClassDB::bind_method(D_METHOD("get_chance"), &LootItem::get_chance);
	ClassDB::bind_method(D_METHOD("set_min_amount", "min_amount"), &LootItem::set_min_amount);
	ClassDB::bind_method(D_METHOD("get_min_amount"), &LootItem::get_min_amount);
	ClassDB::bind_method(D_METHOD("set_max_amount", "max_amount"), &LootItem::set_max_amount);
	ClassDB::bind_method(D_METHOD("get_max_amount"), &LootItem::get_max_amount);
	ClassDB::bind_method(D_METHOD("serialize"), &LootItem::serialize);
	ClassDB::bind_method(D_METHOD("deserialize", "data"), &LootItem::deserialize);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "item_id"), "set_item_id", "get_item_id");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "chance"), "set_chance", "get_chance");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_amount"), "set_min_amount", "get_min_amount");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_amount"), "set_max_amount", "get_max_amount");
}

LootItem::LootItem() {
}

LootItem::~LootItem() {
}

void LootItem::set_item_id(const String &new_item_id) {
	item_id = new_item_id;
}

String LootItem::get_item_id() const {
	return item_id;
}

void LootItem::set_chance(const float &new_chance) {
	chance = new_chance;
}

float LootItem::get_chance() const {
	return chance;
}

void LootItem::set_min_amount(const int &new_min_amount) {
	min_amount = new_min_amount;
}

int LootItem::get_min_amount() const {
	return min_amount;
}

void LootItem::set_max_amount(const int &new_max_amount) {
	max_amount = new_max_amount;
}

int LootItem::get_max_amount() const {
	return max_amount;
}

Dictionary LootItem::serialize() const {
	Dictionary data = Dictionary();
	data["item_id"] = item_id;
	data["chance"] = chance;
	data["min_amount"] = min_amount;
	data["max_amount"] = max_amount;
	return data;
}

void LootItem::deserialize(const Dictionary &data) {
	if (data.has("item_id")) {
		item_id = data["item_id"];
	}
	if (data.has("chance")) {
		chance = data["chance"];
	}
	if (data.has("min_amount")) {
		min_amount = data["min_amount"];
	}
	if (data.has("max_amount")) {
		max_amount = data["max_amount"];
	}
}