/* Made by Halen */
/* Improved by Gheldor */

#define NEWSBAN_SAVE "/data/newsban_d"
#define RESTORE() restore_object(NEWSBAN_SAVE)
#define SAVE() save_object(NEWSBAN_SAVE)
#define PRIVILEGED() (this_player()->query_wiz()>=3)

mapping data;

void invalidate()
{
  string *ind;
  string *ind2;
  int i, j;
  ind = m_indices(data);
  for(i=sizeof(ind);i--; )
  {
    ind2 = m_indices(data[ind[i]]);
    for(j=sizeof(ind2);j--; )
    {
      if(data[ind[i]][ind2[j]] < time())
        data[ind[i]] = m_delete(data[ind[i]], ind2[j]);
    }
  }
}


void reset(status arg)
{
  if(arg) return;
  data = ([ ]);
  RESTORE();
  invalidate();
}

status ban(string who, string group, int until)
{
  invalidate();
  if(!PRIVILEGED())
    return 0;
  if(!data[group])
    data += ([ group : ([ who : until ]) ]);
  else
    data[group] += ([ who : until ]);
  SAVE();
  write_file("/log/NEWSBAN",
    this_player()->query_real_name()+" banned "+who+" from "+
    group+" until "+ctime(until)+".\n");

  return 1;
}

status remove_ban(string who, string group)
{
  invalidate();
  if(!PRIVILEGED())
    return 0;
  if(!data[group])
    return 0;
  data[group] = m_delete(data[group], who);
  SAVE();
  return 1;
}

status alpha_sort(string str, string str2)
{
  return str[0]<str2[0];
}

void show_bans()
{
  string *groups;
  string *bans;
  int i;
  invalidate();
  groups = m_indices(data);
  for(i=0;i<sizeof(groups);i++)
  {
    write(groups[i]+": ");
    bans = m_indices(data[groups[i]]);
    bans = sort_array(bans, "alpha_sort", this_object());
    write(implode(bans, ", "));
    write("\n");
  }
}

mapping query_data()
{
  return data;
}

status query_ban(string who, string group)
{
  invalidate();
  if(!!data["all"])
    if(data["all"][who]>0)
      return 1;
   if(!data[group])
    return 0;

  if(data[group][who]>0)
    return 1;
  return 0;
}




