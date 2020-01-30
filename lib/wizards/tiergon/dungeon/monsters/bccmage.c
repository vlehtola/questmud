inherit "obj/monster";
int number_of_demons;
object cloak,ring;

reset(arg) {
    ::reset(arg);
    number_of_demons = 0;
    if(arg) { return; }
    set_level(53);
    set_name("mage");
    set_alias("magist");
    set_short("The Black Circle's chief magist ");
    set_long("This ancient and wizened man wears expensively tailored robes tailored to hide his enormous paunch. Despite his almost comical appearance, you sense great power in him.\n");
    set_al(-160);
    set_extra(1);
    set_log();    
    set_gender(1);
    set_aggressive(1);
    set_mage(1);
    set_race("human");
    
    ring = clone_object("/wizards/tiergon/eq/dbelt");
    move_object(ring, this_object());
    init_command("wear belt");
  
    cloak = clone_object("/wizards/tiergon/eq/scloak");
    move_object(cloak, this_object());
    init_command("wear cloak");
}
extra() {
    object tiefling;
    int i;
    if (!attacker_ob) { 
        return; 
    }
    if(!query_spell() && !this_object()->query_stunned()) {
    if(random(number_of_demons + 1) >= number_of_demons) {
        tiefling = clone_object("/wizards/tiergon/dungeon/tiefling.c");    
        i = random(5);
        if (i <= 2) { 
        move_object(tiefling, environment(this_object()));
        say("The wizard chants something in the arcane tongue, and a strange-looking woman appears with a puff of smoke.\n");
        }
        if (i == 3) {
        move_object(tiefling, "/wizards/tiergon/c1.c");
        say("The wizard chants something in the Arcane tongue, but luckily nothing seems to happen.");
        }
        if (i == 4) {
        move_object(tiefling, "/wizards/tiergon/c4.c");
        say("The wizard chants something in the Arcane tongue, but luckily nothing seems to happen.");
     }   
     number_of_demons  += 1;
    }
}
}

reduce_number() {
    number_of_demons -= 1;
}
