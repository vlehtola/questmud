cmd_yauts(string str)
{
  string name;
  int hps;
  object ob;
  int Wiza;
 
   Wiza = this_player()->query_wiz();

    sscanf(str, "%s %d", name, hps);

    if (!name)
      { write("Syntax : yauts <target> <hps>\n"); return 1; }

    ob = present(name,environment(this_player()));


     if(!ob)
        ob = find_player(name);
    if (!ob) {
        write("No such person or living in environment or game now.\n");
        return 1;
    }

    if(Wiza < 1) 
      { write("Illegal target at this wizard level.\n"); return 1; }

    ob->reduce_hp(hps);

    write("sin� satuttaa " + capitalize(name) + "nain monta "+hps+" hippelia.\n");
    return 1;
}