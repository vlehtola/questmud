/* //Celtron */

#define SAVEFILE "/std/user_meter_data"
#define OUTPUT "/log/user_meter"
#define OUTPUT_AVG "/log/user_meter_avg"

int *user;
mapping stor;

reset(arg) {
  if(arg) return;
  if(!restore_object(SAVEFILE))
    save_object(SAVEFILE);
  if(!stor) stor = ([ ]);
  if(sizeof(user) > 2000) {
    stor += ([ m_sizeof(stor) : user ]);
    user = 0;
  }
  call_out("half_hour", 0);
}

/* gather new data (automatic) */
static half_hour() {
  int usr, usr_ld, *new;
  object ob;
  int i;
  ob = users();
  for(i=0;i<sizeof(ob);i++) {
    if(ob[i]->query_idle() > 300)
      usr_ld += 1;
    else
      usr += 1;
  }
  new = ({ time(), usr, usr_ld, });
  if(!user) user = ({ new, });
  else user = user + ({ new, });
  save_object(SAVEFILE);
  call_out("half_hour", (30*60));
}


/* manual use functions */

output() {
  string out;
  int i, *user_;
  if(this_player()->query_wiz() != 5) return 0;
  user_ = stor[m_sizeof(stor)-1];
  for(i=0; i < sizeof(user_); i++) {
    out = "#########@#########@#########@#########@##########@#########@#########@"[0..(user_[i][1]-1)] +
	  ".........,.........,.........,.........,..........,.........,.........,"[0..(user_[i][2]-1)];
    write_file(OUTPUT, ctime(user_[i][0])[4..15]+" "+out+"\n");
  }
  write(OUTPUT+" updated.\n");
  return 1;
}

average_output() {
  string out;
  int i, *average, slot, count, user_;
  if(this_player()->query_wiz() != 5) return 0;
  rm(OUTPUT_AVG);
  user_ = stor[m_sizeof(stor)-1];
  average = allocate(24); /* one hour steps */
  for(i=0; i < sizeof(user_); i++) {
    slot = to_int(ctime(user_[i][0])[11..12]);
    if(!average[slot]) average[slot] = allocate(2);
    average[slot][0] += user_[i][1];  
    average[slot][1] += user_[i][2];  
  }
  write_file(OUTPUT_AVG,
"Displaying average of "+i+" counts.\n"+
"First count: "+ctime(user_[0][0])+" Last count: "+ctime(user_[sizeof(user_)-1][0])+"\n");

  count = i/24;
  
  for(i=0; i < sizeof(average); i++) {
    out = "#########@#########@#########@#########@##########@#########@#########@"[0..(average[i][0]/count-1)] +
          ".........,.........,.........,.........,..........,.........,.........,"[0..(average[i][1]/count-1)];
    write_file(OUTPUT_AVG, 
      force_string_length(i+".00", 5)+"-"+force_string_length((i+1)+".00",5)+" "+out+"\n");
  }
  write(OUTPUT_AVG+" updated.\n");
  return 1;
}

