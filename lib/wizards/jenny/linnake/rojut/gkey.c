inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "Golden key labelled as 'prisonkey'"; }

long() { write("The key is made of gold.\n"); }

reset() {
  set_door_file("/wizards/jenny/linnake/huoneet/prison4.c");
  set_door_file("/wizards/jenny/linnake/huoneet/prison6.c");
  set_door_file("/wizards/jenny/linnake/huoneet/prison12.c");
  set_door_file("/wizards/jenny/linnake/huoneet/prison10.c");
  set_door_file("/wizards/jenny/linnake/huoneet/prison16.c");
  set_door_file("/wizards/jenny/linnake/huoneet/prison18.c");

  set_key_code("571");
}

get() { return 1; }

query_weight() { return 20; }
