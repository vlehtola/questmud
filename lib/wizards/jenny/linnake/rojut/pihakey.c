inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "Rusty steel key"; }

long() { write("Very rusty looking steel key.\n"); }

reset() {
  set_door_file("/wizards/jenny/linnake/huoneet/ulkoovi.c");

  set_key_code("471");
}

get() { return 1; }

query_weight() { return 20; }
