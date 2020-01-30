short() { return "A display monitor"; }
long() {
  write("Try: display_kills\n");
}
id(str) { return str == "monitor"; }
init() {
  add_action("display_kills", "display_kills");
}

display_kills() {
  object ob;
  if(!this_player()->query_wiz()) return;
  ob = find_object("/obj/kill_list");
  if(ob) ob->display_deaths();
  else write("Object NOT found.\n");
  return 1;
}
