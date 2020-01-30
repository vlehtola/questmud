// 'Note' -command for QuestMUD by Nalle Jan 2003

#include <ansi.h>

#define TP this_player()
#define USAGE "Usage : See 'help note'\n"
#define MAX_NOTES 15

string int_to_time(int p);

cmd_note(string arg)
{
  mapping note;
  string *arr,*temp;
  int x,i;
  object ob;
  note=(mapping)TP->query_notes();
  if(!mappingp(note)) note=([]);
  arr=m_indices(note);

  if(!arg || arg=="read")
                                {
  x=sizeof(arr);

  if(TP->query_level()<10) 
  { 
  write("Players of below level 10 do not have access to a notebook.\n");
  return 1;
  }

  if(!x) { write("Your notebook is empty.\n"); return 1; }

  write("Your notebook entries :\n");
    for(i=0;i<x;i++)    {
 if(TP->query_terminal()) write(CYAN_F+""+i+OFF" : "+arr[i]+"\n");
 else                     write(""+i+" : "+arr[i]+"\n");
                        }

    write("Done. "+x+" entries displayed.\n");
    return 1;
                                }

  if(arg=="clear" || arg=="reset")
  {
  write("Notebook cleared.\n");
  note=([]);
  TP->set_notes(note);
  return 1;
  }

  if(arg=="help")
  {
    write(USAGE);
    return 1;
  }

  temp=explode(arg," ");

  if(sizeof((temp=explode(arg," "))) == 2)
  if(temp[0]=="erase")
  {
    i=atoi(temp[1]);

    if(i>=x) { write("Invalid notebook entry. ('"+i+"')\n"); return 1; }

    note-=([arr[i]]);
    write("Line "+i+" erased from the notebook.\n");
    TP->set_notes(note);
    return 1;
  }

  if(m_sizeof(note)>=MAX_NOTES)
  {
  write("Your notebook is full, try erasing some entries.\n");
  return 1;
  }

  note+=([arg]);
  TP->set_notes(note);
  write("Line added.\n");

  return 1;
}

