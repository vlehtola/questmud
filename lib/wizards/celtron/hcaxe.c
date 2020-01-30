inherit "obj/weapon";

// resetti tuli joka 20sec. speciali ei ole mikaan overpower.
// Celtron

int amount;

reset(arg) {
    if(!amount) amount = 100;
    if(wielded_by) {
	if(wielded_by->query_attack()) {
	  tell_room(environment(wielded_by),
            "Throatcutter grazes "+wielded_by->query_attack()->query_name()+"'s throat, glowing for a moment!\n");
	  wielded_by->query_attack()->hit_with_spell(amount+random(50));
	}

	tell_room(environment(wielded_by),
           "A warm wave floats from Throatcutter up to it's wielders arm healing and restoring lost strength.\n");
	wielded_by->add_hp(200);
	wielded_by->add_ep(400);
	amount += 15;
	if(amount > 300) amount = 300;	// dam cap
    }
    ::reset(arg);
    if(arg) return;
    set_class(100);
    set_sub_type("battle axe");
    set_alias("throatcutter");
    set_short("A two-edged steel axe 'Throatcutter'");
    set_long("This axe is obviously dwarven origin, but it's\n"+
	"somehow unusually sharp and sees like it would actually live.\n"+
	"Blue runes have been carved to it's black edge.\n");
    set_slayer("demon");
}


