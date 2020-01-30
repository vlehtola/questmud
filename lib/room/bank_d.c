#define SAVEFILE "/data/bank/"+this_player()->query_real_name()
int tin;
string action_history;

query_action_history() {
  string *temp, new_actions;
  int i;
  if(!restore_object(SAVEFILE)) return 0;
  temp = explode(action_history, ":");
  for(i=0; i < 10 && i < sizeof(temp); i++) {
    if(temp[i] && temp[i] != "0")
        new_actions += ":"+temp[i];
  }
  action_history = new_actions;
  save_object(SAVEFILE);
  return action_history;
}

query_money(type) {
  if(file_size(SAVEFILE+".o") != -1) {
    restore_object(SAVEFILE);
    return call_other("/obj/new_money", "query_real_value",type,1,tin);
  }
  return 0;
}

save_account(string str) {

  if("/obj/player"->query_no_savemode()) {
    write("No save mode. Bank balance not altered.\n");
    return 0;
  }
  if(!str) save_object(SAVEFILE);
  else save_object(str);
  return 1;
}

add_money(int num, int type) {
  int i;
  if(file_size(SAVEFILE+".o") != -1) restore_object(SAVEFILE);
  else tin = 0;
  if(num) {
    i = call_other("/obj/new_money", "query_real_value",1,type,num);
    tin += i;
  }
  if(tin>0)
    action_history += ":deposit of "+(i/100)+" bronzes";
  else
    action_history += ":withdraw/transfer of "+(-i/100)+" bronzes";

  this_player()->add_money_summary(i);
  save_account();
  return tin;
}

// A hard set, do not use in normal code
set_money(int num, string plr)
{
 if(!num || !plr) return 0;
 
 if(file_size("/data/bank/"+plr+".o") != -1) restore_object("/data/bank/"+plr);

 tin = num;

 save_object( "/data/bank/"+plr );
 return 1;
}

add_other_money(int num, int type, string who) {
  object ob;
  int i;
  tin = 0;
  if(file_size("/data/bank/"+who+".o") != -1) restore_object("/data/bank/"+who);
  i = num * 100;
  tin += i;
  action_history = action_history + ":transfer of "+(i/100)+" bronzes from "+this_player()->query_name();
  
  ob = find_player(lower_case(who));
  if(ob) { ob->add_money_summary(i); }
  save_account("/data/bank/"+who);
  tin = 0;
}
