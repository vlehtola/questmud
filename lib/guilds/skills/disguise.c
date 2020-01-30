get_time(str) {
  return 10;
}
ep_cost() { return 30; }
query_type() { return "neutral"; }

resolve_skill(target) {
  string str;
  object ob;
  int time;
  if(!target) {
	  write("Disguise yourself at what?\n");
	  return 1;
  }
  if(this_player()->query_disguise()) {
    write("You are already disguised.\n");
    return 1;
  }
  ob = present(target,environment(this_player()));
  if(!ob) {
	  write("No '"+target+"' here.\n");
	  return 1;
  }
  if(!ob->short()) {
	 write("You can't disguise yourself as "+target+"\n");
	 return 1;
 }
 str = ob->short();
 time = this_player()->query_dex()+this_player()->query_lvl()*2;
  clone_object("/wizards/siki/disguise_shadow")->start_disguise(this_player(), time, str);
  write("You disguise yourself as "+target+"!\n");
  return 1;
}

fail_skill() {
  write("You fail to disguise yourself.\n");
  return 1;
}
