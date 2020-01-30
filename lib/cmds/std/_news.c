/* Made by Halen */
/* Improved by Gheldor */

#define NEWS_D "/daemons/news_d"
#define NEWSBAN_D "/daemons/newsban_d"

status has_access(string str)
{
  string tmp;
  if(sscanf(str, "wiz.%s", tmp)==1)
  {
    if(!this_player()->query_wiz())
      return 0;
  }
  if(sscanf(str, "adm.%s", tmp)==1)
  {
    if(this_player()->query_wiz()<4)
      return 0;
  }
  if(sscanf(str, "arch.%s", tmp)==1)
  {
    if(this_player()->query_wiz()<3)
      return 0;
  }
  return 1;
}

status alpha_sort(string str, string str2)
{
  return str[0]>str2[0];
}



status cmd_news(string str)
{
  string tmp, tmp2;
  string *groups;
  string rv;
  int i;
  if(!str) str = "";
  if(str=="read")
  {
    clone_object("/obj/news_reader")->read_news();
    return 1;
  }

  if(sscanf(str, "send %s", tmp)==1)
  {
    if(NEWSBAN_D->query_ban(this_player()->query_real_name(),
       lower_case(tmp)))
    {
      write("You are banished from that group.\n");
      return 1;
    }
    if(!NEWS_D->group_exists(tmp))
    {
      write("No such group.\n");
      return 1;
    }
    if(!has_access(tmp) || tmp[0..3] == "info" && !this_player()->query_wiz()) {
      write("You have no access to that group.\n");
      return 1;
    }
    clone_object("/obj/news_writer")->new_message(tmp);
    return 1;
  }

  if(sscanf(str, "unread %s", tmp)==1)
  {
    if(!NEWS_D->group_exists(tmp))
    {
      write("No such group.\n");
      return 1;
    }
    this_player()->news_hack(tmp, 0);
    write("Marked group '"+tmp+"' unread.\n");
    return 1;
  }

  if(sscanf(str, "create %s", tmp)==1)
  {
    if(this_player()->query_wiz()<4)
    {
      write("This command is only for adminstrators.\n");
      return 1;
    }
    if(NEWS_D->group_exists(tmp))
    {
      write("Group '"+tmp+"' already exists.\n");
      return 1;
    }
    write("Adding group '"+tmp+"'.\n");
    NEWS_D->add_group(tmp);
    return 1;
  }

  if(sscanf(str, "remove %s", tmp)==1)
  {
    if(this_player()->query_wiz()<4)
    {
      write("This command is only for adminstrators.\n");
      return 1;
    }
    if(!NEWS_D->group_exists(tmp))
    {
      write("Group '"+tmp+"' doesn't exist.\n");
      return 1;
    }
    NEWS_D->remove_group(tmp);
    write("Removed group '"+tmp+"'.\n");
  }
  if(str == "help")
  {
    write(
"\nAvailable news-commands:\n"+
"   read           - start reading news\n"+
"   send <group>   - write a message to group <group>\n"+
"   unread <group> - mark group <group> unread\n"+
"   groups         - shows the groups you have access to\n\n");
    if(this_player()->query_wiz()>=4)
    {
      write(
"News-commands for adminstrators:\n"+
"   create <name>  - create a news group named <name>\n"+
"   remove <group> - remove group <group>\n"+
"        !!!USE THESE CAREFULLY!!!\n\n");
    }
    return 1;
  }
  if(str == "groups")
  {
    groups = NEWS_D->query_groups();
    groups = filter(groups, "has_access", this_object());
    groups = sort_array(groups, "alpha_sort");

    if(sizeof(groups)<=0)
    {
      write("You don't have access to any existing group.\n");
      return 1;
    }
    write("You have access to following channels: \n");
    rv = implode(groups, ", ");
    write(rv+"\n");
    return 1;
  }

  write("No such news-command. See 'news help' for help.\n");

  return 1;
}



