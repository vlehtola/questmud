/* new score command // Celtron */
// Some changes by Nalle. March 2004. Also Apr 2004.

#include <ansi.h>

#define LEADER_D        "/daemons/leader_d"
#define BANK_D          "/room/bank_d"
#define EXPLORE_D       "/daemons/explore_d"
#define MULTIGUILD_D    "/daemons/multiguild_d"
#define MAILCOMMAND     "/cmds/std/_mail"

#define THICKBAR "+==========================================================================+\n"
#define THINBAR  "+--------------------------------------------------------------------------+\n"


cmd_score(string str) {
  string result, *secondary;
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
  result = sprintf(THICKBAR);
  race = ob->query_race();
  if(!race) race = "none";

  if( this_player()->query_terminal() )
   result += " " + capitalize(ob->query_real_name()) + ". You are a level " + BOLD + ob->query_level() + OFF +" " + capitalize(race) +"\n";
    else
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
 if(strlen(ob->query_married())) 
  {
   sscanf(ob->query_married(),"%d %s",tmp,married);
   result += sprintf(" You are married with %1s.", married);
  } 

 /* // Commented by nalle, march 2004.
   else 
  { result += sprintf(" You are married to no one."); }
  */

result += sprintf( "\n"+ THINBAR );
result += sprintf(" Xprate: %1d QuestPoints: %1d(%1d) TaskPoints: %1d(%1d)", ob->query_exp_rate(), ob->query_quest_points(), ob->query_max_quest_points(), ob->query_task_points(), ob->query_max_task_points());

 // Maxlevel shown for mortals. -Nalle 12.03.2004 
 if(!ob->query_wiz()) 
    result += " Maximum level: " + ob->query_max_level()+"\n";
     else
    result += "\n";
/*
result += sprintf(" Hp: %1s(%1d) Sp: %1s(%1d) Ep: %1s(%1d)\n", ob->get_color("hp"), ob->query_max_hp(), ob->get_color("sp"), ob->query_max_sp(), ob->get_color("ep"), ob->query_max_ep());
result += sprintf(" Strength: %1d Dexterity: %1d Constitution: %1d\n", ob->query_str(), ob->query_dex(), ob->query_con());
result += sprintf(" Intelligence: %1d Wisdom: %1d Size: %1d\n", ob->query_int(), ob->query_wis(), ob->query_size());
*/

result += sprintf(" Hp: %1s(%1d) Sp: %1s(%1d) Ep: %1s(%1d)\n", to_string(ob->get_color("hp")),
        ob->query_max_hp(), to_string(ob->get_color("sp")), ob->query_max_sp(),
        to_string(ob->get_color("ep")), ob->query_max_ep());
result += sprintf(" Strength: %1d Dexterity: %1d Constitution: %1d\n", ob->query_str(), ob->query_dex(), ob->query_con());
result += sprintf(" Intelligence: %1d Wisdom: %1d Size: %1d\n", ob->query_int(), ob->query_wis(), ob->query_size());


result+= sprintf( THINBAR );

// Multiguildcode by Celtron 17.01.2004
// If starter_guild is a string the char must be fixed -- Rag 4.10.2005
if(ob->query_multiguild()) {
  result+= sprintf(" Primary guild: %1s\n",ob->query_multiguild());
  secondary = MULTIGUILD_D->secondary_guilds(ob->query_multiguild());
  result+= sprintf(" Secondary guilds: %1s and %1s\n", secondary[0], secondary[1]);
} else if(!ob->query_starter_guild() || stringp(ob->query_starter_guild())) {
  result += sprintf("Type fixme to correct a guild issued problem.\n");
} else {
  result += sprintf(" Primary guild: %1s\n",ob->query_starter_guild()[0]);
  result+= sprintf(" Secondary guilds: none\n");
}  

result+= sprintf( THINBAR );

result += sprintf(" You have %1s points of free experience.\n", free_exp_str);
result += sprintf(" You have %1d bronze coins", ob->query_money(3));
result += sprintf(" and %1d bronze on your bank account.\n", BANK_D->query_money(3));
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

result+= sprintf( THINBAR );

result += sprintf(" You are considered as a creature of "+t+" alignment.\n");

  if(ob->query_hunger()*3 < ob->query_max_hunger()) {
result += sprintf(" You are in need of food.\n");
  }
  if(ob->query_thirst()*6 < ob->query_max_thirst()) {
result += sprintf(" You are in need of water.\n");
  }

result += sprintf(" Your age is %1s", age);

 if(ob->query_created())
   {
    result += " and were created on ";

    if( ctime(ob->query_created())[8..8] == " ")
        result += ctime(ob->query_created())[9..9] + ". ";
         else
        result += ctime(ob->query_created())[8..9] + ". ";

        result += convert_to_month(ctime(ob->query_created())[4..6]) + 
                " "+ctime(ob->query_created())[20..24]+".\n";
   }
   else
   {
    result += ". You were created before 2004.\n";
   }


//result += sprintf(" You have explored %1d rooms.\n", EXPLORE_D->explored_rooms(ob) );
result += sprintf(" You last reincarnated %1s ago.\n", last_reinc);
  if (ob->query_wimpy())
result += sprintf(" Wimpy mode.");
  else
result += sprintf(" Brave mode.");

 if( MAILCOMMAND->has_new_mail() )
     result += " You have unread mail.";

 result += "\n";

  if(ob->query_invisible())
  result += sprintf(" You are invisible!\n");
  result += sprintf( THICKBAR );
write(result);
  return 1;
}

/*************************************************************************/
// -N

string convert_to_month(string str)
{
 switch(str)
 {
  case "Jan" : return "January";
  case "Feb" : return "February";
  case "Mar" : return "March";
  case "Apr" : return "April";
  case "May" : return "May";
  case "Jun" : return "June";
  case "Jul" : return "July";
  case "Sep" : return "September";
  case "Oct" : return "October";
  case "Nov" : return "November";
  case "Dec" : return "December";
  default : return "";
 }
}
