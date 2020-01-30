#define SAVEFILE "/data/banrecord"

mapping record;

reset(arg) {
  if(arg) return;
  if(!restore_object(SAVEFILE)) {
    record = ([ ]);
    save_object(SAVEFILE);
  }
}

save_record() {
  save_object(SAVEFILE);
}

add_record(string name,string wiz,string reason,int atime) {
  mapping tmp;
  tmp = ([ ]);
  if(!record[name]) record += ([ name : tmp ]);

  tmp = record[name];
  record -= ([ name ]);
  tmp += ([ ctime(time()) : 
	"Reason: "+reason+" ("+ "/obj/player"->stime(atime) +") By: "+wiz ]);
  record += ([ name : tmp ]);
  save_record();
}

list_record(string str) {
  int i;
  string *arg, *arg2;
  if(record[str]) {
    arg = m_indices(record[str]);
    arg2 = m_values(record[str]);
    write("Displaying record for "+capitalize(str)+":\n");
    while(i < sizeof(arg)) {
      write(arg[i] +"  "+arg2[i]+"\n");
      i += 1;
    }
    write("++End of record.\n");
    return 1;
  }
  arg = m_indices(record);
  if(!arg) return 0;
  write("Displaying players with records:\n");
  while(i< sizeof(arg)) {
    write((i+1)+". "+arg[i]+"\n");
    i += 1;
  }
  write("++End of record.\n");
  return 1;
}
