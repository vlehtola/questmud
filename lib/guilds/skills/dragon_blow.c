#define MASTERY_D "/daemons/mastery_d"
#define MAX_DAMAGE      350     // Set to 350 by Moonstar 17.10.2004

get_time(str) {
  return random(2)+1;
}
ep_cost() { return 2; }
query_type() { return "offensive"; }

resolve_skill(str, ob) {
    int dama;
    object target;
    if(!ob)ob=this_player();
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      tell_object(ob, "Use Dragon blow at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      tell_object(ob, str+" is not a valid target.\n");
      return 1;
    }
    dama = (this_player()->query_dex()+this_player()->query_str())/2;
    dama = dama + random(dama/2) + 5;

   if(dama > 200) dama = (dama-200) / 2 + 200;
   if(dama > 400)  { dama=400;  }
   if(this_player()->query_skills("whirlwind") > random(150)) {
     write("You jump in the air and whirl in RAGE.\n");
     dama = dama + 100;
   }
   if(dama < 90) {
      tell_object(ob, "You scream 'kiaa' and your dragon blow hits " + capitalize(target->query_name()) + " in the knee!\n");
      tell_object(target, capitalize(this_player()->query_name()) +" screams 'kiaa' and punches you in the knee!\n");
      say(capitalize(this_player()->query_name()) + " screams 'kiaa' and punches "+
        capitalize(target->query_name()) + " in the knee!\n", target);
    } else {
    tell_object(ob, "You scream 'ZAS' and PUNCH " + capitalize(target->query_name()) + " in the stomach!\n");
    tell_object(target, capitalize(this_player()->query_name()) +" screams 'SAZ' and PUNCHES you in the stomach!\n");
      say(capitalize(this_player()->query_name()) + " screams 'ZAS' and PUNCHES "+
      capitalize(target->query_name()) + " in the stomach!\n", target);
    }
    dama += MASTERY_D->mastery("Mastery of body focusing",this_player(),target)*3;

// Tuned by Celtron 18.01.2004

  if(dama > MAX_DAMAGE/2) {
    dama = MAX_DAMAGE/2 + (dama-MAX_DAMAGE/2)/2;
  }
  if(dama > MAX_DAMAGE) {
    dama = MAX_DAMAGE;
  }

//end of tune

        if(ob->query_tester() || ob->query_wiz()) {
         tell_object(ob,"Dam: "+dama+"\n");
        }

    ob->attack_object(target, 1);
     target->hit_with_spell(dama, "physical");
}

fail_skill(str, ob) {
    object target;
    if(!ob)ob=this_player();
    if(!str) {
        tell_object(ob, "Use dragon blow at who?\n");
        return 1;
    }
     if(random(100) < this_player()->query_skills("dragon blow")) {
        resolve_skill(str);
        return 1;
     }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    tell_object(ob, "You try to punch " + target->query_name() + ", but miss.\n");
    tell_object(target, this_player()->query_name() + " tries to PUNCH you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to punch " + target->query_name() + ", but misses.\n", target);
    target->attack_object(ob);
    ob->attack_object(target);
}

