/* num must be seconds */
int uptime, time_to_change, time_of_day, light, time_to_log;
int shutting, time_to_shut, chance;

reset(arg) {
  if (arg) { return; }
  time_to_change = 3600 * 2;
  time_of_day = 1;
  light = 3;
  tic();
}

static tic() {
  uptime += 2;
  time_to_log += 2;
  if(time_to_log >= 3*3600) { /* 3h vali */
    log_file("TIMER_LOG", ctime(time())+" Online: "+stime(uptime)+".\n");
    time_to_log = 0;
  }
  time_to_change -= 2;
  if (time_to_change <= 0) {
	change_day_time();
  }
  if(shutting) {
	time_to_shut += 2;
	chance -= 2;
	if (!random(chance)) {
	   shout("A voice booms '"+stime(1800-time_to_shut)+" to Reboot'\n");
	   if (time_to_shut > 1600) {
		chance = 30;
	   } else {
	        chance = 120;
	   }
	}
	if (time_to_shut >= 1800) {
	   reboot();
	   return 1;
	}
  }
  // initiate boot process, if uptime > 1h and time ~ 6am
  if(!shutting && ctime(time())[11..12] == "06" && uptime > 3600) {
    shout("A voice booms 'Reboot in half an hour!'\n");
    shutting = 1;
  }
  call_out("tic", 2);
}

quick_boot() {
  if(this_player()->query_wiz() < 3) return 0;
  shutting = 1;
  uptime = 3600*24-60*30;
  shout("A voice booms 'REBOOT incoming in 30 minutes!'\n");
}

static reboot() {
   object ob, list;
   int i;
   shout("A voice booms 'REBOOTING NOW!'\n");
   ob = first_inventory("/world/special/ldroom");
/*
   //Changed by Celtron 26092007 to save eq
   while(ob) {
	ob->save_me(0); 
	ob = next_inventory(ob);
   }
   list = users();
   while(i<sizeof(list)) {
      list[i]->save_me(0); 
      i += 1;
   }
*/
   shutdown();
   log_file("TIMER_LOG", ctime(time())+ " Shutdown failed.\n");
}



change_day_time() {
  string str;
  object list;
  int i;
  time_of_day += 1;
  /*    1, midday
	2, evening
	3, midnight
	4, night
	5, morning
  */
  if (time_of_day == 2) {
     str = "The sun starts to slowly drop beyond the horizon.\n";
     light = 2;
     time_to_change = 600;
  }
  if (time_of_day == 3) {
     str = "The sun sets.\n";
     light = 1;
     time_to_change = 3000 * 2;
  }
  if (time_of_day == 4) {
     str = "The sun starts to rise.\n";
     light = 2;
     time_to_change = 600;
  }
  if (time_of_day == 5) {
     str = "The sun rises from the east, breaking in to a new day.\n";
     time_of_day = 1;
     light = 3;
     time_to_change = 4600 * 2;
  }
  list = users();
  if (!list) { return; }
  while (i < sizeof(list)) {
    if (list[i] && environment(list[i]) &&
	   !environment(list[i])->query_not_out()) {
	tell_object(list[i], str);
    }
    i += 1;
  }
}

query_time(arg) {
  return stime(uptime);
}

query_int_to_boot() {
  return (3600*24-uptime);
}
query_time_to_boot(arg) {
  if (arg) { return (3600*24-uptime); }
  return stime(3600*24-uptime);
}

query_shutting() {
  return shutting;
}

string stime(int i) {
  string str; str = "";
  if(i/86400) {
    str+=i/86400+"d ";
    i -= (i/86400)*86400;
  }
  if(i/3600) {
    str+=i/3600+"h ";
    i -= (i/3600)*3600;
  }
  if(i/60) {
    str+=i/60+"m ";
    i -= (i/60)*60;
  }
  str+=i+"s";
  return str;
}

get_light_time() {
  return light;
}

query_time_of_day() {
  return time_of_day;
}

get_time_of_day() {
  return time_of_day;
}
