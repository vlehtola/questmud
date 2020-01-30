inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(35);
    set_race("human");
    set_gender(1);
    set_name("nheo");
    set_short("Nheo, the weapons responsible");
    set_long("Nheo is a middle aged man. His duty is to keep an eye on the\n"+
             "equipment which are trusted to him. He looks very protective\n"+
             "towards his equipment and might even kill himself if he would\n" +
             "lose any of the precious items.\n");
    set_al(50);
    set_move_at_random(0);
    
    weapon = clone_object("/wizards/nalle/area/eq/nheoaxe.c");
    move_object(weapon, this_object());
    init_command("wield axe");
}

init() {
  add_action("block", "north");
}

block() {
  if(!this_player()->query_guild_level("veterans")) {
    write("Nheo blocks your way and says: 'Sorry, only for members.'\n");
    say(this_player()->query_name()+" tries to leave north, but Nheo "+
        "steps on the way.\n", this_player());
    return 1;
  }
}
