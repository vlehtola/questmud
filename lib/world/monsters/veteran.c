inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(35);
    set_name("guard");
    set_alias("gateguard");
    set_short("A grubby gateguard stands mighty on the way");
    set_long("The grubby gateguard looks bored, but still he is standing straight and\n" +
             "still. He isen't blinking his eyes, even his breathing can't be heard.\n"+
             "A perfect, watchful guard, confusing the adventures by acting dead.\n" +
             "He is covered with dust, old dried blood and dirty, ripped clothes.\n");
    set_al(10);
    set_aggressive(0);
    set_gender(1);
    set_race("human");

    armour = clone_object("/wizards/walla/area/weapons/gsword");
    move_object(armour, this_object());
    init_command("wield sword");

    weapon = clone_object("/wizards/walla/area/armour/garmour");
    move_object(weapon, this_object());
    init_command("wear mail");
}
jees() {
  if(this_player()->query_skills("find weakness") < 20) {
    tell_object(this_player(),
     "Guard blocks your way and says: 'You are not worthy to pass.'\n");
    say("Guard stops "+this_player()->query_name()+" when "+
        this_player()->query_pronoun()+" attempts to go stairs.\n",this_player());
    return 1;
  } else {
    return 0;
  }
}

init() {
  add_action("jees", "stairs");
}

