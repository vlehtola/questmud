inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A small key"; }

long() { write("A small key, with the text 'warehouse'\n"); }

reset() {
  set_door_file("/wizards/kaappi/dcity/rooms/katu48.c");

  set_key_code("999");
}

get() { return 1; }

query_weight() { return 20; }
