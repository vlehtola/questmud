/* Made by Halen */
/* Improved by Gheldor */

#define NEWS_D "/daemons/news_d"
#define NEWSBAN_D "/daemons/newsban_d"

static string current_group;
static int current_id;

static string *unread_messages;

static object reader;

void quit();
void next_message();
void previous_message();
void reply();
void delete();
void delete_reason(string str);
void in_group_help();
void skip();
void again();
void clear();
void read_message();

void next_group();
void prompt();
void out_group_input(string str);
void in_group_input(string str);
void out_group_prompt();
void out_group_help();


int read_news()
{
  object ob;
  mapping news_data;
  string *ind;
  string *groups;
  int i;

  ob = this_player();
  if(!ob)
    ob = environment(this_object());
  if(!ob || !interactive(ob))
  {
    destruct(this_object());
    return 0;
  }
  news_data = ob->query_news_data();
  if(!news_data)
  {
    destruct(this_object());
    return 0;
  }
  unread_messages = ({ });
  current_group = "";
  current_id = 0;
  reader = ob;

  groups = NEWS_D->query_groups();

  for(i=0;i<sizeof(groups);i++)
  {
    if(!news_data[groups[i]])
    {
      if(groups[i][0..3] == "wiz.")
        if(!reader->query_wiz())
          continue;
      if(groups[i][0..3] == "adm.")
        if(reader->query_wiz()<4)
          continue;
      if(groups[i][0..4] == "arch.")
        if(reader->query_wiz()<3)
          continue;
      if(NEWS_D->query_message_number(groups[i])>0)
        unread_messages += ({ groups[i] });
    }
  }
  ind = m_indices(news_data);
  for(i=0;i<sizeof(ind);i++)
  {
    if(news_data[ind[i]]<NEWS_D->query_message_number(ind[i]))
    {
      unread_messages += ({ ind[i] });
    }
  }
  if(sizeof(unread_messages)<=0)
  {
    write("No unread messages.\n");
    quit();
    return 0;
  }
  next_group();
}


void in_group_input(string str)
{
  int i;
  if(!str) str="";
  if(sscanf(str, "%d", i)==1)
  {
    if(i<=0 || i>NEWS_D->query_message_number(current_group))
    {
      write("No message with id '"+i+"'\n");
      prompt();
      return;
    }
    else
    {
      current_id = i - 1;
      next_message();
      return;
    }
  }
  switch(str)
  {
    case "q":
      quit();
      return;
    case "n":
    case "":
    case 0:
      next_message();
      break;
    case "a":
      again();
      break;
    case "p":
      previous_message();
      break;
    case "r":
      reply();
      break;
    case "d":
      delete();
      break;
    case "s":
      skip();
      break;
    case "c":
      clear();
      break;
    case "?":
      in_group_help();
      break;
    default:
      write("No such command. Type '?' for help.\n");
      prompt();
      break;
  }
}

void quit()
{
  write("Quitting the news-reader.\n");
  destruct(this_object());
}

void read_message()
{
  string msg;
/*object ob;
  ob = clone_object("/obj/pager");
  ob->page(NEWS_D->get_posting(current_group, current_id), "???");*/
  msg = NEWS_D->get_posting(current_group, current_id);
  if(!msg) return;
  write(msg);
}

void next_message()
{
  int last_id;

  this_player()->news_hack(current_group, current_id);

  last_id = NEWS_D->query_message_number(current_group);
  current_id++;

  read_message();
  if(current_id>last_id)
    next_group();
  else
    prompt();

}

void previous_message()
{
  if(current_id<=0)
  {
     write("Unable to open previous message.\n");
     prompt();
     return;
  }
  current_id--;
  read_message();
  prompt();
}

