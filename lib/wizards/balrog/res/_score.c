/* new score command // Celtron */

#define LEADER_D "/daemons/leader_d"
#define BANK_D "/room/bank_d"
#define EXPLORE_D "/daemons/explore_d"

cmd_score(string str) {
  string result;
  object ob;
  string race;
  string t;
  string married, tmp, free_exp_str;
  string age;
  string last_reinc;
  if(str && this_player()->query_wiz()) ob = find_player(str);
  if(!ob) ob = this_player();
  if (ob->query_ghost()) {
        write("You are in an immaterial state with no scores.\n");
        return 1;
  }
  if (!ob->check_condis()) { return 1; }

  free_exp_str=ob->query_free_exp(); // KLUDGE
  if(!free_exp_str || strlen(free_exp_str)<1) free_exp_str="0";

  age = call_other("/obj/timer", "stime", ob->query_age()*2);
  last_reinc = call_other("/obj/timer", "stime", time() - ob->query_last_reinc_time());
  result = sprintf("+=================================================================+\n");
  race = ob->query_race();
  if(!race) race = "none";
  result += sprintf(" %1s. You are a level %1d %1s\n", capitalize(ob->query_real_name()), ob->query_level(), capitalize(race));
  if(ob->query_race()) {
  if(LEADER_D->query_leader() == lower_case(ob->query_real_name())) {
  result += sprintf(" Your race is lead by you.");
} else if(LEADER_D->query_leader() == 0) {
  result += sprintf(" %1s race has no leader.", capitalize(race));
} else {
  result += sprintf(" %1s leads the %1s race.", capitalize(LEADER_D->query_leader()), ob->query_race());
}
}
if(strlen(ob->query_married())) {
sscanf(ob->query_married(),"%d %s",tmp,married);
result += sprintf(" You are married with %1s.", married);
} else { result += sprintf(" You are married to no one."); }
result+= sprintf("\n+-----------------------------------------------------------------+\n");
result += sprintf(" Xprate: %1d QuestPoints: %1d(%1d) TaskPoints: %1d(%1d)\n", ob->query_exp_rate(), ob->query_quest_points(), ob->query_max_quest_points(), ob->query_task_points(), ob->query_max_task_points());
result += sprintf(" Hp: %1d(%1d) Sp: %1d(%1d) Ep: %1d(%1d)\n", ob->query_hp(), ob->query_max_hp(), ob->query_sp(), ob->query_max_sp(), ob->query_ep(), ob->query_max_ep());
result += sprintf(" Strength: %1d Dexterity: %1d Constitution: %1d\n", ob->query_str(), ob->query_dex(), ob->query_con());
result += sprintf(" Intelligence: %1d Wisdom: %1d Size: %1d\n", ob->query_int(), ob->query_wis(), ob->query_size());
result+= sprintf("+-----------------------------------------------------------------+\n");
result += sprintf(" You have %1s points of free experience.\n", free_exp_str);
result += sprintf(" You have %1d bronze coins\n", ob->query_money(3));
result += sprintf(" You have %1d bronze coins in bank.\n", BANK_D->query_money(3));
  switch(ob->query_alignment()) {
    case 100..300:
        t = "an extremely good";
        break;
    case 50..99:
        t = "a good";
        break;
    case 10..49:
        t = "a slightly good";
        break;
    case -9..9:
        t = "a neutral";
        break;
    case -49..-10:
        t = "a slightly evil";
        break;
    case -99..-50:
        t = "an evil";
        break;
    case -300..-100:
        t = "an extremely evil";
        break;
    default:
  }
result+= sprintf("+-----------------------------------------------------------------+\n");
result += sprintf(" You are considered as a creature of "+t+" alignment.\n");

  if(ob->query_hunger()*3 < ob->query_max_hunger()) {
result += sprintf(" You are in need of food.\n");
  }
  if(ob->query_thirst()*6 < ob->query_max_thirst()) {
result += sprintf(" You are in need of water.\n");
  }
result += sprintf(" Your age is %1s.\n", age);
//result += sprintf(" You have explored %1d rooms.\n", EXPLORE_D->explored_rooms(ob) );
result += sprintf(" You last reincarnated %1s ago.\n", last_reinc);
  if (ob->query_wimpy())
result += sprintf(" Wimpy mode.\n");
  else
result += sprintf(" Brave mode.\n");

  if(ob->query_invisible())
  result += sprintf(" You are invisible!\n");
  result += sprintf("+=================================================================+\n");
write(result);
  return 1;
}

