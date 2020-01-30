cmd_creator(string str) {
  object ob;
  if (!str) {
    write("Usage: creator <room | object>\n");
    return 1;
  }
  if (str == "room") {
    if(creator(environment(this_player()))) {
      write(environment(this_player())->short()+" was created by "+
            capitalize(creator(environment(this_player())))+".\n");
    } else {
      write(environment(this_player())->short()+" is part of Questlib.\n");
    }
    return 1;
  }
  ob = present(str, this_player());
  if(!ob) ob = present(str, environment(this_player()));
  if (!ob) { write("No "+str+" here.\n"); return 1; }
  if(creator(ob)) {
    write(ob->short()+" was created by "+capitalize(creator(ob))+".\n");
  } else {
    write(ob->short()+" is part of Questlib.\n");
  }
  return 1;
}

