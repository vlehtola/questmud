inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_experience(20000000);
    set_name("Lutku the tappaja leppakerttu");
    set_alias("lutku");
    set_short("Lutku the tappaja leppakerttu");
    set_long("This thing is yodin's paras kamu niiQ.\n"
             "Aika sopo kaveri eiks je silla on ainakin 4 taplaa. \n" +
             "Jos joku nussii leppiksen pilkut yotini seta suuttuupi.\n");
    set_animal(1);

}

