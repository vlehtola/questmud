// Nalle '03  -- Straight from plan setting code

#define TP this_player()

cmd_desc(string str) 
{
 modify_plan(str);
 return 1;
}

/*****************		****************/

modify_plan(str) {
  if (str == "clear") {
    write("Desc cleared.\n");
    TP->set_desc(0);
    return 1;
  }
  if (str == "set") {
      write("Are you sure? [y/n]\n");
      input_to("plan_choice");
    return 1;
  }
  write("Usage: desc <set/clear>\n");
  return 1;
}

plan_choice(str) {
  if (str == "y") { set_plan(); }
  return 1;
}

set_plan() {
  object ob;
  int lines;
  lines = 6;
  if(TP->query_wiz()) lines = 9;
  ob = clone_object("/daemons/editor");
  ob->start("set_desc", lines);
  return 1;
}
