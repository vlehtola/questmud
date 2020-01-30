#define BASE_HIT_DAMAGE                 10

int c_str, c_dex, c_con, is_npc, number_of_hits, bonus, defence_bonus;
object attacker;
object attacker_ob, alt_attacker_ob;
object name_of_weapon, name_of_right_weapon, name_of_left_weapon;
string cap_name, aname, dname;
string hit_slot;

query_npc() { return is_npc; }
get_weapon_skill(arg) {
  int i;
  if(arg->query_warlock_weapon()) {
  i = attacker->query_skills("chaos "+arg->query_type()+"s") + attacker->query_skills("attack")/3;
  } else if(!arg->query_warlock_weapon()) {
  i = attacker->query_skills(arg->query_type()+"s") + attacker->query_skills("attack")/3;
  }
  if(i > 100) i = 100;
  return i;
}
query_combat_tactic() {
  int i;
  i = random(3)+1;
  switch(i) {
  case 1 : return "head";
  case 2 : return "torso";
  case 3 : return "legs";
  }
}

/* return 1 if fight continues, 0 if enemy dies */
status hit_enemy(int damage, string pref, object hitter) {
  object def;
  if(hitter == attacker) def = attacker_ob;
  else def = attacker;

  if(damage > 400) damage = 400 + (damage-400)/2;
  def->hit_player(damage, pref, hitter);
  if(def->query_hp() < 1) def->death();
  if(!def) {
    destruct(this_object()); /* fight ends */
    return 0;
  }
  return 1;
}

combat_preparation(object ob, int hit) {
  if(!ob) {
    write("No attacker.. combat halted.\n");
    return;
  }
  attacker = ob;
  if(!attacker->query_attack()) return 0;
  is_npc = ob->query_npc();
  aname = ob->query_name();
  attacker_ob = ob->query_attack();
  dname = attacker_ob->query_name();
  alt_attacker_ob = ob->query_alt_attacker();
  c_str = ob->query_str();
  c_dex = ob->query_dex();
  c_con = ob->query_con();
  name_of_right_weapon = ob->query_right_weapon();
  name_of_left_weapon = ob->query_left_weapon();
  name_of_weapon = 0;
  bonus = 0;
  if(hit < 2) {
    if(name_of_right_weapon)
      name_of_weapon = name_of_right_weapon;
  } else {
    if(name_of_left_weapon)
      name_of_weapon = name_of_left_weapon;
  }
  number_of_hits = allocate(4);
  hit_slot = "no hit_slot defined";
  return 1;
}

static ep_effect(int i, object ob) {
  int ep,max_ep;
  if(ob->query_npc() && !ob->query_demon()) return i;
  i = i/2 + (i*100 *ob->query_ep() / (85*ob->query_max_ep()+1)) /2;
  return i;
}

display_combat_messages(object at, object at_ob) {
  int i, ii, direction, rand,tmp2;
  string str, dest_dir, tmp;
  attacker = at;
  aname = at->query_name();
  dname = at_ob->query_name();
  if(!attacker) return;
  if (at_ob && present(at_ob,environment(at))) {
    tell_room(environment(at), aname+" is in vigorous combat with "+dname+".\n", ({at,at_ob}));
  } else {
    return;
  }
  return; /* bugi pois */
  if (random(5) != 0) return;
  dest_dir = environment(attacker)->query_dest_dir();
  while(i < sizeof(dest_dir)) {
    call_other(dest_dir[i], "???");
    if(dest_dir && dest_dir[i] && sscanf(dest_dir[i], "out: %d %d",ii,tmp2) != 2) {
      if (stringp(dest_dir[i]) && call_other(dest_dir[i],"query_room_file")) {
        if(dest_dir[i]->query_dir(file_name(environment(attacker)))) {
          direction = dest_dir[i]->query_dir(file_name(environment(attacker)));
          if (direction) {
            rand = random(5);
            if (rand == 0) {
		str = "You hear sounds of combat from the " + direction + ".\n";
            } else if (rand == 1) {
		str = "You hear weapons clashing in the " + direction + ".\n";
            } else if (rand == 2) {
		str = "You hear weapon hitting against armour in the " + direction + ".\n";
            } else if (rand == 3) {
		str = "You hear curses and shouts of pain from the " + direction + ".\n";
            } else if (rand == 4) {
		str = "You hear sounds of steel clashing from the "+direction+".\n";
            }
            tell_room(dest_dir[i],str);
          }
        }
      }
    }
    i += 2;
  }
  attacker = 0;
  attacker_ob = 0;
}

