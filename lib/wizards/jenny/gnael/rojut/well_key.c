inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A small gold key"; }

long() { write("A small golden key, with the text 'well' is engraved on it\n"); }

reset() {
  set_door_file("/wizards/jenny/gnael/huoneet/well7.c");

  set_key_code("803");
}

get() { return 1; }

query_weight() { return 20; }
