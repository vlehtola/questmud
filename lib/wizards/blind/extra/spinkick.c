get_time(str) {
  return random(2)+1;
}
ep_cost() { return 3; }

resolve_skill(target) {
    int dama;
    if(!target) {
      write("Use spinkick at who?\n");
      return 1;
    }
    dama = (this_player()->query_str() / 3 + this_player()->query_dex()/2);
    dama = dama/2 + random(dama) + 5;
    if(dama < 60) {
      write("You concentrate deeply and suddenly you spinkick " + capitalize(target->query_name()) + " in the head!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
	" makes a powerful spin and kicks you in the head!\n");
      say(capitalize(this_player()->query_name()) + " spinkicks "+
	capitalize(target->query_name()) + " in the head!\n", target);
    } else {
      write("Everything seems to slow down as you spin around and kick "+capitalize(target->query_name())+
	"'s head with devastating force!\n");
      tell_object(target, this_player()->query_name()+
	" spinkicks you in the head with devastating force!\n");
      say(capitalize(this_player()->query_name()) + " spinkicks "+
	capitalize(target->query_name()) + " in the head with devastating force!\n", target);
    }
    if(dama > 100) { dama=100; }
    target->hit_with_spell(dama);
    this_player()->attack_object(target);
}

fail_skill(target) {
    if(!target) {
	write("Use spinkick at who?\n");
	return 1;
    }
    if(random(100) < this_player()->query_skills(call_other("/obj/skillfun","skill_nums","spinkick"))) {
	resolve_skill(target);
	return 1;
    }
    write("You start spinning around and try to aim your foot at " + target->query_name() + ", but you fail you!.\n");
    tell_object(target, this_player()->query_name() + " tries to spinkick you, but fails miserably.\n");
    say(capitalize(this_player()->query_name()) + " tries to spinkick " + capitalize(target->query_name()) + ", but\n" 
       "misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
