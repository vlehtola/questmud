get_time(str) {
  return random(3)+7;
}
ep_cost() { return 15; }
query_type() { return "offensive"; }

resolve_skill(str) {
    int dama;
    int dstab, tstab;
    object target, weapon;
    if(this_player()->query_attack()) {
     write("You can't backstab anybody in combat!\n");
     return 1;
    }
    weapon = this_player()->query_weapon();
    if(!weapon) { write("You need a dagger wielded in right hand.\n"); return 1; }
    if(weapon->query_sub_type() != "dagger") { write("You need a dagger wielded in right hand.\n"); return 1; }
    if (!str) {
      write("Use backstab at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      write(str+" is not a valid target.\n");
      return 1;
    }
    if(this_player()->query_skill("double backstab") > random(120)) {
		dstab = 1;
	}
    if(this_player()->query_skill("triple backstab") > random(130)) {
		tstab = 1;
	}
    dama = (this_player()->query_dex()+this_player()->query_lvl());
    dama += weapon->query_wc();
    dama = dama + random(dama);
    if(dstab)dama = dama + random(dama);
    if(tstab)dama = dama + random(dama);
    write("You BRING your weapon with lightning SPEED torwards the "+capitalize(str)+" and quickly STAB "+target->query_possessive()+" heart!\n");
    tell_object(target, this_player()->query_name()+" brings "+this_player()->query_gender()+" weapon torward you with a lightning SPEED and quickly STABS you!\n");
    say(this_player()->query_name()+" BRINGS "+this_player()->query_name()+" weapon torward the "+str+" with lightning SPEED and STABS "+str+" in the HEART!\n",target);
    if(dstab) {
	write("...AND QUICKLY STAB AGAING!\n");
	tell_object(target, "....AND QUICKLY STABS AGAING!\n");
	say(".......AND QUICKLY STABS AGAING!\n");
}
    if(tstab) {
	write("........AND AGAING!\n");
	tell_object(target, ".......AND AGAING!\n");
	say(".............AND AGAING!\n");
}
this_player()->attack_object(target);
target->hit_with_spell(dama, "physical");
}

fail_skill(str) {
}
