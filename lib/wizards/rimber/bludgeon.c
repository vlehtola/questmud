inherit "obj/weapon";
int i;
start() {
        set_class(9);
        set_sub_type("maul");
        set_name("harvester");
        set_short("A large maul named 'Harvester' "+get_short(i)+"");
        set_long("A large maul which is made from somekind of white material.\n"+
                 "The handle of maul is made from gold and on it is ancient\n"+
                 "dwarven runes going all the way up from down. Inside the maul\n"+
                 "seems to be something mystical and living");
}
init() {
::init();
add_action("read", "read");
add_action("drain", "drain");
add_action("unleash", "unleash");
}

read(string str) {
  if(str != "runes") return 0;
  write("The runes say something about draining the dead souls and unleashing them.\n");
  return 1;
}
drain(string str) {
	object ob;
	if(str != "corpse") return 0;
	if(!wielded_by) return 0;
	ob = present("corpse", environment(this_player()));
	if(!ob) {
		write("A screaming sound comes from the harvester.\n");
		wielded_by->hit_with_spell(random(150), "physical");
		return 1;
	}
	if(!ob->query_corpse()) {
		write("You hear voices inside your head and they don't sound quite friendly.\n");
		return 1;
	}
	i += 1;
	write("You place the harvester above the corpse and it screams in pleasure.\n");
	say(wielded_by->query_name()+" places something above the corpse and loud screaming sound can be heard.\n");
	destruct(ob);
return 1;
}
unleash() {
	int amount;
	if(!wielded_by) return 0;
	if(i < 50) {
		write("Nothing seems to happen while you try to unleash the souls.\n");
		return 1;
	}
	amount = (i/5);
	write("You unleash dead souls from the harvester.\n");
	wielded_by->heal_self(amount*2);
	i -= amount;
	return 1;
}

wield(string str) {
  ::wield(str);
  if(!wielded_by) return 0;
  write("The maul screams in hunger as you wield it.\n");
  return 1;
}

get_short(int i) {
	switch(i) {
		case 0..50: return "<blurring>";
		case 51..100: return "<BLURRING>";
		case 101..200: return "<radiating>";
		case 201..500: return "<RADIATING>";
		case 501..1000: return "<shimmering>";
		case 1001..2000: return "<SHIMMERING>";
		case 2001..5000: return "<burning>";
		}
		return "<BURNING>";
}
