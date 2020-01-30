inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A bronze key"; }

long() { write("The key is made of bronze.\n"); }

reset() {
  set_door_file("/wizards/rag/elf/w_a1");
  set_key_code("817");
}

get() { return 1; }

query_weight() { return 20; }
