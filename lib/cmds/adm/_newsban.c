/* Made by Halen */
/* Improved by Gheldor */

#define NEWSBAN_D "/daemons/newsban_d"

status cmd_newsban(string str)
{
  string group, who;
  int btime;
  if(!str) str = "";
  if(this_player()->query_wiz()<3)
    return 0;
  if(sscanf(str, "%s %s %d", who, group, btime)!=3)
  {
    write("Usage: newsban <who> <group|all> <time in hours>\n");
    return 1;
  }
  who = lower_case(who);
  group = lower_case(group);
  if(!restore_object("/players/"+who))
  {
    write("No such player.\n");
    return 1;
  }

  if( NEWSBAN_D->ban(who, group, (btime*360+time())) )
  {
    write("Banned "+capitalize(who)+" from '"+group+"' "+
          "until "+ctime(time()+(btime*3600))+".\n");
    return 1;
  }
  write("Failed.\n");
  return 1;
}



