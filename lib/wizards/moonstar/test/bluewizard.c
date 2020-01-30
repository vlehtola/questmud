
inherit "obj/monster";
reset(arg) {
object armour;
    object armour2;
    object ring;
    string chat_str, a_chat_str;
::reset(arg);
if (arg)  {return; }
set_name("krazzt");
        set_alias("keeper");
        set_race("human");
        set_mage(1);
        set_level(70+random(20));
        set_experience(14307832);
        set_max_hp(query_max_hp()*3);
set_int(query_int()*4);
        set_wis(query_wis()*2);
        set_con(query_con()*3);
        set_str(query_str()*2);
set_al(30);
        set_gender(1);
        set_short("Krazzt, the secret keeper of water");
        set_long("Old high wizard Krazzt. He is the secret keeper of water.\n"+
 "He has deep blue eyes and long blue hair.\n"+
 "He looks very strong even though he is old\n"+
        "and his hands are emiting strong blue light.\n"+
        "You'd better not disturb him.\n");
set_skill("stun", 100);
        set_skill("bare hands", 40);
        set_skill("attack", 70);
        set_skill("inner strength", 20);
        set_skill("cast essence", 100);
        set_skill("cast ice", 100);
        set_skill("cast earth", 100);
        set_skill("cast fire", 100);
        set_skill("cast electric", 100);
        set_skill("cast bolt", 100);
        set_skill("mana control", 100);
        set_skill("knowledge of heat", 100);
        set_skill("lore of cold", 100);
        set_skill("theory of electricity", 100);
        set_skill("proximity blast", 100);
        set_skill("stunning blast", 100);
        set_skill("counter spell", 100);
        set_skill("reflect spell", 70);
        set_skill("invoke ethereal mana", 100);
        set_skill("power channeling", 80);
        set_skill("power concentration", 80);
        set_skill("power focusing", 80);

    set_log();
    set_dead_ob(this_object());
    set_special(13);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Krazzt screams: 'WHY ARE YOU HERE!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Krazzt says: 'Leave or I will banish you!'\n";
    }
    load_chat(8, chat_str);
    load_a_chat(5, a_chat_str);


    armour = clone_object("/wizards/moonstar/areas/wasteland/eq/bboots");
    move_object(armour, this_object());
    init_command("wear boots");


    armour2 = clone_object("/wizards/moonstar/areas/wasteland/eq/bamulet");
    move_object(armour2, this_object());
    init_command("wear amulet");

    ring = clone_object("/wizards/moonstar/areas/wasteland/eq/wring.c");
    move_object(ring, this_object());
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Krazzt chants 'FRAZER' and immediately HUGE ice rock hits you!\n");
 say("Krazzt casts a HUGE ice rock towards "+ob->query_name()+" by chanting 'FRAZER'!\n", ob);
  ob->hit_with_spell(800, "cold");
}

monster_died() {
    object ob;
    tell_room(environment(this_object()), "As Krazzt falls to the ground his body starts to\n"+
              "shiver and a shadow raises out from the corpse and disappears. Voice of Krazzt can be heard:\n"+
              "'The brotherhood of fire and water shall not be undone.'\n");
}
