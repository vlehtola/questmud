cmd_flook() {
  object ob;
  int i;
  ob = first_inventory(environment(this_player()));
  while(ob) {
      if(ob && ob->short()) { write(ob->short()+": '"+file_name(ob)+"'\n"); }
      ob = next_inventory(ob);
  }
  return 1;
}
