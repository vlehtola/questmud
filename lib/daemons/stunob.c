/* stun object. usage: by shadow. living is stunned and unable to fight,
   use skills and spells and avoid enemy hits.  //Celtron

  skills: inner strength (ignore stun) and stunned maneuvers (escape is possible)
  anti stun = stun resistance

  anti stun for monsters makes them unstunnable for a short period after they
  recover from the stun.
*/

#define ANTI_STUN_ROUNDS 5

int rounds, anti_stun;
object uhri;

/* when force is true, stun cannot be avoided. */
start(object ob, int num, int force) {
  if(!ob) return;
  if(!uhri) {
    uhri = ob;
    shadow(uhri, 1);
  }
  if(!force) {
    if(uhri->query_berserk()) {
      tell_object(uhri, "You shrug off the stun!\n");
      tell_room(environment(uhri), uhri->query_name()+" shrugs off the stun!\n", ({uhri}));
      end_stun(1);
      return 1;
    }
    if(uhri->query_undead()) {
      tell_room(environment(uhri), uhri->query_name()+" is unaffected by the stun!\n");
      end_stun(1);
      return 1;
    }
  }
  /* set rounds of stun */
  set_stunned(num, force);
  if(ob->query_spell()) {
    call_other(ob->query_spell(), "interrupt_spell");
    tell_room(environment(ob),"..spell attempt interrupted by stun.\n");
  }
  if(ob->query_use_skill()) {
    call_other(ob->query_use_skill(), "interrupt_skill", 1);
    tell_object(ob, "Your skill concentration breaks.\n");
  }
}

query_stunned() {
  return query_stun();
}

query_stun() {
  if(anti_stun) return 0;
  return rounds;
}

myllytys() {
  if(anti_stun) {
    return uhri->myllytys();
  }
  tell_object(uhri, "You are stunned are unable to fight back.\n");
  return 1;
}

/* removed by C 7.5.04

link_death() {
  tell_object(uhri, "You can't go ld while stunned.\n");
  return 1;
}
*/

cast(string arg) {
  if(anti_stun) return uhri->cast(arg);
  tell_object(uhri, "You are stunned and can't cast spells.\n");
  return 1;
}

use(string arg) {
  if(anti_stun) return uhri->use(arg);
  tell_object(uhri, "You are stunned and can't use skills.\n");
  return 1;
}

reset_time_points() {
  if(anti_stun) return uhri->reset_time_points();
  tell_object(uhri, "You are stunned and unable to fight.\n");
  return 1;
}

prevent_move(string dir, object dest) {   
  string tmp;
  object ob;
  int skill;
  if(anti_stun || dir == "X" || dir == "XX")
    return uhri->prevent_move(dir,dest);

  skill = uhri->query_skills("stunned maneuvers");
  /* skill = [0,10000] */
  skill = skill*(skill/2 + 50);
  if(skill > random(100*100)) {
    tell_object(uhri, "You manage to control your pain and move.\n");
    return uhri->prevent_move(dir,dest);
  }
  tell_object(uhri, "You are stunned and unable to move.\n");
  return 1;
}

set_stunned(int num, int force) {
  if(anti_stun) return 0;
  if(!num) { end_stun(); return 1; }
  if(!force) {
    /* stun esto tsekit tahan */
    if(random(uhri->query_skills("inner strength")+uhri->query_con()/3) > random(200) + 10) {
      tell_object(uhri, "Your inner strength helps you to avoid being stunned!\n");
      if(environment(uhri)) {
        tell_room(environment(uhri), uhri->query_name()+"'s inner strength helps "+
		uhri->query_objective()+" to avoid being stunned!\n", ({uhri}));
      }
      if(!rounds) destruct(this_object());
      return 1;
    }
  }
  /* stun rundien pisto (2x koska rundi = 2 sec) */
  if (rounds < num*2) {
    remove_call_out("end_stun");
    rounds = num*2;
    num = uhri->query_skills("stunned maneuvers")*rounds / 150;
    if(num) tell_object(uhri, "..your stunned maneuvers "+get_maneuvers_msg(rounds,num)+" lessen the stun.\n");
    rounds -= num;
    call_out("end_stun",rounds);
  }
  return 1;
}

static get_maneuvers_msg(int a, int x) {
  if(x*2 > a) return "greatly";
  if(x*3 > a) return "";
  return "somewhat";
}

end_stun(status silently) {
  if(!silently) tell_object(uhri, "The pain eases and allows you to move again.\n");
  if(uhri->query_npc()) {
    rounds = 0;  // no longer stunned
    anti_stun = ANTI_STUN_ROUNDS;
    call_out("end_anti_stun", anti_stun);
    return 1;
  }
  destruct(this_object());
}

end_anti_stun() {
  destruct(this_object());
}