static get_monster_hits() {
  if(!attacker->query_limb("right arm")) {
    number_of_hits[0] = 5*BASE_HIT_DAMAGE;
    if(random(attacker->query_level() - 20) >= 5) number_of_hits[2] = BASE_HIT_DAMAGE * 5;
  }
  if(!attacker->query_limb("left arm")) {
    number_of_hits[1] = 5*BASE_HIT_DAMAGE;
    if(random(attacker->query_level() - 60) >= 5) number_of_hits[3] = BASE_HIT_DAMAGE * 5;
  }
}

static get_player_hits() {
  number_of_hits[0] = BASE_HIT_DAMAGE * 10;
  if (name_of_right_weapon && attacker->query_skills("doublehit")+
	get_weapon_skill(name_of_right_weapon)+(c_dex/2) > random(300)) {
    number_of_hits[1] = BASE_HIT_DAMAGE * 4;
  }
  /* Two weapons combat */
  if (name_of_left_weapon && name_of_left_weapon->query_type() != "shield") {
    if(attacker->query_skills("two weapons combat")+c_dex/4+
        get_weapon_skill(name_of_left_weapon) > random(300))
      number_of_hits[2] = BASE_HIT_DAMAGE * 6;
  }
}

myllytys() {
  int i, direction, tmp,wepa;
  combat_preparation(previous_object());
  if(!attacker->query_attack()) return 0;
  attacker->query_attack()->attacked_by(attacker);
  if(attacker->query_npc()) get_monster_hits();
  else get_player_hits();
  if (name_of_left_weapon && name_of_left_weapon->query_type() == "shield") {
    if (attacker_ob) {
      if (attacker->query_skills("shield bash") > random((attacker_ob->query_skills("dodge")+attacker_ob->query_skills("shield bash"))*2 + 300)) {
        if(!random(3)) {
          tell_object(attacker, "You stun "+dname+" with your shield bash!\n");
          tell_object(attacker_ob, "You are stunned from the force of "+aname+"'s shield bash!\n");
   	  attacker_ob->set_stunned(2);
        } else {
          tell_object(attacker, "You bash "+dname+" with your shield!\n");
          tell_object(attacker_ob, "You are hit by "+aname+"'s shield bash!\n");
        }
        hit_enemy( random(attacker->query_str()+10) /2, 0, attacker);
      }
    }
  }
  if(attacker->query_necro_horde() && attacker_ob->query_wiz()) tell_object(attacker_ob, "horde myllytys debug\n");
  return number_of_hits;
}

attack(int power,object ob,int hi) {
  int dam,dec, damages, parry, to_hit;
  /* Combat variable factors */
  combat_preparation(ob,hi);
  if(!attacker_ob) return 0;
  if(attacker->query_ep() < 2) return 0;
  attacker->reduce_ep(1);
  /* Give the variables some values */
  to_hit = hit_chance();
  if(to_hit < random(101)) {
    tell_object(attacker, "You miss.\n");
    tell_object(attacker_ob, aname+" misses you.\n");
    return 0;
  }
  if(to_hit < 80) defence_bonus = 80 - to_hit;
  hit_slot = query_combat_tactic();
  damages = allocate(3);
  damages[0] = calculate_damage("bash") * power / 100;
  damages[1] = calculate_damage("slash") * power / 100;
  damages[2] = calculate_damage("pierce") * power / 100;
  if(!deceive_hit() && !attacker_ob->query_stun() && !attacker_ob->query_berserk()) {
   if(!attacker_ob->query_defend(1)) {
    if(attacker_ob->query_skills("foresee attack") >= random(666)) {
      tell_object(attacker, dname+" foresees your attempt and dodges your hit.\n");
      tell_object(attacker_ob, "You foresee the incoming hit and dodge it.\n");
      return 0;
    } else if(dodge_chance()*(defence_bonus+100) / 100 >= random(100)) {
      tell_object(attacker, dname+" dodges your hit.\n");
      tell_object(attacker_ob, "You nimbly dodge "+aname+"'s hit.\n");
      return 0;
    }
    parry = do_parry();
    if(parry == -1) return 0;
   } else { /* defend succesful */
     return 0;
   }
  }
  if(parry) {
    damages[0] = damages[0] * parry / 100;
    damages[1] = 0;
    damages[2] = damages[2] * parry / 200;
  }
  /* dam on nyt integer damage */
  dam = special_skills(damages);
  /* eq monsut */
  if(attacker->query_kill_log()) dam *= 2;
  display_hits(dam);
  return dam;
}

