/* made by Celtron */

#define SAVE_FILE "/std/eq_track_data"
#define OUTPUTA   "/log/armour_list"
#define OUTPUTW   "/log/weapon_list"

mapping weapons, armours;

reset(arg) {
  if(arg) return;
  weapons = ([ ]);
  armours = ([ ]);
  if(!restore_object(SAVE_FILE)) save_object(SAVE_FILE);
}

save_data() {
  if(save_object(SAVE_FILE))
    log_file("EQ_TRACK_ERROR", ctime(time())+": cannot save data.\n");
}

  /* write output */
output() {
  int i;
  string str, str2, tmp, space, short, rest;
  if(this_player()->query_wiz() < 3) return 0;
  if(file_size(OUTPUTA)) rm(OUTPUTA);
  if(file_size(OUTPUTW)) rm(OUTPUTW);
  str = m_indices(weapons);
  str2 = m_values(weapons);
  tmp = "";
  space = "                                                                                      ";
  for(i = 0; i < sizeof(str); i++) {
    str2[i] = lower_case(str2[i]);
    if(strlen(str2[i]) < 60)
      tmp += str2[i] + extract(space,0,60-strlen(str2[i])) + " (" +str[i]+ ")\n";
    else
      tmp += str2[i] + " (" +str[i]+ ")\n";
  }

  write_file(OUTPUTW, tmp);
  str = m_indices(armours);
  str2 = m_values(armours);
  tmp = "";

  for(i=0; i<sizeof(str); i++) {
    str2[i] = lower_case(str2[i]);
    if(sscanf(str2[i], "%s :: %s", short, rest) == 2) {
      if(strlen(short) < 60)
        tmp += short + extract(space,0,60-strlen(short)) + " (" +str[i]+ ") "+
		extract(space,0,85-strlen(str[i]))+rest+"\n";
      else
        tmp += short + " (" +str[i]+ ") "+
		extract(space,0,85-strlen(str[i]))+rest+"\n";
    }
    else tmp += str2[i]+"\t\t("+str[i]+")\n";
  }

  write_file(OUTPUTA, tmp);
  return 1;
}

add_weapon_data(object ob) {
  string file, tmp;
  file = file_name(ob);
  if(!file) return 0;
  if(sscanf(file, "%s#%s", file, tmp) == 2) { }
  if(weapons[file]) weapons -= ([ file ]); /* update */
  weapons += ([ file : ob->short()+" (wc "+ob->query_wc()+") ["+ctime(time())[4..10]+ctime(time())[20..24]+", "+
                                this_player()->query_name()+"]" ]);
  save_data();
}

add_armour_data(object ob) {
  string file, tmp;
  file = file_name(ob);
  if(!file) return 0;
  if(sscanf(file, "%s#%s", file, tmp) == 2) { }
  if(armours[file]) armours -= ([ file ]); /* update */
  armours += ([ file : ob->short()+" :: (ac "+ob->query_ac()+") str "+ob->query_stats("str")+" dex "+ob->query_stats("dex")+
	   	 	     " con "+ob->query_stats("con")+" int "+ob->query_stats("int")+" wis "+ob->query_stats("wis")+
			     " spr "+ob->query_stats("spregen")+" ["+ctime(time())[4..10]+ctime(time())[20..24]+", "+
				this_player()->query_name()+"]" ]);
  save_data();
}

