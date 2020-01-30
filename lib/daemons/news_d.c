/* Made by Halen */
/* Improved by Gheldor */

mapping data;

#define ILLEGAL_CALL() (file_name(previous_object())[0..15]!="/obj/news_reader" &&\
file_name(previous_object())[0..15]!="/obj/news_writer")

#define NOT_ADM() (this_player()->query_wiz()<4)
#define NOT_WIZ() (this_player()->query_wiz()<1)

#define SUBJECT 	0
#define TIME		1
#define FROM		2
#define MESSAGE		3

#define NEWS_SAVE "/data/news_d"
#define CHAN_D ("/daemons/channel_d")

#define MESSAGE_FORMAT\
"\n"+\
"From: %s\n"+\
"Subject: %s\n"+\
"Date: %s\n"+\
"------------------------------------------------------------------------------\n"+\
"%s\n"+\
"------------------------------------------------------------------------------\n"+\
"\n"


/*
 ([ strGroup:	nNextId;
 		([
 			nId:({ strSubject, strDate, strPoster, strMessage
})
 		])
 ])

 ([ "general":	2;
 		([
 			id1:({ "Subject1", "14 Mar 2000", "Mirage",
"Message1" }),
 			id2:({ "Subject2", "15 Mar 2000", "Mirage", "Re:
Message1" }),
		]),
 ]);
*/

void notify_users(string from, string group, string subject)
{
  string tmp;
  if(sscanf(group, "wiz.%s", tmp)==1)
  {
    CHAN_D->send_to_channel("wiz", "*posted a new message "+
       "in '"+group+"'*");
    return;
  }
  if(sscanf(group, "adm.%s", tmp)==1)
  {
    CHAN_D->send_to_channel("adm", "*posted a new message "+
       "in '"+group+"'*");
    return;
  }
  if(sscanf(group, "arch.%s", tmp)==1)
  {
    CHAN_D->send_to_channel("arch", "*posted a new message "+
       "in '"+group+"'*");
    return;
  }
  CHAN_D->send_to_channel("inform", this_player()->query_name()+" posted a new message "+
     "in '"+group+"'");
}

void reset(status arg)
{
	if(arg) return;
	if(!restore_object(NEWS_SAVE))
	{
		data = ([ ]);
	}
}

void add_group(string group)
{
	if(data[group])
		return;
	data += ([ group:1;([ ]) ]);
	save_object(NEWS_SAVE);
}

void remove_group(string group)
{
	if(!data[group])
		return;

	data = m_delete(data, group);
	save_object(NEWS_SAVE);
}

status post(	string group,
		string subject,
		string message)
{
	string from;
	if(!data[group])
		return 0;

	if(ILLEGAL_CALL())
		return 0;

	from = capitalize(this_player()->query_real_name());
	data[group, 1] +=
		([
			data[group, 0]:({ subject, ctime(time()), from,
message })
		]);
	data[group, 0]++;
	save_object(NEWS_SAVE);
	notify_users(from, group, subject);
	return 1;
}

status reply(	string group,
		int id,
		string message)
{
	string from;
	string subject;

	if(!data[group])
		return 0;

	if(ILLEGAL_CALL())
		return 0;

	from = capitalize(this_player()->query_real_name());
	subject = data[group, 1][id][SUBJECT];
	subject = "Re: "+subject;

	data[group, 1] +=
		([
			data[group, 0]:({ subject, ctime(time()), from,
message })
		]);
	data[group, 0]++;
	notify_users(from, group, subject);
	save_object(NEWS_SAVE);
}

status system_post(	string group,
			string subject,
			string message,
			string poster)
{
	if(!data[group])
		return 0;

	data[group, 1] +=
		([
			data[group, 0]:({ subject, ctime(time()), poster,
message })
		]);
	data[group, 0]++;
	save_object(NEWS_SAVE);
}

mixed get_posting(string group, int id)
{
	string message, subject, time, from;
        if(!data[group] || !data[group, 1][id])
		return 0;

	message = data[group, 1][id][MESSAGE];
        if(!message) message = "";
 	subject = data[group, 1][id][SUBJECT];
        if(!subject) subject = "No subject.\n";
	time = data[group, 1][id][TIME];
	from = data[group, 1][id][FROM];
	return sprintf(MESSAGE_FORMAT, from, subject, time, message);
}

int query_message_number(string group)
{
	if(!data[group])
		return -1;
	return data[group, 0] - 1;
}

string *query_groups()
{
	return m_indices(data);
}

// status archive(string group, status non_save) { return 1; }

varargs status archive(string group, status non_save)
{
	int i, sz;
	string posting;
	if(NOT_ADM())
		return 0;
	if(!data[group])
		return 0;

	sz = data[group, 0];
	for(i=0;i<sz;i++)
	{
        	write_file("/data/news/"+group, get_posting(group, i)+"\n\n");
	}
	remove_group(group);
	add_group(group);
	if(!non_save)
		save_object(NEWS_SAVE);
	return 1;
}


status archive_all_groups()
{
	int i;
	string *groups;
	if(NOT_ADM())
		return 0;
	groups = query_groups();
	for(i=sizeof(groups);i--; )
	{
		archive(groups[i], 1);
	}
	save_object(NEWS_SAVE);
	return 1;
}

status delete_message(string group, int id, string reason)
{
	if(ILLEGAL_CALL())
	{
		write("Access violation.\n");
		return 0;
	}
	if(!data[group] || !data[group, 1][id])
		return 0;

	data[group, 1][id][FROM] = "Adminstration team";
	data[group, 1][id][SUBJECT] = "Message deleted.";
	data[group, 1][id][MESSAGE] =
"This message was deleted by the Adminstration-team\n"+
"Reason: \""+reason+"\"\n";
       	return 1;
}

string query_subject(string group, int id)
{
  if(!data[group] || !data[group, 1][id])
    return "You shouldn't see this.";
  return data[group, 1][id][SUBJECT];
}

status group_exists(string grp)
{
  return (data[grp]) ? 1 : 0;
}




