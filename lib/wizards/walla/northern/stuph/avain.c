inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "Golden key labelled as 'hoovee'"; }

long() { write("The key is made of gold.\n"); }

reset() {
  set_door_file("/wizards/walla/northern/rooms/lvl3/drawbridge_2.c");

  set_key_code("221");
}

get() { return 1; }

query_weight() { return 20; }