/* max success 30% */
deceive_hit() {
  int factor, anti;
  factor = attacker->query_skills("deceived attack")-10;
  if(factor < random(300)) return 0;
  anti = attacker_ob->query_skills("ignore wrong strike");
  if(anti < random(125)) {
    tell_object(attacker, "You skillfully deceive "+dname+" with your hit!\n");
    tell_object(attacker_ob, aname+" somehow deceives you!\n");
    return 1; /* success */
  } else {
    tell_object(attacker, "You try to deceive, but "+dname+" ignores it.\n");
    tell_object(attacker_ob, aname+" tries to deceive you.\n");
  }
  return 0;
}
hit_chance(object ob) {
  int chance, sk, dx, dx_bonus, lim1, lim2, hb, tw;
  object lw;
  if(ob) attacker = ob;
  lim1 = 60;
  lim2 = 200;
  lw = attacker->query_left_weapon();
  if(lw && lw->query_type() != "shield") tw = attacker->query_skills("two weapons combat") *3/2 +40;
  if(!name_of_weapon || ob) name_of_weapon = attacker->query_right_weapon();
  if(!name_of_weapon) {
    sk = attacker->query_skills("bare hands")*3+40;
  } else if(name_of_weapon && name_of_weapon->query_warlock_weapon()) {
    sk = attacker->query_skills("chaos "+name_of_weapon->query_type()+"s")*2;
    hb = name_of_weapon->query_hit_bonus(attacker->query_str());
} else if(name_of_weapon && !name_of_weapon->query_warlock_weapon()) {
	sk = attacker->query_skills(name_of_weapon->query_type()+"s")*2;
    /* hb (%). [20,140] */
    hb = name_of_weapon->query_hit_bonus(attacker->query_str());
  }
  if(hb > 140) hb = 140;
  hb += attacker->query_berserk("hit")/2;
  sk += attacker->query_skills("attack");
  /* berserkistd [10,30]/2 :: sk = [0,300] */
  dx = attacker->query_dex();
  if(dx <= lim1)
    dx_bonus = dx/4;
  else if(dx > lim1 && dx <= lim2)
    dx_bonus = lim1/4 + (dx-lim1)/8;
  else if(dx > lim2)
    dx_bonus = lim1/4 + lim2/8;
  dx_bonus += dx_bonus/2;
  /* dx_bonus [0,60] */
  /* chance = [0,300] + [0,60] + 80 = [80,440] */
  chance = sk + dx_bonus + 80;
  if(tw) {
    /* chance [ /4, *1.18 ] maxx 540 */
    chance = chance*tw/160;
  }
  chance = ep_effect(chance, attacker);
  if(attacker->query_npc()) {
    chance = (attacker->query_level()*2+50)*4;
  }
  /* hb = [20,140] + [5,15] = [25,155] */
  if(name_of_weapon) chance = hb*chance/100;
  if(chance > 360) { chance = 360 + (chance-360) / 3; }
  if(chance > 380) { chance = 380 + (chance-380) / 4; }
  if(chance > 392) { chance = 392 + (chance-392) / 10; }
  chance = chance / 4;
  return chance;
}

do_parry() {
  int shieldp, weaponp, roll, result;
  string str;
  roll = random(100)+1;
  shieldp = parry_chance(0,1);
  weaponp = parry_chance();
  if(shieldp+weaponp > 40)
    weaponp -= (shieldp+weaponp) - 40;
  if((shieldp+weaponp) * (defence_bonus+100)/100 < roll) return 0;
  if(roll > shieldp) {
    result = check_hit_through();
    if(!result && attacker_ob->query_right_weapon()) {
	str = attacker_ob->query_right_weapon()->query_name();
    }
  } else { /* parry shieldilla */
/*    str = attacker_ob->query_left_weapon()->query_name(); */
      str = "shield";
  }
  if(!str) return result;
  tell_object(attacker, dname+" parries your hit.\n");
  tell_object(attacker_ob, "You parry "+aname+"'s hit with your "+str+".\n");
  /* see if the weapon breaks or not */
  if(name_of_weapon && !random(3)) name_of_weapon->check_weapon_break();
  if(roll <= shieldp) check_riposte();
  return -1;
}

