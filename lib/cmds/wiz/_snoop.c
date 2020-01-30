cmd_snoop(string arg) {
  object ob;
  if(this_player()->query_wiz() < 2) return 0;
  if(!arg) {
    snoop(this_player());
    return 1;
  }
  ob = find_player(arg);
  if (!ob) {
    write("No such player.\n");
    return 1;
  }
  if(this_player()->query_wiz() < 4) {
        log_file("SNOOPS", this_player()->query_name() +
                ", " + extract(ctime(time()), 4, 15)+ " target: "+ob->query_name()+".\n",1);
  }

  if(   (this_player()->query_wiz() < 5) && 
        (ob->query_real_name()=="houtmi" || ob->query_real_name()=="waltest")) 
        return 0;

  snoop(this_player(), ob);
  return 1;
}

