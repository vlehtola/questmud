inherit "obj/monster";

reset(arg) {
    object armour1;
    object armour2;
    object weapon;
    object weapon2;
    ::reset(arg);
    if(arg) { return; }

    set_race("human");
    set_level(random(5)+60);

    set_name("ilana");
    set_alias("woman");
    set_short("Ilana, a young woman dressed in silk");
    set_long("Ilana is an attractive, young woman. She is clad in fine silky clothes\n"+
             "and wears a ring in her finger. Despite of her young age she\n"+
             "seems to be very skilled in magic arts.\n");

    set_al(30);
    set_al_aggr(200);
    set_log();
    set_mage();
    set_str(query_str() + 135);
    set_int(query_int() + 50);
    set_max_hp(query_hp() + 15000);
    set_hp(query_max_hp());
    set_gender(2);

    set_skill("stunning blast", 50);
    set_skill("proximity blast", 25);
    set_skill("distract concentration", 25);
     
    armour1 = clone_object("/wizards/nalle/jerusalem/eq/newilbelt");
    move_object(armour1, this_object());
    init_command("wear belt");

    armour2 = clone_object("/wizards/nalle/jerusalem/eq/ilring");
    move_object(armour2, this_object());
    init_command("wear ring");

    weapon = clone_object("/wizards/nalle/jerusalem/eq/axe");
    move_object(weapon, this_object());
    init_command("wield axe");
 
    weapon2 = clone_object("/wizards/nalle/jerusalem/eq/axe");
    move_object(weapon2, this_object());
    init_command("lwield axe");

    set_special(35);
}

special_move() {
object ob;
ob = this_object()->query_attack();

  if (random(3)) {
   if(ob->query_gender() == 1) {
    say("Ilana gives "+ob->query_name()+ " a tender kiss on the lips.\n");
    tell_object(ob, "Ilanas kiss makes your mind spin.\n");
    }
   else {
    say("Ilana chants and looks into " +ob->query_name()+ "s eyes.\n");
    tell_object(ob, "Hypnotic gaze makes your mind spin.\n");

    }
   say(query_attack()->query_name()+ " seems paralyzed\n");
     ob->set_stunned(10+random(5));
     return 1;
   }

  else {
   say("Ilana harms " +ob->query_name()+ "s soul with her mysterious spell.\n");
   tell_object(ob, "Ilanas spell makes you mind burn.\n");
   query_attack()->hit_with_spell(500);
 }
}
