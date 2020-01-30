#define RACE_D "/daemons/race_stats"
#define LEADER_D "/daemons/leader_d"
#define GUILD_D "/daemons/guildrank_d"

string raceleader(string str);

cmd_leaders() 
{
 string *races;
 string *guilds;
 string result;
 int r, g;
 races = RACE_D->query_races();

 result = sprintf("+----------------------------------------+\n");

 for(r=0;r<sizeof(races);r++) 
  {
   if(raceleader(races[r]) && raceleader(races[r]) != "no one") 
     {
      result += sprintf("| %-15s | %-20s |\n", capitalize(races[r]), capitalize(raceleader(races[r])));
     } 
  }

 guilds = GUILD_D->query_guilds();

 result += sprintf("+----------------------------------------+\n");

 for(g=0;g<sizeof(guilds);g++) 
 {
  result += sprintf("| %-15s | %-20s | \n", capitalize(guilds[g]), capitalize(GUILD_D->query_leader(guilds[g])));
 }

 result += sprintf("+----------------------------------------+\n");
 write(result);
 return 1;
}


string raceleader(string str)
{
 string fiu;
 int online;
 object ob;

 str = lower_case(str);
 fiu = (string) LEADER_D->query_leaderi(str);

 if(fiu) 
   {
    ob = find_player(fiu);
    online = 1;
    if  (!ob) 
	{
    	 ob = clone_object("obj/player.c");

    	 if (!ob->restore_player(fiu) || fiu == "logon") 
	    {
      		write("No such player.\n");
      		destruct(ob);
      		return "no one";
    	    }

    	 online = 0;
   	}
    if(ob->query_race() != str) return "no one";
   }

 if(!fiu) fiu = "no one";

 return fiu;
}
