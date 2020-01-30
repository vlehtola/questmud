inherit "obj/monster";

reset(arg) {
    object money, weapon, armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(50);
    set_name("witch");
    set_short("The EVIL witch, raiser of spirits");
    set_long("The EVIL witch is raising spirits from dead. The witch is keeping beatiful staff on his left hand. The lightning strikes many times to the staff, which gives magical powers to the witch. The witch is wearing a black hood on protection its face.\n");
    set_al(-20);
    set_aggressive(0);
    set_extra(1);
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast major", 80);
    set_skill("channel", 80);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/irmeli/area4/equ/hood.c");
    move_object(armour, this_object());
    init_command("wear hood");

    armour = clone_object("/wizards/irmeli/area4/equ/boots.c");
    move_object(armour, this_object());
    init_command("wear boots");

    weapon = clone_object("/wizards/irmeli/area4/equ/staff.c");
    move_object(weapon, this_object());
    init_command("wield staff");
}

extra() {
    string spell_words, target_name;
    target_name = "witch";
    spell_words = "chl hea mjr";

    if (!query_spell() && random(100) > 40 && query_hp() < query_max_hp() / 2 &&
        !this_object()->query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
    }
}
