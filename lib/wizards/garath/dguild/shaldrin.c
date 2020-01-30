// Haste
//
// 12.04.02 - Garath


int get_time(string str) {
  return random(2)+10;
}
int ep_cost() { return 150; }

status resolve_skill(string str) {
    int dama;
      write("You mumble 's"'s stomach with a nasty sound!\n");
      tell_object(target, this_player()->query_name()+
	" brutally kicks you in the stomach! OUCH!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the stomach!\n", target);
    }
    if(dama > 40) { dama=40; }
    if(this_player()->query_attack() != target) this_player()->attack_object(target);
    target->hit_with_spell(dama, "physical");

/*
 DISABLED due to abuse //Celtron

    if(!random(1000)) {
     this_player()->set_mastery("Offensive maneuvers",(this_player()->query_mastery()["Offensive maneuvers"] + 1));
   }
    dama += (this_player()->query_mastery()["Offensive maneuvers"]/10);
*/
}

fail_skill(str) {
    object target;
    if(!str) {
	write("Use kick at who?\n");
	return 1;
    }
    if(random(100) < this_player()->query_skills("kick")) {
	resolve_skill(str);
	return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You try to kick " + target->query_name() + ", but miss.\n");
    tell_object(target, this_player()->query_name() + " tries to KICK you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to kick " + target->query_name() +
       ", but misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
