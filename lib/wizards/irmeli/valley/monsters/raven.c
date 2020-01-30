inherit "obj/monster";
reset(arg) {
    object armour,armour2;
::reset(arg);
if (arg) { return; }
    set_level(58);
    set_name("raven");
    set_short("A double-headed Raven");
    set_long("A manipulated raven has two, massive heads. Raven is good flyer,\n"+
             "because of its large wings, which it uses with skill. Its eyes are as\n"+
             "black as itself. The laceration nails, in its limbs, are sharp and\n"+
             "covered with dried blood. Its two, sharp, bloody peaks are a bit of\n"+
             "bend.\n");
         
    set_al(-10);
    set_gender(0);
    set_animal(1);
    set_str(500);
    set_max_hp(20000);
    set_hp(20000);
    set_aggressive(1);
    set_log();
    set_mage(1);
    set_skill("shield bash", 100);
    set_skill("stun", 100);
    set_skill("tumble", 60);
    set_skill("tremendous blow", 80);
    set_skill_chance("tremendous blow", 80);

    armour = clone_object("/wizards/irmeli/valley/eq/ring.c");
    move_object(armour, this_object());

    armour2 = clone_object("/wizards/irmeli/valley/object/meat.c");
    move_object(armour2, this_object());
}





