inherit "obj/monster";

reset(arg) {
    int i;
    object weapon;
    ::reset(arg);
    if(arg) { return; }

    i = random(3);
    set_level(19+random(3)+i*3);
    set_name("hill giant");
    set_exp(query_exp()*0.9);
    set_alias("male");
    set_race("giant");
    if(i == 0) set_short("A small hill giant");
    if(i == 1) set_short("A hill giant");
    if(i == 2) set_short("A huge hill giant");
    set_long("A strong looking hill giant throwing rocks. He has huge\n"+
             "muscles and his skin is dirty. He holds dozens of small\n"+
             "rocks in his left arm.\n");

    set_al(0);
    set_aggressive(0);
    set_gender(1);
    set_special(10+i*5);

    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");

}
special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "The hill giant throws a rock at you!\n");
  say("The hill giant throws a rock at "+ob->query_name()+".\n", ob);
  ob->hit_with_spell(50+random(3)*10);
}

