inherit "obj/armour";

start() {
  set_short("A grey bone bracelet");
  set_long("Bloodstains cover the bracelet from here and there. \n"+
	   "It is made of small bones connected to each other with\n"+
	   "iron wire. It grants some necronomica powers. try 'nhelp'\n");
  set_slot("bracelet");
  set_name("bracelet");
}

init() {
  ::init();
  add_action("show_help", "nhelp");
  add_action("dest_dead", "finish");
}

show_help() {
  write("Commands available:\n");
  write("finish <target> - finishes the 'bugging' monsters\n");
  return 1;
}

dest_dead(string str) {
  object ob;
  if(!str) return show_help();
  if(!worn_by) {
    write("The bracelet must be worn before it can be used.\n");
    return 1;
  }
  ob = present(str, environment(worn_by));
  if(!ob) {
    write("No such target found.\n");
    return 1;
  }
  if(!ob->query_dead()) {
    write("Invalid target.\n");
    return 1;
  }
  log_file("NECRO_BUG", ctime(time())+" | "+ob->short()+" bugged in "+file_name(environment(ob))+". Destructed by "+
	worn_by->query_name()+".\n");

  tell_room(environment(worn_by), worn_by->query_name()+" touches "+worn_by->query_possessive()+
	" bracelet and it sends out a green spark!\n");
  ob->death();
  if(ob) {
    write("Hard destructing target. no exp gained.\n");
    destruct(ob);
  }
  return 1;
}