check_hit_through() {
  int st,st2;
  object shield;
  st = attacker_ob->query_str();
  st2 = attacker->query_str();
  if(st-st2 >= 0 || !random(4)) return 0;
  tell_object(attacker, dname+" partially parries your hit.\n");
  tell_object(attacker_ob, "You partially parry "+aname+"'s hit.\n");
  /* NOTE: obj shield can be a weapon too */
  shield = attacker_ob->query_left_weapon();
  if(shield && !random(3)) {
    shield->check_weapon_break();
  }
  bonus = 1;
  return (st*100/st2);
}
check_riposte() {
  if(attacker_ob->query_skills("riposte") >= random(200)) {
    tell_object(attacker, " ..and counterattacks with blurring speed!\n");
    tell_object(attacker_ob, "  ..and counterattack with ferocity!\n");
    hit_enemy( ( random(attacker_ob->query_str() / 4) +20 ), 0, attacker_ob);
  }
}

/* max success 40% (lapilyonti ja riposte muualla) */
/* shield eli parrytaanko shieldilla. 1 on kylla */
parry_chance(object ob, int shield) {
  int chance, sk, dx, al, dx_bonus, al_bonus, lim1, lim2;
  object lw;
  if(ob) attacker_ob = ob;
  lim1 = 30;
  lim2 = 60;
  if(attacker_ob->query_npc()) {
    sk = attacker_ob->query_skills("shield parry") + attacker_ob->query_skills("weapon parry");
    sk = sk / 2;
  } else if(shield) {
    lw = attacker_ob->query_left_weapon();
    if(!lw || lw->query_type() != "shield") return 0;
    sk = attacker_ob->query_skills("shield parry");
  } else {
    if(!attacker_ob->query_right_weapon()) return 0;
    sk = attacker_ob->query_skills("weapon parry");
    lw = attacker_ob->query_left_weapon();
    if(lw && lw->query_type() != "shield") {
      sk = sk*5/4 * (attacker_ob->query_skills("two weapons combat")*3/2+40) /160;
    }
  }
  /* 60% specialized : 40% general. sk [0,100] */
  sk = (sk*6 + attacker_ob->query_skills("parry")*4)/10;
  al = attacker_ob->query_skills("alertness");
  dx = attacker_ob->query_dex();

  if(dx <= lim1) /* negative */
    dx_bonus = dx - lim1;
  else if(dx > lim1 && dx <= lim2)
    dx_bonus = (dx-lim1)/3;
  else if(dx > lim2)
    dx_bonus = (lim2-lim1)/3;
  /* max dx_bonus = 10 */
  if(al <= 50) al_bonus = (al-50)/2;
  else if(al > 50) al_bonus = (al-50)/4;
  /* al_bonus [-25,12]. chance max 40 */
  /* chance = [0,100] + [-25,12] + [-20,10] = [0, 122] */
  chance = (sk+al_bonus+dx_bonus);
  chance = ep_effect(chance, attacker_ob);
  if(!shield) chance = chance/2;
  if(!ob) chance = chance /3;
  return chance;
}

/* dodge torjuu 45% iskuista maxissa (foresee muualla) */
dodge_chance(object ob) {
  int chance, sk, dx, al, dx_bonus, al_bonus, lim1, lim2, weight_effect;
  if(ob) attacker_ob = ob;
  lim1 = 70;
  lim2 = 200;
  al = attacker_ob->query_skills("alertness");
  sk = attacker_ob->query_skills("dodge");
  dx = attacker_ob->query_dex();
  if(dx <= lim1) /* negative */
    dx_bonus = dx - lim1;
  else if(dx > lim1 && dx <= lim2)
    dx_bonus = (dx-lim1)/5;
  else if(dx > lim2)
    dx_bonus = (lim2-lim1)/5;
  /* max dx_bonus = 30 */
  if(al <= 50) al_bonus = (al-50)/2;
  else if(al > 50) al_bonus = (al-50)/4;
  /* al_bonus [-25,12] */
  /* dex affects dodge */
  chance = ( (sk*(dx_bonus+10)/33) +al_bonus+dx_bonus);
  chance = ep_effect(chance, attacker_ob);
  /* Carrying items reduces dodging possibility */
  weight_effect = attacker_ob->query_local_weight() - attacker_ob->query_str()*20;
  if(weight_effect < 0) weight_effect = 0;
  chance -= chance * weight_effect / 10000;
  if(!ob) chance = chance / 3;
  return chance;
}

