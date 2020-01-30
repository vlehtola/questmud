object target;
object rweapon;
object lweapon;
get_time(str) {
  return random(3)+7;
}
ep_cost() { return 15; }
query_type() { return "offensive"; }

resolve_skill(str) {
    int dama;
    int dstab, tstab;
    if(this_player()->query_attack()) {
     write("You can't backstab anybody in combat!\n");
     return 1;
    }
    rweapon = this_player()->query_right_weapon();
    if(!rweapon) { write("You need a dagger wielded in right hand.\n"); return 1; }
    if(rweapon->query_sub_type() != "dagger") { write("You need a dagger wielded in right hand.\n"); return 1; }
    if (!str) {
      write("Use backstab at whom?\n");
      return 1;
    }
    lweapon = this_player()->query_left_weapon();
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
    dama = this_player()->query_dex()+this_player()->query_lvl();
    dama += rweapon->query_wc();
    dama = dama + random(dama);
    if(lweapon->query_sub_type() == "dagger")dama += lweapon->query_wc();
    if(dstab)dama = dama + random(dama);
    if(tstab)dama = dama + random(dama);
    dama = dama*2;
    write("You BRING your "+lower_case(rweapon->short())+" with lightning SPEED torwards the "+capitalize(str)+" and quickly BACKSTAB "+target->query_possessive()+" heart!\n");
    tell_object(target, this_player()->query_name()+" brings "+this_player()->query_gender()+" "+lower_case(rweapon->short())+" torward you with a lightning SPEED and quickly BACKSTABS you!\n");
    say(this_player()->query_name()+" BRINGS "+this_player()->query_name()+" "+lower_case(rweapon->short())+" torward the "+str+" with lightning SPEED and BACKSTABS "+str+" in the HEART!\n",target);
    if(dstab) {
	write("...AND QUICKLY STAB AGAING!\n");
	tell_object(target, "....AND QUICKLY STABS AGAING!\n");
	say(".......AND QUICKLY STABS AGAING!\n", target);
}
    if(tstab) {
	write("........AND AGAING!\n");
	tell_object(target, ".......AND AGAING!\n");
	say(".............AND AGAING!\n", target);
}
this_player()->attack_object(target);
target->hit_with_spell(dama, "physical");
}

fail_skill(str) {
if(!str) { write("Use backstab at what?\n"); return 1; }
target = present(str, environment(this_player()));
if(!target) { write("Use backstab at what?\n"); return 1; }
write("You try to backstab "+str+".\n");
if(random(110) < this_player()->query_skills("stealth")) {
write("But nobody diden't see your lousy attempt.\n");
return 1;
}
write("But the "+str+" sees your lousy attempt.\n");
tell_object(target, this_player()->query_name()+" tryes to backstab you!\n");
say(this_player()->query_name()+" tryes to backstab "+target->query_name()+".\n", target);
target->attack_object(this_player());
return 1;
}
