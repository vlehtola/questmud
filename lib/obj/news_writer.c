/* Made by Halen */
/* Improved by Gheldor */

#define NEWS_D "/daemons/news_d"

static int lines;
static string message;
static string subject;
static string group;

static object prev;
static string func;

void quit();
void save();

void save()
{
  write("Saving...\n");
  NEWS_D->post(group, subject, message);
}

void quit()
{
  write("Quitting the news-writer.\n");
  if(prev)
    if(func)
      call_other(prev, func);
  destruct(this_object());
}

void message_writer(string str)
{
  if(!str) str = "";
  if(str == "~q")
  {
    quit();
    return;
  }
  if(str == "**")
  {
    save();
    quit();
    return;
  }
  if(!message)
    message = str;
  else
    message += "\n"+str;
  write("# ");
  input_to("message_writer");
}

void write_message(string grp, string sub)
{
  write(
"Type '**' to end and save or '~q' to quit without saving. \n"+
"Try to keep the lines in your messages shorter than the line below.\n"+
"----------------------------------------------------------------------------\n"+
"# ");
  subject = sub;
  group = grp;
  input_to("message_writer");
}


void reply(string grp, int id, string fname)
{
  func = fname;
  prev = previous_object();
  write_message(grp, "Re: "+NEWS_D->query_subject(grp, id));
}

void get_subject(string str)
{
  if(!str) str = "No subject";
  write_message(group, str);
}

void new_message(string grp)
{
  write("Subject: ");
  input_to("get_subject");
  group = grp;
}

