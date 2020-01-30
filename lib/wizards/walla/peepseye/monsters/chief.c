inherit "obj/monster";  
int number_of_guards;
 
reset(arg) {
    object armour,weapon;
    object glasseye;
    number_of_guards = 0;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 42);
    call_other(this_object(), "set_name", "the grand intellect");
    call_other(this_object(), "set_alias", "vorticon");
    call_other(this_object(), "set_alias", "chief");
    call_other(this_object(), "set_short", "The Grand Intellect, the leader of the Vorticons");
    call_other(this_object(), "set_long", "The grand intellect is dresses up in a big cloak, which\n"+
                                         "is pitch black. The only other thing you can see, are The Grand Intellects\n" +
                                          "red glowing eyes.\n");
    call_other(this_object(), "set_al", -21);
    call_other(this_object(), "set_aggressive", 0);
    call_other(this_object(), "set_extra", 1);
    set_log();
    set_block_dir("portal");
 
    glasseye=clone_object("/wizards/walla/peepseye/eq/objs/realeye");
    move_object(glasseye, this_object());
 
    armour = clone_object("/wizards/walla/peepseye/eq/armour/mistymail");
    move_object(armour, this_object());
    init_command("wear mail");

    weapon = clone_object("/wizards/walla/peepseye/eq/weapons/smudgeaxe");   
    move_object(weapon, this_object());
    init_command("wield axe");
}
extra() {
    object leb_guard;
    if (!attacker_ob) {
 
  return;
    }
  if(random(number_of_guards + 1) == number_of_guards) {
        leb_guard = clone_object("wizards/walla/peepseye/monsters/chiefguard.c");
        move_object(leb_guard, environment(this_object()));
        say("The Grand Intellect's eyes go black for a while, and as they start glowing again,\n" +
               "a guard runs in from the maze.\n");
         number_of_guards += 1;
 }
}
reduce_number() {
    number_of_guards -= 1;
}
 

