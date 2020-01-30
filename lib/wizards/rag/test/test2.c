#define QUEST_D "/daemons/quest_d"

inherit "room/room";

init() {
	add_action("fix_quest_points","fix");
	add_action("fix_old","fix_old");
	::init();
}

reset(arg) {
	int i;
        if(arg) return;
	add_exit("west","/wizards/rag/test/testroom");

        short_desc = "Rag's testroom";
        long_desc = "This is Rag's room for testing various things.\n"+
                        "Various machines are scattered around the room and\n"+
                        "smoke rises from most of them.\n"+
this_player()->query_possessive()+" "+
this_player()->query_objective()+" "+
this_player()->query_pronoun()+"\n";
        set_light(1);
        set_not_out(1);

}

fix_quest_points(str) {
  object ob;
  string *rest;
  int i,p;
  p = 0;
  if(!str) {
  	ob = this_player();
  } else {
  	ob = find_player(str);
  	if(!ob) {
  		write("Eep!\n");
  		return 1;
  	}
  }
  rest = explode(ob->query_quests(),"#");
  for(i = 0;i<sizeof(rest);i++) {
  	p += (int)QUEST_D->validate_quest(rest[i]);
  }
  write("P: "+p+" QP: "+ob->query_max_quest_points()+"\n");
  if(ob->query_quest_points() > p)
      write("Wrong number of QP's\n");
  write("Setting max_qp\n");
  return 1;
}

fix_old(str) {
  object ob;
  string rest,rest_tmp,tmp;
  int i,p;
  if(!str) {
  	ob = this_player();
  } else {
  	ob = find_player(str);
  	if(!ob) {
  		write("Eep!\n");
  		return 1;
  	}
  }
  rest = ob->query_quests();
  p += (int)QUEST_D->validate_quest(rest);
  while(rest) {
    i = sscanf(rest, "%s#%s", tmp, rest_tmp);
    if (i == 0)
        break;
    p += (int)QUEST_D->validate_quest(tmp);
    if (i == 1)
        break;
    rest = rest_tmp;
  }
  write("P: "+p+" QP: "+ob->query_max_quest_points()+"\n");
  if(ob->query_quest_points() > p)
      write("Wrong number of QP's\n");
  write("Setting max_qp\n");
  return 1;
}