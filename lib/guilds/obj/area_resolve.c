#define MASTERY_D "/daemons/mastery_d"
#define STORM_DAMAGE_CAP 30000  // 20k by C

resolve(dama, type, word1, word2) {
  object ob, next_ob, p_ob, *mast_ob;
  string target_list, last_target;
  int damage, high, i, lvl;
  target_list = "";
  last_target = "";
  write("You invoke the elemental forces to clear the path before you.\n");
  if (this_player()->query_tester()) {
        write("Daman pitas olla:"+dama+"\n");
  }
  p_ob = this_player()->query_party();
  if (this_player()->query_tester() && p_ob) {
        write("Party found..\n");
  }

  lvl = 0;
  i = 0;
  mast_ob = all_inventory(environment(this_player()));
  while(i < sizeof(mast_ob)) {
        if(mast_ob[i]->query_npc()) {
                if(mast_ob[i]->query_level() > lvl) {
                        high = i;
			lvl = mast_ob[i]->query_level();
                }
        }
        i++;
  }
  MASTERY_D->mastery("Offensive spellcasting",this_player(),mast_ob[high]);
  MASTERY_D->mastery("Dangerous "+word1,this_player(),mast_ob[high]);

  dama += dama * MASTERY_D->mastery("Offensive spellcasting",this_player(),mast_ob[high]) / 200;
  dama += dama * MASTERY_D->mastery("Dangerous "+word1,this_player(),mast_ob[high]) / 200;


  // damage cap to storm by Celtron 021004
  if(dama > STORM_DAMAGE_CAP) {
    write("You feel like your spell has reached it's maximal power capacity.\n");
    dama = STORM_DAMAGE_CAP;
  }

  ob = first_inventory(environment(this_player()));
  while(ob) {
    next_ob = next_inventory(ob);
    if (last_target != "") {
        if (!next_ob) {
          target_list = target_list + " and ";
        } else if (target_list != "") {
            target_list = target_list + ", "; 
        }
        target_list = target_list + last_target;
    }
    last_target = "";
    if (living(ob) && ob != this_player()) {
      if (p_ob && p_ob->is_member(ob) || this_player()->query_npc() && ob->query_npc()) {
      } else {
        last_target = ob->query_name();
        if (this_player()->query_tester()) {
                write("Hitting:"+ob->query_name()+"\n");
        }
        tell_object(ob, this_player()->query_name()+
          " hits you with a "+word1+" "+word2+"!\n");
        this_player()->attack_object(ob, 1);
        ob->hit_with_spell(dama, type);
      }
    }
    ob = next_ob;
  }
  if ( target_list == "" && last_target == "" ) {
    target_list = "nothing";
  }
  /*if (target_list != "" && last_target != "") {
     target_list = target_list+" and "+last_target;
  } else if (last_target != "") {
     target_list = last_target;
  }*/
  write("You hit "+target_list+" with your "+word1+" "+word2+".\n");
}
