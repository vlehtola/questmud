get_time(str) {
  return random(2)+1;
}
ep_cost() { return 3; }

resolve_skill(target) {
    int dama;
    if(!target) {
      write("Use slice and dice at who?\n");
      return 1;
    }
    dama = (this_player()->query_str() / 1 + this_player()->query_dex()/1);
    dama = dama/2 + random(dama) + 100;
    if(dama < 200) {
      write("You weakly cut " + capitalize(target->query_name()) + " in the"+
            "right arm!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
        " pitifully cuts you in the right arm!\n");
      say(capitalize(this_player()->query_name()) + " weakly cuts "+
        capitalize(target->query_name()) + " in the right arm!\n", target);
    } else {
      write("You DEMONICALLY SLICE "+capitalize(target->query_name())+
        "'s CHEST and BLOOD start SPILLING everywhere!\n");
      tell_object(target, this_player()->query_name()+
        " SLICES you in the chest..Your blood spills everywhere!\n");
      say(capitalize(this_player()->query_name()) + " DEMONICALLY SLICES "+
        capitalize(target->query_name()) + " in the CHEST!\n", target);
    }
    if(dama > 200) { dama=200; }
    target->hit_with_spell(dama);
    this_player()->attack_object(target);
}

fail_skill(target) {
    if(!target) {
        write("Use slice at who?\n");
        return 1;
    }
    if(random(100) <
this_player()->query_skills(call_other("/obj/skillfun","skill_nums","slice"))) {
        resolve_skill(target);
        return 1;
    }
    write("You try to slice " + target->query_name() + ", but fail.\n");
    tell_object(target, this_player()->query_name() + " tries to slice you,but"+
               "misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to slice " +
capitalize(target->query_name()) + ", but misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
