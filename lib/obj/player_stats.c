#define SPR_MAX_LEVEL	90
#define HP_CAP 10000  //raised from 3k to 4k by Celtron 26.4.2004. raised to 10k 01.10.08 //C
#define SP_CAP 10000  // 3k -> 10k by C 01.10.08
#define REBIRTH_REGEN_BONUS	35  // percents
#define REBIRTH_HPSP_BONUS 2000 // Bonus to CAP for 3rd rebirth -- Rag 3.5.2004

// Added the lines with cap 3000 //C 01.10.08

resolve_bonuses(string level_bonus) {
    int bonus;
    string arg;
    if(this_player()->query_wiz())
	write("LEVEL_BONUS: "+level_bonus+"\n");
    if(!level_bonus) return 0;
    while(sscanf(level_bonus, "%s %d , %s",arg, bonus, level_bonus) == 3) {
      if(this_player()->query_wiz())
        write("BONUS: "+arg+" "+bonus+" REMAINS: "+level_bonus+"\n");
    }
    if (sscanf(level_bonus, "%s %d , ",arg, bonus) == 2) {
      if(this_player()->query_wiz())
        write("BONUS: "+arg+" "+bonus+" DONE\n");
    }
}

update_points(object ob) {
  int max_ep, max_hp, max_sp, cap;

  // Changed multiplier from 8-> 7 by Celtron 01.10.08
  max_hp = ob->query_con()*8 + ob->query_size()*3/2;
  max_hp -= (max_hp * ob->query_death_legacy_time() / (ob->query_max_death_legacy_time()+1)) *6/10;

//Changed multiplier from 3/4 -> 4/3 by Kaappi 9.10.08
   if(max_hp > 3000) max_hp = 3000 + (max_hp - 3000)*4/3;
  
  //Bonus for 3rd rebirth -- Rag 3.5.2004
  if ( ob->query_rebirth() > 2 ) {
    cap = HP_CAP + REBIRTH_HPSP_BONUS;
  } else {
    cap = HP_CAP;
  }
  if(max_hp > cap) max_hp = cap + (max_hp - cap)/4;
  ob->set_max_hp(max_hp);

  //Bonus here also
  if ( ob->query_rebirth() > 2 ) {
    cap = SP_CAP + REBIRTH_HPSP_BONUS;
  } else {
    cap = SP_CAP;
  }

//Changed multipliers from 7 -> 6 by Kaappi 9.10.08
  max_sp = ob->query_int()*6 + ob->query_wis()*6;

  if(max_sp > 3000) max_sp = 3000 + (max_sp - 3000)*3/4;

  if(max_sp > cap) max_sp = cap + (max_sp - cap)/4;
  ob->set_max_sp(max_sp);

  max_ep = ob->query_con()*2 + ob->query_dex() + 50;
  if(max_ep > 300) max_ep = 300 + (max_ep-300)/4;
  //Another bonus for 3rd rebirth
  if(max_ep > 450 && ob->query_rebirth() < 3) max_ep = 450 + (max_ep-450)/2;
  ob->set_max_ep(max_ep);
  return 1;
}

modify_stat(int stat) {
  return stat;
}

  /* base regen [1,20] * (5 + level/10 [0,6]) = */
get_hp_regen(int base,int level) {
  int hpr;
  hpr = 50 + level;
  if(level > 60) hpr = 50 + 60; 
  hpr = (base * hpr) /200;

  if(previous_object()->query_rebirth())
    hpr += hpr * REBIRTH_REGEN_BONUS / 100;
  return hpr;
}

//players in party in same room get bonus
int mental_unity_percent(object player, int sp_regen) {
  object *ob, party;
  int total_skill, i, valid;
  party = player->query_party();
  if(!party) return 0;
  ob = all_inventory(environment(player));
  for(i=0; i < sizeof(ob); i++) {
    if(party->is_member(ob[i]) && ob[i]->query_skills("mental unity")) {
      total_skill += ob[i]->query_skills("mental unity");
      valid += 1;
    }
  }
  // must have 2 or more players with the skill to benefit
  if(valid < 2 || !total_skill) return 0;

  tell_object(player, "You draw power from the mental unity.\n");
  // limits: 350sp or 2,5x regen. whichever is lower.
  if(sp_regen*total_skill/200 > 350)
    total_skill = 350*200/sp_regen;
  if(total_skill > 250) total_skill = 250;
  return total_skill;
}

/* base = [30,200], caster base = [150,200] */
/* lv 10: 70 spr, lv 50: 250 spr, lv 100: 400 spr */
get_sp_regen(int base,int level) {
  int spr, i, lev;
  i = allocate(11);
  i[0] = 60;
  i[1] = 80;
  i[2] = 100;
  i[3] = 140;
  i[4] = 170;
  i[5] = 200;
  i[6] = 230;
  i[7] = 260;
  i[8] = 280;
  i[9] = 290;
  i[10] = 300;

  if(level > SPR_MAX_LEVEL) {
    lev = level - SPR_MAX_LEVEL;
    level = SPR_MAX_LEVEL;
  }
  // paloittain lineaarisesti jatkuva regen
  // level 60 -> regen 250
  spr = i[level/10] + (i[level/10+1] - i[level/10]) * (level - (level/10*10)) /10;
  spr += lev/10;
  spr = spr * base / 200;
  
  if(previous_object()->query_rebirth())
    spr += spr * REBIRTH_REGEN_BONUS / 100;
  return spr;
}

  /* epr = [0.2, 0.4] * max_ep */
get_ep_regen(int base,int level) {
  int epr;
  epr = previous_object()->query_max_ep();
  if(epr > 100) epr = 100 + (epr - 100) / 20;
  epr = epr * (base+20) / (20*5);

  if(previous_object()->query_rebirth())
    epr += epr * REBIRTH_REGEN_BONUS / 100;
  return epr;
}   

