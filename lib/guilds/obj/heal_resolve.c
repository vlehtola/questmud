healing_resolve(type,class,category,effect_bonus,string target,string god) {
    int heal, damage_to_self, god_modifier;
    object ob, next_ob;
    string text_word,text_word2, target2,tmp;
    if (!target) {
        write("Cast at whom?\n");
        return;
    }
    if (god == "morai") {
	god_modifier = 65;
	god = "Morai";
	if (this_player()->query_god_status() > -30) {
	   write("Morai doesn't help you.\n");
	   return 1;
	}
    }
    if (god == "cyral") {
        god_modifier = 100 + (this_player()->query_god_status() / 5 * 3);
	god = "Cyral";
	if (this_player()->query_god_status() < 30) {
	   write("Cyral doesn't help you.\n");
	   return 1;
	}
	if(god_modifier > 200) god_modifier = 200;
    }

    ob = present(lower_case(target), environment(this_player()));
    if (!ob) {
        write("There is no " + target + " here.\n");
        return;
    }
    if (class == "hea") {
        heal += 50;
        heal += this_player()->query_wis() / 5;
    }
    if (class == "xfr") {
        heal += 70;
        heal += this_player()->query_wis() / 4;
    }
    if (type == "min") {
        heal = heal * 1;
        text_word = "Minor";
    }
    if (type == "les") {
        heal = heal * 2;
        text_word = "Lesser";
    }
    if (type == "mjr") {
        heal = heal * 3;
        text_word = "Major";
    }
    if (type == "gra") {
        heal = heal * 4;
        text_word = "Greater";
    }
    if (type == "rea") {
        heal = heal * 6;
        text_word = "True";
    }

    if (!heal) { return; }

    if (effect_bonus > 100) {
        effect_bonus = 100 + ((effect_bonus - 100) / 4);
    }
    heal += heal * effect_bonus / 100;
    target2 = target;
    target = capitalize(target);
    target2 = capitalize(target2);
    if (ob == this_player()) { target = "yourself"; target2 = "himself"; }
    write("You heal " + target + ".\n");
    say(capitalize(this_player()->query_name())+" heals "+target2+".\n",ob);
    if (ob != this_player()) {
        tell_object(ob, capitalize(this_player()->query_name()) + " heals your wounds.\n");
    }
    if (class == "xfr") {
	if (ob == this_player() || this_player()->query_hp() == 1) { return 1; }
        damage_to_self = heal/5;
	if (damage_to_self >= this_player()->query_hp()) {
	    damage_to_self = this_player()->query_hp() - 1;
	    heal = damage_to_self * 5;
        }
	this_player()->reduce_hit_point(damage_to_self);
	this_player()->casting_sp_reduce(heal/10);
    } else {
        this_player()->casting_sp_reduce(heal / 5);
    }
    if (class != "xfr" || damage_to_self) {
	if (god_modifier) {
		write("You feel " +god+" affecting your casting.\n");
		heal = heal * god_modifier / 100;
	}
	ob->heal_hp(heal);
    }
    return 1;
}


