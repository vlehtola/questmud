/* modified by Celtron 3.5.2004
   target argument can be given by wizards to display mortal's skills.
*/

#include "/sys/ansi.h"

#define REBIRTH_SKILLS_BONUS    10
#define SKILL_LEARN_D   "/daemons/skill_learn_d"

cmd_skills(arg) {
  string tmp, name;
  object ob;

  if(!arg) {
    skills();
    write("Try: 'help skills' for more info.\n");
    return 1;    
  }
  if(this_player()->query_wiz()) {
    if(sscanf(arg, "%s %s", tmp, name) == 2) {
      arg = tmp;
      ob = find_player(name);
    } else {
      ob = find_player(arg);
      if(ob) return skills(0,ob);
    }
  }

  if(arg == "adjectives") {
    list_adjectives();
    return 1;
  }
  if(arg == "magic") { skills(3,ob); return 1; }
  if(arg == "combat") { skills(2,ob); return 1; } 
  if(arg == "general") { skills(1,ob); return 1; } 
  if(arg == "casting") { skills(4,ob); return 1; } 
  write("Try: 'help skills' for more info.\n");
  return 1;
}


skills(int arg, object ob) {
    int i, skill_pros, end_line;
    string skill_name, pros_space;
    string temp,temp2, spaces, alt;
    mapping skills, learn;
    if (!this_player()->check_condis()) { return 1; }
    if(!ob) ob = this_player();
    skills = ob->query_skill_map();
    learn = ob->query_learn_map();
    if (!skills) {
        write("You don't know any skills.\n");
        return 1;
    }
    spaces = "                                 ";
    temp = m_values(skills);
    temp2 = m_indices(skills);
    temp2 = call_other("/daemons/alpha","alpha",skills);

// mod by C. 20.6.2004, take learn map into account when displaying

    while(i<sizeof(temp2)) {
      temp[i] = skills[temp2[i]] + to_int(sqrt(to_float(learn[temp2[i]]) / 5000));

// value = to_int(sqrt(to_float(value) / 5000));

      if(temp[i] < 100 && ob->query_rebirth()) {
        temp[i] += REBIRTH_SKILLS_BONUS;
      }
      if(temp[i] > 100) temp[i] = 100;
      i += 1;
    }
    i = 0;   
    write("\n");

write("+-----------------------------------+-----------------------------------+\n");
write("|Skills:                   Knowledge|Skills:                   Knowledge|\n");
write("+-----------------------------------+-----------------------------------+\n");
    while(i < sizeof(temp)) {

      if(!arg || call_other("/guilds/obj/skillfun", "skill_costs",temp2[i],0,0,1) == arg) {
        write("|"+capitalize(temp2[i])+extract(spaces,0,23-strlen(temp2[i])));
        alt = call_other("/guilds/obj/skillpros.c", "pros_names", temp[i]);
        if(SKILL_LEARN_D->skill_value(temp2[i], learn) && ob->query_terminal())
                alt = BOLD + alt + OFF;
        write(alt);
        end_line += 1;
      }
      if(end_line == 2) { write("|\n"); end_line = 0; }
      i += 1;
    }
    if(end_line == 1) { write("|                                   |\n"); }

write("+-----------------------------------+-----------------------------------+\n");
    return 1;
}

list_adjectives() {
  int i;
  i = 1;
  write("\n");
  while (i < 51) {
    write("  "+call_other("/guilds/obj/skillpros", "pros_names", i));
    write("      "+call_other("/guilds/obj/skillpros", "pros_names", i+50)+"\n");
    i += 5;
  }
  write("                   "+call_other("/guilds/obj/skillpros","pros_names",100)+"\n");
}

jees() {
  int i;
  i = 1;
  write("\n");
  while (i < 101) {
    write(call_other("/guilds/obj/skillpros", "pros_names", i));
    if(i /4*4 == i)
      write("\n");
    else  
      write("\t");
    i += 5;
  }
  write(call_other("/guilds/obj/skillpros", "pros_names", 100)+"\n");
}
