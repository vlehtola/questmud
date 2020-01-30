/*
This daemon is for multiguild purposes. ie. you can select a
multiguild and thus get 2 backgroundguilds plus the variation
between these two.  //Celtron
*/

#include <ansi.h>
#define GUILD_INIT "/guilds/guilds/guild_init"

mapping multiguilds; // guild name : list(bg guilds)

status join_multiguild(string multi_name, object player);

void reset(status arg) {
  multiguilds = GUILD_INIT->query_multiguilds();
}

status query_guild(string guild) {
  if(multiguilds[guild]) return 1;
  return 0;
}

string *secondary_guilds(string guild) {
  return ({ multiguilds[guild, 0], multiguilds[guild, 1], });
}

// Check if such a multiguild exists, join if possible (1)
// returns the starter guild (background) which must be completed first
string get_starter_guild(string guild_name) {
  if(!guild_name || !query_guild(guild_name))
    return 0;
  return multiguilds[guild_name,0];
}

void set_multiguild(string guild_name, object player) {
  write("You are now an initiate for the "+YELLOW_F+guild_name+OFF+" guild,\n"+
	"and must complete your background guilds before joining.\n\n");
  player->set_multiguild(guild_name);
}

// any player tries to join any guild
status join_guild(string join_name, object player) {
  string multi, guild_file;
  mapping guilds;
  if(!player) player = this_player();
  guilds = GUILD_INIT->query_guilds();
  multi = player->query_multiguild();
 // guild_file = guilds[join_name, 2];
  guild_file = file_name(environment(player));
/* if not a multiguilder, check if the guild is part of the starter guild (same dir)
   /guilds/psi/ .. 12 letters
*/
  if(!multi) {
    if(this_player()->query_tester() || this_player()->query_wiz())
	write("Compare: "+guild_file[0..11]+" vs "+player->query_starter_guild()[1][0..11]+"\n");
//A quick fix by Rag, players were unable to advance
    if(guild_file[0..11] == player->query_starter_guild()[1][0..11] ||
       guild_file[1..11] == player->query_starter_guild()[1][0..10]) {
      return 1;
    } else {
//    write("You do not belong to a multiguild and cannot choose\n"+
//		"other guilds than "+player->query_starter_guild()[0]+" subguilds.\n");
      return 0;
    }
  }
// the multiguild case
  if(!player->query_guild_level(multi)) {
    //check if join_name is player's multiguild or one of bg guilds, otherwise return 0
    join_name = lower_case(join_name);

    if(player->query_tester()) {
	write("compare: "+join_name+" vs "+multi+"/"+guilds[multiguilds[multi,0],0]+"\n");
    }

    if(join_name == lower_case(guilds[multiguilds[multi,0],0]) || 
	join_name == lower_case(guilds[multiguilds[multi,1],0]) ) {
      return 1;
    } else if(join_name == multi) {
      return join_multiguild(join_name, player);
    } else if(join_name == multi+"s") {
      return join_multiguild(multi, player);
    } else {
      write("You have chosen the "+multi+" multiguild and must join it\nbefore you can join other guilds.\n");
      return 0;
    }
  }
  // player has joined his multiguild and can join any of the two bg guild subs aswell
  if(this_player()->query_tester())
	write("join_name: "+join_name+" guild_file: "+guild_file+"\n");
  if(guild_file[0..11] == guilds[ multiguilds[multi,0] , 2][0..11] ||
       guild_file[0..11] == guilds[ multiguilds[multi,1] , 2][0..11] ||
	GUILD_INIT->query_subguilds()[multi] && guild_file[0..11] == GUILD_INIT->query_subguilds()[multi][0..11] ) {
    return 1;
  } else {
    write("You are not permitted to join this guild due multiguild restriction.\n");
    return 0;
  }
}

// check if joining to multiguild is possible.
// the 2 bg guilds must be completed
status join_multiguild(string multi_name, object player) {
  mapping guilds;
  string *guild_file, guild_n;
  int max_level, current_level;
  int i;
  if(!player) player = this_player();
  if(!multiguilds[multi_name]) {
    write("No such guild.\n");
    return 0;
  }
  guilds = GUILD_INIT->query_guilds();
  guild_file = ({ guilds[multiguilds[multi_name,0], 1], guilds[multiguilds[multi_name,1], 1], });
  write("Guild_files: "+guild_file[0]+", "+guild_file[1]+"\n");
  for(i=0; i < sizeof(guild_file); i++) {
    guild_n = guild_file[i]->guild_name();
    max_level = guild_file[i]->guild_max_level();
    current_level = player->query_guild_level(guild_n);
    if(player->query_tester()) {
      write("compare:"+guild_n+" "+current_level+"/"+max_level+"\n");
    }
    if(current_level < max_level) {
	write("You must complete your secondary guild, '"+guild_n+"' first. You have currently level "+current_level+" of "+max_level+".\n");
        return 0;
    }
  }
  write("You join the "+multi_name+" guild. Congratulations!\n");
  return 1;
}
