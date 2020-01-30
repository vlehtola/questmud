
inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A bronze key"; }

long() { write("The key is made of bronze.\n"); }

reset() {
  set_door_file("/wizards/belar/tree.c");
  set_key_code(66);
 }

get() { return 1; }
