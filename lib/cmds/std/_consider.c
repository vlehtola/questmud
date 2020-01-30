cmd_consider(string str) {
  int value1, value2, index;
  object ob;
  if(!str) {
     write("Usage: 'consider [name]'.\n");
     return 1;
  }
  ob = present(lower_case(str), environment(this_player()));
  if (!ob) {
    write("No "+capitalize(str)+" here.\n");
    return 1;
  }
  value1 = this_player()->query_level() / 2 + 1;
  value1 = value1*100;
  
  if (ob->query_npc()) {
    value2 = ob->query_level();
        if(ob->query_kill_log()) {
          value2 = value2 * 3/2;
        }
    value2++;
  } else {
    value2 = ob->query_level() / 2 + 1;
  }

  if ( !value2 ) value2++;
  
  index = value1 / value2;
  if (index > 200) {
    write(ob->query_name()+" looks much weaker than you.\n");
    return 1;
  }
  if (index > 130) {
    write(ob->query_name()+" looks weaker than you.\n");
    return 1;
  }
  if (index > 90) {
    write(ob->query_name()+" looks about equal to you.\n");
    return 1;
  }
  if (index > 60) {
    write(ob->query_name()+" looks quite tough.\n");
    return 1;
  }
  if (index > 50) {
    write(ob->query_name()+" looks stronger than you.\n");
    return 1;
  }
  if (index > 30) {
    write(ob->query_name()+" looks much stronger than you.\n");
    return 1;
  }
  if (index >= 0) {
    write("You would not stand a chance against "+ob->query_name()+".\n");
    return 1;
  }

}
