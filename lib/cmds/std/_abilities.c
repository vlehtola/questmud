#define ABILITY_D "/daemons/ability_d"

void do_sense();

int cmd_abilities(string arg) {
  mapping abilities;
  int i;
  string *index, tmp, str;
  object ob;

  if(arg && this_player()->query_wiz())
    ob = find_player(arg);

  if(!ob)
    ob = this_player();

  if ( arg == "sense" && this_player()->query_ability("monstersense") ) {
    do_sense();
    return 1;
  }

  if ( arg && ( sscanf(arg,"setmin %s",tmp) == 1 ||
       sscanf(arg,"setmout %s",tmp) ) == 1 ) {
    if ( !this_player()->query_ability("movementmessages") ) {
      return 1;
    }
    if ( sizeof(tmp) > 30 ) {
      write("Too long movement message.\n");
      return 1;
    }
    if ( sscanf(arg,"setmin %s",tmp) == 1 ) {
      this_player()->setmin(tmp);
      str = "Movement message when entering set to "+tmp+".\n";
    } else {
      this_player()->setmout(tmp);
      str = "Movement message when leaving set to "+tmp+".\n";
    }
    return 1;
  }

  abilities = ob->query_abilities();
  if(m_sizeof(abilities)) index = m_indices(abilities);
  write("+----------------------------------------+-------------+\n");
  write("| Name of the ability                    |       Value |\n");
  write("+----------------------------------------+-------------+\n");
  for(i=0;i<sizeof(index);i++) {
    tmp = ABILITY_D->get_ability_name(index[i]);
    printf("| %39-s| %10i%% |\n",tmp,abilities[index[i]]);
  }
  write("+----------------------------------------+-------------+\n");
  printf("| %39-s|\n","Total of "+sizeof(index)+" abilities");
  write("+----------------------------------------+\n");
  write("See also help abilities\n");
  return 1;
}

void do_sense() {
  object room = environment(this_player());
  object *monsters;
  string msg = "";
  
  monsters = all_inventory(room);
  
  for ( int i = 0; i < sizeof(monsters); i++ ) {
    if ( monsters[i]->query_npc() && monsters[i]->query_turbo() ) {
      msg += monsters[i]->short() + "\n";
    }
  }
  
  if ( msg != "" ) {
    write("The followings monsters are stronger than normal:\n");
    write(msg);
  } else {
    write("There are no abnormally strong monsters around.\n");
  }
}
