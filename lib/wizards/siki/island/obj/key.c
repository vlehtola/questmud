inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "An iron key"; }

long() { write("A small iron key.\n"); }

reset() {
  set_door_file("/wizards/siki/island/floora4");
}

get() { return 1; }

