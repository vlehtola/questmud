inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A shimmering key"; }

long() { write("The key is made of iron.\n"); }

reset() {
  set_door_file("/wizards/neophyte/city/lighthouse/corridor16.c");
  set_key_code(123);
}

get() { return 1; }
