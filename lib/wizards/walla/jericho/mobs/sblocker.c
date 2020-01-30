inherit "obj/monster";

reset(arg) {
    object miecka,sheldu,plate,legut;
    ::reset(arg);
    if (arg) return;
    set_level(70+random(10));
    set_experience(3030000);
    set_str(query_str() + 250);
    set_dex(query_dex() + 200);
    set_name("guard");
    set_block_dir("north");
    set_short("Leb Kamar's Elite guard");
    set_long("In front of you, stands one of the most brutal looking men, you've\n"+
             "ever seen. The guard is well over 6 feet tall, and almost as wide.\n"+
             "Even so, the man moves with an unpresented smoothness and speed.\n");
    set_al(-30);
    set_gender(1);
    set_race("human");


    miecka = clone_object("/wizards/walla/jericho/stuph/bsword");
    move_object(miecka, this_object());
    init_command("wield sword");

    sheldu = clone_object("/wizards/walla/jericho/stuph/bshield");
    move_object(sheldu, this_object());
    init_command("wield shield");

    plate = clone_object("/wizards/walla/jericho/stuph/bplate");
    move_object(plate, this_object());
    init_command("wear plate");

    legut = clone_object("/wizards/walla/jericho/stuph/blegut");
    move_object(legut, this_object());
    init_command("wear leggings");

}
