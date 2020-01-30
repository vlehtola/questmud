init() {
  add_action("reloc", "reloc");
}

id(str) { return str == "orb"; }

short() { return "A glowing orb"; }

long() { write("Usage: reloc <player>\n"); }

get() { return 1; }

reloc(str) {
  object ob;
  if(!str) return 0;
  ob = find_player(str);
  if(!ob) {
    write("Player not found.\n");
    return 1;
  }
  write("Moving..\n");
  move_object(this_player(), environment(ob));
  say(this_player()->query_name()+" appears from nowhere!\n");
  return 1;
}
