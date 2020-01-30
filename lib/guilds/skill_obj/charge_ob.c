#define MAX_DISTANCE 5  // stop in case of a wall or within five rooms
#define COOLDOWN 10	// 10 minutes before useable again

// Skill usable in berserk only, hits randomly creatures on the charge path.
// User takes damage relative to the amount made.
//
// Made by Celtron

mapping victims;

int damage, distance;
string dir;
object user;

start(object ob, string str) {
  int time_online;
  object previous_charge_ob;

  user = ob;
  dir = str;

  previous_charge_ob = present("charge_object", user);

  // Made to prevent quit&re-enter abuse. C
  time_online = time() - ob->query_enter_time();
  if(time_online / 60 < COOLDOWN || previous_charge_ob) {
    tell_object(user, "You are not yet ready to perform a charge.\n");
    destruct(this_object());
    return 1;
  }
  move_object(this_object(), user);

  // damage should be ok. if you do much, then you'll probably die yourself too
  damage = ( user->query_str()+user->query_dex() ) * user->query_size() / 100;
  damage = damage * (user->query_skills("charge rush")/8 + random(10)+2);
  call_out("move",0);
}

query_charge_ob() { return this_object(); }
id(string str) { return str == "charge_object"; }

move() {
  string dest;
  if(distance >= MAX_DISTANCE) {
    tell_object(user, "You end your charge.\n");
    tell_room(environment(user), user->query_name()+" ends "+user->query_possessive()+" charge.\n",
	({user}));
    destruct(this_object());
    return 1;
  }
  tell_object(user, "You charge forward!\n");
  tell_room(environment(user), user->query_name()+" charges "+dir+"!\n",({user}));
  dest = environment(user)->query_valid_dir(dir);
  if(!dest) {
    collide_wall();
    return 1;
  }
  user->move_player(dir+"#"+dest);
  tell_room(environment(user), user->query_name()+" arrives charging!\n",({user}));
  if (environment(user)->query_property("no_kill")) {
    write("You run into a magical barrier.\n");
    collide_wall();
    return 1;
  }
  distance += 1;
  collide();
}

collide_wall() {
  tell_object(user, "You run to a wall! OUCH!\n");
  tell_room(environment(user), user->query_name()+" runs to a wall!\n",({user}));
  user->hit_with_spell(damage/10);
  end_charge();
}

collide() {
  object ob;
  int max_dam, divider;
  ob = get_target();
  if(ob) {
    ob->attack_object(user);
    if(ob->query_kill_log()) {
      tell_object(ob, "You dodge "+user->query_name()+"'s charge!\n");
      tell_object(user, ob->short()+" nimbly dodges your charge!\n");      
    } else {
      tell_object(ob, user->query_name()+" charges at you!\n");
      tell_object(user, "You collide with "+ob->short()+"!\n");
      tell_room(environment(user), user->query_name()+" collides with "+ob->short()+"!\n",({user,ob}));
      max_dam = ob->query_hp();

   /* pelaajiin t�rm��misest� tulee suhteessa enemm�n damaa */
      if(ob->query_npc()) divider = 10;
      else divider = 1;

      ob->hit_with_spell(damage);
      if(max_dam > damage) max_dam = damage;
      user->hit_with_spell(max_dam / divider);
    }
  }
  if(ob) {
    if(user->query_skills("stun") > random(100)) {
      tell_object(user, "Your charge STUNS "+ob->query_name()+"!\n");
      tell_object(ob, "You are STUNNED by the impact of "+user->query_name()+"'s charge!\n");
      ob->set_stunned(5);
    }
    end_charge();
    return 1;
  }
  move();
}

end_charge() {
  tell_object(user, "Your charge is stopped by the collision.\n");
  tell_room(environment(user), user->query_name()+" stops "+user->query_possessive()+
	" charge.\n", ({user}));
  call_out("destroy_charge_ob", 60*COOLDOWN);
}

destroy_charge_ob() {
  tell_object(user, "You feel recovered from your last charge.\n");
  destruct(this_object());
}

get_target() {
  object ob;
  int i;
  victims = ([ ]);
  ob = all_inventory(environment(user));
  while(i<sizeof(ob)) {
    if(ob[i] && living(ob[i]) && ob[i] != user) {
      victims += ([ob[i]:0]);
    }
    i += 1;
  }
  ob = m_indices(victims);
  if(!victims || !ob || !sizeof(ob)) return 0;
  return ob[random(sizeof(ob))];
}
