inherit "obj/monster";

reset(arg) {
    object armour1;
    object armour2;
    object weapon;
    object weapon2;
    ::reset(arg);
    if(arg) { return; }

    set_race("human");
    set_level(random(5)+20);

    set_name("esko");
    set_alias("woman");
    set_short("Esko, a young woman dressed in silk");
    set_long("Ilana is an attractive, young woman. She is clad in fine silky clothes\n"+
             "and wears a ring on her finger. Despite of her young age she\n"+
             "seems to be very skilled in the magical arts.\n");

    set_al(30);
    set_al_aggr(200);
    set_log();
    set_mage(1);
    set_str(query_str() + 135);
    set_dex(query_dex() + 50);
    set_int(query_int() + 50);
    set_max_hp(query_hp() + 15000);
    set_hp(query_max_hp());
    set_gender(2);

    set_skill("stunning blast", 50);
    set_skill("proximity blast", 25);
    set_skill("deceived attack", 75);
    set_skill("kick", 100);
    set_skill_chance("kick", 10);

    set_special(35);
}

special_move() {
object ob;
ob = this_object()->query_attack();

   tell_object(ob, "Esko's mysterious kick hoovees you off the potkuri.\n");
   say(query_attack()->query_name()+ " seems thrown hoovee.\n", ob);
   move_object(ob,"/wizards/walla/workroom.c");

}