void reply()
{
  object ob;
  string str;
  if(NEWSBAN_D->query_ban(this_player()->query_real_name(),
lower_case(current_group)))
  {
    write("You are banished from this group.\n");
    prompt();
    return;
  }
  if(!this_player()->query_wiz() && current_group[0..3] == "info") {
    write("You have no access to that group.\n");
    prompt();
    return;
  }
  ob = clone_object("/obj/news_writer");
  ob->reply(current_group, current_id, "prompt");
}

void delete()
{
  if(this_player()->query_wiz()<4)
  {
    write("This command is only for adminstrators.\n");
    prompt();
    return;
  }
  write("Give reason ('~q' to abort): ");
  input_to("delete_ok");
}

void delete_ok(string str)
{

  if(this_player()->query_wiz()<4)
  {
    write("Access violation.\n");
    prompt();
    return;
  }
  if(str=="~q")
  {
    write("Aborted.\n");
    prompt();
    return;
  }
  if(!NEWS_D->delete_message(current_group, current_id, str))
  {
    write("Failed.\n");
    prompt();
    return;
  }
  write("Message deleted.\n");
  prompt();
}

void in_group_help()
{
  write(
"\nCommands available in the news-reader:\n"+
"     q - quit the news-reader\n"+
"     n - move to the next message\n"+
"     a - read the current message again\n"+
"     p - move to the previous message\n"+
"     s - skip over the current message\n"+
"         without reading it\n"+
"     r - reply to the current message\n"+
"     c - mark rest of the messages in the\n"+
"         current group to be read and move on\n"+
"         to the next group.\n"+
"     ? - this help\n");
  if(reader->query_wiz()>=4)
    write(
"     d - delete current message\n");
  write(
"\n"+
"     Typing a number will move you to the message\n"+
"     with the id you typed.\n\n");
  prompt();
}

void skip()
{
  int last_id;

  this_player()->news_hack(current_group, current_id);

  current_id++;

  last_id = NEWS_D->query_message_number(current_group);

  write("Skipped.\n");

  if(current_id>last_id)
    next_group();
  else
    prompt();

}

void clear()
{
  write("Marked group '"+current_group+"' as read.\n");
  this_player()->news_hack(current_group,
NEWS_D->query_message_number(current_group));
  next_group();
}

void next_group()
{
  int unread;

  if(current_group != "")
    unread_messages -= ({ current_group });

  if(sizeof(unread_messages)<=0)
  {
    write("No unread messages left.\n");
    quit();
    return;
  }

  current_group = unread_messages[0];
  current_id = reader->query_read_id(current_group);

  unread = NEWS_D->query_message_number(current_group) - current_id;
  out_group_prompt();
}

void out_group_prompt()
{
  int unread;
  unread = NEWS_D->query_message_number(current_group) - current_id;
  write((unread)+" unread messages in group '"+current_group+"', read now? [yncq?] ");
  input_to("out_group_input");
}

void out_group_input(string input)
{
  switch(input)
  {
    case "y":
    case "":
    case 0:
      //prompt();
      next_message();
      break;
    case "n":
      next_group();
      break;
    case "q":
      quit();
      break;
    case "c":
      clear();
      break;
    case "?":
    case "h":
      out_group_help();
      break;
    default:
      write("No such option. Type '?' for help.\n");
      out_group_prompt();
  }
}

void out_group_help()
{
  write(
"\nCommands available in the news-reader:\n"+
"     y - start reading the next group\n"+
"     n - skip the next group and leave it\n"+
"         for later times\n"+
"     c - mark the current group unread\n"+
"     q - quit the news-reader\n"+
"     ? - this help\n\n");
  out_group_prompt();
}


void prompt()
{
  int messages_left;
  messages_left = NEWS_D->query_message_number(current_group) -
current_id;

  write("Message "+(current_id)+"/"+NEWS_D->query_message_number(current_group)+
        " in group '"+current_group+"'. Options: [#qnapscr");
  if(reader->query_wiz()>=4)
    write("d");

  write("?] ");
  input_to("in_group_input");
}

void again()
{
  read_message();
  prompt();
}