special_skills(int dam) {
  int factor, bash_damage, slash_damage, pierce_damage;
  int stun_factor, damage, i, enhance, tmp, con;
  string text, race;
  bash_damage = dam[0];
  slash_damage = dam[1];
  pierce_damage = dam[2];
  if(!random(10)) do_bleeding(slash_damage+pierce_damage/2);
  /* damage armoreille */
  damage = bash_damage + slash_damage + pierce_damage;
  factor = attacker->query_skills("critical");
  factor += attacker->query_skills("find weakness");
  if(factor > random(700)) {
    i = random(200);
    i += attacker_ob->query_skills("foresee attack");
    i -= attacker->query_skills("find weakness");
    enhance = attacker_ob->query_skills("enhance criticals");
    if(i>100) { i = 100; }
    i = i / 10;
    if(i<0) i = 0;
    text = get_critical_text(hit_slot,i);
    tell_object(attacker, "You score a CRITICAL hit to "+dname+
        "'s "+text+"!\n");
    tell_object(attacker_ob, aname+" scores a CRITICAL hit to your "+text+"!\n");
    tmp = damage;
    damage = (damage*16 / (2*(i+2)) + 20) + damage*enhance/100;
    if(damage > tmp*10) damage = tmp*10;
    if(attacker_ob->query_npc() && random(25) > attacker_ob->query_level() && !random(5))
        attacker_ob->remove_limb(get_critical_text(hit_slot,0,1));
    if(!attacker_ob) return;
  }
  /* stun_factor = [0,100] + [0,50] = max 150 */
  stun_factor = (attacker->query_skills("stun")+(damage/5));

  if(attacker->query_npc()) {
    stun_factor = attacker->query_level()*3-20;
    if(!random(20)) stun_factor += stun_factor;
  }

  if(stun_factor > 200) stun_factor = 200;
  stun_factor = stun_factor * random(3);
  /* for eq monsters */
  if(attacker->query_kill_log()) stun_factor *= 2;

  con = attacker_ob->query_con();
  if(attacker_ob->query_npc()) con = attacker_ob->query_level()*4 + 20;
  if(con < 1) con = 0;
  if(con > 160) con = 160 + (con-160)/5;
  if(con > 195) con = 195;

  if(stun_factor - con > random(1000)) {
    tell_object(attacker, "You STUN "+dname+"!\n");
    tell_object(attacker_ob, "You are STUNNED by the force of "+aname+"'s attack!\n");
    stun_factor = stun_factor/40;
    if(stun_factor > 5) stun_factor = 5;
    attacker_ob->set_stunned(random(stun_factor+1)+1);
  }
  if(name_of_weapon) {
    race = name_of_weapon->query_slayer();
    if(race && race == attacker_ob->query_race() && !random(2)) {
      tell_object(attacker, "The weapon feels hot in your hand as it hits your foe!\n");
      damage = damage * 2;
    }
  }
  return damage;
}

do_bleeding(int dam) {
  object ob;
  if(20 > random(dam)) return 0;
  ob = attacker_ob->query_bleeding();
  if(!ob) ob = clone_object("/daemons/bleeding");
  ob->start(attacker_ob,dam/2);
}

get_critical_text(string slot,int i, limb) {
  string text;
  if(limb) {
    if(slot == "head") return "head";
    if(!random(2)) text = "right ";
    else text = "left ";
    if(slot == "torso") return text+"arm";
    if(slot == "legs") return text+"leg";
    return "illegal critical";
  }
  if(slot == "head") {
    if(i==0) text = "neck";
    if(i>0&&i<4) text = "face";
    if(i>3&&i<7) text = "side of the head";
    if(i>6) text = "ear";
  }
  if(slot == "torso") {
    if(i==0) text = "chest";
    if(i>0&&i<4) text = "stomach";
    if(i>3&&i<7) text = "shoulder";
    if(i>6) text = "arm";
  }
  if(slot == "legs") {
    if(i==0) text = "hip";
    if(i>0&&i<4) text = "hip";
    if(i>3&&i<7) text = "knee";
    if(i>6) text = "shank";
  }
  if(i>3) {
    if(!random(2)) text = "right "+ text;
    else text = "left " + text;
  }
  return text;
}

