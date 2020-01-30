inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A black key"; }

long() { write("The key is black. It's bigger than the usual keys.\n"); }

reset() {
  set_door_file("/wizards/irmeli/castle/well.c");

set_key_code("447");
}


get() { return 1; }

