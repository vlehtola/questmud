inherit "obj/monster";

reset(arg) {
        object weapon, armour, shield;
        ::reset(arg);
        if(arg) { return; }
        set_level(24+random(4));
        set_name("elf");
        set_race("wood elf");
        set_short("An elf is here guarding the flet");
        set_long("This elf has long brown hair and crystal blue eyes. He is\n"+
                "wearing simple green clothes. He must be very skilled in\n"+
                "combat. His equipment seem to be of very high quality. He\n"+
                "is watching your every move and you get the feeling that you\n"+
                "don't want to mess with this elf.\n");
        set_al(40);
        set_aggressive(0);
        set_al_aggr(80);
        set_gender(1);

        weapon = clone_object("/wizards/rag/elf/weapons/elf_sword");
        move_object(weapon,this_object());
        init_command("wield sword");

        shield = clone_object("/wizards/rag/elf/weapons/elf_shield");
        move_object(shield,this_object());
        init_command("wield shield");

        armour = clone_object("/wizards/rag/elf/armours/elf_mail");
        move_object(armour,this_object());
        init_command("wear mail");
}
