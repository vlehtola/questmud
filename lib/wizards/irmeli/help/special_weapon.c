inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("hammer");
    set_short("The Mighty hammer called 'Skullsmasher'");
    set_long("Steel made hammer, forged obviously by dwarves. It has some\n"+
		"strange runes on it's handle: 'lighter' and 'heavier'\n");
    set_value(50000);
    set_weight(1000);
    set_type(1);
    set_wc(70);
    set_hit_func(1);
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(5) != 0) return;
  tell_room(environment(wielded_by), "The Skullsmasher glows brightly and gives "+
	"a real shock to "+wielded_by->query_attack()->query_name()+"!\n");
/* Hits with electric damage: (the last 5 is the number of the damage type)*/
  wielded_by->query_attack()->hit_with_spell(random(100)+50,5);
  return 1;
}

