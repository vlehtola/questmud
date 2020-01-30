//Added a feature to count objects in room, Rag
//Added a feature to count objects in a container, Rag
status cmd_count(string str) {
  int i,amount;
  string what,where, txt;
  object *inv;
  object ob;
  if(!str) {
    write("Use: count item in me/room/container\n");
    return 1;
  }
  if(sscanf(str,"%s in %s",what,where) != 2) {
        write("Use: count item in me/room/container\n");
        return 1;
  }
  //A little something by Rag
  if(what == "life") {
    write("You have a QuestMUD life! Could you wish for more?\n");
    return 1;
  }
  if(where == "me") {
        inv = all_inventory(this_player());
  } else if(where == "room") {
        inv = all_inventory(environment(this_player()));
        txt = "here";
  } else {
        ob = present(where, environment(this_player()));
        if ( !ob ) {
          ob = present(where, this_player());
        }
        if ( !ob ) {
          write("There is no '"+where+"' here.\n");
          return 1;
        }

        if ( !ob->can_put_and_get() ) {
          write("You can't do that.\n");
          return 1;
        }

        inv = all_inventory(ob);
        txt = "in the "+where;
  }
  for(i=0;i<sizeof(inv);i++) {
     if(inv[i]->id(what) && what != "coins") amount++;
     if(what == "coins") amount += inv[i]->query_value();
  }
  if(where == "me") {
        if(!amount) write("You don't have any '"+what+"'\n");
        else if(amount == 1) write("You have one '"+what+"'\n");
        else write("You have "+amount+" of '"+what+"'\n");
        return 1;
  } else {
        if(!amount) write("There is no '"+what+"' "+txt+".\n");
        else if(amount == 1) write("There is one '"+what+"' "+txt+".\n");
        else write("There are "+amount+" of '"+what+"' "+txt+".\n");
        return 1;
  }
}