display_hits(int damage) {
  if(!bonus) { /* partial parry */
    if(attacker->query_artist()) {
      attacker->get_combat_texts();
    } else {
      call_other("/daemons/texts", "get_combat_texts", attacker, damage, name_of_weapon);
      /* punch if nothing in left hand */
      if(!name_of_left_weapon && !attacker->query_npc() && attacker_ob) {
        if(attacker->query_skills("punch") > random(200)) {
          tell_object(attacker, "You punch "+dname+" with your left hand.\n");
          tell_object(attacker_ob, aname+" punches you with a left hook.\n");
          hit_enemy(c_str/5+5, 0, attacker);
        }
      }
    }
  }
}

calculate_damage(string type) {
  int dam,base_dam,wc,ac,save,tw,mastery, pros;
  string wt;
  if(!attacker) return;
  wt = "npc";
  if(name_of_weapon && !name_of_weapon->query_warlock_weapon()) {
    wt = name_of_weapon->query_type();
    pros = name_of_weapon->query_damage(type);
  } else if(name_of_weapon && name_of_weapon->query_warlock_weapon()) {
	wt = "chaos "+ name_of_weapon->query_type();
	pros = name_of_weapon->query_damage(type);
  }
  if(!attacker->query_npc()) {
  if(!name_of_weapon) {
    /* unarmed damage */
    if(type != "bash") return 0;
    dam = attacker->query_skills("bare hands")/10 + c_str/40;
    return (dam+random(dam/2)+1);
  }
  if(wt == "bludgeon") {
    mastery = attacker->query_skills("pound");
  } else if(wt == "axe") {
    mastery = attacker->query_skills("cut");
  } else if(wt == "blade") {
    mastery = attacker->query_skills("slash");
  } else if(wt == "chaos bludgeon") {
	mastery = attacker->query_skills("chaos bludgeons");
  } else if(wt == "chaos blade") {
	mastery == attacker->query_skills("chaos blades");
  } else if(wt == "chaos axe") {
	mastery == attacker->query_skills("chaos axes");
}
  /* tw = [0,100] * [80,150] (/ 100) (skillmax ja iso race penalty) */
  tw = attacker->query_skills("throw weight") * (attacker->query_size()+50) /100;
  /* wcssa on weight, dam bonus ja class */
  /* bd = [30,180] * [50,100] (/ 500) = [3, 30?] */
  base_dam = name_of_weapon->query_wc()*( 50 + attacker->query_level()/3);

  // strena on jotain 300-700...
  base_dam += base_dam*c_str/500;
  if(base_dam > 20) base_dam = 20 + (base_dam-20)*9/10;

  /* lopussa jakajat: bd, (tw+mastery+base), pros */
  dam = (base_dam * pros) * (mastery + tw + 150) / (500*150*100);
  dam += attacker->query_berserk("damage", dam);
  if(dam > 400) dam = 400;

  } else { /* siis if query_npc */

  /* monsut lyo. ase vaikuttaa vaan damatypeihin, ei damaan */
  dam = (10+c_str) * (attacker->query_level()*2+20);
  /* monsulla ei oo asetta*/
  if(wt == "npc") {
    if(type != "bash") return 0;
    dam = dam / (20*10);
  } else {
    dam = dam * pros / (20*10*100);
  }
  if(dam > 2000) dam = 2000; /* should not happen, bug cases */
  } /* endif query_npc damagelle */
  /* vahan randomia */
  dam = ( dam*8 + random(dam*4) ) /10;
  /* - armourit, suoja% [0,50] */
  ac = attacker_ob->query_slot_ac(hit_slot);
  if(ac > 100) ac = 100;
  if(ac < 30) {
    save = ac*10;
  } else {
    save = 300;
  }
  save += ac*2;
  dam -= dam*save/1000;
  return (dam+1);
}
