show_quests(ob) {
  write("\n");
  write(ob->query_name()+"'s quests:\n");
  if(ob->query_quests()) write(ob->query_quests()+"\n");
  else write("None completed.\n");
  write(ob->query_name()+"'s reinc quests:\n");
  if(ob->query_quests(-1)) write(ob->query_quests(-1)+"\n");
  else write("None completed.\n");
  write("Questpoints: "+ob->query_quest_points()+"("+ob->query_max_quest_points()+")\n");
}

show_stats(ob) {
  string tmp0,tmp1,tmp2,exp;
  tmp2 = "                                                                   ";
  tmp0 = "+-----------------------------------------------------------------+";
  tmp1 = "| "+ob->short()+"  (Name: "+ob->query_name()+")";
  write(tmp0+"\n");
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  write("| "+file_name(ob)+"\n");
  write(tmp0+"\n");
  if(ob->query_npc()) exp = ob->query_exp();
  else exp = ob->query_free_exp();
  tmp1 = "| Level: "+ob->query_level()+" Exp: "+exp+" Totals: "+ob->query_total_string();
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Wiz: "+ob->query_wiz()+" Tester: "+ob->query_tester()+
    " Dead: "+ob->query_dead()+" Death: "+ob->query_death()+
    " QP: "+ob->query_quest_points()+"("+ob->query_max_quest_points()+") TP: "+ob->query_task_points()+
    "("+ob->query_max_task_points()+")";
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| ";
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Hp: "+ob->query_hp()+"("+ob->query_max_hp()+") Sp: "+ob->query_sp()+"("+ob->query_max_sp()+") "+
        "Ep: "+ob->query_ep()+"("+ob->query_max_ep()+")";
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Str: "+ob->query_str()+" Dex: "+ob->query_dex()+" Con: "+ob->query_con()+
    " Int: "+ob->query_int()+" Wis: "+ob->query_wis()+" Size: "+ob->query_size();
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  if(ob->query_npc()) {
    tmp1 = "| (Monster) Regen: "+ob->query_regen();
    write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  } else {
    tmp1 = "| Hpregen: "+ob->query_hp_regen()+" Spregen: "+ob->query_sp_regen()+" Epregen: "+ob->query_ep_regen();
    write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  }
  tmp1 = "| ";
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Gender: "+ob->query_pronoun()+" ("+ob->query_gender()+") Alignment: "+ob->query_alignment();
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "| Weapon class: "+ob->query_wc()+" Carry: "+
        ob->query_local_weight()+ " ("+(ob->query_local_weight()/100)+" kg)";
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  tmp1 = "";
  if(ob->query_name_of_right_weapon()) {
    tmp1 = "| Right weapon: "+ob->query_name_of_right_weapon()+"  Wc: "+
      ob->query_right_weapon()->query_wc()+" Weight: "+ob->query_right_weapon()->query_weight();
    write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  } 
  if(ob->query_name_of_left_weapon()) {
    tmp1 = "| Left weapon: "+ob->query_name_of_left_weapon()+"  Wc: "+
      ob->query_left_weapon()->query_wc()+" Weight: "+ob->query_left_weapon()->query_weight();
    write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  }  
  if(ob->query_attack()) {
    tmp1 = "| Attacker_ob: "+ob->query_attack()->short()+" (Name: "+ob->query_attack()->query_name()+")";
    write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  }
  tmp1 = "| Age: "+find_object("/obj/player")->stime(ob->query_age()*2);
  write(tmp1+extract(tmp2,0,strlen(tmp0)-2-strlen(tmp1))+"|\n");
  write(tmp0+"\n");
}

help() {
write("Syntax: stat <name> [skills | resists | quests]\n\n");
write("Without arguments stat shows some general information about the target.\n");
write("The target can be either a player or a monster.\n");
write("Any ideas, bugs must be reported to Celtron.\n");
}

cmd_stat(name) {
    object ob;
    int show_resists,show_skills,i;
    string it, pref;
    if(!this_player()->query_wiz()) return;
    if (!name || name == "help") {
        help();
        return 1;
    }
    if (sscanf(name, "%s resists", name)) {
        show_resists = 1;
    }
    if(sscanf(name,"%s skills",name)) {
        show_skills = 1;
    }
    if(sscanf(name,"%s quests",name)) {
        show_skills = 2;
    }
    it = lower_case(name);
    ob = present(name, environment(this_player()));
    if (!ob || !living(ob))
        ob = find_living(it);
    if (!ob) {
        write("No such person is playing now.\n");
        return 1;
    }
    if (show_resists) {
        while(i < 8) {
           pref = "/obj/resists"->resist_names(i);
           write(pref+ ":" + ob->query_resists(pref));
           if(i == i/2*2) write("\n");
           else write("    ");
           i += 1;
        }
        return 1;
    }
    if(show_skills == 2) {
      show_quests(ob);
      return 1;
    }
    if(show_skills) {
      skills(ob);
      return 1;
    }
    show_stats(ob);
    return 1;
}
skills(str) {
    int i, skill_pros;
    string skill_name, pros_space;
    string temp,temp2, spaces;
    mapping skills;
    spaces = "                                 ";
    skills = str->query_skill_map();
    temp = m_values(skills);
    temp2 = m_indices(skills);
    write("\n");
    write("+----------------------------------+----------------------------------+\n");
    write("|Skills:                          %|Skills:                          %|\n");
    write("+----------------------------------+----------------------------------+\n");
    while(i < sizeof(temp)) {
      write("|"+capitalize(temp2[i])+extract(spaces,0,29-strlen(temp2[i]))+
        str->query_skills(temp2[i])+" ");
      if(i+1<sizeof(temp))
        write("|"+capitalize(temp2[i+1])+extract(spaces,0,29-strlen(temp2[i+1]))+
        str->query_skills(temp2[i+1])+" |\n");
      else
        write("|                                  |\n");
      i += 2;
    }
    write("+----------------------------------+----------------------------------+\n");
    return 1;
}

