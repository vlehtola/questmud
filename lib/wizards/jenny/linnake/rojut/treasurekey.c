inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "jeweled silver key"; }

long() { write("Gorgeous looking jeweled silver key.\n"); }

reset() {
  set_door_file("/wizards/jenny/linnake/huoneet/treasure2.c");

  set_key_code("371");
}

get() { return 1; }

query_weight() { return 20; }
