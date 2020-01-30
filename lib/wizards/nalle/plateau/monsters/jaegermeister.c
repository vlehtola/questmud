#define AREAPATH "wizards/nalle/plateau/"

inherit "obj/monster";

reset(arg) {
    object armour1;
    object weapon;
    object weapon2;
    ::reset(arg);
    if(arg) { return; }

    set_race("human");
    set_level(65);

    set_name("rutger");
    set_alias("huntmaster");
    set_short("Rutger, the Huntmaster");
 set_long("Rutger, the legendary huntmaster is an elderly man, who has\n"+
          "moved to the mountains in the twilight of his life, to hunt\n"+
          "for the local game and generally take it easy. Despite his\n"+
          "age, he seems very fit and would be a worthy opponent in battle.\n");

    set_al(5);
    set_log();
    set_str(query_str() + 100);
    set_dex(query_dex() + 50);
    set_max_hp(query_hp() + 15000);
    set_hp(query_max_hp());
    set_gender(1);

    set_skill("deceived attack", 90);
    set_skill("kick", 100);
    set_skill_chance("kick", 10);
     
    armour1 = clone_object(AREAPATH+"eq/jaegerhood");
    move_object(armour1, this_object());
    init_command("wear hood");

    weapon = clone_object(AREAPATH+"eq/longsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    weapon2 = clone_object(AREAPATH+"eq/longsword");
    move_object(weapon2, this_object());
    init_command("wield sword");

    set_special(20);
}

special_move() {
object ob;
ob = this_object()->query_attack();

say("Rutger grabs a knife from his belt and throws it at "+ob->query_name()+".\n", ob);
tell_object(ob, "Rutger throws a knife at you, and it sinks painfully in your gut.\n");
   query_attack()->hit_with_spell(750);
   return 1;
}
