#define MASTERY_D "/daemons/mastery_d"
get_time()  {
  return random(3)+2;
}
ep_cost() { return 3; }
query_type() { return "offensive"; }

resolve_skill(str) {
  int dama;
  string str1,str2;
  object tp,tgt;
  tp = this_player();
  str1 = ""; str2 = "";
  if(!str) {
    write("claws storm at whom?\n");
    return 1;
  }
    if(!tp->query_right_weapon() || !tp->query_left_weapon()) {
        write("You need to wield knuckles in your right and left hand to use claws storm.\n");
        return 1;
    }

    if( tp->query_right_weapon()->query_type() != "knuckles" ||
        tp->query_left_weapon()->query_type() != "knuckles") {
        write("You need to wield knuckles in your right and left hand to use claws storm.\n");
        return 1;
    }

   tgt = present(str,environment(this_player()));
     if(!tgt || !living(tgt) || tgt == tp) {
        tell_object(tp,capitalize(str)+" is not a valid target.\n");
        return 1;
     }
  dama = (tp->query_str()+tp->query_dex()*2) + (tp->query_skills("claws storm")*2/3+tp->query_skills("dragon blow")/2);
  if (dama > 350) str1 = " relax and";
if (dama > 750) {
    dama = 750;
        str2 = " with FORCE";
  }
  if(tp->query_skills("whirlwind") > random(300)) {
    write("You jump in the air and whirl in RAGE.\n");
   dama = dama + 350;
  }
  dama += MASTERY_D->mastery("Mastery of body focusing",this_player(),tgt)*4;

  write("You"+str1+" whirl your knuckles"+str2+" inside "+tgt->query_name()+"'s chest.\n");
   say(tp->query_name()+" whirls his knuckles"+str2+" and passionately slashes "+tgt->query_name()+" in the chest causing ribs to bend in.\n",tgt);
  tell_object(tgt, tp->query_name()+" whirls his knuckles"+str2+" and punctures your chest with a CRUSHING claws storm!\n");

  this_player()->attack_object(tgt, 1);
  tgt->hit_with_spell(dama);
  return 1;
}
fail_skill(str) {
  object tp,tgt;
  if(!str) {
    write("claws storm at whom?\n");
    return 1;
  }
  tgt = present(str,environment(this_player()));
  if(!tgt) {
     write(str+" is not a valid target.\n");
    return 1;
  }
  tp = this_player();
  write("You cannot keep the balance to perform the claws storm.\n");
  say(tp->query_name()+" tries to slash "+tgt->query_name()+", but loses "+tp->query_possessive()+" balance and falls down on his kneels.\n");
  tell_object(tgt, tp->query_name()+" whirl his knuckles, but misses.\n");
  return 1;
}

