#define LEADER_D "/daemons/leader_d"
#define GUILDRANK_D "/daemons/guildrank_d"

cmd_leader(string str) {
  string fiu, glead;
  object ob;
  status online;
  if(!str) {
    write("Usage : leader [race | guild]\n");
    return 1;
  }
  str = lower_case(str);

  fiu = LEADER_D->query_leaderi(str);

  glead = GUILDRANK_D->query_leader(str);
  if(glead != "no one" && !fiu) {
    write("The "+str+" guild is lead by "+capitalize(glead)+".\n");
    return 1;
  } else if(glead == "no one" && !fiu) {
    write("The "+str+" guild does not have a leader.\n");
    return 1;
  }

  if(fiu) {
   ob = find_player(fiu);
   online = 1;
   if (!ob) {
    ob = clone_object("obj/player.c");
    if (!ob->restore_player(fiu) || fiu == "logon") {
      write("No such a player.\n");
      destruct(ob);
      return 1;
    }
    online = 0;
   }
  }
  if(!fiu || ob->query_race() != lower_case(str) || fiu == "no one") {
    write(capitalize(str) + " race does not have a leader.\n");
  } else {
    write("The leader of " + capitalize(str) + " race is " + capitalize(fiu) + ".\n");
  }
  if(!online) destruct(ob);
  return 1;
}

