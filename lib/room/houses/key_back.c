inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A bronze key"; }

long() { write("The key is made of bronze.\nYou could 'transfer key to [name]'.\n"); }

reset() {
  set_door_file("/world/city/silcop3.c", "hc");
}

drop() { return 0; }
get() { return 1; }

query_auto_load() { return "/room/houses/key:"; }

init() {
  add_action("transfer","transfer");
}

transfer(str) {
  object ob;
  if (sscanf(str, "key to %s", str)) {
    ob = present(str, environment(this_player()));
    if (!ob || !living(ob) || ob->query_npc()) {
      write(capitalize(str)+" is not here.\n");
      return 1;
    }
    write("You transfer the key to "+ob->query_name()+".\n");
    tell_object(ob, this_player()->query_name()+" gives you the key to a house.\n");
    move_object(this_object(), ob);
    return 1;
  }
  return 0;
}
