inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A long iron key"; }

long() { write("A long iron key.\n"); }

reset() {
  set_door_file("/wizards/siki/island/cave1");
}

get() { return 1; }

