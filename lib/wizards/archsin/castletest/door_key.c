inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A bronze key"; }

long() { write("The key is made of tin.\n"); }

reset() {
  set_door_file("/wizards/archsin/roor_room.c");
}

get() { return 1; }

